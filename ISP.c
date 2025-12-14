#include "ISP.h"

#include <MTV230M_XFR.h>
#include <MTV230M_XFR_bits.h>
#include <MTV230M_XFR_masks.h>

static uint8_t ISP_SlaveAddress = 0x3E;

static inline void ISP_DisableInterrupts();
static inline void ISP_EnterIdle();

inline bool ISP_SetSlaveAddress(uint8_t address) {
    if (address & ~ISPSLV_MASK)
        return false;

    ISP_SlaveAddress = address;
    ISPSLV = ISP_SlaveAddress;
    return true;    
}
inline uint8_t ISP_GetSlaveAddress() {
    return ISP_SlaveAddress;
}
/** Enter ISP mode */
inline void ISP_Enter() {
    Watchdog_Pet();
    ISP_DisableInterrupts();   
    ISPEN = 0x93;  // Magic constant to enter ISP mode  
    ISP_EnterIdle();
}