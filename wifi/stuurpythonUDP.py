# https://wiki.python.org/moin/UdpCommunication

import socket


UDP_IP = "192.168.8.60"
UDP_PORT = 2390
MESSAGE = b"Hello, World!"
MESSAGE = b"Praat met PS3"

print("UDP target IP: %s" % UDP_IP)
print("UDP target port: %s" % UDP_PORT)
print("message: %s" % MESSAGE)
 
sock = socket.socket(socket.AF_INET, # Internet
                      socket.SOCK_DGRAM) # UDP
sock.sendto(MESSAGE, (UDP_IP, UDP_PORT))
