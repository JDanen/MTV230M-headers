 
#pragma once

#include <stdbool.h>
#include <stdint.h>

//////////////// INPUT

/** @return true if input HSync is present and higher than 10 KHz */
inline bool Sync_HPresent();

/** @return true if input VSync is present.
 *  @note VSync presence has hysteresis - appears if over 40 Hz, disappears if
 * falls below 10 Hz
 */
inline bool Sync_VPresent();

/** @return true if CSync is detected on HSync input */
inline bool Sync_CPresent();

/** @return true if HSync off level is high */
inline bool Sync_HInverted();

/** @return true if VSync off level is high */
inline bool Sync_VInverted();

/** @return true if HSync is positive, false if negative */
inline bool Sync_HPolarity();

/** @return true if HSync is positive, false if negative */
inline bool Sync_VPolarity();

/** @return the contents of HVSTUS byte. Mask with offsets from MTV230M_XFR_bits.h to get the specifics */
inline uint8_t Sync_Status(); 

/** @return HSync frequency in counts (see datasheet) */
inline uint16_t Sync_HFreqRaw();

/** @return VSync frequency in counts (see datasheet) */
inline uint16_t Sync_VFreqRaw();

//////////////// OUTPUT
/** @return cached contents of HVCTR0 */
inline uint8_t Sync_GetConfig0();

enum Sync_VBLANKSource { 
    Sync_VBLANKSource_Off =     0b00,
    Sync_VBLANKSource_Auto =    0b01,
    Sync_VBLANKSource_VSync =   0b10,
    Sync_VBLANKSource_CSync =   0b11
};
void Sync_SetVBLANKSource(enum Sync_SetVBLANKSource sync);
void Sync_SetHBLANKPolarity(bool positive);
void Sync_SetVBLANKPolarity(bool positive);

void Sync_SetHBLANKInsert(bool yes);

//////////////// NEITHER
/** Clear the H/V Sync Processor interrupt flags
 *  @param flags which interrupts to clear. Values from MTV230M_XFR_bits.h can
 * be used.
 */
void Sync_ClearInterrupts(uint8_t flags);

/** @return state of H/V Sync Processor interrupt flags. Mask with offsets from
 * MTV230M_XFR_bits.h to get specific.*/
uint8_t Sync_InterruptFlags();

/** Enable the H/V Sync interrupts specified in the parameter and disable all others */
inline void Sync_SetInterrupts(uint8_t interrupts);
inline uint8_t Sync_GetInterrupts();