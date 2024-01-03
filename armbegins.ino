#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

int pos1 = 0;  //first motors position
int poten1;    // first potentiometer

int pos2 = 0;
int poten2;

int pos3 = 0;
int poten3;

int pos4 = 0;
int poten4;
void setup() {
  Serial.begin(9600);
  servo1.attach(9);

  servo2.attach(8);

  servo3.attach(7);

  servo4.attach(6);
}

void loop() {

  poten1 = analogRead(1);

  poten2 = analogRead(2);

  poten3 = analogRead(3);

  poten4 = analogRead(4);

  pos1 = map(poten1, 0, 1023, 0, 180);

  pos2 = map(poten2, 0, 1023, 0, 180);

  pos3 = map(poten3, 0, 1023, 0, 180);

  pos4 = map(poten4, 0, 1023, 0, 180);

  Serial.print("{1}");
   Serial.print(poten1);
   Serial.print("/");
    Serial.print(pos1);
  Serial.print("\t");

  Serial.print("{2}");
    Serial.print(poten2);
     Serial.print("/");
      Serial.print(pos2);
  Serial.print("\t");

  Serial.print("{3}");
    Serial.print(poten3);
      Serial.print("/");
        Serial.print(pos3);
  Serial.print("\t");

  Serial.print("{4}");
   Serial.print(poten4);
     Serial.print("/");
       Serial.print(pos4);
  Serial.println();


  servo1.write(pos1);
  servo2.write(pos2);
  servo3.write(pos3);
  servo4.write(pos4);

  delay(50);
}
