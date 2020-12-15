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
 * @returns A flag indicating whether any new events were observed.
 */
bool HardwareInterface::scan() {

	// TODO do the rounds

	return false;

}