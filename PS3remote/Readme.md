# Bluetooth PS3 remote

Die PS3 remote kan op die USB 2.0 host shield ingeprop word met sy laai kabel en dit kan dan die opdragte na die Arduino skryf.  Dit word gedoen met die PS3 USB skets.

Om die PS3 remote met bluetooth te koppel moet 'n Bluetooth 2.0 + EDR (Enhanced data rate) adapter gebruik word andersins werk dit nie.  Net Bluetooth 2.0 werk nie en 5.0 werk nie.

Gebruik die volgende video om die koppeling te doen en gebruik die PS3BT skets.  Dit verduidelik hoe om die basis voorbeeld skets te verander totdat dit werk.

Die kode vir die USB host shield 2.0 en dokumentasie is by:
https://github.com/felis/USB_Host_Shield_2.0

Prop eers die Bluetooth adapter in en verkry dan so die adres wat vertoon word in serial monitor.  Verander dan die skets om hierdie adres te he.  Dan laai weer die skets en sit die PS3 dan in.  Dan word die PS3 remote gelaai met die korrekte Bluetooth adres.


Onthou om in die settings.h leer die volgende vlag te stel anders wys die serial monitor niks wat gebeur nie.

```
#define ENABLE_UHS_DEBUGGING 1
```

Op Ubuntu is hierdie leer in:
```
~/Arduino/libraries/USB_Host_Shield_Library_2.0
```