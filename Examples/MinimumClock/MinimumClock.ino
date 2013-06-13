/*
Clock
 Copyright Rudy Rimland 2012 - 2013
 
 This MinimumClock example sketch provides the minimum code needed to run the clock.
 */
#include <Clock.h>        // Include Clock Library

Clock clock = Clock();    // Declare the Clock

void setup()
{
  Serial.begin(9600);     // Time output on USB
}

void loop()
{
  clock.run();            // Runs the Clock
}
