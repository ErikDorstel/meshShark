//#define HELTECV2
#define HELTECV3

#ifdef HELTECV2
  #include <SX127x.h> // LoRaRF Arduino Library https://github.com/chandrawi/LoRaRF-Arduino
  SX127x LoRa;

  #define SCK 5
  #define MISO 19
  #define MOSI 27
  #define CS 18
  #define RST 14
  #define DIO0 26
  #define syncWord 0x2b
  #define SDA 4
  #define SCL 15
  #define RESET 16
#endif

#ifdef HELTECV3
  #include <SX126x.h> // LoRaRF Arduino Library https://github.com/chandrawi/LoRaRF-Arduino
  SX126x LoRa;

  #define SCK 9
  #define MISO 11
  #define MOSI 10
  #define CS 8
  #define RST 12
  #define BUSY 13
  #define DIO1 14
  #define syncWord 0x2b
  #define SDA 17
  #define SCL 18
  #define RESET 21
#endif

#include <Adafruit_SSD1306.h> // Library https://github.com/adafruit/Adafruit_SSD1306
Adafruit_SSD1306 oled(128,32,&Wire,RESET);

void setup() {
  Serial.begin(115200);
  Serial.println("meshShark (Meshtastic Header Sniffer)");
  Serial.println("... sniffing ...");

  SPI.begin(SCK,MISO,MOSI,CS);
  LoRa.setSPI(SPI,16000000);
#ifdef HELTECV2
  LoRa.begin(CS,RST,DIO0,-1,-1);
  LoRa.setRxGain(LORA_RX_GAIN_BOOSTED,true);
#endif
#ifdef HELTECV3
  LoRa.begin(CS,RST,BUSY,DIO1,-1,-1);
  LoRa.setRxGain(SX126X_RX_GAIN_BOOSTED);
  LoRa.setDio2RfSwitch(true);
  LoRa.setDio3TcxoCtrl(SX126X_DIO3_OUTPUT_1_8,SX126X_TCXO_DELAY_10);
  LoRa.setRegulator(SX126X_REGULATOR_LDO);
#endif
  LoRa.setFrequency(869525000);
  LoRa.setLoRaModulation(11,250000,5,false);
  LoRa.setLoRaPacket(LORA_HEADER_EXPLICIT,16,32,true,false);
  LoRa.setSyncWord(syncWord);
#ifdef HELTECV2
  LoRa.request(SX127X_RX_CONTINUOUS);
#endif
#ifdef HELTECV3
  LoRa.request(SX126X_RX_CONTINUOUS);
#endif

  Wire.begin(SDA,SCL);
  oled.begin(SSD1306_SWITCHCAPVCC,0x3c);
  oled.setTextSize(1);
  oled.setTextColor(SSD1306_WHITE);
  oled.cp437(true);
  oled.clearDisplay();
  oled.setCursor(0,0);
  oled.println("Meshtastic");
  oled.println("Header Sniffer");
  oled.println("");
  oled.println("... sniffing ...");
  oled.display();
}

void loop() {
  static uint16_t last;
  static unsigned long timer;
  const uint8_t length=LoRa.available();
  if (length) {
    last=0;
    timer=millis()+1000;
    char message[length];
    LoRa.read(message,length);

    uint32_t toAddr=(message[3]<<24)+(message[2]<<16)+(message[1]<<8)+(message[0]);
    uint32_t fromAddr=(message[7]<<24)+(message[6]<<16)+(message[5]<<8)+(message[4]);
    uint32_t senderID=(message[11]<<24)+(message[10]<<16)+(message[9]<<8)+(message[8]);
    uint8_t hopLimit=message[12]&0b00000111;
    bool wantAck=(message[12]&0b00001000)>>3;
    bool viaMQTT=(message[12]&0b00010000)>>4;
    uint8_t hopStart=(message[12]&0b11100000)>>5;
    uint8_t hash=message[13];

    Serial.print("From:" + String(fromAddr,HEX) + " To:" + String(toAddr,HEX) + " ID:" + String(senderID,DEC));
    Serial.print(" Hops:" + String(hopLimit) + "/" + String(hopStart));
    Serial.print(" wantAck:" + String(wantAck) + " viaMQTT:" + String(viaMQTT));
    Serial.print(" Hash:" + String(hash,DEC) + " Length:" + String(length,DEC) + " Bytes");
    Serial.println(" RSSI:" + String(LoRa.packetRssi()) + " dBm SNR:" + String(LoRa.snr()) + " dB Status:" + String(LoRa.status()));

    oled.clearDisplay();
    oled.setCursor(0,0);
    oled.println("From: " + String(fromAddr,HEX));
    oled.println("To: " + String(toAddr,HEX));
    oled.println("RSSI: " + String(LoRa.packetRssi()) + " dBm");
    oled.println("SNR: " + String(LoRa.snr()) + " dB");
    oled.setCursor(104,24);
    oled.println(last);
    oled.display();
  }

  if (millis()>=timer) {
    timer=millis()+1000;
    last++;
    oled.fillRect(104,24,24,8,SSD1306_BLACK);
    oled.setCursor(104,24);
    oled.println(last);
    oled.display();
  }
}
