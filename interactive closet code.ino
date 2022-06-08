// Copyright Arthur (Qianyi) Zhao Australian National University u7423357
// This is the code for the closet part of the interactive system.
#include <Servo.h> // Call the built-in library for servo control.
Servo myservo; // Name the servo as "myservo".
// Constants won't change. They're used here to set pin numbers:
const int buttonPin1 = 13;     // the number of the pushbutton pin1
const int servoPin =  12;      // the number of the servo pin
const int buttonPin2 =  11;    // the number of the pushbutton pin2
const int fanPin = 10;         // the number of the fan pin

// variables will change:
int buttonState1 = 0;         // variable for reading the pushbutton status
int buttonState2 = 0; 
void setup() {
  // initialize the pushbutton pin as inputs:
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  // initialize the fan pin as output:
  pinMode(fanPin, OUTPUT);
  myservo.attach(12); // attach servo signal pin to 12 on the arduino board.
}

// The main loop.
void loop() {
  // read the state of the pushbutton value, and store them in variables:
  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);
  // check if the pushbutton is pressed. If it is, the buttonState turns into HIGH
  // If button 1 is pressed, which means "dislike", the servo shakes and drop the clothes into the bin.
  if (buttonState1 == HIGH) {
    myservo.write(60);
    delay(1000);
  } else {
    // Do nothing.
    myservo.write(180);
  }
  // If button 2 is pressed, which means "like", the fan starts to spin.
    digitalWrite(fanPin,HIGH);
    delay(5000);
  } else {
    // Do nothing.
    digitalWrite(fanPin,LOW);
  }
}
