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

