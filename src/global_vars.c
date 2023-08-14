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
volatile const char VERSION[] __attribute__((used)) = "2Boost " CALID " 0003.00.00";

volatile const char INFO[] __attribute__((used)) = "Compiled GCC " __VERSION__;

//Map switch source (no switching / cruise button / Si-Drive switch) option. Can be modified by tuner.
volatile const uint8 CFG_GLOBAL_MAP_SWITCH_SOURCE = MAP_SWITCH_SOURCE_NONE;

//MAF/SD blending mode, default no blending, SD only
volatile const uint8 CFG_MAF_SD_BLENDING = MAF_SD_BLENDING_OFF;

//Overtake button source (disabled/cruise cancel button) option. Can be modified by tuner.
volatile const uint8 CFG_OVERTAKE_BUTTON_SWITCH_SOURCE = OVERTAKE_BUTTON_SOURCE_NONE;

//Engine displacement, default 2.457 liters
volatile const float CFG_ENGINE_DISPLACEMENT = 2.457f;

//Minimum accelerator pedal value to activate Overtake button, precents
volatile const float CFG_OVERTAKE_BUTTON_MIN_ACCELERATOR_PEDAL_VALUE = 25.0f;

//Declare RAM variables and place them at RAM hole
ram_variables_t *RAM_VARIABLES = ((ram_variables_t*)RAM_HOLE);

//Calc 3D function is located at ORIG_CALC_3D_UINT_TO_FLOAT_FUNCTION_ADDRESS
//uint only
//Returns Z axis value converted to float
calc_3d_uint_to_float_t calc_3d_uint_to_float =
        ((calc_3d_uint_to_float_t)ORIG_CALC_3D_UINT_TO_FLOAT_FUNCTION_ADDRESS); //-V566

//Calc 2D function is located at ORIG_CALC_3D_UINT_TO_FLOAT_FUNCTION_ADDRESS
//uint only
//Returns Y axis value converted to float
calc_2d_uint_to_float_t calc_2d_uint_to_float = 
        ((calc_2d_uint_to_float_t)ORIG_CALC_2D_UINT_TO_FLOAT_FUNCTION_ADDRESS); //-V566

#if defined(ORIG_CALC_2D_FLOAT_TO_FLOAT_FUNCTION_ADDRESS)
//This calc 2D function is located at ORIG_CALC_2D_FLOAT_TO_FLOAT_FUNCTION_ADDRESS
//float only
//Returns Y axis float value without conversion
calc_2d_float_to_float_t calc_2d_float_to_float = 
        ((calc_2d_float_to_float_t)ORIG_CALC_2D_FLOAT_TO_FLOAT_FUNCTION_ADDRESS); //-V566
#endif
