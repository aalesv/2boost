// This is an independent project of an individual developer. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

/*This file is part of 2Boost
*
*2Boost is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
*
*This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
*/

#include "macros.h"
#include "types.h"

#if defined(P_CEL_LIGHT_STATUS_OEM) && defined(ORIG_CEL_TRIGGER_OUTER_FUNCTION_ADDRESS)

//This function replaces original CEL flash outer function, Flash Hack #1
void celTrigger_hooked(void) ROM_CODE;

//This function sets CEL flash initial parameters but only if not flashing now
static inline void startFlash(uint8 celFlashOnCount, uint8 celFlashOffCount, uint8 celFlashCyclesCount) ROM_CODE;

//Main CEL flash function. Place it to the main loop.
static inline void celFlash(void) ROM_CODE;

extern void_fn_ptr celTrigger;
extern ram_variables_t *RAM_VARIABLES;
extern uint8 overtakeMapSwitch(void);
extern const uint8 CFG_CEL_FLASH_ENABLED;
extern const uint8 CFG_CEL_FLASH_OVERTAKE_ON;
extern const uint8 CFG_CEL_FLASH_OVERTAKE_OFF;
extern const uint8 CFG_CEL_FLASH_OVERTAKE_CYCLES;
extern const uint8 CFG_CEL_FLASH_FBKC_ON;
extern const uint8 CFG_CEL_FLASH_FBKC_OFF;
extern const uint8 CFG_CEL_FLASH_FBKC_CYCLES;
extern const float CFG_CEL_FLASH_FBKC_LIMIT;
extern const float CFG_CEL_FLASH_FBKC_LOAD_LIMIT;


#elif defined(P_CEL_LIGHT_STATUS_OEM) || defined(ORIG_CEL_TRIGGER_OUTER_FUNCTION_ADDRESS) //P_CEL_LIGHT_STATUS_OEM
 #error Both ORIG_CEL_TRIGGER_OUTER_FUNCTION_ADDRESS and P_CEL_LIGHT_STATUS_OEM must be defined
#endif //elif
