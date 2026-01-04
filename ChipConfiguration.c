#include "ChipConfiguration.h"

#include <stdint.h>
#include <stdbool.h>

#include <MTV230M_XFRs.h>
#include <MTV230M_XFR_bits.h>
#include <MTV230M_XFR_masks.h>

static struct {
    uint32_t PADMOD;
    uint8_t  OPTION;
} CC_cache = {0, 0};

inline uint32_t CC_GetPADMOD() {
    return CC_cache.PADMOD;
}
inline uint8_t CC_GetOPTION() {
    return CC_cache.OPTION;
}

inline void CC_WritePADMOD(uint32_t value) {
    CC_cache.PADMOD = value;
    PADMOD = value;
}

inline void CC_WriteOPTION(uint8_t value) {
    CC_cache.OPTION = value;
    OPTION = value;
}