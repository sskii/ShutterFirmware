/*
 * hardware.h
 * 
 * Exposes simple methods to interface with all connected hardware.
 *
 *  Created on: 16/12/2020
 *      Author: Sam
 */

#ifndef HARDWARE_H_
#define HARDWARE_H_

#include <Arduino.h>

// TODO implement a stack of registererd inputs?

// TODO handle rotory encoder
// TODO handle button presses



class HardwareInterface {
public:
	uint8_t savedStates;	// variable to track the last states of controls
	/*  Bit index   Representation
 	* 		  MSB	shutter button
 	* 			6	select button
 	* 			1	encoder DATA
 	* 		  LSB	encoder CLK
 	*/
	
	void init();
	bool scan();

	bool remainingInteractions();
	uint8_t popInteraction();
	

	HardwareInterface();	// constructor

private:
	// TODO finish implementing a stack for interactions
	uint8_t interactions[10];
	void pushInteraction(uint8_t interactionType);

};

#endif