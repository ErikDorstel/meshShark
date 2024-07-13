# meshShark
ESP32 based Meshtastic LoRa Header Sniffer
#### Features
* works with Heltec WiFi LoRa 32 (V2) and (V3) modules
* suitable for comparing or aligning antennas
* displays reception field strength and signal-to-noise ratio
* console output of the header attributes of the received packets
#### display output
![IMAGE ALT TEXT HERE](documentation/meshSharkDisplay.png)
#### console output
```
11:48:38.571 -> meshShark (Meshtastic Header Sniffer)
11:48:38.571 -> ... sniffing ...
11:48:58.077 -> From:4358e168 To:ffffffff ID:901146663 Hops:7/7 wantAck:0 viaMQTT:0 Hash:8 Length:47 Bytes RSSI:-38 dBm SNR:7.50 dB Status:7
11:48:59.287 -> From:4358e168 To:ffffffff ID:901146663 Hops:6/7 wantAck:0 viaMQTT:0 Hash:8 Length:47 Bytes RSSI:-71 dBm SNR:6.75 dB Status:7
11:48:59.969 -> From:4358e168 To:ffffffff ID:901146663 Hops:6/7 wantAck:0 viaMQTT:0 Hash:8 Length:47 Bytes RSSI:-44 dBm SNR:6.50 dB Status:7
11:49:15.930 -> From:4358e168 To:ffffffff ID:901146665 Hops:7/7 wantAck:0 viaMQTT:0 Hash:8 Length:41 Bytes RSSI:-41 dBm SNR:5.75 dB Status:7
11:49:16.821 -> From:4358e168 To:ffffffff ID:901146665 Hops:6/7 wantAck:0 viaMQTT:0 Hash:8 Length:41 Bytes RSSI:-73 dBm SNR:6.25 dB Status:7
11:49:18.416 -> From:4358e168 To:ffffffff ID:901146665 Hops:6/7 wantAck:0 viaMQTT:0 Hash:8 Length:41 Bytes RSSI:-46 dBm SNR:5.75 dB Status:7
11:50:29.654 -> From:4358e168 To:84995930 ID:2097704915 Hops:7/7 wantAck:0 viaMQTT:0 Hash:8 Length:20 Bytes RSSI:-48 dBm SNR:6.25 dB Status:7
11:50:30.685 -> From:84995930 To:4358e168 ID:1565201279 Hops:2/2 wantAck:0 viaMQTT:0 Hash:8 Length:46 Bytes RSSI:-46 dBm SNR:6.00 dB Status:7
11:50:31.248 -> From:4358e168 To:84995930 ID:2097704915 Hops:6/7 wantAck:0 viaMQTT:0 Hash:8 Length:20 Bytes RSSI:-64 dBm SNR:6.00 dB Status:7
11:50:39.173 -> From:4358e168 To:84995930 ID:2097704916 Hops:7/7 wantAck:1 viaMQTT:0 Hash:8 Length:20 Bytes RSSI:-45 dBm SNR:7.25 dB Status:7
11:50:40.065 -> From:84995930 To:4358e168 ID:1565201280 Hops:2/2 wantAck:1 viaMQTT:0 Hash:8 Length:23 Bytes RSSI:-46 dBm SNR:6.25 dB Status:7
11:50:41.049 -> From:4358e168 To:84995930 ID:2097704916 Hops:6/7 wantAck:1 viaMQTT:0 Hash:8 Length:28 Bytes RSSI:-64 dBm SNR:6.75 dB Status:7
11:50:41.659 -> From:4358e168 To:84995930 ID:901146670 Hops:2/2 wantAck:0 viaMQTT:0 Hash:8 Length:27 Bytes RSSI:-46 dBm SNR:6.75 dB Status:7
11:50:42.784 -> From:4358e168 To:84995930 ID:901146670 Hops:1/2 wantAck:0 viaMQTT:0 Hash:8 Length:27 Bytes RSSI:-64 dBm SNR:6.50 dB Status:7
```