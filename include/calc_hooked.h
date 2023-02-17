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

//Lookup table for 3D tables
//[][0] element contains orig table address
//[][1] element contains table 1 address
//[][2] element contains table 2 address
//[][3] element contains table 3 address
//Array of pointers
static const table_3d_float_t * const FLOAT_3D_LUT[][NUMBER_OF_TABLES+1] ROM_LUT;

//This function replaces original calc 3D table function
//x - X axis value
//y - Y axis value
//*tablePointer - pointer to structure that desctibes 3D table
//Returns Z axis value
float calc_3d_float_hooked (const float x, const float y, const table_3d_float_t *tablePointer) OPTIMIZE("O") ROM_CODE;

//Prevent LUT array overrun condition
//Function always will inlined
static inline unsigned char sanitizeLutSecondIndex (unsigned char index) ALWAYS_INLINE OPTIMIZE("O") ROM_CODE;

//Calc 3D function.
extern calc_3d_float_t calc_3d_float;

//RAM variables.
extern ram_variables_t *RAM_VARIABLES;

//What map to use
extern unsigned char globalMapSwitch();
