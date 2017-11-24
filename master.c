/**
 * SLAVE_RECEIVER_CODE
 *
 * Master (RECEIVER)
 * master.c
 * 
 * @created 2017-11-24 10:34:52 
 * @version 0.01
 */


#include <Wire.h>

int ledPin[] = {10,11};

int temperatureC = Wire.read() ;

void setup() {
  Wire.begin(8);                // join i2c bus with address #8
  Wire.onReceive(receiveEvent); // register event
  Serial.begin(9600);           // start serial for output
  for (int i=0; i<2; i++){
        pinMode(ledPin[i], OUTPUT);
  }
}

/*
*/
void loop() {
  delay(100);

if ( 23.5 <= temperatureC <= 23.75 ) {
  digitalWrite(ledPin[0], HIGH); 
  }
else if ( temperatureC <= 23 || temperatureC >= 24 ) {
  digitalWrite(ledPin[0], LOW);
  digitalWrite(ledPin[1], HIGH); 
  }  
}

/*
*/
void receiveEvent(int howMany) {
  while (1 < Wire.available()) { // loop through all but the last
    char c = Wire.read(); // receive byte as a character
    Serial.print(c);         // print the character
  }
  int temperatureC = Wire.read();    // receive byte as an integer
  Serial.println(temperatureC);         // print the integer

  int lightLevel = Wire.read();    // receive byte as an integer
  Serial.println(lightLevel);         // print the integer
}
