#include "HVSyncProcessor.h"

#include <stdint.h>
#include <stdbool.h>

#include <MTV230M_XFR.h>
#include <MTV230M_XFR_bits.h>
#include <MTV230M_XFR_masks.h>

bool Sync_HPresent() {
return (bool)(HVSTUS & Hpre);
}

bool Sync_VPresent() {
return (bool)(HVSTUS & Vpre);
}

bool Sync_CPresent() {
return (bool)(HVSTUS & CVpre);
}
bool Sync_HInverted() {
return (bool)(HVSTUS & Hoff);
}

bool Sync_VInverted() {
return (bool)(HVSTUS & Voff);
}

bool Sync_HPolarity() {
return (bool)(HVSTUS & Hpol);
}

bool Sync_VPolarity() {
    return (bool)(HVSTUS & Vpol);
}

uint8_t Sync_Status() {
    return HVSTUS;
} 

uint16_t Sync_HFreqRaw() {
    return HCNT;
}

uint16_t Sync_VFreqRaw() {
    return VCNT;
}


//////////////// OUTPUT

static struct {
    uint8_t HVCTR0;
    uint8_t HVCTR3;
    uint8_t HVINTEN;
} Sync_cache = {0};

void Sync_SetVBLANKSource(enum Sync_SetVBLANKSource sync) {
    Sync_cache.HVCTR0 &= ~(HVC1 | HVC0);
    Sync_cache.HVCTR0 |= (sync << 6);
    HVCTR0 = Sync_cache.HVCTR0;
}

void Sync_SetHBLANKPolarity(bool positive) {
    if (positive) Sync_cache.HVCTR0 &= ~HBpl;
    else          Sync_cache.HVCTR0 |=  HBpl;
    HVCTR0 = Sync_cache.HVCTR0;

}

void Sync_SetVBLANKPolarity(bool positive) {
    if (positive) Sync_cache.HVCTR0 &= ~VBpl;
    else          Sync_cache.HVCTR0 |=  VBpl;
    HVCTR0 = Sync_cache.HVCTR0;
}


void Sync_SetHBLANKInsert(bool yes) {
    if (yes) Sync_cache.HVCTR0 &= ~NoHins;
    else     Sync_cache.HVCTR0 |=  NoHins;
    HVCTR0 = Sync_cache.HVCTR0;
}

uint8_t Sync_GetConfig0() {
    return Sync_cache.HVCTR0;
}

//////////////// NEITHER
void Sync_ClearInterrupts(uint8_t flags) {
    HVINTFLG = flags;
}

uint8_t Sync_InterruptFlags() {
    return HVINTFLG;
}

inline void Sync_SetInterrupts(uint8_t interrupts) {
    Sync_cache.HVINTEN = interrupts;
    HVINTEN = interrupts;
}
inline uint8_t Sync_GetInterrupts() {
    return Sync_cache.HVINTEN;
}