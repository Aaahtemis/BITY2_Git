#include <Arduino.h>
#include <IRremote.hpp> // include the ir remote library

//#include <stdint.h>
uint8_t lastSignal;
volatile uint8_t currentSignal;
uint8_t IR_INTERRUPT = 0;
#define IR_INPUT_PIN  A0 // To be compatible with interrupt example, pin 2 is chosen here.

void setup() {
  IrReceiver.enableIRIn();
  Serial.begin(115200);
  attachInterrupt(digitalPinToInterrupt(IR_INTERRUPT), signalRecieved, CHANGE);
  pinMode(LED_BUILTIN, OUTPUT);
  IrReceiver.begin(IR_INPUT_PIN, DISABLE_LED_FEEDBACK); // Start the receiver
}

void loop() {
  // put your main code here, to run repeatedly:
  if (IrReceiver.decode()) {
      Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX); // Print "old" raw data
      IrReceiver.printIRResultShort(&Serial); // Print complete received data in one line
      IrReceiver.resume(); // Enable receiving of the next value
  }
}

void signalRecieved(){
    IrReceiver.printIRResultMinimal(currentSignal);
    Serial.println("Signal Recieved");

}