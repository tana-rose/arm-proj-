#include <Servo.h>

Servo servo1;  //base
Servo servo2;  //bicep

int base = 0;  //base motors position
int potenbs;   // base's potentiometer

int bicep = 0;  // ditto but for bicep
int potenbi;    // you should get the jist by now

#define startup 5500;
#define delayval 50;

void setup() {

  Serial.begin(9600);
  servo1.attach(8);
  servo2.attach(9);

  servo1.write(90);
  servo2.write(180);

  delay(startup);

}
void loop() {

  //base starts at 90
  //bicep starts at 180

  potenbs = analogRead(1);
  potenbi = analogRead(2);

  base = map(potenbs, 0, 1023, 0, 180);
  bicep = map(potenbi, 0, 1023, 0, 180);


  Serial.print(potenbs);
  Serial.print("/");
  Serial.print(base);
  Serial.print("\t");
  Serial.print(potenbi);
  Serial.print("/");
  Serial.print(bicep);
  Serial.println();

  delay(delayval);

  servo1.write(base);
  servo2.write(bicep);
}
