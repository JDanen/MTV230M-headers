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

