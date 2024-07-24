# Hoe om Bluetooth te gebruik as 'n diens

Gebruik volgende tutoriaal om 'n diens op te stel en met die foon te monitor en te verander:

https://docs.arduino.cc/tutorials/nano-33-iot/bluetooth/


Dit werk maar net deur die USB kabel met die rekenaar.  Wanneer die vierkantige 9V (9V PP3) battery opgesit word, dan werk dit nie meer nie.

Hierdie forum antwoord mag dalk die rede verskaf:

https://forum.arduino.cc/t/ble-begin-fails-to-run-on-nano-33-iot-when-running-on-battery/1186971

> 9V batteries are for smoke alarms, and are totally unsuitable for powering anything that draws a significant amount of current, such as the radio when you try to execute BLE.begin().
> You need a power supply capable of delivering 200-300 mA or more. 

![9VPP3 battery](Prente\1_Battery9VPP3.jpeg)

Hier is hoe om die Arduino Nano 33 IOT te bedraad.

![Arduino bedraad Nano](Prente\2_ArduinoBedraad.png)

Volgende stap:  Gebruik 4 x AA 1.5V batterye en kyk of die Bluetooth dan werk:
![Arduino bedraad Nano](Prente\3_AA_batterye.png)


Op 2024-07-15:  bedraad die Arduino 33 IOT aan 'n 6V (4 x AA 1.5V batterye) battery en gee krag aan die Arduino.

![AA batterye Nano](Prente/4_AA_bedrading.jpg)

Dit werk egter nog steeds nie.  Kry dan hierdie post:

https://forum.arduino.cc/t/nano-ble-sense-bluetooth-not-working-on-battery-powersupply/641959

Dit gee die raad dat die setup funksie 'n serie kommunikasie oopmaak.  As dit aan 'n battery gekoppel is, maar nie aan die rekenaar nie, dan bly hierdie 'n ondeindige lus.  Hierdie lyn moet dus uitgekommentaar word:

```
while(!Serial);
```

Na hierdie gedoen is, het die bluetooth gewerk op die 4 x AA batterye.  Daarna is die 9V battery ook getoets en dit het nog steeds gewerk.  Gebruik dus nou die 9V battery want dit is kleiner.  Hierdie skets is nou suksesvol implementeer.
 
