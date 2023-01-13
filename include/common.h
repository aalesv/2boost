// This is an independent project of an individual developer. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

/*This file is part of 2Boost
*
*2Boost is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
*
*This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
*/

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

//Returns 1 if Cruise is enabled, 0 if disabled
char pCruiseStateEnabled();
//Returns 0 if must use 1st map, 1 if must use 2nd map
char globalMapSwitch();

//Type def for our global variables
typedef struct {
	//0 if must use 1st map, 1 if must use 2nd map
	unsigned char globalMapSwitch;
} ram_variables_t;

//Type def for 3D table
typedef struct {
	short x_len;
	short y_len;
	void *x_axis_ptr;
	void *y_axis_ptr;
	void *data_ptr;
	long data_type;
	float multiplier;
	float offset;
} table_3d_t;

//Type for calc 3D fuction
typedef float (*calc_3d_t)(float, float, const table_3d_t *);

//Calc 3D function. Address is set in boost_switch_cruise.c
calc_3d_t calc_3d;

//RAM variables. Address is set in boost_switch_cruise.c
ram_variables_t *RAM_VARIABLES;

//This function replaces original calc 3D table function
float boost_switch_hack (const float x, const float y, const table_3d_t *tablePointer) __attribute__((optimize("O")));
//Returns 0 if must use 1st map, 1 if must use 2nd map
char globalMapSwitch() __attribute__((optimize("O")));
//Returns 1 if cruise is enabled, 0 otherwise
char pCruiseStateEnabled () __attribute__((optimize("O")));

/* If you want to use non-standard sized tables
 * that will be incompatible with existing definitions,
 * please set last two digits of version to something different from zero.
*/

static const char VERSION[] __attribute__((used)) __attribute__ ((aligned (0x200))) = "2Boost " CALID " 0001.04.00";
//Needed for definitions compatibility since version 1.04 . Remove in ver 2
static const int COMPAT_FILL __attribute__((used)) = 0xDEADBEEF;
