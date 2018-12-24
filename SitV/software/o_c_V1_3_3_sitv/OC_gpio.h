#ifndef OC_GPIO_H_
#define OC_GPIO_H_

#include "OC_options.h"

#ifdef THEVOID_QT
  // "Spoken Into The Void" and "QuadtroTeenia" Pin Outs for Teensy 3.5 & 3.6"
  #ifdef FLIP_180
    #define CV4 33  //19
    #define CV3 34  //18
    #define CV2 35  //20
    #define CV1 36  //17

    #define TR4 0
    #define TR3 1
    #define TR2 2
    #define TR1 3
  
    #define but_top 4
    #define but_bot 5
  #else
    #define CV1 33  //19
    #define CV2 34  //18
    #define CV3 35  //20
    #define CV4 36  //17
  
    #define TR1 0
    #define TR2 1
    #define TR3 2
    #define TR4 3
  
    #define but_top 5
    #define but_bot 4
  #endif

// NOTE: encoder pins R1/R2 changed for rev >= 2c
  #ifdef FLIP_180
    #define encL1 20  //16
    #define encL2 29  //15
    #define butL  39  //14
  
    #define encR1 25  //22
    #define encR2 21  //21
    #define butR  24  //23
  #else
    #define encR1 20  //16
    #define encR2 29  //15
    #define butR  39  //14
  
    #define encL1 25  //22
    #define encL2 21  //21
    #define butL  24  //23
  #endif

  // SPI Bus
  #define OLED_DC   26        //6
  #define OLED_RST  27        //7
  #define OLED_CS    8        //8
  #define DAC_RST   28        //9
  #define DAC_CS    10        //10
  #define DAC_DOUT   7        //11
  #define DAC_DIN   12        //12
  #define DAC_SCK   14        //13

 // DEBUG PINS NOTE: back side :(
      #define OC_GPIO_DEBUG              2  //number of DEBUG pins
      #define OC_GPIO_DEBUG_PIN1        54  // was 24
      #define OC_GPIO_DEBUG_PIN2        55  // was 25

 // Pin Modes
      #define OC_GPIO_BUTTON_PINMODE    INPUT_PULLUP
      #define OC_GPIO_TRx_PINMODE       INPUT_PULLUP
      #define OC_GPIO_ENC_PINMODE       INPUT_PULLUP
      
 // OLED CS is active low
      #define OLED_CS_ACTIVE            LOW
      #define OLED_CS_INACTIVE          HIGH
     
  // MIDI Bus    
      #define QT_MIDI_PINS    2   // number of QTMIDI pins 
                                  // 0=Not Enabled 1=In Only, 2 = In + Out, 3= In + Out + Clk, 4 = All
      #define QT_MIDI_PORT   Serial4                        
      #define QT_MIDI_IN     31   // MIDI RXD
      #define QT_MIDI_OUT    32   // MIDI TXD
      #define QT_MIDI_CLK    49   // Note : Backside pins
      #define QT_MIDI_RUN    50   // Note : Backside pins

  // GATE OUT Bus
      #define QT_GTO_PINS     0    // number of QT GATE_OUT (GTO) pins
                                   // 0=Not Enabled
      #define QT_GTO1        43
      #define QT_GTO2        44
      #define QT_GTO3        45
      #define QT_GTO4        46

// DAC OUT BUS
      #define QT_DAC_PINS     2    // number of (internal) DAC pins
                                   // 0=Not Enabled
      #define QT_DAC_RESOL   12    // number of DAC bits
      #define QT_DAC1       A21
      #define QT_DAC2       A22

// I2S OUT BUS
      #define QT_I2S_PINS      0        // number of I2S pins/channels
                                        // 0-3=Not Enabled, 4=TXD12, 5=+RXD12, 6=+TXD34, 7=Quad In/Out)
      #define QT_I2S_TYPE      SGTL5000 // I2S type
      #define QT_I2S_I2C_PORT  0        // I2C Control Bus number
      #define QT_I2S_I2C_ADRM  0x0A     // I2C Control Bus address (master)
      #define QT_I2S_I2C_ADRS  0x1A     // I2C Control Bus address (slave)
      #define QT_I2S_BCLK      9
      #define QT_I2S_MCLK     11
      #define QT_I2S_LRCLK    23
      #define QT_I2S_TXD12    22
      #define QT_I2S_RXD12    13
      #define QT_I2S_TXD34    22
      #define QT_I2S_RXD34    13

 // ADC IN
      #define QT_ADC_PINS      0        // number of ADC pins/channels
                                        // 0=Not Enabled
      #define QT_ADC_TYPE      ADS1015  // ADC type
      #define QT_ADC_I2C_PORT  0        // ADC Control Bus number
      #define QT_ADC_I2C_ADRM  0x48     // ADC Control Bus address (master=0)

// FRAM (Embedis KeyStore)
      #define QT_FRAM_PINS     0         // number of FRAM pins/bank selects
                                         // 0=Not Enabled
      #define QT_FRAM_TYPE      FM24W256 // FRAM type
      #define QT_FRAM_I2C_PORT  0        // FRAM Control Bus number
      #define QT_FRAM_I2C_ADRM  0x50     // FRAM Control Bus address (master=0)
      #define QT_FRAM_I2C_SIZE  32767    // FRAM Control Bus size      
#else
// "Original O&C, uO&C, Buchla, etc."
    #ifdef FLIP_180
      #define CV4 19
      #define CV3 18
      #define CV2 20
      #define CV1 17
      #define TR4 0
      #define TR3 1
      #define TR2 2
      #define TR1 3
      #define but_top 4
      #define but_bot 5
      #define encL1 16
      #define encL2 15
      #define butL  14
      #define encR1 22
      #define encR2 21
      #define butR  23
    #else
      #define CV1 19
      #define CV2 18
      #define CV3 20
      #define CV4 17
      #define TR1 0
      #define TR2 1
      #define TR3 2
      #define TR4 3
      #define but_top 5
      #define but_bot 4
      #define encR1 16
      #define encR2 15
      #define butR  14
      #define encL1 22
      #define encL2 21
      #define butL  23
    #endif

    // OLED CS is active low
    #define OLED_CS_ACTIVE LOW
    #define OLED_CS_INACTIVE HIGH
    #define OLED_DC 6
    #define OLED_RST 7
    #define OLED_CS 8
    #define DAC_RST 9
    #define DAC_CS 10

    // NOTE: back side :(
    #define OC_GPIO_DEBUG              2  // number of DEBUG pins, 0 = disabled
    #define OC_GPIO_DEBUG_PIN1        24
    #define OC_GPIO_DEBUG_PIN2        25

    #define OC_GPIO_BUTTON_PINMODE    INPUT_PULLUP
    #define OC_GPIO_TRx_PINMODE       INPUT_PULLUP
    #define OC_GPIO_ENC_PINMODE       INPUT_PULLUP

    // QT Stubs
    #define QT_MIDI_PINS    0    // number of QT MIDI pins
    #define QT_GTO_PINS     0    // number of QT GATE_OUT (GTO) pins
    #define QT_DAC_PINS     0    // number of (internal) DAC pins
    #define QT_I2S_PINS     0    // number of I2S pins/channels
    #define QT_ADC_PINS     0    // number of ADC pins/channels
    #define QT_FRAM_PINS    0    // number of FRAM pins/bank selects        
  #endif
#endif // OC_GPIO_H_
