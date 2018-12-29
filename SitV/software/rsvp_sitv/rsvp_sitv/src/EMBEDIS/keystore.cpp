/*  Embedis - Embedded Dictionary Server
    Copyright (C) 2015, 2016 PatternAgents, LLC

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
// Configuration settings are loaded from the default dictionary (EEPROM).

#include "../../rsvp.h"

// board : what board? (SITV, QT, etc.)
String rsvp_board(void) {
    String rsvp_board;
    if (!Embedis::get("rsvp_board", rsvp_board)) {
      // not found - return an empty string...
    }
    rsvp_board.toLowerCase();
    return rsvp_board;        
}
