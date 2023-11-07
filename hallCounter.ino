/*

The counting for the Hallsensor
Counts number of times the hall sensor is tripped. This is used to assess rpm's. 
Set number of hall trips for RPM reading (higher improves accuracy).

----Watch out for the double counting of rpms.

*/

void hallCounter() {
  bool on_state = false;
  int hall_pin = 14;
  float hall_count = 1.0;
  float hall_thresh = 10.0;
  while (true) {
    if (digitalRead(hall_pin) == 0) {
    if (on_state == false) {
      on_state = true;
      hall_count += 1.0;
    }
    } else {
      on_state = false;
      }
    if (hall_count >= hall_thresh) {
      break;
   }
  }
}