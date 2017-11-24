/**
 * SLAVE_MASTER_ARDUINOCODE
 *
 * Slave
 * salve.c
 *
 * @created 2017-11-24 10:34:52 
 * @version 0.01
 */

//TMP36 Pin Variables
#include <Wire.h>
int sensorPin = A0; //the analog pin the TMP36's Vout (sense) pin is connected to
                        //the resolution is 10 mV / degree centigrade with a
                        //500 mV offset to allow for negative temperatures
//PhotoResistor Pin
int lightPin = A1; //the analog pin the photoresistor is 
                  //connected to
                  //the photoresistor is not calibrated to any units so
                  //this is simply a raw sensor value (relative light)

/*
 * setup() - this function runs once when you turn your Arduino on
 * We initialize the serial connection with the computer
 */

void setup()
{
  Serial.begin(9600);  //Start the serial connection with the computer
                       //to view the result open the serial monitor 
  Wire.begin(); // join i2c bus (address optional for master)                     
}
 
void loop()                     // run over and over again
{
 //getting the voltage reading from the temperature sensor
 int reading = analogRead(sensorPin);  
 
 // converting that reading to voltage, for 3.3v arduino use 3.3
 float voltage = reading * 5;
 voltage /= 1024.0; 
 
 // now print out the temperature
 float temperatureC = (voltage - 0.5) * 100 ;  //converting from 10 mv per degree wit 500 mV offset
                                               //to degrees ((voltage - 500mV) times 100)
int lightLevel=analogRead(lightPin);

 Serial.print(temperatureC); Serial.println(" degrees C");
   
 Serial.print("Light "); Serial.println(lightLevel);  //write the value

 
  Wire.beginTransmission(8); // transmit to device #8
  Wire.write("temp ");        // sends five bytes
  Wire.write(byte(temperatureC));   // sends one byte
  Wire.write("light ");
  Wire.write(byte(lightLevel)); 
  Wire.endTransmission();    // stop transmitting


  
  delay(1000);
}


