#include <LiquidCrystal.h>

String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete
String commandString = "";
const int ledPin =  6; 


boolean isConnected = false;




void setup() {
  
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {

if(stringComplete)
{
  stringComplete = false;
  getCommand();

  
  
  if(commandString.equals("STAR"))
  {
    digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
                          // wait for a second
    Serial.write("GotSTAR!\n");
  }
  
  else if(commandString.equals("TEXT"))
  {
    digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
    Serial.write("GotTEXT\n");
      
  }

  else if(commandString.equals("LED1"))
  {
    digitalWrite( ledPin , HIGH );    // turn the LED on by making the voltage LOW
    Serial.write("GotLED\n");
      
  }
     
  inputString = "";
  
}

}


void getCommand()
{
  if(inputString.length()>0)
  {
     commandString = inputString.substring(1,5);
  }
}




void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    if (inChar == '\n') {
      stringComplete = true;
      
    }
  }
}
