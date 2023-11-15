/*

This functiion serves as the bstopCheck. This is the part that controls the feathering under "too windy conditions". 
- Anytime you see digitalWrite this means you are moving the actuator in or out in the program this is HIGH or LOW.

What is needed:
- Emergency stop via push button. Signal to plc then to linear actuator
- Emergency stop button takes precedence.


Note:
l>rpmLimits uses the demo printValues(); function
l>rpmvalLimits uses the oldprintVal(); function


This functiion serves as the bstopCheck. This is the part that controls the feathering under "too windy conditions". 
- Anytime you see digitalWrite this means you are moving the actuator in or out in the program this is HIGH or LOW.

What is needed:
- Emergency stop via push button. Signal to plc then to linear actuator
- Emergency stop button takes precedence.

*/

void bstopCheck() {
  bool BSTOP = false;
  const int buttonPin = 2;
  int buttonState = 0;
  bool is_at_max = false;
  bool is_at_min = true ;
  bool on_state = false;
  float hall_count = 1.0;
  float start = micros();
  float end_time = micros();
  float time_passed = ((end_time - start) / 1000000.0);
  float rpm_val = (hall_count / time_passed) * 60.0;
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH) {
    Serial.print("#");//edit to create an estop if button is pressed.
    BSTOP = true;
    delay(1);
  }

  if (BSTOP == false && rpm_val < 500) {
    /* Above 500 will be the edited value. This the rpm value when the blades will be slowed down due to "too windy conditions"*/
    /*This here HIGH and LOW controls the feathering via linear actuator. A HIGH and LOW may need to be swapped depending on how it is wired*/
    digitalWrite(8, HIGH);
    digitalWrite(7, LOW);
    is_at_min = true;
    if (!is_at_min){
      delay(6800); // 2 seconds
      is_at_min = false;
    }
    //Stop Actuator
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    delay(10000); //maybe modify times, it always ends state stopped then checks
  }
  else if (BSTOP == false && rpm_val > 500) { //rpm val adjust to optimize
    is_at_max = false;
    // Retracts Linear Actuator
    digitalWrite(8, LOW); //change low and high in order to switch directions
    digitalWrite(7, HIGH);
    if (!is_at_max){
      delay(6800); // 2 seconds
      is_at_max = true;
    }
    // Stop Actuator
    digitalWrite(7,LOW);
    digitalWrite(8,LOW);
    delay(2000); // 2 seconds
  }
}