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
#ifndef RSVP_H_
#define RSVP_H_

  #include <Arduino.h>
  #include <stdarg.h>
	#include <Audio.h>
	#include <Wire.h>
	#include <SPI.h>
	#include <SD.h>
	#include <SerialFlash.h>
	#include <Embedis.h>

	#include "../rsvp/rsvp_options.h"
	#include "../rsvp/rsvp_pins.h"
    #include "../util/util_misc.h"
	#include "../EEPROM/ieeprom.h"
	#include "../ADC/i2c_adc.h"
	#include "../FRAM/i2c_fram.h"
	#include "../SDcard/SDcard.h"
	#include "../AUDIO/DSP_Audio.h"
	//#include "../GFX/spi_oled.h"
	#include "../GFX/display.h"
	#include "../EMBEDIS/commands.h"
	#include "../EMBEDIS/keystore.h"

	// Include Wavetable and Waveform Samples for the DSP_Audio System
	// Note Bene : careful with large samples not to overflow the 256K/512/1M flash memory size!!!
	#include "../samples/piano_samples.h" 

	extern void rsvp_setup(void);
	extern void rsvp_loop(void);

#endif
