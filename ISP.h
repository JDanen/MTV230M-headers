#pragma once

#include <stdint.h>
#include <stdbool.h>

/** Set address to which the controller will respond in ISP mode.
 * @param address I2C address in the form 0bxxxxxx00
 * @return true if address was valid and could be set, false otherwise
 */
inline bool ISP_SetSlaveAddress(uint8_t address);
inline uint8_t ISP_GetSlaveAddress();
/** Enter ISP mode. Only way back out is reset. */
inline void ISP_Enter();

