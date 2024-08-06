# Prop PS3 remote in met draad
# Haal dan uit en sit bluetooth adapter in en skakel remote aan.  Dan werk PS3 deur die rekenaar.  Werk met Linux
# Kyk na controller met jstest-gtk

# Stuur deur die rekenaar beheer instruksies aan 'n kar met bluetooth of wifi

#%%

# https://stackoverflow.com/questions/16032982/getting-live-info-from-dev-input
import struct

infile_path = "/dev/input/js0"
EVENT_SIZE = struct.calcsize("llHHI")
file = open(infile_path, "rb")
event = file.read(EVENT_SIZE)
while event:
    print(struct.unpack("llHHI", event))
    (tv_sec, tv_usec, type, code, value) = struct.unpack("llHHI", event)
    event = file.read(EVENT_SIZE)




#%%


# https://core-electronics.com.au/guides/using-usb-and-bluetooth-controllers-with-python/

#import evdev
from evdev import InputDevice, categorize, ecodes

#creates object 'gamepad' to store the data
#you can call it whatever you like
gamepad = InputDevice("/dev/input/js0")

#prints out device info at start
print(gamepad)

#evdev takes care of polling the controller in a loop
for event in gamepad.read_loop():
    print(categorize(event))
# %%
