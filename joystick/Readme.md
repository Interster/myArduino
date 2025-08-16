**Opdatering:  2025-08-16:  Gebruik dalk eerder die PS3 met die ESP32 om 'n joystick te bou**



The latest build of Version 2.0 of the Arduino Joystick Library can be downloaded from the following GitHub repository:

https://github.com/MHeironimus/ArduinoJoystickLibrary/tree/version-2.0

The library can also be downloaded directly using the following: https://github.com/MHeironimus/ArduinoJoystickLibrary/archive/version-2.0.zip

Copy the Joystick folder to the Arduino Libraries folder (typically located at %userprofile%\Documents\Arduino\libraries on Microsoft Windows machines). On Microsoft Windows machines this can be done by executing deploy.bat. The library should now appear in the Arduino IDE list of libraries.

![Circuit-Diagram-for-Joystick-Game-Controller-using-Arduino-Leonardo](Prente\Circuit-Diagram-for-Joystick-Game-Controller-using-Arduino-Leonardo.png)

![Arduino-Joystick-Game-Controller](Prente\Arduino-Joystick-Game-Controller.png)



![Circuit-Hardware-for-Joystick-Game-Controller-using-Arduino-Leonardo](Prente\Circuit-Hardware-for-Joystick-Game-Controller-using-Arduino-Leonardo.jpg)

![JoyStickLibraryFunctions](Prente\JoyStickLibraryFunctions.png)

The following PS3 type resistors can be obtained from old PS3 remotes:

![SPIPP007_nash-4l](Prente\SPIPP007_nash-4l.jpg)



The example Arduino sketch files listed below are included in this library. These will appear in the Arduino Example menu when the Arduino Joystick Library is installed.

**JoystickTest** – Simple test of the Joystick library. It exercises many of the Joystick library’s functions when pin A0 is grounded.

**MultipleJoystickTest** - Creates 4 Joysticks using the library and exercises the first 16 buttons, the X axis, and the Y axis of each joystick when pin A0 is grounded.

**JoystickButton** - Creates a Joystick and maps pin 9 to button 0 of the joystick, pin 10 to button 1, pin 11 to button 2, and pin 12 to button 3.

**JoystickKeyboard** - Creates a Joystick and a Keyboard. Maps pin 9 to Joystick Button 0, pin 10 to Joystick Button 1, pin 11 to Keyboard key 1, and pin 12 to Keyboard key 2.

**GamepadExample** - Creates a simple Gamepad with an Up, Down, Left, Right, and Fire button.

**DrivingControllerTest** - Creates a Driving Controller and tests 4 buttons, the Steering, Brake, and Accelerator when pin A0 is grounded.

**FlightControllerTest** - Creates a Flight Controller and tests 32 buttons, the X and Y axis, the Throttle, and the Rudder when pin A0 is grounded.

**HatSwitchTest** - Creates a joystick with two hat switches. Grounding pins 4 - 11 cause the hat switches to change position.

![DevicesPrinters](Prente\DevicesPrinters.png)

![SettingsJoystick](Prente\SettingsJoystick.png)

![Properties](Prente\Properties.png)



![PropertiesSetup](Prente\PropertiesSetup.png)









