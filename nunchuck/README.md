# Wii-Nunchuk

![Nunchuk](Prente/nunchuk.jpg)

Schema
---

![screen](Prente/screen.png)


Documentation
---
The full documentation can be found [here](http://www.xarg.org/2016/12/using-a-wii-nunchuk-with-arduino/).


Eie nunchuk:

Dit lyk asof die drade van die nunchuk die volgende konvensie het, weens die orientasie van die drade toe dit uitgekom het.  Die drade was af, so dit was nie moontlik om die konneksie te bevestig nie.

Hier is fotos van die bestaande nunchuk, maar die drade was reeds afgebreek:

![1_DradeRigting](Prente/1_DradeRigting.jpg)

![2_DradeRigting](Prente/2_DradeRigting.jpg)


Nadat die nunchuk oopgemaak is kon die konvensie van die bord af verkry word want dit is daar gedruk op die PC bord.



    Yellow → 3v3
    Bruin → nc
    Blou → SCL of A5
    Red → SDA of A4
    nc
    White → GND

Die drade van die nunchuk is soos hierbo en in die foto gekoppel en dit het gewerk.  Die spesifieke nunchuk het 'n probleem met die joystick in die sin dat net die x-kanaal (links/regs) werk.  Die y-as of op en af is stukkend.

![3_NunchuckArduino](Prente/3_NunchuckArduino.jpg)

![4_NunchukBedrading](Prente/4_NunchukBedrading.jpg)
