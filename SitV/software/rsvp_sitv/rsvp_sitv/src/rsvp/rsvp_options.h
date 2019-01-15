/*
 *
 * Configuration and Compile time options
 *
 */

#ifndef RVSP_OPTIONS_H_
#define RSVP_OPTIONS_H_

/* ------------- PLATFORM and OPTIONS definitions ----------------------------------------------------*/
#define RSVP_PLATFORM				SITV			//! one of O_C, SITV, QT, etc.
#define RSVP_PLATFORM_VERSION		3_5_1			//! Platform Version Number

/* ------------- Embedis definitions ----------------------------------------------------------------*/
#define RSVP_CONSOLE				Serial			//! USB Virtual Serial is used for the console CLI
#define RSVP_CONSOLE_WAIT			false			//! Wait for USB Virtual Serial to connect - set to 'false' for live instruments !!!

/* ------------- DISPLAY and OPTIONS definitions ----------------------------------------------------*/
#define RSVP_DISPLAY_TYPE			SH1106			//! one of HEADLESS, SH1106, SSD1306, ILI9571, etc.
#define RSVP_DISPLAY_PORT			SPI				//! one of NONE, SOFTSPI, SPI, SPI1, SPI2, etc.
												    //! NONE will be "write only" tests to the (ram) buffer (TODO)
#define RSVP_DISPLAY_ORIENTATION	0				//! one of 0, 90, 180, 270 (degrees)
													//#define FLIP_180 is deprecated
#define RSVP_DISPLAY_INVERT			0				//! one of 0/1 (1=invert)
												    //#define INVERT_DISPLAY is deprecated

/* --------------- External DAC type definitions ----------------------------------------------------  */
#define RSVP_EDAC_CHANNELS			4				//! 0 to 16 channels
#define RSVP_EDAC_TYPE				DAC8554			//! one of DAC8554, etc.
#define RSVP_EDAC_PORT				SPI				//! one of NONE, I2C, I2C1, I2C2, SPI, SPI1, Serial1, etc.
												                  //! NONE is "write only/bit-bucket" to the frame buffer
#define RSVP_EDAC_RESOLUTION		16				//! 8 to 32 bits
#define RSVP_EDAC_INVERT			0			    //! one of 0/1 (1=inverted opamp output)

/* --------------- External ADC type definitions ----------------------------------------------------  */
#define RSVP_EADC_CHANNELS			4				//! 0 to 16 channels
#define RSVP_EADC_TYPE				ADS1015			//! one of ADC1105, ADC1115, MCPxxxx, etc.
#define RSVP_EADC_PORT				WIRE			//! one of NONE, WIRE, WIRE1, WIRE2, SPI, SPI1, Serial1, etc.
												    //! NONE is "write only/bit-bucket", read zeros 
#define RSVP_EADC_RESOLUTION		12				//! 8 to 32 bits
#define RSVP_EADC_INVERT			0			    //! one of 0/1 (1=inverted opamp output)
#define RSVP_EADC_GAIN				1			    //! one of 0-5 gain settings

/* --------------- External MIDI type definitions -----------------------------------------------------------------  */
#define RSVP_MIDI_U_CHANNELS	    16				//! Number of USB device MIDI channels (0-16)
#define RSVP_MIDI_H_CHANNELS        4				//! Number of USB Host MIDI channels (0-4) on external USB Hub (4 port)
#define RSVP_MIDI_S_CHANNELS	    1				//! Number of Serial MIDI channels (0-2)
#define RSVP_MIDI_S1				Serial4			//! Port for Serial MIDI 1
#define RSVP_MIDI_S2				Serial5			//! Port for Serial MIDI 2

/* ------------ print debug messages to USB serial --------------------------------------------------  */
#define RSVP_ENABLE_LOG
//#define PRINT_DEBUG


/* ------------ uncomment for Buchla/non-octaval/quartertone support: -------------------------------  */
//#define BUCHLA_SUPPORT
/* ------------ uncomment for use with Northernlight cOC program card: ------------------------------  */
//#define BUCHLA_cOC
/* ------------ uncomment for use with Northernlight 4U / cOC : -------------------------------------  */
//#define BUCHLA_4U

#endif
