
#include <Servo.h>
Servo myservo;
// constants won't change. They're used here to set pin numbers:
const int buttonPin1 = 13;     // the number of the pushbutton pin
const int servoPin =  12;      // the number of the LED pin
const int buttonPin2 =  11;
const int fanPin = 10;

// variables will change:
int buttonState1 = 0;         // variable for reading the pushbutton status
int buttonState2 = 0; 
void setup() {
  // initialize the LED pin as an output:
  //pinMode(servoPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(fanPin, OUTPUT);
  myservo.attach(12);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState1 == HIGH) {
    myservo.write(60);
    delay(1000);
  } else {
    // turn LED off:
    myservo.write(180);
  }
  if (buttonState2 == HIGH) {
    digitalWrite(fanPin,HIGH);
    delay(10000);
  } else {
    // turn LED off:
    digitalWrite(fanPin,LOW);
  }
}
