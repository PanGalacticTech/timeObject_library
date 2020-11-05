/*~~@@@@ timeObject.h @@@@~~




   Library to convert times between millis()
   & times converted from starting values.


   outputs that count up & down.

   Returns: Micros, Millis, Seconds, Minutes, Hours, Days, Weeks, Years.



*/


#ifndef timeObject_h
#define timeObject_h

#if (ARDUINO >=100)
#include <Arduino.h>
#else
#include <wProgram.h>
#endif



class timeObject {

  public:


    // Global Variables

    struct complexClockData {
      int32_t microS;
      int32_t milliS;
      int32_t secs;
      int32_t mins;
      int32_t hours;
      int32_t days;
      int32_t weeks;
      int32_t years;
    };

    complexClockData complex_clock_countUp;             //Global Variable for RTC
    complexClockData complex_clock_countDown;               // Global Variable for countdown timer

    complexClockData complex_clock_startTime;              // Used for clock that counts up as a RTC
    complexClockData complexTimer_startTime;                // Used as starting point for countdown timer.


    struct simpleClockData {
      int32_t h;
      int32_t m;
      int32_t s;
    };

    simpleClockData clock_countUp;      //Global Variable for RTC
    simpleClockData clock_countDown;    // Global Variable for countdown timer

    simpleClockData clock_start_time;   // Used for clock that counts up as a RTC
    simpleClockData timer_start_time;   // Used as starting point for countdown timer.


    //  Constructor
    timeObject();

    //  Methods
  //  void complexTimeBegin(complexClockData startTime);

  //  void complexClockLoop();

    void clockBegin(int32_t hours, int32_t minutes, int32_t seconds);

     void countdownBegin(int32_t hours, int32_t minutes, int32_t seconds);

    void simpleClockLoop();

    int32_t clock_to_millis(int32_t hours, int32_t minutes, int32_t seconds);
    
//simpleClockData millis_to_clock();

    //  Variables



  private:


    uint32_t initialMillis;    // records the inital millis(); reading and uses this to calculate the starting point for both clock & countdown timer

    int32_t initial_clock_millis;   // clock input start time is converted to millis

    int32_t initial_countdown_millis;   // countdown input start time is converted to millis

};


#endif
