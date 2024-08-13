# https://wiki.python.org/moin/UdpCommunication


#%%
import socket


UDP_IP = "192.168.9.172"
UDP_PORT = 2390
MESSAGE = b"Hello, World!"
MESSAGE = b"Praat met PS3"

print("UDP target IP: %s" % UDP_IP)
print("UDP target port: %s" % UDP_PORT)
print("message: %s" % MESSAGE)
 
sock = socket.socket(socket.AF_INET, # Internet
                      socket.SOCK_DGRAM) # UDP
sock.sendto(MESSAGE, (UDP_IP, UDP_PORT))
#%%

# Wag vir boodskap terug:  Werk nog nie.  Moet die socket se terug poort nog implementeer
sock.bind((UDP_IP, UDP_PORT))
 
while True:
    data, addr = sock.recvfrom(1024) # buffer size is 1024 bytes
    print("received message: %s" % data)

# %%
