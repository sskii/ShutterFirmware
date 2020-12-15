/*
 * timer.cpp
 *
 * Core timing funcitonality.
 *
 *  Created on: 13/12/2020
 *      Author: Sam
 */

#include "main.h"

/* Begin an exposure sequence. Claims operational control for duration of exposure.
 */
// TODO get menus to always start from the top of the stack when opening. That way they reopen after firing the shutter?
void Timer::beginExp() {
	// start by confirming the exposure time in milliseconds, cast to long
	long expTime = long(getDuration()*1000);

	// work out if it is a 'long' exposure
	// we'll only display a stopwatch on the display if it is.
	// doStopwatch will go false when there's less than 2 sec to go anyway.
	#define stopwatchUntil 2
	bool doStopwatch = (expTime > stopwatchUntil);

	/* a loop will hold operational control while the shutter runs.
	 * this is a safety precaution to avoid any other process getting screwed
	 * up by the shutter interrupt. This flag will be set by an interrupt when
	 * the shutter is closed to return control to this thread.
	 */ 
	bool escape = false;
	// TODO rewrite to allow certain background tasks while the shutter is tripped?
	
	long startTime;		// place to store the start time

	// TODO update the display one last time to advertise that an exposure is in progress

	// TODO set up interrupts to regularly check shutter

	// TODO do some math to see if we need to do a fast trip timing sequence
	//		if so we'll need to start releasing the second electromagnet blind

	// TODO open the shutter

	// note the close time
	long closeTime = millis() + expTime;

	// now we idle and hold contol 
	while(!escape) {}

	// this function continues execution when shutter is closed

	// TODO unset interrupts
	// TODO tidy up

}

/* Get the duration of the currently-set shutter speed.
 * @returns The shutter speed duration in seconds (floating point)
 */
float Timer::getDuration() {
	uint8_t speedThirdSteps = settings.peek(M_BaseExp);
													// the shutter speed in third steps
	float duration = pow(2, (speedThirdSteps/3));	// raise 2 to a power.
	return duration;
}
