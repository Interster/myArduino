import socket
import struct

s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
# s.connect(("localhost", 1234))
s.connect(("172.16.16.139", 2390))

while True:
    x, y, z = (float(s) for s in input('Enter x, y, z: ').split())
    packed = struct.pack('fff', x, y, z)
    s.send(packed)
    # c = input()
    # s.send(c.encode())
