#pragma once 

#include <stdbool.h>
#include <stdint.h>

#pragma once

#include <stdint.h>
#include <stdbool.h>

/** Get the cached contents of the PADMOD register.
 *  (cached because the register is write-only)
 */
inline uint32_t CC_GetPADMOD();
/** Get the cached contents of the OPTION register.
 *  (cached because the register is write-only)
 */
inline uint8_t CC_GetOPTION();

/** Write value to PADMOD */
inline void CC_WritePADMOD(uint32_t value);
/** Write value to OPTION */
inline void CC_WriteOPTION(uint8_t option);



