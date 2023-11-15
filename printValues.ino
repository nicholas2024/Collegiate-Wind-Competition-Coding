/*
This is demo program calculating time and rpm with interupts and unassigned longs.

source: jefvr
https://forum.arduino.cc/t/rpm-counter/695457/48

Unsigned long is an integer

checking format
then changing it into a double or float
currently using "unsigned int"
*/

void valuesSetup(){
  partialvalueSetup();
  revDetectorISR();
}

void partialvalueSetup() {
  volatile unsigned long isrCount;
  int hall_pin = 14;
  pinMode(hall_pin,INPUT);
  Serial.begin(115200);
  Serial.println("ISRdemotest.ino");
  pinMode(hall_pin,INPUT);
  isrCount = 0;
  attachInterrupt(0, revDetectorISR, RISING);
}

void revDetectorISR() {
// variables for the ISR
volatile unsigned long isrMicros;
volatile unsigned long isrCount;
volatile bool newisrMicros = false;
  isrMicros = micros();
  isrCount ++;
  newisrMicros = true;
}

void printValues() {
const byte potPin = 14;
int potVal;
//int pwmVal;
unsigned long revMicros;
unsigned long prevrevMicros;
unsigned long revDuration;
unsigned long revCount;
unsigned long prevdisplayMillis;
unsigned long  displayInterval = 1000;
// variables for the ISR
volatile unsigned long isrMicros;
volatile unsigned long isrCount;
volatile bool newisrMicros = false;
unsigned int RPM = 60000000ul / revDuration;
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
  unsigned long revDuration;
  unsigned long revCount;
  unsigned int RPM = 60000000ul / revDuration;
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
