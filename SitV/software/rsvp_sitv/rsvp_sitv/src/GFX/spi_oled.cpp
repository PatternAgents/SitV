/*  SPI_OLED
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

#include "../rsvp/rsvp.h"

#if (RSVP_DISPLAY_TYPE == SH1106)
  #include <Adafruit_GFX.h>
  #include <Adafruit_SH1106.h>

  #if (RSVP_DISPLAY_PORT == SPI)
    Adafruit_SH1106 display(OLED_DC, OLED_RST, OLED_CS);
  #else
    Adafruit_SH1106 display(OLED_MOSI, OLED_SCK, OLED_DC, OLED_RST, OLED_CS);
  #endif

  #if (SH1106_LCDHEIGHT != 64)
    #error("Height incorrect, please fix Adafruit_SH1106.h!");
  #endif

  void SPI_OLED_setup(void) {
    display.begin();
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(16,0);
    display.println("PatternAgents");
    display.setCursor(16,16);
    display.println("Spoken into");
    display.setCursor(16,32);
    display.println(" the Void");
    display.setCursor(16,48);
    display.println("SitV 3.6.1");
    display.display();
  }

  void SPI_OLED_loop(void) {
    display.display();
  }
#else
  // stubs for others right now...
  void SPI_OLED_setup(void) { }
  void SPI_OLED_loop(void)  { }
#endif