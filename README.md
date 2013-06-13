  Arduino Clock v1.0
================
  Copyright (c) 2012-2013, Rudy Rimland

  Non-commercial educational and hobby use permitted

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
  THE SOFTWARE.

 Welcome to an Arduino Clock.
================

This Object Oriented Clock for the Arduino Platform is an example of my coding skills.  The code comments are in Doxygen style.


- This code tested on the Arduino Uno R3
- It is not Unicode aware
- It consumes approximately 2400 bytes of Program Memory and 171 bytes static ram (workspace)

Using the Clock
================

Place the Clock library directory into your Arduino Libraries directory.  Sample sketches are in the Examples sub-directory.
- MinimumClock		Demonstrates minimum code needed to run the Clock
- ClockWithMethods	Demonstrates Clock Class methods


Clock Object
================
The Clock maintains state of the current:
- Day of Week
- Hour (in 24 hour format)
- Minute
- Second
- Ticks in Milliseconds at last update, which is less than or equal to the output of millis()

Clock.run() updates the current time.  If the clock is behind by more than a second, it only adds one second.  This guarantees all time states are entered, however if the clock is run less than once per second, it will lose time.
