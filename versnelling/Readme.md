https://www.robotics.org.za

R89.70 op 2021-10-07

# ADXL335 Module Triple Axis Accelerometer Breakout

The 3 axis ADXL335 from Analog Devices is the latest in a long,  proven line of analog sensors - the holy grail of accelerometers. The  ADXL335 is a triple axis MEMS accelerometer with extremely low noise and power consumption - only 320uA! The sensor has a full sensing range of  +/-3g. The Board comes fully assembled and tested with external  components installed.

# Quick Spec

- Sensor Chip: ADXL335
- Power Supply:  1.8V- 6V  (Onboard 3.3V Regulator)
- Integrated X, Y, and Z axis accelerometer on a single chip
- X and Y axis has a 0.5Hz to 1600Hz bandwidth
- Z axis has a 0.5Hz to 550Hz bandwidth
- Hermetically sealed for temp and humidity resistance
- 10,000 g shock tolerant
- Dimensions: 21 x 16 mm

![GY-61-Layout01](GY-61-Layout01.jpg)

![GY-61-Layout02](GY-61-Layout02.jpg)

![GY-61-Layout03](GY-61-Layout03.jpg)





# Bespreking van filter

Dit is nodig om 'n filter op te sit om die effek van ho"e frekwensie geraas te verminder.

![FilterEffek](Prente/FilterEffek.png)


# Karakteriseer die geraas van die sensor

Gebruik die skets versnellingmeet.ino

Log nou data van die sensor.
Gebruik die volgende terminaal opdrag om die data vanaf die seriepoort te log:

(stty raw; cat > received.log) < /dev/ttyUSB0

Die Arduino was by die ttyUSB0 poort ingeprop.  Begin die skets loop en dan begin die opdrag hierbo.  Dan onderbreek net hierdie stelling en dan word die data na die teksleer gestuur.

Nou kan hierdie data analiseer word.



## Die gebruik van 'n onderbreking (Interrupt)

Dit is nodig om 'n interrupt te gebruik om die tydsberekening van metings te verseker.  Andersins sal die metings moontlik nie teen 'n vaste monsterfrekwensie kan gebeur nie.

Interrupts word as volg met 'n Arduino gedoen:

https://electronoobs.com/eng_arduino_tut140.php
