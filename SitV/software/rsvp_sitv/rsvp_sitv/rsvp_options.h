/*
 *
 * compile options.
 *
 */

#ifndef RVSP_OPTIONS_H_
#define RSVP_OPTIONS_H_

/* ------------- PLATFORM and OPTIONS definitions ----------------------------------------------------*/
#define RSVP_PLATFORM				    SITV		//! one of O_C, SITV, QT, etc.
#define RSVP_PLATFORM_VERSION		3_5_1   //! Platform Version Number

/* ------------- PLATFORM and OPTIONS definitions ----------------------------------------------------*/
#define RSVP_DISPLAY_TYPE       SH1106		//! one of HEADLESS, SH1106, SSD1306, ILI9571, etc.
#define RSVP_DISPLAY_PORT			  SPI       //! one of NONE, SOFTSPI, SPI, SPI1, SPI2, etc.
												                  //! NONE will be "write only" tests to the (ram) buffer (TODO)
#define RSVP_DISPLAY_ORIENTATION	0			  //! one of 0, 90, 180, 270 (degrees)
                                          //#define FLIP_180 is deprecated
#define RSVP_DISPLAY_INVERT			  0       //! one of 0/1 (1=invert)
												                  //#define INVERT_DISPLAY is deprecated

/* --------------- External DAC type definitions ----------------------------------------------------  */
#define RSVP_EDAC_TYPE				DAC8554		//! one of DAC8554, etc.
#define RSVP_EDAC_PORT				SPI			//! one of NONE, I2C, I2C1, I2C2, SPI, SPI1, Serial1, etc.
												//! NONE is "write only" to the (ram) buffer !
#define RSVP_EDAC_RESOLUTION		16			//! 8 to 32 bits
#define RSVP_EDAC_INVERT			0			//! one of 0/1 (1=inverted opamp output)

/* ------------ print debug messages to USB serial --------------------------------------------------  */
//#define PRINT_DEBUG

/* Other/legacy defines */
/* ------------ uncomment for Buchla/non-octaval/quartertone support: -------------------------------  */
//#define BUCHLA_SUPPORT
/* ------------ uncomment for use with Northernlight cOC program card: ------------------------------  */
//#define BUCHLA_cOC
/* ------------ uncomment for use with Northernlight 4U / cOC : -------------------------------------  */
//#define BUCHLA_4U

#endif
