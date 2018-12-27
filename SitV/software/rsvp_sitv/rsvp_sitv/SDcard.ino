/*  RSVP - 
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

#include <SD.h>
#include <SPI.h>
const int sdCardSelect = BUILTIN_SDCARD;
Sd2Card card;
SdVolume volume;
SdFile root;
File sdFileDes;
bool sdPresent;

void SDcard_setup(void) {
    sdPresent = SD.begin(sdCardSelect);
    // N.B. if card hardware detect possible, pin change IRQ can set/reset sdPresent, etc.
    if (!sdPresent) {
      Serial.println("[ QuadroTeenia : RSVP : SD CARD : SDIO Driver FAILED! Card Inserted? ]");
    }
}

void sdListFiles() {
  Serial.println("-------------------");
    // Initialize SD Card
    // use SD library (SDcard chipselect, (optional) spi speed)
    //  sdPresent = SD.begin(sdCardSelect);
    sdPresent = card.init(SPI_FULL_SPEED, sdCardSelect);
    
    // N.B. if card hardware detect possible, pin change IRQ can set/reset sdPresent, etc.
    if (!sdPresent) {
      Serial.println("[ QuadroTeenia : RSVP : SD CARD : SDIO Driver FAILED! Card Inserted? ]");
    } else {
      // Now we will try to open the 'volume'/'partition' - it should be FAT16 or FAT32
      if (!volume.init(card)) {
        Serial.println("[ QuadroTeenia : RSVP : SD CARD : no FAT16/FAT32 partition found? ]");
        sdPresent = 0;
        return;
      }
      // open the root of the filesystem volume
      root.openRoot(volume);
      // list all files in the card with date and size
      root.ls(LS_R | LS_DATE | LS_SIZE);
      root.close();
    }
  Serial.println("-------------------");
}

void sdCatFile(char *filepath) {

  File myfile = SD.open(filepath, FILE_READ);
  if (myfile) 
  {
    while (myfile.available())
    {
      Serial.write(myfile.read());
    }
    myfile.close();
  }  
  // if the file cannot be opened give error report
  else {
      Serial.println("RSVP: Error : File Open");
  } 
}

void sdCardInfo() {
  Serial.println("-------------------");
    // Initialize SD Card
    // use SD library (SDcard chipselect, (optional) spi speed)
    //  sdPresent = SD.begin(sdCardSelect);
    sdPresent = card.init(SPI_FULL_SPEED, sdCardSelect);
    
    // N.B. if card hardware detect possible, pin change IRQ can set/reset sdPresent, etc.
    if (!sdPresent) {
      Serial.println("[ QuadroTeenia : RSVP : SD CARD : SDIO Driver FAILED! Card Inserted? ]");
    } else {
      Serial.println("SD Card Information");
      // print the type of card
      Serial.print("Card type: ");
      switch(card.type()) {
        case SD_CARD_TYPE_SD1:
          Serial.println("SD1");
        break;
        case SD_CARD_TYPE_SD2:
          Serial.println("SD2");
        break;
        case SD_CARD_TYPE_SDHC:
          Serial.println("SDHC");
        break;
        default:
          Serial.println("Unknown");
        break;
      }
      // print the type and size of the first FAT-type volume
      uint32_t volumesize;
      Serial.print("Volume type : FAT");
      Serial.println(volume.fatType(), DEC);
      volumesize = volume.blocksPerCluster();    // clusters are collections of blocks
      volumesize *= volume.clusterCount();       // we'll have a lot of clusters
      if (volumesize < 8388608ul) {
        Serial.print("Volume size (bytes): ");
        Serial.println(volumesize * 512);        // SD card blocks are always 512 bytes
      }
      Serial.print("Volume size (Kbytes): ");
      volumesize /= 2;
      Serial.println(volumesize);
      Serial.print("Volume size (Mbytes): ");
      volumesize /= 1024;
      Serial.println(volumesize);
    }
  Serial.println("-------------------");
}
