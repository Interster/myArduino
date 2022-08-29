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