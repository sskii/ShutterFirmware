
/* Persistent settings manager for the Shutter Firmware
 * Manages settings fetch and update.
 * 
 * Maps setting UIDs to either virtual values or to data
 * in EEPROM.
 * 
 * @author Sam
 * Created on 3 Nov 2020
 */

#ifndef SETTINGS_H_
#define SETTINGS_H_

#include <Arduino.h>
#include <EEPROM.h>     // yeah, we'll be lazy
                        // we can do it manually if we run short on memory.

class SettingsRegistry {
public:

    uint8_t peek(uint8_t UID);
    uint8_t open(uint8_t UID);
    uint8_t change(int8_t delta);
    uint8_t close(bool commit);

private:

    uint8_t openUID;        // the UID of the currently-open setting
    uint8_t liveValue;      // buffer to store value for open setting to avoid abusing EEPROM
    //void write(uint8_t UID, uint8_t value);
    //uint8_t read(uint8_t UID);

};

#endif