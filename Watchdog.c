#include "Watchdog.h"

#include <MTV230M_XFR.h>
#include <MTV230M_XFR_bits.h>
#include <MTV230M_XFR_masks.h>


inline void Watchdog_Set() {
    WDT = WDEN;
}

inline void Watchdog_Pet() {
    WDT = WDCLR;
}

inline void Watchdog_SetInterval(uint8_t interval) {
    if (interval < 1 || interval > 8)
        return; // illegal argument

    WDT = interval;
}