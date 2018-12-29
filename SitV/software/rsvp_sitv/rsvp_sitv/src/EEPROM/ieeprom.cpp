/*  Embedis - Embedded Dictionary Server
    Copyright (C) 2015, 2016, 2017, 2018 PatternAgents, LLC

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include "../../rsvp.h"

// Add an "EEPROM" dictionary to Embedis, using the Ardunio EEPROM API
//
// We show in this example how to use Embedis to hold configuration settings in EEPROM.
// Due to Wear leveling issues this is not recommended for real-time and changing data.
// Use SRAM, NVSRAM, FRAM or other suitable storage technology for rapidly changing data sets!
//
// To configure an EEPROM dictionary, call EEPROM_setup from your
// main setup() function. Optionally, supply the database name you want to use.
// e.g. EEPROM_setup();
//      EEPROM_setup( F("MYEEPROM") );
//
// Use the Embedis "select" command to enable your optional database name
// e.g. embedis-> select MYEEPROM
// The Embedis default database is "EEPROM", using the internal EEPROM memory.
// (or in the case of ESP8266 or Arduino Due, Emulated EEPROM...)
//
void EEPROM_setup(const String& dict) 
{
    Embedis::dictionary( dict,
        EEPROM_SIZE,
        [](size_t pos) -> char { return EEPROM.read(pos); },
        [](size_t pos, char value) { EEPROM.write(pos, value); }
    );
}

