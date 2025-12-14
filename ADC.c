#include "ADC.h"

#include <stdbool.h>
#include <stdint.h>

#include <MTV230M_XFR.h>
#include <MTV230M_XFR_bits.h>
#include <MTV230M_XFR_masks.h>


static uint8_t ADC_activeChannel = 0;

inline void ADC_Set(bool on) {
    if (on) ADCCTRL = ENADC;
    else ADCCTRL = 0;     
}

inline bool ADC_StartConversion(uint8_t channel) {
    switch (channel) {
        case 0: ADCCTRL = (ENADC | SADC0); break;
        case 1: ADCCTRL = (ENADC | SADC1); break;
        case 2: ADCCTRL = (ENADC | SADC2); break;
        case 3: ADCCTRL = (ENADC | SADC3); break;

        default: return false;
    }

    ADC_activeChannel = channel;
    return true;
}

inline uint8_t ADC_GetChannel() {
    return ADC_activeChannel;
}

inline uint8_t ADC_GetSample() {
    return ADCCONV;
}