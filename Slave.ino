#include <Servo.h>
#define button 8

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;

int f[4];
String readString, Servo_val, servo1_val, servo2_val;
int state = 20;
int buttonState = 0;

void setup() {
  pinMode(button, INPUT);
  servo1.attach(3);
  servo2.attach(10);
  servo3.attach(11);
  servo4.attach(6);
  servo5.attach(5);
  Serial.begin(38400); //Baud rate of Uno
}
// In this loop you are reading the incoming string and parsing the characters and reading the value after the associated char
void loop() {
  if (Serial.available() > 0) {
    char c = Serial.read();
    //Serial.print(c);
    if (c == ',') {
      if (readString.length() > 1) {

        Serial.println(readString);

        int n = readString.toInt(); //convert readString into a number
        Serial.print("writing Angle: ");
        Serial.println(n);
        if (readString.indexOf('a') >0) servo1.write(n);
        if (readString.indexOf('b') >0) servo2.write(n);
        if (readString.indexOf('c') >0) servo3.write(n);
        if (readString.indexOf('d') >0) servo4.write(n);
        if (readString.indexOf('e') >0) servo5.write(n);
        
        readString = ""; //clears variable for new input
      }
    }
    else {
      readString += c; //make readString
    }
    //Servo_val = Serial.read(); //Reads data from Serial Port
    //Serial.println(Servo_val);
    servo1_val = Servo_val.substring(0, 8); //get the first 8 digits
    servo2_val = Servo_val.substring(8, 16); //get the last 8 digits
  }
  
  //Reading the button
  buttonState = digitalRead(button);
  if (buttonState = HIGH) {
    Serial.write('1'); //Sends '1' to the master to turn on LED
  }
  else {
    Serial.write('0');
  }
}
