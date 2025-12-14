#pragma once

#include <stdbool.h>
#include <stdint.h>

/** Turn the watchdog on. No option to turn it off afterwards. */
inline void Watchdog_Set();

/** Reset the watchdog timer */
inline void Watchdog_Pet();

/** Set watchdog interval. @param interval interval length from 1 to 8 in increments of 250 ms. */
inline void Watchdog_SetInterval(uint8_t interval);