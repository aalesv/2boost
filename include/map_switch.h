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

#if defined(P_CRUISE_STATE_MASK_CRUISE_ENABLED) && defined(P_CRUISE_STATE_MASK_CRUISE_DISABLED)
#error Only one of P_CRUISE_STATE_MASK_CRUISE_ENABLED and P_CRUISE_STATE_MASK_CRUISE_DISABLED must be defined
#endif

#if !defined(P_CRUISE_STATE_MASK_CRUISE_ENABLED) && !defined(P_CRUISE_STATE_MASK_CRUISE_DISABLED)
#error P_CRUISE_STATE_MASK_CRUISE_ENABLED or P_CRUISE_STATE_MASK_CRUISE_DISABLED must be defined
#endif

#if defined(P_CRUISE_STATE_MASK_CRUISE_ENABLED)
#pragma message "P_CRUISE_STATE_MASK_CRUISE_ENABLED is defined, using straight cruise logic"
#endif

#if defined(P_CRUISE_STATE_MASK_CRUISE_DISABLED)
#pragma message "P_CRUISE_STATE_MASK_CRUISE_DISABLED is defined, using reverse cruise logic"
#endif

//Returns 0 if must use original ROM map, 1 if must use 1st map, 2 if must use 2nd map, 3 if must use 3d map, 4 if must use 4th map
uint8 globalMapSwitch(void) ROM_CODE;
//Returns 1 if cruise is enabled, 0 otherwise
#if !defined(BUILD_TESTS)
static inline
#endif
uint8 cruiseStateEnabled (void) ROM_CODE;
//Returns 1 if I, 2 if S, 3 if S#, 0 otherwise
#if !defined(BUILD_TESTS)
static inline
#endif
uint8 siDriveState (void) ROM_CODE;
//Returns map switch source defined in MAP_SWITCH_SOURCE enum
//As function will always be inlined, do not specify linker section and it will be stripped
static inline uint8 globalMapSwitchSource (void) ROM_CODE;

//Returns 1 if overtake button conditions met, and 0 otherwise
#if !defined(BUILD_TESTS)
static inline
#endif
uint8 overtakeMapConditionsMet(void) ROM_CODE;
//Returns overtake map number
static inline uint8 overtakeMapNumber(void) ROM_CODE;
//Returns overtake map column number if overtake conditions are met and 0 otherwise
uint8 overtakeMapSwitch(void) ROM_CODE;
//Returns 1 if cruise cancel button is pressed, 0 otherwise
#if !defined(BUILD_TESTS)
static inline
#endif
uint8 cruiseCancelPressed(void) ROM_CODE;
//Returns 1 if brake pedal is pressed, 0 otherwise
#if !defined(BUILD_TESTS)
static inline
#endif
uint8 brakePedalPressed(void) ROM_CODE;

extern uint8 CFG_GLOBAL_MAP_SWITCH_SOURCE;
extern uint8 CFG_OVERTAKE_BUTTON_SWITCH_SOURCE;
extern float CFG_OVERTAKE_BUTTON_MIN_ACCELERATOR_PEDAL_VALUE;
extern ram_variables_t *RAM_VARIABLES;
