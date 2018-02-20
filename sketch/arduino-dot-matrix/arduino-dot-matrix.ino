/* include the dot-matrix library */
#include "LedControl.h"

/* 
 * Now we create a new LedControl. 
 * We use pins 12,11 and 10 on the Arduino for the SPI interface
 * Pin 12 is connected to the DATA IN-pin of the first MAX7221
 * Pin 11 is connected to the CLK-pin of the first MAX7221
 * Pin 10 is connected to the LOAD(/CS)-pin of the first MAX7221   
 * There will only be a single MAX7221 attached to the arduino in this example
*/
LedControl DotMatrix = LedControl(12,11,10,1);


void setup() {
  // put your setup code here, to run once:
  //wake up the MAX72XX from power-saving mode 
  DotMatrix.shutdown(0,false);
  //set a medium brightness for the Leds
  DotMatrix.setIntensity(0,15); // setIntensity(int addr, int intensity) --> intensity is 0..15
}

void loop() {
  //switch on the led in the 3'rd row 8'th column
  //and remember that indices start at 0! 

  // LEFT EYE

  DotMatrix.setLed(0,7,1,true);
  DotMatrix.setLed(0,7,2,true);
  DotMatrix.setLed(0,7,3,true);
  DotMatrix.setLed(0,6,1,true);
  DotMatrix.setLed(0,6,3,true);
  DotMatrix.setLed(0,5,1,true);
  DotMatrix.setLed(0,5,2,true);
  DotMatrix.setLed(0,5,3,true);

  // RIGHT EYE
  DotMatrix.setLed(0,2,1,true);
  DotMatrix.setLed(0,2,2,true);
  DotMatrix.setLed(0,2,3,true);
  DotMatrix.setLed(0,1,1,true);
  DotMatrix.setLed(0,1,3,true);
  DotMatrix.setLed(0,0,1,true);
  DotMatrix.setLed(0,0,2,true);
  DotMatrix.setLed(0,0,3,true);
  
  
  DotMatrix.setLed(0,1,6,true);
  DotMatrix.setLed(0,2,7,true);
  DotMatrix.setLed(0,3,7,true);
  DotMatrix.setLed(0,4,7,true);
  DotMatrix.setLed(0,5,7,true);
  DotMatrix.setLed(0,6,6,true);
  
  delay(500);
  //switch the first Led off (second one stays on)
  DotMatrix.setLed(0,2,7,false);
}
