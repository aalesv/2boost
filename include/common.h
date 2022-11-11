// This is an independent project of an individual developer. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

/*This file is part of 2Boost
*
*2Boost is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
*
*This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
*/

#if defined(CRUISE_FLAG_IS_CRUISE_SYSTEM_STATE) && defined(CRUISE_FLAG_IS_BUTTON_FLAG)
#error Only one of CRUISE_FLAG_IS_CRUISE_SYSTEM_STATE and CRUISE_FLAG_IS_BUTTON_FLAG must be defined
#endif

#if !defined(CRUISE_FLAG_IS_CRUISE_SYSTEM_STATE) && !defined(CRUISE_FLAG_IS_BUTTON_FLAG)
#error CRUISE_FLAG_IS_CRUISE_SYSTEM_STATE or CRUISE_FLAG_IS_BUTTON_FLAG must be defined
#endif

#if defined(CRUISE_FLAG_IS_BUTTON_FLAG)
#pragma message "CRUISE_FLAG_IS_BUTTON_FLAG is defined"
#endif

#if defined(CRUISE_FLAG_IS_BUTTON_FLAG) && defined(P_CRUISE_BTN_SYSTEM_MASK_CRUISE_ENABLED) && defined(P_CRUISE_BTN_SYSTEM_MASK_CRUISE_DISABLED)
#error Only one of P_CRUISE_BTN_SYSTEM_MASK_CRUISE_ENABLED and P_CRUISE_BTN_SYSTEM_MASK_CRUISE_DISABLED must be defined
#endif

#if defined(CRUISE_FLAG_IS_BUTTON_FLAG) && !defined(P_CRUISE_BTN_SYSTEM_MASK_CRUISE_ENABLED) && !defined(P_CRUISE_BTN_SYSTEM_MASK_CRUISE_DISABLED)
#error P_CRUISE_BTN_SYSTEM_MASK_CRUISE_ENABLED or P_CRUISE_BTN_SYSTEM_MASK_CRUISE_DISABLED must be defined
#endif

#if defined(CRUISE_FLAG_IS_BUTTON_FLAG) && defined(P_CRUISE_BTN_SYSTEM_MASK_CRUISE_ENABLED)
#pragma message "P_CRUISE_BTN_SYSTEM_MASK_CRUISE_ENABLED is defined, using straight cruise logic"
#endif

#if defined(CRUISE_FLAG_IS_BUTTON_FLAG) && defined(P_CRUISE_BTN_SYSTEM_MASK_CRUISE_DISABLED)
#pragma message "P_CRUISE_BTN_SYSTEM_MASK_CRUISE_DISABLED is defined, using reverse cruise logic"
#endif

#if defined(CRUISE_FLAG_IS_CRUISE_SYSTEM_STATE)
#pragma message "CRUISE_FLAG_IS_CRUISE_SYSTEM_STATE is defined"
#endif

#if defined(CRUISE_FLAG_IS_CRUISE_SYSTEM_STATE) && defined(P_CRUISE_STATE_MASK_CRUISE_ENABLED) && defined(P_CRUISE_STATE_MASK_CRUISE_DISABLED)
#error Only one of P_CRUISE_STATE_MASK_CRUISE_ENABLED and P_CRUISE_STATE_MASK_CRUISE_DISABLED must be defined
#endif

#if defined(CRUISE_FLAG_IS_CRUISE_SYSTEM_STATE) && !defined(P_CRUISE_STATE_MASK_CRUISE_ENABLED) && !defined(P_CRUISE_STATE_MASK_CRUISE_DISABLED)
#error P_CRUISE_STATE_MASK_CRUISE_ENABLED or P_CRUISE_STATE_MASK_CRUISE_DISABLED must be defined
#endif

#if defined(P_CRUISE_STATE_MASK_CRUISE_ENABLED) && defined(CRUISE_FLAG_IS_CRUISE_SYSTEM_STATE)
#pragma message "P_CRUISE_STATE_MASK_CRUISE_ENABLED is defined, using straight cruise logic"
#endif

#if defined(P_CRUISE_STATE_MASK_CRUISE_DISABLED) && defined(CRUISE_FLAG_IS_CRUISE_SYSTEM_STATE)
#pragma message "P_CRUISE_STATE_MASK_CRUISE_DISABLED is defined, using reverse cruise logic"
#endif

#include "functions.h"

typedef struct {
	unsigned char prevCruiseBtnState;
	unsigned char boostHackEnable;
} ram_variables_t;

typedef struct {
	short x_len;
	short y_len;
	void *x_axis_ptr;
	void *y_axis_ptr;
	void *data_ptr;
	long data_type;
	float miltiplier;
	float offset;
} table_3d_t;

//ram_variables_t *RAM_VARIABLES = ((ram_variables_t*)RAM_HOLE);
extern ram_variables_t *RAM_VARIABLES;

/* If you want to use non-standard sized tables
 * that will be incompatible with existing definitions,
 * please set last two digits of version to something different from zero.
*/

static const char VERSION[] __attribute__((used)) __attribute__ ((aligned (0x200))) = "2Boost " CALID " 0001.02.00";
