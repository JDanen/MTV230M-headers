/*
    The MTV230M is equipped with four 6-bit A/D converters. The refresh rate for the ADC is OSC freq./12288.
    The ADC compares the input pin voltage with internal VDD*N/64 voltage (where N = 0 - 63). 
    The ADC output value is N when pin voltage is greater than VDD*N/64 and smaller than VDD*(N+1)/64.

    WARNING: The author of this library has no idea what may happen if conversions are started without
            enabling the ADC. Proceed at your own peril. 

    WARNING: The functions here do not check with the pin configuration, you'll have to handle that on your own.
*/

#pragma once
#include <stdint.h>

#define F_ADC ((F_CPU) / 12288U)

inline void ADC_Set(bool on);

/** Start conversion, if enabled. @param channel from 0 to 3. @returns whether the sample could be started. */
bool ADC_StartConversion(uint8_t channel);
/** Which channel was last conversion started on */
uint8_t ADC_GetChannel();
/** @return result of the last conversion */
uint8_t ADC_GetSample();





