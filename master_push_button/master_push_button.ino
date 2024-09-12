// Include the required Wire library for I2C<br>#include 
#include <Wire.h>
int btnpin = 4;
int a = 0;
void setup() {
  // Start the I2C Bus as Master
  //Wire.begin(); 
  Serial.begin(9600);
  pinMode(btnpin, INPUT);
}
void loop() {
  //Wire.beginTransmission(0x55); // transmit to device #0x55
  a=digitalRead(btnpin);
  Serial.println(a);
  //Wire.write(a);              // sends x 
  //Wire.endTransmission();    // stop transmitting
  delay(10);
}
