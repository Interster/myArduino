# Radio beheer kar met kamera

Bou 'n radiobeheer kar met die Fat Shark kamera op.

![Diagram](Prente/1_KarMetKameraDiagram.jpg)


## Statiese IP adres

Stel statiese IP adres op met volgende kode

```
WiFiNINA - WiFi.config()
```


https://www.arduino.cc/reference/en/libraries/wifinina/wifi.config/

Voorbeeld:

```
// the IP address for the shield:
IPAddress ip(192, 168, 0, 177);

WiFi.config(ip);
```