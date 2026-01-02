# ArduinoNano33 Gyro
This is a project to generate gyro data on Arduino Nano 33 device.  The device has a LMS6DS3 IMU [[st_imu_lsm6ds3_datasheet.pdf]].  The aim is to read the gyro data out at 208 Hz, over the wifi and into an excel file.

In the arduino folder there is a arduino_secrets.h file missing and it should contain:
```
#define SECRET_SSID ""     // SSID
#define SECRET_PASS ""     // Password
```
with the correct values populated.

## Arduino code
Load onto device.  Not the IP address is hard coded.  This address should be used in the consumer script.
## Python code
Make sure the Arduino IP is correct.  Install requirement.  To only read the data run
```
python pipe_reader.py
```
To display a crude 3d model, as well, run
```
python render_3d.py
```

## Notas

Die monsterfrekwensie is 208Hz.
Die Arduino rapporteer 88Hz, maar dit is nie korrek nie.  Die instellings in LSM6DS3.cpp lei tot 'n 208Hz monsterfrekwensie.

op 2026-01-02 doen volgende toetse:

kalibrasie_data.csv - beweeg die instrument rondom z-as van 0 tot 60 grade to 0 grade vir tien herhalings.  Dit moet ongeveer 'n gemiddeld van 30grade/s gee.  Die data wys dit is naastenby wat gemeet is.  Die maksimum waardes is meer want by die draaipunte is hoektempo meer.  Tydsduur is 40 sekdondes.

looprondVliegtuig.csv - Loop rond met vliegtuig en meet tot by einde van gras om reikafstand te toets. Tydsduur is 60 sekdondes.
om_swembad.csv - Loop rond met vliegtuig rondom swembad en tot by grens van erf met die groot muur.  Dit wys dat die reikafstand genoeg is van die wifi.  Tydsduur is 120 sekdondes.

Hierdie toetse wys dat die Arduino Nano 33IOT met 'n 9V battery ver genoeg kan meet.  Die prosedure wat gewerk het is as volg:
Skakel die Nano aan.  Maak 'n terminaal oop en ping die netwerkadres van die Arduino.  Dit werk as die toestel antwoord.  Dan begin die meting met:

```bash
python pipe_reader.py
```
Hou die tyd dop op 'n stophorlosie.  Dan loop weer terug na die rekenaar naaste aan wifi.  Dan plot die resultate met:

```bash
python plotgirodata.py
```

Te doen:

Skryf 'n roetine wat die hoeke integreer van die gemete giro data om die vlughoek van die vliegtuig te bepaal.  As die vliegtuig sweef, is alpha (invalshoek) gelyk aan theta (vlughoek)