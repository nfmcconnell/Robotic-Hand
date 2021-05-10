#define ledPin 2

int f[4];
String Servo_val;
const float VCC = 4.98;

//Flex Sensor 0//
const int flexPin0 = A0;
const float R_DIV = 9700;
const float STRAIGHT_RES = 12400; 
const float BEND_RES = 25500;

//Flex Sensor 1//
const int flexPin1 = A1;
const float R_DIV_1 = 9700;

//Flex Sensor 2//
const int flexPin2 = A2;
const float R_DIV_2 = 9700;

//Flex Sensor 3//
const int flexPin3 = A3;
const float R_DIV_3 = 9700;

//Flex Sensor 4//
const int flexPin4 = A4;
const float R_DIV_4 = 9700;

//42800 for short flex & 12400 for long flex
//85000 for short flex & 25500 for long flex    
const float SHORT_STRAIGHT_RES = 42800;
const float SHORT_BEND_RES = 85000;

int state = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  pinMode(flexPin0, INPUT);
  pinMode(flexPin1, INPUT);
  pinMode(flexPin2, INPUT);
  pinMode(flexPin3, INPUT);
  pinMode(flexPin4, INPUT);
  Serial.begin(38400); //Baud rate of Nano
}

void loop() {
  if (Serial.available() > 0) {
    state = Serial.read(); //Reads the data from the Serial Port
  }

  //Controlling the LED
  if (state == '1') {
    digitalWrite(ledPin, HIGH); //LED ON
    state = 0;
  }
  else if (state == '0') {
    digitalWrite(ledPin, LOW); //LED OFF
    state = 0;
  }

  //Reading the Flex Sensors
  int flex0ADC = analogRead(flexPin0);
  int flex1ADC = analogRead(flexPin1);
  int flex2ADC = analogRead(flexPin2);
  int flex3ADC = analogRead(flexPin3);
  int flex4ADC = analogRead(flexPin4);
  
  // Filter the ADC Values
  flex0ADC = flex0ADC * 0.9 + float(analogRead(flexPin0)) * 0.1;
  flex1ADC = flex1ADC * 0.9 + float(analogRead(flexPin1)) * 0.1;
  flex2ADC = flex2ADC * 0.9 + float(analogRead(flexPin2)) * 0.1;
  flex3ADC = flex3ADC * 0.9 + float(analogRead(flexPin3)) * 0.1;
  flex4ADC = flex4ADC * 0.9 + float(analogRead(flexPin4)) * 0.1;

  // Convert to Voltage
  float flex0V = flex0ADC * VCC / 1023.0;
  float flex1V = flex1ADC * VCC / 1023.0;
  float flex2V = flex2ADC * VCC / 1023.0;
  float flex3V = flex3ADC * VCC / 1023.0;
  float flex4V = flex4ADC * VCC / 1023.0;

  // Voltage Divider to determine Resistance
  float flex0R = (R_DIV * flex0V) / (VCC - flex0V);
  float flex1R = (R_DIV * flex1V) / (VCC - flex1V);
  float flex2R = (R_DIV * flex2V) / (VCC - flex2V);
  float flex3R = (R_DIV * flex3V) / (VCC - flex3V);
  float flex4R = (R_DIV * flex4V) / (VCC - flex4V);

  // Map the resistance to servo values
  f[0] = map(flex0R, SHORT_STRAIGHT_RES, SHORT_BEND_RES, 0, 180.0);
  f[1] = map(flex1R, STRAIGHT_RES, BEND_RES, 0, 180.0);
  f[2] = map(flex2R, STRAIGHT_RES, BEND_RES, 0, 180.0);
  f[3] = map(flex3R, STRAIGHT_RES, BEND_RES, 0, 180.0);
  f[4] = map(flex4R, STRAIGHT_RES, BEND_RES, 0, 180.0);

  f[0] = constrain(f[0], 0, 180.0);
  f[1] = constrain(f[1], 0, 180.0);
  f[2] = constrain(f[2], 0, 180.0);
  f[3] = constrain(f[3], 0, 180.0);
  f[4] = constrain(f[4], 0, 180.0);

  // Create strings to send to Uno
  String a = "a,"; //Servo 1
  String b = "b,"; //Servo 2
  String c = "c,"; //Servo 3
  String d = "d,"; //Servo 4
  String e = "e,"; //Servo 5

  // The serial communication can not send multiple variables, instead send a string and then parse the string in the uno
  // Combine the strings
  Servo_val =f[0] + a + f[1] + b + f[2] + c + f[3] + d + f[4] + e;
  //Convert to char array
  char carray[24];
  Servo_val.toCharArray(carray, sizeof(carray));

  Serial.println(carray);
  Serial.write(carray, sizeof(carray));
  delay(100);
}
