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
	// TODO finish implementing a FIFO buffer for interactions
	#define interactionsDepth 10	// number to track
	uint8_t interaction[interactionsDepth],
			latestInteraction,
			oldestInteraction;

	/* The interactions stack is a circular/revolving buffer
	 * as it must be FIFO.
	 * Thus we track the memory location of the newest
	 * interaction (latestInteraction, the last one logged)
	 * and oldest (oldestInteraction, the next to be read).
	 */
	bool pushInteraction(uint8_t interactionType);

};

#endif