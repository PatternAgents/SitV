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

// if MIDI Serial enabled, create those instances
#include "../rsvp/rsvp.h"

#if (RSVP_MIDI_S_CHANNELS > 0)
  MIDI_CREATE_INSTANCE(HardwareSerial, RSVP_MIDI_S1, serMIDI1);
#endif

#if (RSVP_MIDI_S_CHANNELS > 1)
  MIDI_CREATE_INSTANCE(HardwareSerial, RSVP_MIDI_S2, serMIDI2);
#endif

// if MIDI USB Host is enabled, create those instances
// we're starting with only four (4) devices to reduce the handling time/latency
#if (RSVP_MIDI_H_CHANNELS == 4)
	USBHost midihost;
	USBHub hub1(midihost);
	USBHub hub2(midihost);
	USBHub hub3(midihost);
	USBHub hub4(midihost);
	MIDIDevice hostMIDI1(midihost);
	MIDIDevice hostMIDI2(midihost);
	MIDIDevice hostMIDI3(midihost);
	MIDIDevice hostMIDI4(midihost);
	MIDIDevice * hostmidis[RSVP_MIDI_H_CHANNELS] = {
		&hostMIDI1, &hostMIDI2, &hostMIDI3, &hostMIDI4 
    };
#endif

void rsvp_midi_setup(void){
	#if (RSVP_MIDI_S_CHANNELS > 0)
	  // start the (Serial) MIDI handler
	  serMIDI1.begin(MIDI_CHANNEL_OMNI);	/* We respond to all incoming channels */
      serMIDI1.turnThruOff();				/* this was causing HAVOC/crash on Loopback (LOL) */
	#endif
	#if (RSVP_MIDI_S_CHANNELS > 1)
	  // start the (Serial) MIDI handler
	  serMIDI2.begin(MIDI_CHANNEL_OMNI);	/* We respond to all incoming channels */
      serMIDI2.turnThruOff();				/* this was causing HAVOC/crash on Loopback (LOL) */
	#endif

	// Wait 1.5 seconds before turning on USB Host.  
	// If connected USB devices use too much power, 
	// the Teensy will (at least) completes USB enumeration;
	// making it easier to isolate any USB power releated issues.
	//
	// Note Bene : USE A POWERED USB HUB !!!
	//             The computers USB port may NOT provide enough power 
	//             for large USB MIDI devices or Synthesizers!
	//
	#if (RSVP_MIDI_H_CHANNELS > 0)
	  delay(1500);
	  // start the (USB Host) MIDI handler
	  midihost.begin();
	#endif
}

void rsvp_midi_loop(void) {
	  bool activity = false;

  // TODO : recode to directly register the (generic?) callback(s) and eliminate the polling loop
  //      : create a callback (table) to modify the 1:n message routing more easily
  //	  : recall/store the (table) from an Embedis keystore
  //      : code UI to change values in the keystore (val, type?)

  // read any messages from the Serial MIDI IN ports
  #if (RSVP_MIDI_S_CHANNELS > 0)
    if (serMIDI1.read()) {
	  // Send Serial1 MIDI Messages to USB MIDI (DeviceX16) Cable #1
      usbMIDI_Send(serMIDI1.getType(), serMIDI1.getData1(), serMIDI1.getData2(), serMIDI1.getChannel(), serMIDI1.getSysExArray(), 1);
      activity = true;
    }
  #endif
  #if (RSVP_MIDI_S_CHANNELS > 1)
    if (serMIDI2.read()) {
	  // Send Serial1 MIDI Messages to USB MIDI (DeviceX16) Cable #2
      usbMIDI_Send(serMIDI2.getType(), serMIDI2.getData1(), serMIDI2.getData2(), serMIDI2.getChannel(), serMIDI2.getSysExArray(), 2);
      activity = true;
    }
  #endif

  // read messages arriving from the USB devices plugged into the Teensy3.6  USB Host port
  // send them up to the USB MIDI (DeviceX16) Cable #3, #4, #5, #5 respectively */ 
  #if (RSVP_MIDI_H_CHANNELS > 0)
	midihost.Task();
    for (int port=0; port < RSVP_MIDI_H_CHANNELS; port++) {
      if (hostmidis[port]->read()) {
        uint8_t type =       hostmidis[port]->getType();
        uint8_t data1 =      hostmidis[port]->getData1();
        uint8_t data2 =      hostmidis[port]->getData2();
        uint8_t channel =    hostmidis[port]->getChannel();
        const uint8_t *sys = hostmidis[port]->getSysExArray();
        usbMIDI_Send(type, data1, data2, channel, sys, 3 + port);
        activity = true;
      }
    }
  #endif

  // Read any messages the PC sends to Teensy, and forward them
  // to either Serial MIDI or to USB devices on the USB host port.
  #if (RSVP_MIDI_U_CHANNELS > 0)
  if (usbMIDI.read()) {
    // get the USB MIDI message, defined by these 5 numbers (except SysEX)
    byte type = usbMIDI.getType();
    byte channel = usbMIDI.getChannel();
    byte data1 = usbMIDI.getData1();
    byte data2 = usbMIDI.getData2();
    byte cable = usbMIDI.getCable();

    // forward this message to one of the Serial MIDI OUT ports
    if (type != usbMIDI.SystemExclusive) {
      // Normal messages, first convert the 
	  // usbMIDI's type (an ordinary byte) 
	  // into the MIDI library's special MidiType
      midi::MidiType mtype = (midi::MidiType)type;

      
      switch (cable) {
        case  0: 
            // reserve for synth, etc.
			break;
        case  1: 
			// use the (Serial) MIDI library send()
			#if (RSVP_MIDI_S_CHANNELS > 0)
			serMIDI1.send(mtype, data1, data2, channel); 
		    #endif
			break;
        case  2: 
			// use the (Serial) MIDI library send()
			#if (RSVP_MIDI_S_CHANNELS > 1)
			serMIDI2.send(mtype, data1, data2, channel);
		    #endif
			break;
        default: 
			// cases 3-15
			// use the (USB Host) MIDI library send()
			#if (RSVP_MIDI_H_CHANNELS > 0)
			hostmidis[cable - 3]->send(type, data1, data2, channel);
			#endif
			break;
      }

    } else {
      // SysEx messages are special.  The message length is given in data1 & data2
      unsigned int SysExLength = data1 + data2 * 256;
      switch (cable) {
        case 0:
			// reserve for synth, etc.
			break;
        case 1: 
			// use the (Serial) MIDI library sendSysEx()
			#if (RSVP_MIDI_S_CHANNELS > 0)
			serMIDI1.sendSysEx(SysExLength, usbMIDI.getSysExArray(), true);
		    #endif
			break;
        case 2: 
			// use the (Serial) MIDI library sendSysEx()
			#if (RSVP_MIDI_S_CHANNELS > 1)
			serMIDI2.sendSysEx(SysExLength, usbMIDI.getSysExArray(), true);
		    #endif
			break;
        default: 
			// cases 3-15
			// use the (USB Host) MIDI library sendSysEx()
		    #if (RSVP_MIDI_H_CHANNELS > 0)
			hostmidis[cable - 3]->sendSysEx(SysExLength, usbMIDI.getSysExArray(), true);
			#endif
		    break;
      }
    }
    activity = true;
  }
  #endif
}

/* Helper functions */
void usbMIDI_Send(byte type, byte data1, byte data2, byte channel, const uint8_t *sysexarray, byte cable) {
  if (type != midi::SystemExclusive) {
    usbMIDI.send(type, data1, data2, channel, cable);
  } else {
    unsigned int SysExLength = data1 + data2 * 256;
    usbMIDI.sendSysEx(SysExLength, sysexarray, true, cable);
  }
}