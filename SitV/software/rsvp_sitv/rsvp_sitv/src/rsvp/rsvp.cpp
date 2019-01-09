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

#include "rsvp.h"

// Embedis will run on the USB Virtual Serial port ("Serial"). 
// Use the Arduino serial monitor and type "COMMANDS" to get started.
// Make sure "No line ending" is -NOT- selected. All others should work.
//
Embedis embedis(RSVP_CONSOLE);

void rsvp_setup(void) {
    // Start the Serial Console
    RSVP_CONSOLE.begin(115200);
    // wait for serial port to connect 
    #if (RSVP_CONSOLE_WAIT)
      while (!RSVP_CONSOLE) { ; }
    #endif

    // Start Logging
    LOG( String() + F("[ RSVP : Embedis    : Installed ]") );
    
    // start all the subsystems and log it
    EEPROM_setup("EEPROM");
    LOG( String() + F("[ RSVP : EEPROM     : EEPROM Embedis dictionary Installed ]") );
    
    I2C_FRAM_setup("FRAM");
    LOG( String() + F("[ RSVP : Embedis    : FM24W256-G Embedis dictionary Installed ]") );
    
    I2C_ADC_setup(RSVP_EADC_GAIN); 
    LOG( String() + F("[ RSVP : I2C_ADC    : ADS1015/ADS1115 driver Installed ]") );

    DSP_Audio_setup();
    LOG( String() + F("[ RSVP : DSP_Audio  : DSP/Audio driver Installed ]") );

    SDcard_setup();
    LOG( String() + F("[ RSVP : SDCard     : SDIO Driver Installed ]") );

    SPI_OLED_setup();
    LOG( String() + F("[ RSVP : SD1106     : GFX/OLED Driver Installed ]") );    

	rsvp_midi_setup();
    LOG( String() + F("[ RSVP : MIDI Host  : USB MIDIx04 Host   Installed ]") );    
    LOG( String() + F("[ RSVP : MIDI Device: USB MIDIx16 Device Installed ]") );    
    LOG( String() + F("[ RSVP : MIDI Serial: COM MIDIx01 Serial Installed ]") );    

	commands_setup();
    LOG( String() + F("[ RSVP : Embedis    : type 'commands' to get a list of installed Embedis commands ]") );
    LOG( String() + F("[ RSVP : Embedis    : type 'help' to get more information on installed Embedis commands ]") );

    // end logging
    LOG( String() + F(" ") );
}
  
void rsvp_loop(void) {
    /* run the MIDI stacks */
    rsvp_midi_loop();

    /* Always call the process method from the main loop (or a timer) to run the Embedis system */
    embedis.process();

    /* run the MIDI stacks */
    rsvp_midi_loop();

    /* Give the internal RTOS time to task switch in ESP8266, Edison, Currie, etc.   */
    /* not really necessary on AVR or Cortex platforms, but hey - it doesn't hurt... */
    yield(); 
}