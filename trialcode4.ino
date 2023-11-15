/*

When Using Program Note:
- initialize serial communication at 115200 BAUD. This is in the hallSetup function.
- setup is a once through. the loop is continuously called.
  l> simply call functions that are needed using the format functionName(); ie. hallSetup();

On hardware: Analog pin A0 is the hall pin, On the Uno the value of the A0 variable is 14

*/


void setup() {
  hallSetup();
  valuesSetup();

}

void loop() {
  hallCounter();
  printValues();
}

