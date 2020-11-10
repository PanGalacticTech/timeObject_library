/*~~@@@@ timeObject.cpp @@@@~~




   Library to convert times between millis()
   & times converted from starting values.


   outputs that count up & down.

   Returns: Micros, Millis, Seconds, Minutes, Hours, Days, Weeks, Years.



*/

#include "timeObject.h"



timeObject::timeObject() {

}

// Public Methods:

void timeObject::countdownStart() {

  Serial.println("Countdown Started");
  runCountdown = true;

  initialRecordedMillis = millis();
  initial_countdown_millis = clock_to_millis(countdown_master.h, countdown_master.m, countdown_master.s);
}


void timeObject::countdownStop() {
  Serial.println("Countdown Paused");
  runCountdown = false;

}



void timeObject::countdownSetup(int32_t hours, int32_t minutes, int32_t seconds) {

  Serial.println("");
  Serial.println("Countdown Setup");
  tminus = true;                        // Resets incase time is being added after t=0
  tzeroFudge = true;                     // resets incase time is being added after t=0
  initialRecordedMillis = millis();
  initial_countdown_millis = clock_to_millis(hours, minutes, seconds);

  Serial.printf("  timer_start_time: %02i:%02i:%02i || inital_timer_millis: %i ", hours, minutes, seconds, initial_countdown_millis);
  Serial.println("");
  Serial.println("");

  millis_to_countdown_clock(initial_countdown_millis);
}





void timeObject::countdownLoop() {

  if (runCountdown) {
    int32_t calcMillis = returnTimePassed(initial_countdown_millis);
    millis_to_countdown_clock(calcMillis);
  }
  updateAPIclocks();
}




void timeObject::countdownPrint(bool forcePrint) {
  if (timeUpdated()) {
    Serial.println(countdownclock_as_char);
  } else if (forcePrint) {                           // If set true then bypasses update function
    Serial.println(countdownclock_as_char);
  }
  //  Serial.println(countdown_clock_string);
  //Serial.printf("%02i:%02i:%02i", clock_countDown.h, clock_countDown.m, clock_countDown.s
  // Serial.println("");
}





// Private Methods

int32_t timeObject::returnTimePassed(uint32_t countdown_start_millis) {

  uint32_t millisPassed = millis() - initialRecordedMillis;

  millisPassed = countdown_start_millis - millisPassed;

  return  millisPassed;
}



// Method to return a total millis value from simple clock data input
int32_t timeObject::clock_to_millis(int32_t hours, int32_t minutes, int32_t seconds) {

  int32_t calc;

  calc = 1000 * (seconds + 60 * (minutes + (60 * hours)));

  return calc;

}


// Method to return simple clock data (HH:MM:SS) from a millis input (updates global variable on completion)
void timeObject::millis_to_countdown_clock(int32_t inputMillis) {


  simpleClockData calc;

  calc.s = inputMillis / 1000;
  // Serial.print("Totals Passed: ");
  // Serial.printf("calc.s: %i  |", calc.s);
  calc.m = calc.s / 60;
  // Serial.printf("calc.m: %i  |", calc.m);
  calc.h = calc.m / 60;
  //Serial.printf("calc.h: %i  |", calc.h);

  //Serial.println("");
  //Serial.println("Returned Time: ");

  calc.m = calc.m - (60 * calc.h);
  calc.s = calc.s - ( 60 * (calc.m + (60 * calc.h)));

  if (calc.s < 0) {
    calc.s = (calc .s * -1);
    tminus = false;
  }
  if (calc.m < 0) {
    calc.m = (calc.m * -1);
  }
  if (calc.h < 0) {
    calc.h = (calc.h * -1);
  }


  if (calc.s == 0 && calc.m == 0 && calc.h == 0) {
    if (tzeroFudge) {
      initial_countdown_millis = initial_countdown_millis - 1000;
      tzeroFudge = false;
      tzero = true;    // External flag for API
      // Serial.println("FUDGE FACTOR APPLIED");
    }
  }
  countdown_master = calc;

  //Serial.print("Return Clock: ");
  //  Serial.printf("%02i:%02i:%02i", clock_countDown.h, clock_countDown.m, clock_countDown.s);
  // Serial.println("");

}



void timeObject::updateAPIclocks() {     // Method to update different variables that can be polled by external objects

  if (tminus) {
    sprintf(countdownclock_as_char, "T- %02i:%02i:%02i", countdown_master.h, countdown_master.m, countdown_master.s);
  } else {
    sprintf(countdownclock_as_char, "T+ %02i:%02i:%02i", countdown_master.h, countdown_master.m, countdown_master.s);
  }

  countdown_clock_string = countdownclock_as_char;

}


bool timeObject::timeUpdated() {

  if (countdown_master.s != previousSecond || countdown_master.m != previousMinute || countdown_master.h != previousHour) {
    previousSecond = countdown_master.s;
	previousMinute = countdown_master.m;
	previousHour = countdown_master.h;
	time_updated = true;                // Gltobal variable latches true, can be unlatched externally.
    return true;
  } else {
    return false;
  }
}
