**Phong Trinh - 07/06/2020***
int const redPin = 2; 
int const yellowPin = 3; 
int const greenPin = 4;
int const  bluePin = 12;
int countCycle = 0;
unsigned long timeStamp;
int const switchPin = 11;
int switchState = 0;
int nextCycle = 0;

void setup()
{
  pinMode(redPin,OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(switchPin, INPUT);
  Serial.begin(9600);
}

void loop(){
// check button
if(digitalRead(switchPin) == HIGH ) {
switchState = 1;
Serial.println("Switch pressed"); }
// Light cycle
timeStamp = millis() - countCycle * 6000;
if (timeStamp < 2000) {
digitalWrite(yellowPin, LOW);
digitalWrite(redPin, HIGH);
//turn on blue if button's pressed
    if (nextCycle == 1) {
    digitalWrite(bluePin, HIGH);
    delay(2000);
    digitalWrite(bluePin, LOW);
    nextCycle = 0;}
} 
else if (timeStamp >= 2000&& timeStamp < 4000){
digitalWrite(redPin, LOW);
digitalWrite(greenPin, HIGH);}
else if (timeStamp >= 4000&& timeStamp < 6000) {
digitalWrite(greenPin, LOW);
digitalWrite(yellowPin, HIGH);}
else {
  countCycle = countCycle + 1;
  if (switchState == 1){
    nextCycle = 1;
    switchState = 0;}
}
  

}
