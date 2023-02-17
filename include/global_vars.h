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

//Global variables, constants, etc.

//Version string
volatile const char VERSION[] ROM_METADATA;
//Map switch source (no switching / cruise button / Si-Srive switch) option. Can be modified by tuner.
volatile const unsigned char CFG_GLOBAL_MAP_SWITCH_SOURCE ROM_CONFIG;

//RAM variables.
ram_variables_t *RAM_VARIABLES ROM_DATA;

//Calc 3D function.
calc_3d_float_t calc_3d_float ROM_DATA;

