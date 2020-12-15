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

}

/* Get the duration of the currently-set shutter speed.
 * @returns The shutter speed duration in seconds (floating point)
 */
float Timer::getDuration() {
	uint8_t speedThirdSteps;	// the shutter speed in third steps
	speedThirdSteps = settings.peek(M_BaseExp);	// get said speed
	float duration = pow(2, (speedThirdSteps/3));	// raise 2 to a power.
	return duration;
}
