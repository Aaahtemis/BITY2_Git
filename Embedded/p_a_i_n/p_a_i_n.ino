const byte LED = 8;
const byte SWITCH = 2;
volatile bool onOff = false;

void setup() {
  pinMode ( LED, OUTPUT); 
  pinMode (SWITCH, INPUT_PULLUP);
  attachInterrupt (digitalPinToInterrupt (SWITCH), switchPressed, CHANGE);
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
 //notin
  digitalWrite(LED, onOff ? HIGH : FALSE);
}

void switchPressed (){
  onOff = !onOff;
}