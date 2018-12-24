# Spoken into the Void - 

[![License: CC BY-NC 4.0](https://img.shields.io/badge/License-CC%20BY--NC%204.0-lightgrey.svg)](https://creativecommons.org/licenses/by-nc/4.0/)
[![Wiki Updated](https://img.shields.io/badge/Wiki-Updated-blue.svg)](https://github.com/PatternAgents/TheVoid/wiki)

"Spoken into the Void" is an CPU upgrade/add-on for the Teensy3.2 CPU to the larger Teensy 3.5/3.6 CPU, 
yielding more memory space and other resouces. The upgrade is simple, remove the existing Teensy3.2 CPU, 
and plug in the "Spoken into the Void" board in it's place.

"Spoken into the Void" has the following features :

* Eurorack 3U/8HP compatible
* Teensy 3.6 Based (32 bit 180 MHz ARM Cortex-M4 processor with floating point unit and DSP)
* 4X Flash Upgrade (1M)
* 4X RAM Upgrade (256K)
* Supports up to two(2) Teensy Audio Shields for four(4) channel 16-bit Audio I/O
* 4X external (16 bit) Analog to digital converters (ADS1115) for independent CV sampling
* USB Full-Speed Device (USB Audio, MIDI, COM, HID)
* USB Full-Speed Host (USB Keyboard, peripherals)
* Two  (2) AC coupled, line level audio input channels 
* Two  (2) AC coupled, line level audio output channels
* UART Jack for Serial MIDI Expansion
* I2C Jack for Controls & UI Expansion
* 32K bytes NVSRAM (non-volatile memory) for configuration memory (with Embedis support)

Format : Eurorack / (Dual) Breadboard Friendly

Height : 3U 

Width: 8HP

Depth : 1.0 cm

Power : +5V (USB) 200mA

Jacks : Stereo Line Input, Stereo Line Output, UART, I2C

---------------------------------------

[![micro:O&C](https://raw.githubusercontent.com/patternagents/SitV/master/SitV/images/uO_C.png?raw=true)](https://github.com/patternagents/TheVoid)  [![TheVoid](https://img.youtube.com/vi/XBFi51OQsEs/0.jpg)](https://www.youtube.com/watch?v=XBFi51OQsEs)


[![TheVoid](https://raw.githubusercontent.com/patternagents/SitV/master/SitV/images/osh_boards.png?raw=true)SitV](https://github.com/PatternAgents/TheVoid)

---------------------------------------
## SitV Applications <a name="SitV_Applications"/>

"Spoken into the Void" upgrades a Teensy.2 CPU Socket to accept the larger Teensy 3.6 embedded CPU module.

- "SitV" is also "breadboard friendly" and can be used to develop other circuits based on the Teensy 3.6 embedded CPU module
together with several Teensy Audio Modules.
- "SitV" can also be used with the [8HP micro:Ornament and Crime Eurorack module from JakPlug](https://github.com/jakplugg/uO_c)
- "SitV" can also be used with the [8HP micro:Temps Utile Eurorack module from JakPlug](https://github.com/jakplugg/T_u)

---------------------------------------
## SitV Status <a name="SitV_Status"/>

**11/28/2018:** 
- R1.0.0 : Initial Layout sent to OSHpark

**12/14/2018:**
- R1.0.0 : Initial Bringup and Testing
- Teensy3.5 working correctly
- Teensy3.6 SPI Bus Issue with alternate SPI pins
- Ornament&Crime R1.3.3 Up and Running

**12/23/2018:**
- "Serial+MIDIx16+Audio" Tested and working
- "USBHost" (MIDI Host) Tested and working

---------------------------------------
## SitV Model Images


[![patternagents TheVoid](https://raw.githubusercontent.com/patternagents/SitV/master/SitV/images/SitV_top.png?raw=true)Spoken into the Void - Top Side](https://github.com/patternagents/SitV)


[![patternagents TheVoid](https://raw.githubusercontent.com/patternagents/SitV/master/SitV/images/SitV_bot.png?raw=true)Spoken into the Void - Bottom Side](https://github.com/patternagents/SitV)


---------------------------------------

## SitV Documentation Index <a name="TheVoid_documentation_index"/>

[Ornament and Crime](http://ornament-and-cri.me/)

[micro:Ornament and Crime](https://github.com/jakplugg/uO_c)

[TheVoid Project](https://github.com/PatternAgents/SitV/wiki)

[TheVoid Hardware](https://github.com/patternagents/SitV/tree/master/SitV/revisions/)


---------------------------------------

## Documentation Index <a name="documentation_index"/>

[Organization Website](http://patternagents.github.io)

[FAQ - Frequently Asked Questions](http://thingsoc.github.io/support/faq.html)

---------------------------------------

[![thingSoC](http://thingsoc.github.io/img/projects/thingSoC/thingSoC_thumb.png?raw=true) 
*PatternAgents, LLC*](http://thingsoc.github.io)
