/*
Important: Makes sure hall sensor doesn't produce more than Arduino can support (5 volts)

The setup for the Hallsensor. Allowing the Arduino to recognize the hardware.
-The serial monitor BAUD rate is 115200, as noted in the setup.
- The 7 and 8 is the actual pin that is wired on the arduino.

*/

void hallSetup() {
  int hall_pin = 14;
  Serial.begin(115200);
  pinMode(hall_pin, INPUT);// make the hall pin an input
  //pinMode(7,OUTPUT);
  //pinMode(8, OUTPUT);
  //digitalWrite(7, LOW); // Initialize pin 7 as Low
  //digitalWrite(8, LOW); // Initialize pin 8 as Low
}