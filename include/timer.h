/*
 * timer.h
 * 
 * Core timing funcitonality.
 *
 *  Created on: 13/12/2020
 *      Author: Sam
 */

#ifndef TIMER_H_
#define TIMER_H_

#include <Arduino.h>

// hard-code shutter speeds in third stops
// we don't have the capacity to perform exponentiation
// ahem actually, we do with Arduino.h
// TODO: rewrite to use Arduino's pow(float base, float exponent) function.

int FourthSpeedsThirds[] = {512, 406, 323}; // speeds > 256
uint8_t ThirdSpeedsThirds[] = {255, 203, 161, 128, 102, 81, 64, 51, 40, 32},	// speeds with 0 d.p.
		SecondSpeedsThirds[] = {254, 202, 160, 127, 100, 80, 64, 50, 40, 32},	// speeds with 1 d.p.
		FirstSpeedsThirds[] = {252, 200, 159, 126},	// speeds with 2 d.p.
		SpeedsChangeoversAsc[] = {4, 14, 24, 27};	// used to work out which array to read from


class Timer {
public:
	void start();
};

#endif
