/*

This right here is the function that prints information like rpm and time passed.
Using this function for values until I make an array where we can store and analyze a lot more information.

associated variables:
bool on_state = false;
float hall_count = 1.0;
float start = micros();
float end_time = micros();
float time_passed = ((end_time - start) / 1000000.0);
float rpm_val = (hall_count / time_passed) * 60.0;

*/


void printValues() {
  Serial.begin(115200);
  bool on_state = false;
  float hall_count = 1.0;
  float start = micros();
  float end_time = micros();
  float time_passed = ((end_time - start) / 1000000.0);
  float rpm_val = (hall_count / time_passed) * 60.0;
  Serial.print("Time Passed: ");
  Serial.print(time_passed);
  Serial.println("s");
  Serial.print(rpm_val);
  Serial.println(" RPM");
  delay(10); //delay in between reads for stability
}