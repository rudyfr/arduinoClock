/*
Clock
 Copyright Rudy Rimland 2012 - 2013
 
 This clockWithMethods example sketch uses varius methods in the Clock class.
 */
#include <Clock.h>        // Include Clock Library

Clock clock = Clock();    // Declare the Clock

void setup()
{
  Serial.begin(9600);     // Time output on USB
  
  Serial.println("Clock time before setting");
  clock.printTime();
  
  // Set the Clock
  clock.setDayOfWeek(3);
  clock.setHour(15);
  clock.setMinute(35);
  clock.setSecond(8);
  
  // Get the values
  Serial.print("The day of week is: ");
  Serial.println(clock.getDayOfWeek());
  
  Serial.print("The hour is: ");
  Serial.println(clock.getHour());
  Serial.print("The minute is: ");
  Serial.println(clock.getMinute());
  Serial.print("The second is: ");
  Serial.println(clock.getSecond());
}

void loop()
{
  clock.run();            // Runs the Clock
}
