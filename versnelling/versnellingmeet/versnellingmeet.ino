//Analog read pins
const int xPin = 0;
const int yPin = 1;
const int zPin = 2;

//Kalibrasiefaktore is verkry terwyl die 
//versnellingsmeter stil gehou word teenoor
//gravitasiekrag met elke as om die beurt.
int minVal = 265;
int maxVal = 402;

//to hold the caculated values
double x;
double y;
double z;

void setup(){
  Serial.begin(9600); 
}

void loop(){

  //lees die analoog waardes van die versnellingsmeters
  int xRead = analogRead(xPin);
  int yRead = analogRead(yPin);
  int zRead = analogRead(zPin);

  //convert read values to degrees -90 to 90 - Needed for atan2
  int xg = map(xRead, minVal, maxVal, -100, 100);
  int yg = map(yRead, minVal, maxVal, -100, 100);
  int zg = map(zRead, minVal, maxVal, -100, 100);

  x = xg;
  y = yg;
  z = zg;

  //Druk die resultate
  Serial.print("x: ");
  Serial.print(x);
  Serial.print(" | y: ");
  Serial.print(y);
  Serial.print(" | z: ");
  Serial.println(z);

  //Hou die uitlees stil vir 100 millisekondes
  delay(100);
}
