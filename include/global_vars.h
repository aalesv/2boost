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
//Date and time of compilation and compiler version
volatile const char INFO[] ROM_OTHER_DATA;

//Map switch source (no switching / cruise button / Si-Srive switch) option. Can be modified by tuner.
volatile const uint8 CFG_GLOBAL_MAP_SWITCH_SOURCE ROM_CONFIG;

//MAF/SD Blending mode, default to no blendig, SD only
volatile const uint8 CFG_MAF_SD_BLENDING ROM_CONFIG;

//Overtake button source (disabled/cruise cancel button) option. Can be modified by tuner.
volatile const uint8 CFG_OVERTAKE_BUTTON_SWITCH_SOURCE ROM_CONFIG;

//Engine displacement, default 2.457 liters
volatile const float CFG_ENGINE_DISPLACEMENT ROM_CONFIG;

//Minimum accelerator pedal value to activate Overtake button, precents
volatile const float CFG_OVERTAKE_BUTTON_MIN_ACCELERATOR_PEDAL_VALUE ROM_CONFIG;

//RAM variables.
ram_variables_t *RAM_VARIABLES ROM_DATA;

//Calc 3D function. uint only. Returns float.
calc_3d_uint_to_float_t calc_3d_uint_to_float ROM_DATA;

//Calc 2D function. uint only. Returns float.
calc_2d_uint_to_float_t calc_2d_uint_to_float ROM_DATA;

#if defined(ORIG_CALC_2D_FLOAT_TO_FLOAT_FUNCTION_ADDRESS)
//Calc 2D function. float only, no conversion.
calc_2d_float_to_float_t calc_2d_float_to_float ROM_DATA;
#endif

