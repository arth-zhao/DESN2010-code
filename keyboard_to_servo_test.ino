#include <Servo.h>
Servo myservo;
const int numRows=4;//define 4 rows
const int numCols=4;//define 4 lines
const int debounceTime=20;// debounce the time
const char keymap[numRows][numCols]={//the value of the keys,
  //with the same order on the keyboard.
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
const int rowPins[numRows]={11,10,9,8};
const int colPins[numCols]={7,6,5,4};//set up the pins
void setup() { //set up for the main loop
Serial.begin(9600);
for (int row=0;row<numRows;row++){
  pinMode(rowPins[row],INPUT);
  digitalWrite(rowPins[row],HIGH);
}
for (int column=0;column<numCols;column++){
  pinMode(colPins[column],OUTPUT);
  digitalWrite(colPins[column],HIGH);
}
myservo.attach(3);  //connect the servo signal pin to pin3 on arduino
}
//This is the main loop.
void loop() {
char key=getkey();
if(key==0){  //If there is no input (default condition)
  myservo.write(90);
}
if(key=='1'){ //If the keyboard receives 1,shake at speed 1
  myservo.write(90);
  delay(100);
  myservo.write(85);
  delay(100);
  myservo.write(90);
  delay(100);
  myservo.write(85);
  delay(100);
  myservo.write(90);
  delay(100);
  myservo.write(85);
  delay(100);
}
if(key=='2'){ //If the keyboard receives 2,shake at speed 2
  myservo.write(90);
  delay(100);
  myservo.write(50);
  delay(100);
  myservo.write(90);
  delay(100);
  myservo.write(50);
  delay(100);
  myservo.write(90);
  delay(100);
  myservo.write(50);
  delay(100);
}
if(key=='3'){ //If the keyboard receives 3,shake at speed 3
  myservo.write(90);
  delay(100);
  myservo.write(30);
  delay(100);
  myservo.write(90);
  delay(100);
  myservo.write(30);
  delay(100);
  myservo.write(90);
  delay(100);
  myservo.write(30);
  delay(100);
}
if(key=='4'){  //If the keyboard receives 4,shake at speed 4
  myservo.write(90);
  delay(100);
  myservo.write(15);
  delay(100);
  myservo.write(90);
  delay(100);
  myservo.write(15);
  delay(100);
  myservo.write(90);
  delay(100);
  myservo.write(15);
  delay(100);
}
if(key=='5'){  //If the keyboard receives 5,shake at speed 5
  myservo.write(90);
  delay(100);
  myservo.write(0);
  delay(100);
  myservo.write(90);
  delay(100);
  myservo.write(0);
  delay(100);
  myservo.write(90);
  delay(100);
  myservo.write(0);
  delay(100);
}
}
char getkey(){ //switch the key pressed to a character variable "getKey"
  char key=0;
  for (int column=0;column<numCols;column++){
    digitalWrite(colPins[column],LOW);
    for (int row=0;row<numRows;row++){
      if(digitalRead(rowPins[row])==LOW){
        delay(debounceTime);
        while(digitalRead(rowPins[row])==LOW);
        key=keymap[row][column];
      }
    }
    digitalWrite(colPins[column],HIGH);//Deactive the current column
  }
  return key;
}
