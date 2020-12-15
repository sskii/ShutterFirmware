/*
 * main.h
 *
 *  Created on: 29/10/2020
 *      Author: Sam
 */

#ifndef MAIN_H_
#define MAIN_H_

#include "menus.h"
#include "settings.h"
#include "timer.h"
#include "hardware.h"


#include <Arduino.h>

// set up modules
static MenuLogic menuLogic;			// menu logic
static SettingsRegistry settings;	// settings
static HardwareInterface hardware;  // hardware

#endif /* MAIN_H_ */