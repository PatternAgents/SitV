/*  DSP_Audio
    Copyright (C) 2017, 2018 PatternAgents, LLC

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

    DSP Audio - Audio Subsystem

    A vanilla wrapper (wafer?) around the Teensy Audio System
    
   ======================================================================================
*/

#include "rsvp.h"

// GUItool: begin automatically generated code
AudioInputAnalogStereo   adcs_in;          //xy=249,392
AudioInputUSB            usb_in;           //xy=249,448
AudioSynthWavetable      wavetable;      //xy=254,508
AudioSynthWaveformSine   sine;          //xy=257,577
AudioMixer4              mixer_dac_left;         //xy=521,585
AudioMixer4              mixer_dac_right;         //xy=523,671
AudioMixer4              mixer_usb_left;          //xy=525,405
AudioMixer4              mixer_usb_right;         //xy=525,492
AudioOutputAnalogStereo  dacs_out;          //xy=727,582
AudioOutputUSB           usb_out;           //xy=733,486
AudioConnection          patchCord1(adcs_in, 0, mixer_usb_left, 0);
AudioConnection          patchCord2(adcs_in, 0, mixer_dac_left, 0);
AudioConnection          patchCord3(adcs_in, 1, mixer_usb_right, 0);
AudioConnection          patchCord4(adcs_in, 1, mixer_dac_right, 0);
AudioConnection          patchCord5(usb_in, 0, mixer_usb_left, 1);
AudioConnection          patchCord6(usb_in, 0, mixer_dac_left, 1);
AudioConnection          patchCord7(usb_in, 1, mixer_usb_right, 1);
AudioConnection          patchCord8(usb_in, 1, mixer_dac_right, 1);
AudioConnection          patchCord9(wavetable, 0, mixer_usb_left, 2);
AudioConnection          patchCord10(wavetable, 0, mixer_usb_right, 2);
AudioConnection          patchCord11(wavetable, 0, mixer_dac_left, 2);
AudioConnection          patchCord12(wavetable, 0, mixer_dac_right, 2);
AudioConnection          patchCord13(sine, 0, mixer_usb_left, 3);
AudioConnection          patchCord14(sine, 0, mixer_usb_right, 3);
AudioConnection          patchCord15(sine, 0, mixer_dac_left, 3);
AudioConnection          patchCord16(sine, 0, mixer_dac_right, 3);
AudioConnection          patchCord17(mixer_dac_left, 0, dacs_out, 0);
AudioConnection          patchCord18(mixer_dac_right, 0, dacs_out, 1);
AudioConnection          patchCord19(mixer_usb_left, 0, usb_out, 0);
AudioConnection          patchCord20(mixer_usb_right, 0, usb_out, 1);
// GUItool: end automatically generated code

// Add any Wavetable Samples here...
#include "piano_samples.h"

void setup_DSP_Audio() 
{
    //initialize all the Audio objects.
    AudioMemory(20);
    dacs_out.analogReference(INTERNAL);
    wavetable.setFrequency(1000);
    wavetable.setInstrument(piano);
    wavetable.amplitude(1);
    sine.frequency(440);
    sine.amplitude(1);
    // ADC in to USB
    mixer_usb_left.gain(0, 0.0);
    mixer_usb_right.gain(0, 0.0);
    mixer_usb_left.gain(1, 0.0);
    mixer_usb_right.gain(1, 0.0);
    mixer_usb_left.gain(2, 0.0);
    mixer_usb_right.gain(2, 0.0);
    mixer_usb_left.gain(3, 0.7);
    mixer_usb_right.gain(3, 0.0);
 
    // Sine Wave to DAC out
    mixer_dac_left.gain(3, 0.7);
    mixer_dac_right.gain(3, 0.7);
}
  
