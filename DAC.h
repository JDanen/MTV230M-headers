/*
    Each PWM DAC output pulse width of the converter is controlled by an 8-bit register in XFR. The frequency
    of PWM clock is 47KHz or 94KHz, selected by PWMF. And the total duty cycle step of these DAC outputs is
    253 or 256, selected by DIV253. If DIV253=1, writing FDH/FEH/FFH to DAC register generates stable high
    output. If DIV253=0, the output will pulse low at least once even if content of the DAC register is FFH. Writing
    00H to DAC register generates stable low output.
*/


#pragma once

#include <stdbool.h>
#include <stdint.h>

/** Configure which DAC channels get connected to a pin
 *  @param pins each bit corresponds to an DAC channel. Upper nybble ignored.
 */
inline void DAC_AttachPins(uint8_t pins);

/** Set the duty cycle of a DAC channel.
 *  @param channel which channel to set (0-3)
 *  @param value duty cycle value
 *  @return true if params were legal and value was set, false otherwise
 */
inline bool DAC_SetPulseWidth(uint8_t channel, uint8_t value);

/** Getthe duty cycle of a DAC channel.
 *  @param channel which channel to set (0-3)
 *  @return duty cycle value of the channel
 */
inline uint8_t DAC_GetPulseWidth(uint8_t channel);

enum DAC_PWMFreq { 
    DAC_PWMFreq_47KHz = 0, 
    DAC_PWMFreq_94KHz = 1 
};
inline void DAC_SetPWMFreq(enum DAC_PWMFreq freq);

enum DAC_Resolution { 
    DAC_Resolution_256 = 0,
    DAC_Resolution_253 = 1
};
inline void DAC_SetResolution(enum DAC_Resolution res);

