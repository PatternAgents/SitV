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

	#include "rsvp_options.h"
	#include "rsvp_pins.h"
    #include "src/util/util_misc.h"
	#include "src/EEPROM/ieeprom.h"
	#include "src/ADC/i2c_adc.h"
	#include "src/FRAM/i2c_fram.h"
	#include "src/SDcard/SDcard.h"
	#include "src/AUDIO/DSP_Audio.h"
	#include "src/GFX/spi_oled.h"
	#include "src/EMBEDIS/commands.h"
	#include "src/EMBEDIS/keystore.h"

  // Include Wavetable and Waveform Samples for the DSP_Audio System
  // Note Bene : careful with large samples not to overflow the 256K/512/1M flash memory size!!!
  #include "src/samples/piano_samples.h" 

#endif
