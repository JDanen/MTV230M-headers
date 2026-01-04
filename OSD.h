#pragma once

#include <stdbool.h>
#include <stdint.h>

const uint8_t OSD_ROW_COUNT = 15;
const uint8_t OSD_COL_COUNT = 30;
const uint8_t OSD_POS_SAME = UINT8_MAX; /** Pass this value to OSD_SetAdress to only change one coordinate */

const uint16_t OSD_SYMBOL_COUNT = 496;
const uint8_t  OSD_RGBSYM_COUNT = 16;

enum OSD_Colors { 
    OSD_RED     = 0b100,
    OSD_GREEN   = 0b010,
    OSD_BLUE    = 0b001,

    OSD_CYAN    = OSD_GREEN | OSD_BLUE,
    OSD_MAGENTA = OSD_RED   | OSD_BLUE,
    OSD_YELLOW  = OSD_RED   | OSD_BLUE,

    OSD_WHITE   = OSD_RED | OSD_GREEN | OSD_BLUE,
    OSD_BLACK   = 0 /* transparent for background */
};


/*
    To program ADDRESS bytes and ATTRIBUTE bytes of the display RAM:
Step 1. Write data into OSDRA to determine the programming row address of the
display RAM. And define whether it is the row address of ADDRESS byte (bit7-bit6
= “0, 0”) or ATTRIBUTE byte (bit7-bit6 = “0, 1”). Step 2. Write data into OSDCA
to determine the programming column address of the display RAM. Step 3. Write to
OSDDT0 or OSDDT1 the address or attribute of the character to be displayed on
the screen. Step 4. Post increment operation is executed in the OSDCA (i.e.
OSDCA ← OSDCA + 1) to make it point to the next display RAM location. Overflow
of the OSDCA, i.e. overflow from 31, makes itself return to 0 and makes post
increment operation executed in the OSDRA (i.e. OSDRA ← OSDRA + 1). Overflow of
the OSDRA, i.e. overflow from 15, makes itself return to 0
*/

inline void OSD_WriteToCurrent(uint16_t val);
inline void OSD_SetAddress(uint8_t row, uint8_t col, bool attrib);

