const int numRows=4;//define 4 rows
const int numCols=4;//define 4 lines
const int debounceTime=20;// debounce the time
const char keymap[numRows][numCols]={//the value of the keys
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
}
//This is the main loop.
void loop() {
char key=getkey();
if(key!=0){
  Serial.print("Got key");
  Serial.println(key);
}
}
char getkey(){
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
