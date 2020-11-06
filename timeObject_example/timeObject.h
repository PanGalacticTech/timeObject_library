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

    //  Constructor
    timeObject();

    //Public Methods

    void countdownSetup(int32_t hours, int32_t minutes, int32_t seconds);   // Called to set a new start time

    void countdownLoop();       // Called through every loop to manage clock functions

    void countdownStart();

    void countdownStop();

    void countdownPrint(bool forcePrint = false);    // Prints the current value of clock_countDown

    bool timeUpdated();  //Method to track if time has been updated, can be used to delay printing

    // Global Variables

    char countdownclock_as_char[12];   //

    String countdown_clock_string;

    bool tminus = true;        // API can be polled to detect if clock is in t- or t+ mode

    bool runCountdown = false;   //


    //

    struct simpleClockData {
      int32_t h;
      int32_t m;
      int32_t s;
    };


    simpleClockData countdown_master;    // Global Variable for countdown timer
    simpleClockData timer_start_time;   // Used as starting point for countdown timer.

    //   simpleClockData clock_countUp;      //Global Variable for RTC
    //   simpleClockData clock_start_time;   // Used for clock that counts up as a RTC

    // simpleClockData return_clock;   // Global variable used to pass data between function



  private:

    int32_t clock_to_millis(int32_t hours, int32_t minutes, int32_t seconds);

    void millis_to_countdown_clock(int32_t inputMillis);

    int32_t returnTimePassed(uint32_t countdown_start_millis);

    void updateAPIclocks();



    bool tzeroFudge = true; // bool used to lock out the fudge factor once it has been applied

    uint32_t initialRecordedMillis;    // records the inital millis(); reading and uses this to calculate the starting point for both clock & countdown timer

    int32_t initial_clock_millis;   // clock input start time is converted to millis

    int32_t initial_countdown_millis;   // countdown input start time is converted to millis

    int16_t previousSecond;
    /*

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



    */



};


#endif
