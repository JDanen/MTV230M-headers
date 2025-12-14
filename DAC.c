#include "DAC.h"

#include <stdbool.h>
#include <stdint.h>

#include <MTV230M_XFR.h>
#include <MTV230M_XFR_bits.h>
#include <MTV230M_XFR_masks.h>

inline bool DAC_SetPulseWidth(uint8_t channel, uint8_t value) {
    switch (channel) {
        case 0: DA0 = value; break;
        case 1: DA1 = value; break;
        case 2: DA2 = value; break;
        case 3: DA3 = value; break;

        default: return false;
    }
    return true;
}

inline uint8_t DAC_SetPulseWidth(uint8_t channel) {
    switch (channel) {
        case 0: return DA0;
        case 1: return DA1;
        case 2: return DA2;
        case 3: return DA3;
    }
    return 0;
}
