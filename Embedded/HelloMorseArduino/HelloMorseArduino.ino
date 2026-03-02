/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKRlongBeep on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://docs.arduino.cc/hardware/

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  https://docs.arduino.cc/built-in-examples/basics/Blink/
*/

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);

}

int shortBeep = 200;
int longBeep = 800;
int shortRest = 500;
int longRest = 1000;


// the loop function runs over and over again forever
void loop() {

  // H
  digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(shortBeep);  
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW

  delay(shortRest); 

  digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(shortBeep);  
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW

  delay(shortRest);    

  digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(shortBeep);          
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW

  delay(shortRest);  

  digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(shortBeep);      
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
    

  // e
  delay(longRest);  

  digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(shortBeep);      
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
    
  delay(longRest);  


  // l
  digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(shortBeep);      
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
    
  delay(shortRest);  

  digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(longBeep);      
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
    
  delay(shortRest);  

  digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(shortBeep);      
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
    
  delay(shortRest);  

  digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(shortBeep);      
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
         
  delay(shortRest);  

  digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(shortBeep);  
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW


  delay(longRest); 


  // l
  digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(shortBeep);      
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
    
  delay(shortRest);  

  digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(longBeep);      
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
    
  delay(shortRest);  

  digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(shortBeep);      
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
    
  delay(shortRest);  

  digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(shortBeep);      
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
         
  delay(shortRest);  

  digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(shortBeep);  
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW


  delay(longRest); 


  // o
  digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(longBeep);      
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
    
  delay(shortRest);  

  digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(longBeep);      
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
    
  delay(shortRest);  

  digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(longBeep);      
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
}
