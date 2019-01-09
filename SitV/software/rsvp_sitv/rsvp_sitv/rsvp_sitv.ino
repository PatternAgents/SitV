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

    Intended for 3.5, 3.6, 4.0 portability over raw performance
    (we'll see how well that goes...)

    Current SitV Teensy 3.6 Test Settings
    -------------------------------------
    Board: Teensy 3.6
    USB Type: Serial + MIDIx16 + Audio
    CPU Speed: 240Mhz (Overclock)
    
   ======================================================================================
*/

/* apps will fill in the upper tabs, the rsvp framework is under ./src */
#include "src/rsvp/rsvp.h"

/* basic templates to start - add apps once the core is tested */
void setup() {
  /* rsvp - initialize all subsystems */
  rsvp_setup();
}

void loop() {
    /* run-  the rsvp stacks */
    rsvp_loop();
}
