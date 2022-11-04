# LSM6DS3 Accelerometer

The LSM6DS3 is a accelerometer, gyroscope and temperature sensor all in one. with I2C and SPI communications. Power consumption: 0.9 mA in combo normal mode and 1.25 mA in combo high-performance mode up to 1.6 kHz. "Always on" experience with low power consumption for both accelerometer and gyroscope

Quick Spec

   -Supply Range: 1.71 to 3.6V
   -Interface: SPI/I2C
   -Event driven Interrupts
   -FIFO: 8 kbyte
   -Sense: Acceleration, Gyro, Tilt, Free Fall, Vibration, Temperature
   -Libraries: Arduino



https://www.arduinolibraries.info/libraries/lsm6
https://learn.sparkfun.com/tutorials/lsm6ds3-breakout-hookup-guide#using-the-arduino-library
https://www.arduinolibraries.info/libraries/smart-everything-lsm6-ds3



Werk ongelukkig met 3.3V.  Dit beteken dat om die Arduino se 5V krag te gebruik moet die versnellingsmeter 'n logic level converter kry wat die krag reguleer.

https://www.robotics.org.za/LEVEL-4P?search=logic%20level

Kan dit egter op 'n power supply toets wat 3.3V gee en indien dit werk kan dit net van batterye voorsien word en dan sal dit werk.

# SPI 3.3 Volt logic level converter circuit

Moet die versnellingsmeter met 'n SPI (serial peripheral interface) op die Arduino koppel.

![SPI_circuit](Prente\SPI_circuit.jpg)

The creation of myIMU has a dark secret. If you're not using I2C, address 0x6B (defualt), you can specify your port during the construction. From the example,

``` 
LSM6DS3 myIMU( SPI_MODE, 10 );
```
...we specify SPI_MODE, a custom keyword, and pin 10. This makes use of the SPI interface and uses pin 10 for the CS line. As the logic is not arduino specific, any pin can be CS.

![SPI_circuit](Prente\LSM6DS3_bo.png)
![SPI_circuit](Prente\LSM6DS3_bo_label.png)
![SPI_circuit](Prente\LSM6DS3_onder.png)


# TXB0108 level shifter

The following level shifter was used to convert the 5V supply from the Arduino to the 3.3V required to power the LSM6 unit.

The A side of the level shifter is the low voltage (1.2V to 3.6V) and the B side of the level shifter is high voltage side (1.65V to 5.5V) according to the data sheet of the level shifter.

Die OE pen beteken "Output Enable".  Dit moet verbind word met VA of die 3.3V om die seine se hekke oop te maak, anders gaan niks gemeet word nie.

![TXB0108](Prente\TXB0108.JPG)


# Probleme

Eerste keer toe konneksie gemaak is met SPI bedrading en logic level shifter wys dit
"Failed to initialize IMU!"

Dit kan wees omdat dit eintlik I2C verwag en nie SPI nie.  Die ADDR jumper moet oop gesoldeer word om die I2C af te skakel en die SPI aan te skakel.  Daar is egter nie so 'n jumper op die pers LSM6DS3 bord nie.  Daar is so 'n jumper op die Sparkfun bord.  Dus probeer die volgende:

Probeer eers die bord met 3.3V krag gee.  Miskien gebruik die versnellingsmeter nie so baie krag nie.  Dus kry die data deur I2C.  Miskien kan hierdie bord nie eintlik SPI hanteer nie.

Hier is die bedrading wat gedoen moet word:

![I2C_circuit](Prente\I2C_circuit.jpg)

Het dit probeer.  Maar dit het nie gewerk nie.  Die 3.3V is net 'n reference spanning en nie genoeg om die versnellingsmeter krag te gee nie.


Volgende oplossings:
- Moet dalk 'n 3.3V Arduino Nano koop en toets of dit werk.  Dit sal genoeg krag gee.
- Gee die Chip select 'n spanning om dit aan te skakel (dalk gaan dit nie werk nie)
- Doen dalk SPI bedrading, maar sit die 3.3V op VIN instede van 3V3.