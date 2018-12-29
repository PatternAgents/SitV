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

Adafruit_FRAM_I2C fram = Adafruit_FRAM_I2C();

/* the settings for your particlar I2C_FRAM type... */
#define  I2C_FRAM_MODEL  FM24W256-G /* Cypress/Ramtron/etc. */
#define  I2C_FRAM_SIZE   32767      /* FM24V10 = 128K x 8   */
uint8_t  I2C_FRAM_Addr = 0x50;      /* A2 = A1 = A0 = "0"   */
 
void I2C_FRAM_setup(const String& dict) 
{
   if (fram.begin(I2C_FRAM_Addr)) {
     LOG( String() + F("[ RSVP : I2C_FRAM   : FM24W256-G FRAM Found ]") );
   } else {
     LOG( String() + F("[ RSVP : I2C_FRAM   : ERROR: FM24W256-G FRAM Not Found! ]") );
     // while (1); // implement "required resources!"
   }
  
    Embedis::dictionary( dict,
        (I2C_FRAM_SIZE),
        [](size_t pos) -> char { return fram.read8(pos); },
        [](size_t pos, char value) { fram.write8(pos, value); },
        []() { }
    );
}

