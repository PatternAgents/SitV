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
#ifndef DSPAUDIO_H_
#define DSPAUDIO_H_

  extern void DSP_Audio_setup(void);
  extern void DSP_Audio_play_drum(int drum_num, int drum_freq, int drum_length, float drum_secmix, float drum_pitchmod);
  extern void DSP_Audio_play_wavetable(int wave_num, int wave_freq, int wave_length, float wave_amp);
  extern void DSP_Audio_play_string(int string_num, int string_freq, int string_length, float string_velocity);
  extern void DSP_Audio_mixer(int mixer_num, int mixer_input, float mixer_amplitude);
  extern void DSP_Audio_filter(int filter_num, int filter_freq, float filter_Q, float filter_octave);
  extern void DSP_Audio_USB_in(void);
  extern void DSP_Audio_noise(int noise_num, float noise_amplitude);
  extern void DSP_Audio_pinknoise(int noise_num, float noise_amplitude);
  extern void DSP_Audio_envelope(int env_num, int env_length, float env_A, float env_H, float env_D, float env_S, float env_R);
  extern void DSP_Audio_playSdWav(int wsd_num, char *filepath);

#endif