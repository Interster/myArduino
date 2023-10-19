#%%
# From:  
# https://wiki.python.org/moin/UdpCommunication


#%%

import socket

UDP_IP = "192.168.9.172"
UDP_PORT = 2390 # Poort van Arduino kode
MESSAGE = b"Hello world"

print("UDP target IP: %s" % UDP_IP)
print("UDP target port: %s" % UDP_PORT)
print("message: %s" % MESSAGE)

sock = socket.socket(socket.AF_INET, # Internet
                     socket.SOCK_DGRAM) # UDP
sock.sendto(MESSAGE, (UDP_IP, UDP_PORT))


#%%

MESSAGE = b"w"
sock.sendto(MESSAGE, (UDP_IP, UDP_PORT))


# Skryf nog gedeelte wat UDP pakket ontvang van die Arduino
# sodat die versnellings gelog kan word.
# %%
