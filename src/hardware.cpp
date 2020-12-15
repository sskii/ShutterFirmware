/*
 * hardware.cpp
 * 
 * Defines simple methods to interface with all connected hardware.
 *
 *  Created on: 16/12/2020
 *      Author: Sam
 */

#include "hardware.h"

/* Constructor
 */
HardwareInterface::HardwareInterface() {

	savedStates = 0b00000000;	// zero states

}

/* Scans for any interaction with controls and pushes any updates to its stack.
 * Call this regularly.
 * @returns A flag indicating whether any new events were observed.
 */
bool HardwareInterface::scan() {

	// TODO check each control individually

	return false;

}

/* Attempt to push an interaction to the buffer.
 * @returns True if successful (false if buffer saturated).
 */
bool HardwareInterface::pushInteraction(uint8_t interactionType) {
	
	// check for saturation
	// find the number of saved actions
	uint8_t bufferCount = interactionsDepth + latestInteraction - oldestInteraction + 1;
	if(bufferCount >= interactionsDepth) bufferCount -= interactionsDepth;
	// TODO fix that garbage ^^ and find a better implementation

}