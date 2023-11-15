/*
This is demo program calculating time and rpm with interupts and unassigned longs.

source: jefvr
https://forum.arduino.cc/t/rpm-counter/695457/48
*/

const byte potPin = 14;
//================
int potVal;
//int pwmVal;
//================
unsigned long revMicros;
unsigned long prevrevMicros;
unsigned long revDuration;
unsigned long revCount;
//================
unsigned long prevdisplayMillis;
unsigned long  displayInterval = 1000;
//================
// variables for the ISR
volatile unsigned long isrMicros;
volatile unsigned long isrCount;
volatile bool newisrMicros = false;
//================
unsigned int RPM = 60000000ul / revDuration;
int hall_pin = 14;
//================

void valuesSetup(){
  partialvalueSetup();
  revDetectorISR();
}

void partialvalueSetup() {
  pinMode(hall_pin,INPUT);
  Serial.begin(115200);
  Serial.println("ISRdemotest.ino");
  pinMode(hall_pin,INPUT);
  isrCount = 0;
  attachInterrupt(0, revDetectorISR, RISING);
}

void revDetectorISR() {
  isrMicros = micros();
  isrCount ++;
  newisrMicros = true;
}

void printValues() {
  Serial.begin(115200);
  if (newisrMicros == true) {
    prevrevMicros = revMicros; // save the previous value
    noInterrupts();
    revMicros = isrMicros;
    revCount = isrCount;
    newisrMicros = false;
    interrupts();
    revDuration = revMicros - prevrevMicros;
  }
  if (millis() - prevdisplayMillis >= displayInterval) {
    prevdisplayMillis += displayInterval;
    showData();
    potVal = analogRead(potPin);
  }
}

void showData() {
  Serial.println();
  Serial.println("===============");
//Serial.print("PWM Val "); 
//Serial.println(pwmVal);
  Serial.println();
  Serial.print("  Rev Duration ");
  Serial.print(revDuration);
  Serial.print("  Rev Count "); 
  Serial.print(revCount);
  Serial.println();
  Serial.print(" RPM ");
  Serial.print(RPM);
}
