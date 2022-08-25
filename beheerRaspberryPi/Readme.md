# Beheer die Arduino met 'n Raspberry Pi

Gebruik volgende tutoriaal om die Arduino deur die seriepoort te beheer met behulp van 'n Raspberry Pi.

https://pythonforundergradengineers.com/python-arduino-LED.html

Nog 'n tutoriaal:

https://automaticaddison.com/2-way-communication-between-raspberry-pi-and-arduino/



## Send a String From Arduino to Raspberry Pi

Let’s get started by sending a string of text (“Hello World”) from your Arduino to your Raspberry Pi.

Write the following program and upload it to your Arduino. Save it as **send_string_to_raspberrypi.ino**. 

Before you connect the Arduino to your Raspberry Pi, you need to set up the Raspberry Pi so that it can receive data from the Arduino. We first need to figure out the port that connects the Arduino and the Raspberry Pi.

Turn on your Raspberry Pi, and open a new terminal window.

Update the list of packages on your system:

```bash
sudo apt-get update
```

Upgrade any outdated packages (optional):

```bash
sudo apt-get upgrade
```

Install the PySerial package.

```bash
python3 -m pip install pyserial
```

Open a new terminal window, and type the following command to get a list of all the ports that begin with the prefix **tty**.

```
ls /dev/tty*
```

You see the new port? You should see a new port with a name like **/dev/ttyACM0**. That is your Arduino.

Another way to see all the USB devices connected to your Raspberry Pi is to use this command:

```
lsusb
```

Set the baud rate of that port (i.e. the speed of data communication over that port/channel). Let’s use 9600. 9600 isn’t set in stone. For other projects you could use 38400, 57600, 115200, etc.

```
stty -F /dev/ttyACM0 9600
```

Let’s check the baud rate to see if it is set properly.

```
stty -F /dev/ttyACM0
```

Create a new Python program.

```
gedit receive_string_from_arduino.py
```

Make it executable.

```
chmod +x receive_string_from_arduino.py
```

Now run the program.

```
./receive_string_from_arduino.py
```

You should see this print out to your screen.



## Send Integers From Arduino to Raspberry Pi

Let’s create programs to send integers from Arduino to Raspberry Pi.

Upload the following code to your Arduino. Save the file as **send_ints_to_raspberrypi.ino**.



Now go over to your Raspberry Pi. 

Open a new terminal and go to your folder.

```
cd Documents/pi_arduino_communication
```

Create a new Python program.

```
gedit receive_ints_from_arduino.py
```

Write the following code and save it.

Make it executable.

```
chmod +x receive_ints_from_arduino.py
```

Plug your Arduino into your Raspberry Pi using the USB cable.

Now run the Python program.

```
./receive_ints_from_arduino.py
```

You should see this print out to your screen.



## Send Integers From Raspberry Pi to Arduino

Let’s put it all together. We will:

1. Create a Python program that sends integers from the Raspberry Pi to the Arduino.
2. The Arduino will respond back to the Raspberry Pi with the integers it has received.
3. The Raspberry Pi will print out the integers it received from the Arduino.

Let’s start by creating the program for the Arduino.

Create the following sketch, and upload it to your Arduino. Save it as **receive_ints_from_raspberrypi.ino**.

Now go over to your Raspberry Pi, and open a new Python file.

```
gedit send_ints_to_arduino.py
```

Write the following code and save it.



Make it executable.

```
chmod +x send_ints_to_arduino.py
```

Plug your Arduino into your Raspberry Pi using the USB cable.

Now run the Python program.

```
./send_ints_to_arduino.py
```

You should see this print out to your screen.