# Motor oordragfunksie uit toets

Bepaal die motor oordragfunksie vir beheerstelsel deur te toets.

Gebruik volgende artikel as riglyn:

https://ctms.engin.umich.edu/CTMS/index.php?example=MotorSpeed&section=SystemModeling

Hierdie is eenvoudiger en gebruik dit dalk eerder:

https://medium.com/@caglayanserbtci/estimate-any-dc-motor-transfer-function-2a67e3d67b20



## Hall effek sensor

Gebruik 'n Hall-effek sensor om die die rotasie teen tyd data in te win:

https://www.robotics.org.za/KY-024?search=hall%20effect

Hier is die bedrading vir die Hall effek sensor:



![1_HallEffekSensorBedrading](Prente\1_HallEffekSensorBedrading.jpg)

Gebruik die skets:  HallEffek.ino

## Hall Effek toetsopstelling

Maak toetsopstelling op 2024-02-13.

Die digitale sein is raserig, soveel so dat dit die aantal kere aan en af sal verkeerd tel.  As die sensor op 'n sekere manier neergesit word, werk dit reg, maar dis moeilik herhaalbaar.  Moet dalk 'n twisted pair vir die kragdrade maak.  Hulle het moontlik 'n magneetveld wat die sensor optel.  Die lang drade in die lug is eintlik 'n bron van elektriese velde en magneetvelde.

![2_HallEffekOpstelling](Prente\2_HallEffekOpstelling.png)



![3_AanAf](Prente\3_AanAf.png)