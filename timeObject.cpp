/*~~@@@@ timeObject.cpp @@@@~~




   Library to convert times between millis()
   & times converted from starting values.


   outputs that count up & down.

   Returns: Micros, Millis, Seconds, Minutes, Hours, Days, Weeks, Years.



*/

#include "timeObject.h"


void timeObject::clockBegin(int32_t hours, int32_t minutes, int32_t seconds) {

}



void timeObject::countdownBegin(int32_t hours, int32_t minutes, int32_t seconds) {

  initialMillis = millis();

  Serial.printf("initialMillis: %i ", initialMillis);

  initial_clock_millis = clock_to_millis(hours, minutes, seconds);

  Serial.printf("  clock_start_time: %2i:%2i:%2i || inital_clock_millis: %i ", hours, minutes, seconds, initial_clock_millis);

  initial_countdown_millis = clock_to_millis(hours, minutes, seconds);

  Serial.printf("  timer_start_time: %2i:%2i:%2i || inital_timer_millis: %i ", hours, minutes, seconds, initial_countdown_millis);
  Serial.println("");
}



void timeObject::simpleClockLoop() {



}



// Method to return a simple clock data input as millis
int32_t timeObject::clock_to_millis(int32_t hours, int32_t minutes, int32_t seconds) {

  int32_t calc;

  calc = 1000 * (hours + 60 * (minutes + (60 * seconds)));

  return calc;

}


//simpleClockData timeObject::millis_to_clock(int32_t inputMillis){

//simpleClockData calc;


//}
