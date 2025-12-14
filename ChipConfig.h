#pragma once 

#include <stdbool.h>
#include <stdint.h>

enum IIC_Freq {
    IIC_Freq_50KHz =  0b01,
    IIC_Freq_100KHz = 0b00,
    IIC_Freq_200KHz = 0b10,
    IIC_Freq_400KHz = 0b11
};

void IIC_SetMasterFreq(enum IIC_Freq freq);