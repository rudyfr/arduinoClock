/** @file Clock.h
 * @brief Header file for an Arduino-based Clock.
 *
 * The Clock is object-based.  The Class includes methods to set, retrieve,
 * and print out the current time.
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
 */

#ifndef Clock_h
#define Clock_h

#include "Arduino.h"

const long int ZERO = 0; /**<Declared constant */
const long int MILLIS_PER_SECOND = 1000; /**<Declared constant */
const long int SECONDS_PER_MINUTE = 60; /**<Declared constant */
const long int MINUTES_PER_HOUR = 60; /**<Declared constant */
const long int HOURS_PER_DAY = 24; /**<Declared constant */
const long int DAYS_PER_WEEK = 7; /**<Declared constant */
const int MONDAY = 1; /**<Declared constant */
const int TUESDAY = 2; /**<Declared constant */
const int WEDNESDAY = 3; /**<Declared constant */
const int THURSDAY = 4; /**<Declared constant */
const int FRIDAY = 5; /**<Declared constant */
const int SATURDAY = 6; /**<Declared constant */
const int SUNDAY = 7; /**<Declared constant */
const char COLON = ':'; /**<Declared constant */

/**
 * @class Clock
 * @brief A Clock Class for Arduino.
 *
 * The Clock is based on:
 *  http://www.faludi.com/examples/open-source-arduino-clock, but this version
 * is object-based.  Converted to a libtrary by following the tutorial at:
 *  http://arduino.cc/en/Hacking/LibraryTutorial.
 * Finally, the code comments are in Doxygen style.
*/

class Clock
{
public:
  Clock();
  void setTime(unsigned long time);
  unsigned long getTime();
  void setDayOfWeek(int dayOfWeek);
  int getDayOfWeek();
  void setHour(int hour);
  int getHour();
  void setMinute(int minute);
  int getMinute();
  void setSecond(int second);
  int getSecond();
  void printTime();
  boolean run();
private:
  unsigned long _time;
  unsigned long _ticks;
  int _second;
  int _minute;
  int _hour;
  int _dayOfWeek;
  boolean _secondDay;
  boolean _thirdDay;
  boolean _dayBeforeThirdDay;
  char _buffer[10];
  void _addDay();
  void _addHour();
  void _addMinute();
  void _addSecond();
};

#endif
