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

#include "../rsvp/rsvp.h"

// Adds some useful commands to Embedis.
// We'll add some Arduino I/O commands for making it interpretive...
//
// Call commands_setup() from your main setup() function.
// e.g. commands_setup();

void commands_setup(void)
{
    /* create an interactive "pinMode" command */
    Embedis::command( F("pinMode"), [](Embedis* e) {
        if (e->argc != 3) return e->response(Embedis::ARGS_ERROR);
        int pin = String(e->argv[1]).toInt();
        String argv2(e->argv[2]);
        argv2.toUpperCase();
        int mode;
        if (argv2 == "INPUT") mode = INPUT;
        else if (argv2 == "OUTPUT") mode = OUTPUT;
        else if (argv2 == "INPUT_PULLUP") mode = INPUT_PULLUP;
        else return e->response(Embedis::ARGS_ERROR);
        pinMode(pin, mode);
        e->response(Embedis::OK);
    });

    /* create an interactive "digitalWrite" command */
    Embedis::command( F("digitalWrite"), [](Embedis* e) {
        if (e->argc != 3) return e->response(Embedis::ARGS_ERROR);
        int pin = String(e->argv[1]).toInt();
        String argv2(e->argv[2]);
        argv2.toUpperCase();
        int mode;
        if (argv2 == "HIGH") mode = HIGH;
        else if (argv2 == "LOW") mode = LOW;
        else mode = argv2.toInt();
        digitalWrite(pin, mode);
        e->response(Embedis::OK);
    });

    /* create an interactive "digitalRead" command */
    Embedis::command( F("digitalRead"), [](Embedis* e) {
        if (e->argc != 2) return e->response(Embedis::ARGS_ERROR);
        int pin = String(e->argv[1]).toInt();
        if (digitalRead(pin)) {
            e->response(F("HIGH"));
        } else {
            e->response(F("LOW"));
        }
    });

    /* create an interactive "analogRead" command */
    Embedis::command( F("analogRead"), [](Embedis* e) {
        if (e->argc != 2) return e->response(Embedis::ARGS_ERROR);
        int pin = String(e->argv[1]).toInt();
        e->response(':', analogRead(pin));
    });

    /* create an interactive "adcRead" command for I2C_ADC */
    Embedis::command( F("adcRead"), [](Embedis* e) {
        if (e->argc != 2) return e->response(Embedis::ARGS_ERROR);
        int pin = String(e->argv[1]).toInt();
        e->response(':', I2C_ADC_Read(pin));
    });
    
    /* SDcard Information */
    Embedis::command( F("sdInfo"), [](Embedis* e) {
        sdCardInfo();
        e->response(Embedis::OK);
    });

    /* SDcard root directory */
    Embedis::command( F("ls"), [](Embedis* e) {
        sdListFiles();
        e->response(Embedis::OK);
    });

    /* SDcard cat a file */
    Embedis::command( F("cat"), [](Embedis* e) {
        if (e->argc != 2) return e->response(Embedis::ARGS_ERROR);
         sdCatFile(e->argv[1]);
         e->response(Embedis::OK);
    });

	/* create an interactive "drum" command */
	/* drum instance# frequency# length# mix# pitch# */
    Embedis::command( F("drum"), [](Embedis* e) {
        if (e->argc != 6) return e->response(Embedis::ARGS_ERROR);
        int instrument_num = String(e->argv[1]).toInt();
		int instrument_freq = String(e->argv[2]).toInt();
		int instrument_dur = String(e->argv[3]).toInt();
		float instrument_mix = String(e->argv[4]).toFloat();
		float instrument_pitch = String(e->argv[5]).toFloat();
		DSP_Audio_play_drum(instrument_num, instrument_freq, (float) instrument_dur, instrument_mix, instrument_pitch);
		e->response(Embedis::OK);
    });

	/* create an interactive "wavetable" command */
	/* wave instance# frequency# length# amplitude# */
    Embedis::command( F("wave"), [](Embedis* e) {
        if (e->argc != 5) return e->response(Embedis::ARGS_ERROR);
        int instrument_num = String(e->argv[1]).toInt();
		int instrument_freq = String(e->argv[2]).toInt();
		int instrument_dur = String(e->argv[3]).toInt();
		float instrument_amp = String(e->argv[4]).toFloat();
		DSP_Audio_play_wavetable(instrument_num, instrument_freq, instrument_dur, instrument_amp );
		e->response(Embedis::OK);
    });

	/* create an interactive "string" command */
	/* string instance# frequency# length# velocity# */
    Embedis::command( F("string"), [](Embedis* e) {
        if (e->argc != 5) return e->response(Embedis::ARGS_ERROR);
        int instrument_num = String(e->argv[1]).toInt();
		int instrument_freq = String(e->argv[2]).toInt();
		int instrument_dur = String(e->argv[3]).toInt();
		float instrument_amp = String(e->argv[4]).toFloat();
		DSP_Audio_play_string(instrument_num, instrument_freq, instrument_dur, instrument_amp );
		e->response(Embedis::OK);
    });

	/*
	Embedis::command( F("clear"), [](Embedis* e) {
		GRAPHICS_BEGIN_FRAME(false);
		graphics.clearRect(0,0,128,64);
		GRAPHICS_END_FRAME(); 
		display::Flush();
		display::Update();
        e->response(Embedis::OK);
    });

	Embedis::command( F("draw"), [](Embedis* e) {
		GRAPHICS_BEGIN_FRAME(false);
		graphics.drawFrame(0,0,128,64);
		GRAPHICS_END_FRAME(); 
		display::Flush();
		display::Update();
        e->response(Embedis::OK);
    });
	*/

}
