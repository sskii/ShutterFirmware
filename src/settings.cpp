
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

