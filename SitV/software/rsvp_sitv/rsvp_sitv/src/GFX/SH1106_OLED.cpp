
#include "../rsvp/rsvp.h"

static uint8_t SH1106_data_start_seq[] = {
  0x10, /* set upper 4 bit of the col adr to 0 */
  0x02, /* set lower 4 bit of the col adr to 0 */
  0x00  /* 0xb0 | page */  
};

static uint8_t SH1106_init_seq[] = {
  0x0ae,          /* display off, sleep mode */
  0x0d5, 0x080,   /* clock divide ratio (0x00=1) and oscillator frequency (0x8) */
  0x0a8, 0x03f,   /* multiplex ratio, duty = 1/32 */

  0x0d3, 0x000,   /* set display offset */
  0x040,          /* start line */

  0x08d, 0x014,   /* [2] charge pump setting (p62): 0x014 enable, 0x010 disable */

  0x020, 0x000,   /* 2012-05-27: page addressing mode */ // PLD: Seems to work in conjuction with lower 4 bits of column data?
  #ifdef FLIP_180
  0x0a0,          /* segment remap a0/a1*/
  0x0c0,          /* c0: scan dir normal, c8: reverse */
  #else
  0x0a1,          /* segment remap a0/a1*/
  0x0c8,          /* c0: scan dir normal, c8: reverse */
  #endif
  0x0da, 0x012,   /* com pin HW config, sequential com pin config (bit 4), disable left/right remap (bit 5) */
  0x081, 0x0cf,   /* [2] set contrast control */
  0x0d9, 0x0f1,   /* [2] pre-charge period 0x022/f1*/
  0x0db, 0x040,   /* vcomh deselect level */
  
  0x02e,        /* 2012-05-27: Deactivate scroll */ 
  0x0a4,        /* output ram to display */
#ifdef INVERT_DISPLAY
  0x0a7,        /* inverted display mode */
#else
  0x0a6,        /* none inverted normal display mode */
#endif
  //0x0af,      /* display on */
};

static uint8_t SH1106_display_on_seq[] = {
  0xaf
};

static uint8_t empty_page[SH1106_OLED::kPageSize];

void SH1106_OLED::Init() {
  // put OLED pins to a known state
  pinMode(OLED_CS, OUTPUT);
  pinMode(OLED_RST, OUTPUT);
  pinMode(OLED_DC, OUTPUT);

  // Initialize SPI transactions 

  // assert OLED reset
  digitalWriteFast(OLED_RST, HIGH);
  delay(1);
  digitalWriteFast(OLED_RST, LOW);
  delay(10);
  digitalWriteFast(OLED_RST, HIGH);

  // perform OLED initialization sequence
  digitalWriteFast(OLED_CS, OLED_CS_INACTIVE);			//! first disable the chip 
  digitalWriteFast(OLED_DC, LOW);						//! set command mode
  digitalWriteFast(OLED_RST, LOW);						//! assert OLED reset
  delay(20);											//! minimum reset low pulse with = (1*16)+2 milliseconds
  digitalWriteFast(OLED_RST, HIGH);						//! deassert OLED reset
  delay(20);											//! minimum reset recover time
  digitalWriteFast(OLED_CS, OLED_CS_ACTIVE);			//! now enable chip */
  SendBuffer(SH1106_init_seq, sizeof(SH1106_init_seq));	//! send OLED initialization commands
  digitalWriteFast(OLED_CS, OLED_CS_INACTIVE);			//! go inactive
  Clear();												//! clear the screen
}

void SH1106_OLED::Flush() {
	// TODO: add eventresponder / async transfer 
}

void SH1106_OLED::Clear() {
  memset(empty_page, 0, sizeof(kPageSize));

  SH1106_data_start_seq[2] = 0xb0 | 0;
  digitalWriteFast(OLED_DC, LOW);
  digitalWriteFast(OLED_CS, OLED_CS_ACTIVE);
  SendBuffer(SH1106_data_start_seq, sizeof(SH1106_data_start_seq));
  digitalWriteFast(OLED_DC, HIGH);
  for (size_t p = 0; p < kNumPages; ++p)
    SendBuffer(empty_page, kPageSize);
  digitalWriteFast(OLED_CS, OLED_CS_INACTIVE);

  digitalWriteFast(OLED_DC, LOW);
  digitalWriteFast(OLED_CS, OLED_CS_ACTIVE);
  SendBuffer(SH1106_display_on_seq, sizeof(SH1106_display_on_seq));
  digitalWriteFast(OLED_DC, HIGH);
}

void SH1106_OLED::SendPage(uint_fast8_t index, const uint8_t *data) {
  SH1106_data_start_seq[2] = 0xb0 | index;
  digitalWriteFast(OLED_DC, LOW);
  digitalWriteFast(OLED_CS, OLED_CS_ACTIVE);
  SendBuffer(SH1106_data_start_seq, sizeof(SH1106_data_start_seq));
  digitalWriteFast(OLED_DC, HIGH);
  SendBuffer(data, kPageSize );
  digitalWriteFast(OLED_CS, OLED_CS_INACTIVE);
}

inline void SH1106_OLED::SendBuffer(const uint8_t *data, size_t n) {

  uint8_t *buf = (uint8_t *)data;
  SPI.beginTransaction(SPISettings(30000000, MSBFIRST, SPI_MODE0));
    (void)SPI.transfer(buf, n);
  SPI.endTransaction();

}

void SH1106_OLED::AdjustOffset(uint8_t offset) {
  SH1106_data_start_seq[1] = offset; // lower 4 bits of col adr
}
