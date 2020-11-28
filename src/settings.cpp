
/* Persistent settings manager for the Shutter Firmware
 * Manages settings fetch and update.
 * 
 * Maps setting UIDs to either virtual values or to data
 * in EEPROM.
 * 
 * @author Sam
 * Created on 3 Nov 2020
 */

#include <settings.h>

/* Peek at the value of a setting.
 * No changes are made—this method is entirely seperate from open().
 * @param uid The UID of the setting to read.
 * @returns The raw value of the setting.
 */
uint8_t SettingsRegistry::peek(uint8_t UID) {

	return EEPROM.read((int)UID);	// easy, read from the location.
						// not sure why we need a seperate function

}

/* Open a setting for adjustment.
 * @param UID The UID of the target setting.
 * @returns Its value current to opening.
 */
uint8_t SettingsRegistry::open(uint8_t UID) {

	if(openUID == 0xFF) return (liveValue = EEPROM.read((int)(openUID = UID)));
		// if there is no open connection already
		// set the open setting UID, then log and return its value.

	else {
		// undefined behaviour.

	}

}

/* Request the open setting be changed.
 * @param delta The required change (likely -1 or 1). Added to current value.
 * @returns The new value of the setting after the change.
 */
uint8_t SettingsRegistry::change(int8_t delta) {

	return (liveValue += delta);     // update and return the live value

	// TODO remember that we're also responsible for, uh, bounds!!!
	// TODO we actually want to give it as a string, don't we?

}

/* Determines the maximum value for the given menu item.
 * @param itemNo The item UID.
 * @returns The maximum bound for the item (inclusive).
 */
uint8_t SettingsRegistry::itemMaxVal(uint8_t itemNo) {

	if(itemNo <= LAST_STEPPED_TIME) {
		// setting is of type STEPPED TIME
		// TODO return max value
	} else if(itemNo <= LAST_ZONE_INTEGER) {
		// setting is of type ZONE INTEGER
		return 10;
	} else {
		// the last two don't require an upper bound.
		return 0xff;
	}

}

/* Get the raw value formatted as a string for display.
 * @param UID The UID of the setting whose value is passed. (Needed to identify type.)
 * @param renderVal The raw value to be rendered as a string.
 * @returns The formatted string in English.
 */
String SettingsRegistry::settingAsString(uint8_t UID, uint8_t renderVal) {

	// check for STEPPED TIME
	if(UID <= LAST_STEPPED_TIME) {
		// make a string from a STEPPED TIME value

		/* STEPPED TIME:
		 * value of 126 represents 2^-0.33, or .5 sec
		 * value of 127 represents 2^0, or 1 sec
		 * value of 128 represents 2^1, or 2 sec
		 */

		// TODO come back and redesign the origin such that the saved value of 0 represents the fastest shutter time. Long exp. times can then trail from there.

		bool fraction = (renderVal < 127);	// flag if it's a fraction (less than one second).
		if(fraction) renderVal = 127 - renderVal;	// take the "reciprocal." Well, it has that effect.
		else renderVal -= 127;	// bring back a non-fraction back to normal

		// TODO find a way to perform the operation for without exponentiation.

	}

}

/* Close the setting being adjusted.
 * @param commit Set true to commit the changes, false to about.
 * @returns The final value, reflecting any and all changes.
 */
uint8_t SettingsRegistry::close(bool commit) {

	// NB we do end up making two disting EEPROM reads here; could be optimised.

	if(commit) EEPROM.update((int)openUID, liveValue);
						// commit the changes to EEPROM

	liveValue = EEPROM.read((int)openUID);
						// read the new setting
	openUID = 0xFF;		// flag as closed off
	return liveValue;	// return the new value
	
}

/* Private: write specified data to specified location.
 * @param UID The setting location into which to write.
 * @param value The value to write.
 */
/*void SettingsRegistry::write(uint8_t UID, uint8_t value) {
	/* NB
	 * We need to be careful not to make any reads
	 * when the user is powering down the device.
	 * 
	 * We also need to avoid any interrupts firing while the
	 * erase/write cycle is occuring (which takes 3.4 ms).
	 *//*


}*/

/* Private: read the data in a specified location
 * @param UID The setting location from which to read.
 * @returns The raw value of the setting.
 *//*
uint8_t SettingsRegistry::read(uint8_t UID) {

} */

