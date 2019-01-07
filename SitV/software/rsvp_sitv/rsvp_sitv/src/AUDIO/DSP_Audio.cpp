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

    A vanilla wrapper (wafer thin?) around the Teensy Audio System
    
   ======================================================================================
*/

#include "../rsvp/rsvp.h"

// GUItool: begin automatically generated code
AudioInputUSB            usb_in;           //xy=779.2699127197266,1015.0872812271118
AudioOutputUSB           usb_out;           //xy=1495.1269302368164,771.8174629211426
AudioOutputAnalogStereo  dacs_out;          //xy=1506.1269302368164,950.8174324035645
AudioSynthWavetable      wavetable[16];
AudioSynthKarplusStrong  string[8];        //xy=137.77779006958008,991.1110897064209
AudioSynthSimpleDrum     drum[8];          //xy=133.96826171875,711.1110992431641
AudioSynthNoiseWhite     noise[2];         //xy=131.25000381469727,1437.500020980835
AudioSynthNoisePink      pink[2];          //xy=131.25000381469727,1475.0000228881836
AudioSynthWaveform       waveform[2];      //xy=131.25000381469727,1511.2500228881836
AudioPlaySdWav           playSdWav[1];     //xy=137.5,1401.250020980835
AudioEffectEnvelope      envelope[2];      //xy=488.75000762939453,1445.000020980835
AudioFilterStateVariable filter[3];        //xy=652.5000114440918,1470.0000228881836
AudioEffectFlange        flange[1];        //xy=659.6667594909668,497.86511993408203
AudioEffectGranular      granular[1];      //xy=660,539
AudioEffectChorus        chorus[1];        //xy=661.6667594909668,458.86511993408203
AudioMixer4              mixer[20];         //xy=300.9090690612793,225.26774215698242
AudioConnection          patchCord1(wavetable[1], 0, mixer[0], 1);
AudioConnection          patchCord2(wavetable[5], 0, mixer[1], 1);
AudioConnection          patchCord3(wavetable[2], 0, mixer[0], 2);
AudioConnection          patchCord4(wavetable[8], 0, mixer[2], 0);
AudioConnection          patchCord5(wavetable[10], 0, mixer[2], 2);
AudioConnection          patchCord6(wavetable[13], 0, mixer[3], 1);
AudioConnection          patchCord7(wavetable[6], 0, mixer[1], 2);
AudioConnection          patchCord8(wavetable[7], 0, mixer[1], 3);
AudioConnection          patchCord9(wavetable[0], 0, mixer[0], 0);
AudioConnection          patchCord10(wavetable[14], 0, mixer[3], 2);
AudioConnection          patchCord11(wavetable[3], 0, mixer[0], 3);
AudioConnection          patchCord12(wavetable[11], 0, mixer[2], 3);
AudioConnection          patchCord13(wavetable[4], 0, mixer[1], 0);
AudioConnection          patchCord14(wavetable[15], 0, mixer[3], 3);
AudioConnection          patchCord15(wavetable[12], 0, mixer[3], 0);
AudioConnection          patchCord16(wavetable[9], 0, mixer[2], 1);
AudioConnection          patchCord17(drum[0], 0, mixer[7], 0);
AudioConnection          patchCord18(noise[1], 0, mixer[13], 0);
AudioConnection          patchCord19(pink[1], 0, mixer[13], 1);
AudioConnection          patchCord20(waveform[1], 0, mixer[13], 2);
AudioConnection          patchCord21(drum[1], 0, mixer[7], 1);
AudioConnection          patchCord22(waveform[0], 0, mixer[12], 2);
AudioConnection          patchCord23(drum[4], 0, mixer[8], 0);
AudioConnection          patchCord24(drum[2], 0, mixer[7], 2);
AudioConnection          patchCord25(drum[3], 0, mixer[7], 3);
AudioConnection          patchCord26(drum[5], 0, mixer[8], 1);
AudioConnection          patchCord27(drum[6], 0, mixer[8], 2);
AudioConnection          patchCord28(drum[7], 0, mixer[8], 3);
AudioConnection          patchCord29(string[0], 0, mixer[9], 0);
AudioConnection          patchCord30(string[1], 0, mixer[9], 1);
AudioConnection          patchCord31(playSdWav[0], 0, mixer[12], 3);
AudioConnection          patchCord32(playSdWav[0], 1, mixer[13], 3);
AudioConnection          patchCord33(string[2], 0, mixer[9], 2);
AudioConnection          patchCord34(string[4], 0, mixer[10], 0);
AudioConnection          patchCord35(string[5], 0, mixer[10], 1);
AudioConnection          patchCord36(string[6], 0, mixer[10], 2);
AudioConnection          patchCord37(string[7], 0, mixer[10], 3);
AudioConnection          patchCord38(noise[0], 0, mixer[12], 0);
AudioConnection          patchCord39(pink[0], 0, mixer[12], 1);
AudioConnection          patchCord40(string[3], 0, mixer[9], 3);
AudioConnection          patchCord41(mixer[0], 0, mixer[4], 0);
AudioConnection          patchCord42(mixer[1], 0, mixer[4], 1);
AudioConnection          patchCord43(mixer[2], 0, mixer[4], 2);
AudioConnection          patchCord44(mixer[3], 0, mixer[4], 3);
AudioConnection          patchCord45(mixer[7], 0, mixer[11], 0);
AudioConnection          patchCord46(mixer[8], 0, mixer[11], 1);
AudioConnection          patchCord47(mixer[9], 0, mixer[11], 2);
AudioConnection          patchCord48(mixer[12], envelope[0]);
AudioConnection          patchCord49(mixer[10], 0, mixer[11], 3);
AudioConnection          patchCord50(mixer[13], envelope[1]);
AudioConnection          patchCord51(mixer[4], 0, mixer[5], 0);
AudioConnection          patchCord52(mixer[4], chorus[0]);
AudioConnection          patchCord53(mixer[4], flange[0]);
AudioConnection          patchCord54(mixer[4], granular[0]);
AudioConnection          patchCord55(envelope[1], 0, mixer[15], 0);
AudioConnection          patchCord56(envelope[1], 0, filter[2], 0);
AudioConnection          patchCord57(envelope[0], 0, filter[1], 0);
AudioConnection          patchCord58(envelope[0], 0, mixer[14], 0);
AudioConnection          patchCord59(filter[2], 0, mixer[15], 1);
AudioConnection          patchCord60(filter[2], 1, mixer[15], 2);
AudioConnection          patchCord61(filter[2], 2, mixer[15], 3);
AudioConnection          patchCord62(filter[1], 0, mixer[14], 1);
AudioConnection          patchCord63(filter[1], 1, mixer[14], 2);
AudioConnection          patchCord64(filter[1], 2, mixer[14], 3);
AudioConnection          patchCord65(flange[0], 0, mixer[5], 2);
AudioConnection          patchCord66(granular[0], 0, mixer[5], 3);
AudioConnection          patchCord67(chorus[0], 0, mixer[5], 1);
AudioConnection          patchCord68(mixer[11], 0, mixer[19], 2);
AudioConnection          patchCord69(mixer[11], 0, mixer[16], 2);
AudioConnection          patchCord70(mixer[11], 0, mixer[17], 2);
AudioConnection          patchCord71(mixer[11], 0, mixer[18], 2);
AudioConnection          patchCord72(usb_in, 0, mixer[18], 3);
AudioConnection          patchCord73(usb_in, 0, mixer[16], 3);
AudioConnection          patchCord74(usb_in, 1, mixer[19], 3);
AudioConnection          patchCord75(usb_in, 1, mixer[17], 3);
AudioConnection          patchCord76(mixer[14], 0, mixer[16], 1);
AudioConnection          patchCord77(mixer[14], 0, mixer[18], 1);
AudioConnection          patchCord78(mixer[15], 0, mixer[17], 1);
AudioConnection          patchCord79(mixer[15], 0, mixer[19], 1);
AudioConnection          patchCord80(mixer[5], 0, mixer[6], 0);
AudioConnection          patchCord81(mixer[5], 0, filter[0], 0);
AudioConnection          patchCord82(filter[0], 0, mixer[6], 1);
AudioConnection          patchCord83(filter[0], 1, mixer[6], 2);
AudioConnection          patchCord84(filter[0], 2, mixer[6], 3);
AudioConnection          patchCord85(mixer[6], 0, mixer[16], 0);
AudioConnection          patchCord86(mixer[6], 0, mixer[17], 0);
AudioConnection          patchCord87(mixer[6], 0, mixer[18], 0);
AudioConnection          patchCord88(mixer[6], 0, mixer[19], 0);
AudioConnection          patchCord89(mixer[16], 0, usb_out, 0);
AudioConnection          patchCord90(mixer[17], 0, usb_out, 1);
AudioConnection          patchCord91(mixer[19], 0, dacs_out, 1);
AudioConnection          patchCord92(mixer[18], 0, dacs_out, 0);
// GUItool: end automatically generated code

void DSP_Audio_setup(void) {
    //initialize all the Audio objects.
    AudioMemory(120);
    dacs_out.analogReference(INTERNAL);

}
  
void DSP_Audio_loop(void) {
}

void DSP_Audio_play_drum(int drum_num, int drum_freq, int drum_length, float drum_secmix, float drum_pitchmod) {
			drum[drum_num].frequency(drum_freq);
		    drum[drum_num].length(drum_length);
            drum[drum_num].secondMix(drum_secmix);
            drum[drum_num].pitchMod(drum_pitchmod);  
			drum[drum_num].noteOn();
}

void DSP_Audio_play_wavetable(int wave_num, int wave_freq, int wave_length, float wave_amp) {
			wavetable[wave_num].setInstrument(epiano);
			wavetable[wave_num].amplitude(wave_amp);
            wavetable[wave_num].playFrequency(wave_freq);
			wavetable[wave_num].amplitude(wave_amp);
			delay(wave_length);
            wavetable[wave_num].stop();
}

void DSP_Audio_play_string(int string_num, int string_freq, int string_length, float string_velocity) {
			string[string_num].noteOn(string_freq, string_velocity);
			delay(string_length);
			string[string_num].noteOff(string_velocity);
}