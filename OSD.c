#include <OSD.h>

#include <stdbool.h>
#include <stdint.h>

#include <MTV230M_XFR.h>
#include <MTV230M_XFR_bits.h>
#include <MTV230M_XFR_masks.h>

struct {
    uint8_t OSDRA;
    uint8_t OSDCA;    
} OSD_cache = {0};

/** @brief Write to current character cell
 *  The character cell address will autoincrement after write.
 *  Value is not checked, that's on you.
 *  
 *  @param val - value to write. 9-bit, when writing character value, 8-bit otherwise.
 */
inline void OSD_WriteToCurrent(uint16_t val) {
    if (val & 0xFF00) // if 
        OSDDT1 = (val & 0xFF);
    else
        OSDDT0 = (val & 0xFF);

    if (++OSD_cache.OSDCA >= OSD_COL_COUNT) {
        if (++OSD_cache.OSDRA >= OSD_ROW_COUNT)
            OSD_cache.OSDRA  = 0;

        OSD_cache.OSDCA = 0;
    }
}

/** @brief Select which character cell to write to
 *  @warning Inputs are not checked, that's your duty.   
 *  @param row - duh. Max value - OSD_ROW_COUNT - 1
 *  @param col - duh. Max value - OSD_COL_COUNT - 1
 *  @param attrib - if true, will write character cell attributes, otherwise will write character values
 */
inline void OSD_SetAddress(uint8_t row, uint8_t col, bool attrib) {
    if (row != OSD_POS_SAME) {
        OSDRA = row | (attrib? A0 : 0);
        OSD_cache.OSDRA = row;
    }

    if (col != OSD_POS_SAME) {
        OSDCA = col | (attrib? A0 : 0);
        OSD_cache.OSDCA = col;
    }
}