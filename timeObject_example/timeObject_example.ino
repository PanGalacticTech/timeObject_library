
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


#define INITAL_HOURS 0
#define INITAL_MINS 0
#define INITAL_SECS 10




#define PRINT_DELAY 1000


#define FORCE_PRINT_CLOCK false


void setup() {
  Serial.begin(115200);
  delay(100);
  simpleClock.countdownSetup(INITAL_HOURS, INITAL_MINS, INITAL_SECS);

  simpleClock.countdownStart();
}



void loop() {


  // Call in every loop
  simpleClock.countdownLoop();



  // Prints the clock every time seconds change.
  //Can be forced to print by passing true as an argument
  simpleClock.countdownPrint(FORCE_PRINT_CLOCK);

  // To Pause the countdown:
  //  simpleClock.countdownStop();


  // To Change time left on countdown Timer:
  //   simpleClock.countdownSetup(1, 3, 42);

}
