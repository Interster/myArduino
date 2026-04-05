/***************************************************
* Liquid Level Sensor-XKC-Y25-T12V
* ****************************************************
* This example is to get liquid level

* @author jackli(Jack.li@dfrobot.com)
* @version  V1.0
* @date  2016-1-30

* GNU Lesser General Public License.
* See  for details.
* All above must be included in any redistribution
* ****************************************************/
int Liquid_level_top=0;
int Liquid_level_bottom=0;

void setup() {
 Serial.begin(9600);
 pinMode(5,INPUT); // Vloeistofvlak bolimiet
 pinMode(6,INPUT); // Vloeistofvlak onderlimiet
}

void loop() {
Liquid_level_top=digitalRead(5);
Liquid_level_bottom=digitalRead(5);
Serial.print("Bo limiet= ");
Serial.print(Liquid_level_top,DEC);
Serial.print(" Onder limiet= ");
Serial.println(Liquid_level_bottom,DEC);

delay(500);
}