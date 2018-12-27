/*  I2C_ADC
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

#include <Wire.h>
#include <Adafruit_ADS1015.h>
Adafruit_ADS1015 ads;  /* Use ADS1015 for 12-bit version, ADS1115 for 16-bit version */

  // simple globals for now...
  int i2c_adc[4]  = { 0, 0, 0, 0 };
  
  // uncomment for debug messages
  //#define I2C_ADC_DEBUG  1

void setup_I2C_ADC() 
{
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
  ads.setGain(GAIN_ONE);        // 1x gain   +/- 4.096V  1 bit = 2mV      0.125mV
  ads.begin();
}

int I2C_ADC_Read(uint8_t pin) {
  if (pin < 4) {
    i2c_adc[pin] = ads.readADC_SingleEnded(pin);
    return(i2c_adc[pin]);
  } else {
    return(0);
  }  
}

// simple loop, needs to be recoded to be interrupt/timer driven...
void loop_I2C_ADC() 
{
  
  i2c_adc[0] = ads.readADC_SingleEnded(0);
  i2c_adc[1] = ads.readADC_SingleEnded(1);
  i2c_adc[2] = ads.readADC_SingleEnded(2);
  i2c_adc[3] = ads.readADC_SingleEnded(3);

  #ifdef I2C_ADC_DEBUG
    Serial.print("I2C_ADC 0: "); Serial.println(i2c_adc[0]);
    Serial.print("I2C_ADC 1: "); Serial.println(i2c_adc[1]);
    Serial.print("I2C_ADC 2: "); Serial.println(i2c_adc[2]);
    Serial.print("I2C_ADC 3: "); Serial.println(i2c_adc[3]);
  #endif
}
