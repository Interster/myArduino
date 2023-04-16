# Lees die seriepoort van 'n Arduino
# Vul net die regte COM poort in en onthou om baud tempo reg te maak
# Die versnellingsmeter spoeg die resultate uit in seriepoort
# en hierdie program lees dit uit

# bron:
# https://stackoverflow.com/questions/16077912/python-serial-how-to-use-the-read-or-readline-function-to-read-more-than-1-char

import serial
ser = serial.Serial("COM12", 9600)
while True:
     cc=str(ser.readline())
     print(cc[2:][:-5])

     # Skryf 'n roetine wat die versnellings in 'n buffer stoor en dit elke nou en dan 
     # na hardeskyf uitskryf.