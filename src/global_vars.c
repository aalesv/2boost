// This is an independent project of an individual developer. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

/*This file is part of 2Boost
*
*2Boost is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
*
*This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
*/

#include "global_vars.h"

//Version string
volatile const char VERSION[] __attribute__((used)) = "2Boost " CALID " 0002.01.00";
//Map switch source (no switching / cruise button / Si-Srive switch) option. Can be modified by tuner.
volatile const unsigned char CFG_GLOBAL_MAP_SWITCH_SOURCE = MAP_SWITCH_SOURCE_NONE;

//Declare RAM variables and place them at RAM hole
ram_variables_t *RAM_VARIABLES = ((ram_variables_t*)RAM_HOLE);

//Calc 3D function is located at ORIG_CALC_3D_FUNCTION_ADDRESS
calc_3d_float_t calc_3d_float = ((calc_3d_float_t)ORIG_CALC_3D_FUNCTION_ADDRESS); //-V566
