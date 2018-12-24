/*  rsvp - Reference System Virtual Platform
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
/*
   ====================================================================================== 

    "Spoken Into The Void" & QuadroTeenia Hardware Platforms
    --------------------------------------------------------

    Intended for Teensy LC, 3.2, 3.5, 3.6, 4.0 Portability 
    (we'll see how well that goes...)
    
   ======================================================================================
*/
#include "rsvp.h"

// Embedis will run on the USB Virtual Serial port ("Serial"). 
// Use the Arduino serial monitor and type "COMMANDS" to get started.
// Make sure "No line ending" is -NOT- selected. All others should work.
//
Embedis embedis(Serial);

void setup() 
{
    Serial.begin(115200);
    // wait for serial port to connect 
    // !!! comment out for live instruments !!!
    // leave it in if you want to see the startup LOG...
    while (!Serial) { ; }

    // Start Logging
    LOG( String() + F("[ RSVP : Embedis    : Installed ]") );
    
    // start all the subsystems and log it
    setup_EEPROM();
    LOG( String() + F("[ RSVP : EEPROM     : EEPROM Embedis dictionary Installed ]") );
    
    setup_I2C_FRAM();
    LOG( String() + F("[ RSVP : I2C_FRAM   : FM24W256-G Embedis dictionary Installed ]") );
    
    setup_I2C_ADC(); 
    LOG( String() + F("[ RSVP : I2C_ADC    : ADS1015/ADS1115 driver Installed ]") );

    setup_DSP_Audio();
    LOG( String() + F("[ RSVP : DSP_Audio  : DSP/Audio driver Installed ]") );

    setup_commands();
    LOG( String() + F("[ RSVP : commands   : type 'commands' to get a list of Installed Commands ]") );

    // end logging
    //LOG( String() + F(" ") );
}

void loop() 
{
    /* Always call the process method fro the main loop to run the Embedis system */
    embedis.process();

    /* Give the internal RTOS time to task switch in ESP8266, Edison, Currie, etc.   */
    /* not really necessary on AVR or Cortex platforms, but hey - it doesn't hurt... */
    yield(); 
}

// This will log to an embedis channel called "log".
// Use SUBSCRIBE LOG to get these messages.
// Logs are also printed to Serial until an empty message is received.
void LOG(const String& message) {
    static bool inSetup = true;
    if (inSetup) {
        if (!message.length()) {
            inSetup = false;
            return;
        }
        Serial.println(message);
    }
    Embedis::publish("log", message);
}
