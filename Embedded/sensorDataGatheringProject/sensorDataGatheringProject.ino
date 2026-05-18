#include <Arduino.h>
#include <IRremote.hpp>       // include the ir remote library
#include "sensorVariables.h"  //include local variables for this specific remote

//#include <stdint.h>
volatile String hexSignal;
volatile IRDecodedRawDataType rawSignal;

volatile bool canSignal = true;

uint8_t IR_INTERRUPT = 2;
byte IR_INPUT_PIN = A0;

void setup() {
  IrReceiver.enableIRIn();
  attachInterrupt(digitalPinToInterrupt(IR_INTERRUPT), signalRecieved, CHANGE);
  pinMode(LED_BUILTIN, OUTPUT);
  IrReceiver.begin(IR_INPUT_PIN, DISABLE_LED_FEEDBACK);  // Start the receiver
}

void loop() {
  // put a timer to reduce number of ir inputs recieved.
  if (!canSignal) {

    delay(500);
    IrReceiver.resume();  // Enable receiving of the next value
    canSignal = true;
  }
}

void signalRecieved() {
  Serial.begin(9600);

  if (IrReceiver.decode() && canSignal) {
    canSignal = false;
    auto tDecodedRawData = IrReceiver.decodedIRData.decodedRawData;
    if (IrReceiver.decodedIRData.decodedRawData != 0 && IrReceiver.decodedIRData.decodedRawData != rawSignal) {
      rawSignal = IrReceiver.decodedIRData.decodedRawData;
      hexSignal = String(rawSignal, HEX);
    }
    if (hexSignal == channelUp) {
      Serial.println("Channel Up");
    } else if (hexSignal == channel) {
      Serial.println("Channel Selection");
    } else if (hexSignal == channelDown) {
      Serial.println("Channel Down");
    } else if (hexSignal == previous) {
      Serial.println("Previous");
    } else if (hexSignal == next) {
      Serial.println("Next");
    } else if (hexSignal == playPause) {
      Serial.println("Play / Pause");
    } else if (hexSignal == volumeDown) {
      Serial.println("Volume Down");
    } else if (hexSignal == volumeUp) {
      Serial.println("Volume Up");
    } else if (hexSignal == equalizer) {
      Serial.println("Equalizer Settings");
    } else if (hexSignal == incr100) {
      Serial.println("100+");
    } else if (hexSignal == incr200) {
      Serial.println("200+");
    } else if (hexSignal == num0) {
      Serial.println("0");
    } else if (hexSignal == num1) {
      Serial.println("1");
    } else if (hexSignal == num2) {
      Serial.println("2");
    } else if (hexSignal == num3) {
      Serial.println("3");
    } else if (hexSignal == num4) {
      Serial.println("4");
    } else if (hexSignal == num5) {
      Serial.println("5");
    } else if (hexSignal == num6) {
      Serial.println("6");
    } else if (hexSignal == num7) {
      Serial.println("7");
    } else if (hexSignal == num8) {
      Serial.println("8");
    } else if (hexSignal == num9) {
      Serial.println("9");
    }
  }
  Serial.end();
}
