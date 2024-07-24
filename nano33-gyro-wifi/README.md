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