#include "Arduino.h"
#include "Clock.h"

/** @file Clock.cpp
 * @author Rudy Rimland
 * @copyright 2012 - 2013 Rudy Rimland
 * @version 1.0b
 * @warning THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
 * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR
 * THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 * @brief An Arduino-based Clock
 *
 * The Clock is object-based.  The Class includes methods to set, retrieve,
 * and print out the current time.
 */

/** @brief Construct a Clock object
 *
 * The Clock object is initialized and ready to run starting
 * with ZERO values, except for the tick counter, which is
 * set to the value returned by millis() at time of construction.\n
 * @post Clock is initialized
 * @return Address of new Clock object
 */ 
Clock::Clock()
{
  _time = ZERO;
  _ticks = millis();
  _dayOfWeek = MONDAY;
  _second = ZERO;
  _minute = ZERO;
  _hour = ZERO;
  _secondDay = false;
  _thirdDay = false;
  _dayBeforeThirdDay = false;
  _buffer[ZERO] = '\0';
}

/** @brief Set the Clock time in milliseconds
 * @pre time is an unsigned long
 * @post time is set to param
 * @todo Bounds-check time
 * @param time New time value
 * @return Void
 */
void Clock::setTime(unsigned long time)
{
  _time = time;
}

/** @brief Get the Clock time in milliseconds
 * @pre none
 * @post unchanged
 * @return _time Time in milliseconds
 */
unsigned long Clock::getTime()
{
  return _time;
}

/** @brief Set the Clock Day of Week
 *
 * @pre dayOfWeek is an int
 * @post time is set to param
 * @todo Bounds-check day of week
 * @param dayOfWeek New Day of Week value
 * @return Void
 */
void Clock::setDayOfWeek(int dayOfWeek)
{
  _dayOfWeek = dayOfWeek;
}

/** @brief Get the Clock Day of Week
 * The day of week follows the Unix convention for day of week:\n
 * Value | Day of Week
 * :-----:|:--------
 *   1 | Monday
 *   2 | Tuesday
 *   3 | Wednesday
 *   4 | Thursday
 *   5 | Friday
 *   6 | Saturday
 *   7 | Sunday
 * @pre none
 * @post unchanged
 * @return _dayOfWeek Day of Week
 */
int Clock::getDayOfWeek()
{
  return _dayOfWeek;
}

/** @brief Sets the Clock hour
 * @pre hour is a value between 0 and 23 inclusive
 * @post The Clock hour is set to hour
 * @todo Bounds-check hour
 * @param hour 0<=hour<=23
 * @return Void
 */
void Clock::setHour(int hour)
{
  _hour = hour;
}

/** @brief Get the Clock hour
 * @pre none
 * @post unchanged
 * @return _hour Hour in 24 hour format
 */
int Clock::getHour()
{
  return _hour;
}

/** @brief Sets the Clock minute
 * @pre minute is a value between 0 and 59 inclusive
 * @post The Clock hour is set to minute
 * @todo Bounds-check minute
 * @param minute 0<=minute<=59
 * @return Void
 */
void Clock::setMinute(int minute)
{
  _minute = minute;
}

/** @brief Get the Clock minute
 * @pre none
 * @post unchanged
 * @return _minute Minute
 */
int Clock::getMinute()
{
  return _minute;
}

/** @brief Sets the Clock second
 * @pre hour is a value between 0 and 60 inclusive
 * @post The Clock hour is set to second
 * @todo Bounds-check second
 * @param second 0<=second<=60
 * @return Void
 */
void Clock::setSecond(int second)
{
  _second = second;
}

/** @brief Get the Clock seconds
 * @pre none
 * @post unchanged
 * @return _second Seconds
 */
int Clock::getSecond()
{
  return _second;
}

/** @brief Increments the Clock Day of Week
 * Day is a value between 0 and 6 inclusive, with 0 corresponding to
 * Monday.  Incrementing day 6 rolls the value of Day of week over to 0.
 * The Clock also tracks every second and every third day.
 * @return Void
 */
void Clock::_addDay()
{
  if(_dayOfWeek == DAYS_PER_WEEK)
  {
    _dayOfWeek = MONDAY;
    _secondDay = !_secondDay;

    if(_thirdDay) _thirdDay = false;
    if(_dayBeforeThirdDay && !_thirdDay)
    {
      _thirdDay = true;
      _dayBeforeThirdDay = false;
    }
    else
    {
      _dayBeforeThirdDay = true;
    }
  }
}

/** @brief Increments the Clock Hour
 * Hour is a value between 0 and 23 inclusive. A value of 24 rolls over to 0.
 * @return Void
 */
void Clock::_addHour()
{
  if(++_hour == HOURS_PER_DAY)
  {
    _hour = ZERO;
    _addDay();
  }
}

/** @brief Increments the Clock Minute
 * Minute is a value between 0 and 59 inclusive. A value of 60 rolls over to 0.
 * @return Void
 */
void Clock::_addMinute()
{
  if(++_minute == MINUTES_PER_HOUR)
  {
    _minute = ZERO;
    _addHour();
  }
}

/** @brief Increments the Clock Second
 * Second is a value between 0 and 59 inclusive. A value of 60 rolls over to 0.
 * @return Void
 */
void Clock::_addSecond()
{
  if(++_second == SECONDS_PER_MINUTE)
  {
    _second = ZERO;
    _addMinute();
  }
  _time = _time + MILLIS_PER_SECOND;
}

/** @brief Prints out the current Clock time
 *
 * Format of time is "<Day of Week>, <hour>:<minute>:<second>"
 * @todo Prepend 0 to single-digit hour, minute, and second
 * @return Void
 */
void Clock::printTime()
{
  const String PROGMEM dayStrings[8] = {
    ", ",
    "Monday",
    "Tuesday",
    "Wednesday",
    "Thursday",
    "Friday",
    "Saturday",
    "Sunday"    
};
  /*
  strcpy_P(_buffer, PSTR("Time : "));
  Serial.print(_buffer);
  //*/

  Serial.print(dayStrings[_dayOfWeek]);
  //strcpy_P(_buffer, dayStrings[_dayOfWeek]);
  //Serial.print(_buffer);

  //strcpy_P(_buffer, PSTR(dayStrings[ZERO]));
  //Serial.print(_buffer);
  Serial.print(dayStrings[ZERO]);
  Serial.print(_hour);
  //strcpy_P(_buffer, PSTR(COLON));
  Serial.print(COLON);
  Serial.print(_minute);
  //strcpy_P(_buffer, PSTR(COLON));
  //Serial.print(_buffer);
  Serial.print(COLON);
  Serial.print(_second);
  Serial.println();
}

/** @brief Runs the Clock
 *
 * If the Clock is at least 1 second behind, 1 second is added to the
 * Clock object.  If the Clock is not run at least once a second, it
 * will fall further behind.
 * @todo Verify rollover of internal clock does not cause incorrect operation.
 * The internal clock will roll over after about 5 weeks.
 * @todo Add flag to run silently
 * @todo Add flag to jump to current time without running through each state
 * @todo Add setters and getters for every second day and every third day
 * @todo Use avr/pgmspace library to minimize sram footprint
 * @todo Investigate further sram space reduction (through memory layout)
 * @todo Add support for Calendar day and month
 * @todo Add support for Time Zones
 * @return boolean True if Clock updated time, false otherwise
 */
boolean Clock::run()
{
  //1000 millis go by
  if(_ticks + MILLIS_PER_SECOND < millis())  // need to deal with rollover
  {
    _ticks = _ticks + MILLIS_PER_SECOND;
    _addSecond();
    printTime();
    return true;
  }
  return false;
};

