
/*~~@@@@ timeObject.h @@@@~~




   Library to convert times between millis()
   & times converted from starting values.


   outputs that count up & down.

   Returns: Micros, Millis, Seconds, Minutes, Hours, Days, Weeks, Years.

  Simple & Complex Mode

  Easy way to implement clocks & countdown timers

*/


#include "timeObject.h"

timeObject simpleClock;


#define INITAL_HOURS 1
#define INITAL_MINS 2
#define INITAL_SECS 43

#define INITAL_CLOCK_VALUE {2,34,56}

//simpleClock.simpleClockData(0 , 1, 32);    // h.m.s

void setup(){

  simpleClock.countdownBegin(INITAL_HOURS, INITAL_MINS, INITAL_SECS);
}




void loop(){



  
}
