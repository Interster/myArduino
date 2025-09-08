# myArduino
Versameling van persoonlike Arduino projekte


## Beheerstelsels

Implementering van PID beheer in Arduino.

Vanaf:
https://www.teachmemicro.com/arduino-pid-control-tutorial/



```C
//PID constants
double kp = 2
double ki = 5
double kd = 1
 
unsigned long currentTime, previousTime;
double elapsedTime;
double error;
double lastError;
double input, output, setPoint;
double cumError, rateError;
 
void setup(){
        setPoint = 0;                          //set point at zero degrees
}    
 
void loop(){
        input = analogRead(A0);                //read from rotary encoder connected to A0
        output = computePID(input);
        delay(100);
        analogWrite(3, output);                //control the motor based on PID value
 
}
 
double computePID(double inp){     
        currentTime = millis();                //get current time
        elapsedTime = (double)(currentTime - previousTime);        //compute time elapsed from previous computation
        
        error = Setpoint - inp;                                // determine error
        cumError += error * elapsedTime;                // compute integral
        rateError = (error - lastError)/elapsedTime;   // compute derivative
 
        double out = kp*error + ki*cumError + kd*rateError;                //PID output               
 
        lastError = error;                                //remember current error
        previousTime = currentTime;                        //remember current time
 
        return out;                                        //have function return the PID output
}
```

## Probleme teegekom

### Probleem met skryfregte na die /dev/ttyACM0


To confirm the port exists enter the following from the root directory.

```
ls /dev/ttyACM0
```

To set read/write permissions, enter the following

```
sudo chmod a+rw /dev/ttyACM0
```

Doen dit in die terminaal in 'n gids waar die Arduino IDE is.
Daarna voer die volgende uit:

```
./arduino-ide
```

### Probleem om Nano IOT33 te koppel:

Sukkel om die Arduino Nano IOT33 te koppel:

The problem is that pop-desktop comes with (and depends on) brltty, a package for working in brail. When you plug in an arduino, it detects it as a brail device, tries to connect to it, fails, and then gets stuck.

To fix it, disable brltty following this comment:

```
systemctl stop brltty-udev.service  
sudo systemctl mask brltty-udev.service  
systemctl stop brltty.service  
systemctl disable brltty.service
```


### Probleem om PS3 outomaties te koppel in Linux:

Linux vra 'n pairing kode en dit moenie as jy 'n PS3 remote met bluetooth koppel.  Om dit reg te maak, raadpleeg die volgende artikel:

https://askubuntu.com/questions/1497783/why-does-official-ps3-bluetooth-controller-no-longer-work-and-pin-code-suddenly

Basically in  `/etc/bluetooth/input.conf` add `ClassicBondedOnly=false` and run `systemctl restart bluetooth`. Solved it instantly :)