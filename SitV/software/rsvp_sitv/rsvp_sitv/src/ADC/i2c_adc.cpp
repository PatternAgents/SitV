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
#include "../../rsvp.h"

Adafruit_ADS1015 eadc;  /* Use ADS1015 for 12-bit version, ADS1115 for 16-bit version */

  // simple globals for now...
  int i2c_adc[4]  = { 0, 0, 0, 0 };

void I2C_ADC_setup(const uint8_t gain) {
  //
  // The ADC input range (or gain) can be changed via the following
  // functions, but be careful never to exceed VDD +0.3V max, or to
  // exceed the upper and lower limits if you adjust the input range!
  // Setting these values incorrectly may destroy your ADC!
  //                                                                ADS1015  ADS1115
  //                                                                -------  -------
  // ads.setGain(GAIN_TWOTHIRDS);  // 2/3x gain +/- 6.144V  1 bit = 3mV      0.1875mV (default)
  // ads.setGain(GAIN_ONE);        // 1x gain   +/- 4.096V  1 bit = 2mV      0.125mV
  // ads.setGain(GAIN_TWO);        // 2x gain   +/- 2.048V  1 bit = 1mV      0.0625mV
  // ads.setGain(GAIN_FOUR);       // 4x gain   +/- 1.024V  1 bit = 0.5mV    0.03125mV
  // ads.setGain(GAIN_EIGHT);      // 8x gain   +/- 0.512V  1 bit = 0.25mV   0.015625mV
  // ads.setGain(GAIN_SIXTEEN);    // 16x gain  +/- 0.256V  1 bit = 0.125mV  0.0078125mV
  
  // need to adjust the input amps to maximize the range
  // it's not good right now  @ 0-> 3.3V
  switch (gain) {
  case 0 :
		eadc.setGain(GAIN_TWOTHIRDS);
		break;
  case 1 :
		eadc.setGain(GAIN_ONE);
		break;
  case 2 :
		eadc.setGain(GAIN_TWO);
		break;
  case 3 :
		eadc.setGain(GAIN_FOUR);
		break;
  case 4 :
		eadc.setGain(GAIN_EIGHT);
		break;
  case 5 :
		eadc.setGain(GAIN_SIXTEEN);
		break;
  default :
		eadc.setGain(GAIN_ONE);        // 1x gain   +/- 4.096V  1 bit = 2mV      0.125mV
	  break;
  }
  
  eadc.begin();  // start the external ADC driver
}

int I2C_ADC_Read(uint8_t pin) {
  if (pin < 4) {
    i2c_adc[pin] = eadc.readADC_SingleEnded(pin);
    return(i2c_adc[pin]);
  } else {
    return(0);
  }  
}

// simple loop, needs to be recoded to be interrupt/timer driven...
void I2C_ADC_loop() 
{
  i2c_adc[0] = eadc.readADC_SingleEnded(0);
  i2c_adc[1] = eadc.readADC_SingleEnded(1);
  i2c_adc[2] = eadc.readADC_SingleEnded(2);
  i2c_adc[3] = eadc.readADC_SingleEnded(3);

  #ifdef PRINT_DEBUG
    RSVP_CONSOLE.print("I2C_ADC 0: "); RSVP_CONSOLE.println(i2c_adc[0]);
    RSVP_CONSOLE.print("I2C_ADC 1: "); RSVP_CONSOLE.println(i2c_adc[1]);
    RSVP_CONSOLE.print("I2C_ADC 2: "); RSVP_CONSOLE.println(i2c_adc[2]);
    RSVP_CONSOLE.print("I2C_ADC 3: "); RSVP_CONSOLE.println(i2c_adc[3]);
  #endif
}
