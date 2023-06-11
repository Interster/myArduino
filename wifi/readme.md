The intention is that the file would be in the sketch folder. Additional files are shown as tabs in the Arduino IDE:

Click the downwards pointing triangle button near the top right of the Arduino IDE window.
Click "New Tab".
Give the new file the name arduino_secrets.h
Click "OK".
Add your code to the arduino_secrets.h tab.





Die arduino_secrets.h lêer moet die volgende inhoud hê:



```c++
#define SECRET_SSID "xxxxxxxx"
#define SECRET_PASS "xxxxxxxx"
```

Onthou dit moet as volg in die hoofskets ingesluit word, anders werk dit nie:

```c++
#include "arduino_secrets.h"
```

Die arduino_secrets.h lêer moet in dieselfde plek wees as die Arduino skets.