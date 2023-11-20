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

//MAF/SD Blending mode, default to no blendig, SD only. Can be modified by tuner.
volatile const uint8 CFG_MAF_SD_BLENDING ROM_CONFIG;

//Overtake button source (disabled/cruise cancel button) option. Can be modified by tuner.
volatile const uint8 CFG_OVERTAKE_BUTTON_SWITCH_SOURCE ROM_CONFIG;

//Global CEL flash enable flag. Can be modified by tuner.
volatile const uint8 CFG_CEL_FLASH_ENABLED ROM_CONFIG;

//Overtake mode CEL on count
volatile const uint8 CFG_CEL_FLASH_OVERTAKE_ON ROM_CONFIG;

//Overtake mode CEL off count
volatile const uint8 CFG_CEL_FLASH_OVERTAKE_OFF ROM_CONFIG;

//Overtake mode CEL on/off cycles
volatile const uint8 CFG_CEL_FLASH_OVERTAKE_CYCLES ROM_CONFIG;

//FBKC CEL on count
volatile const uint8 CFG_CEL_FLASH_FBKC_ON ROM_CONFIG;

//FBKC mode CEL off count
volatile const uint8 CFG_CEL_FLASH_FBKC_OFF ROM_CONFIG;

//FBKC mode CEL on/off cycles
volatile const uint8 CFG_CEL_FLASH_FBKC_CYCLES ROM_CONFIG;

//FBKC limit that enables CEL flashing
volatile const float CFG_CEL_FLASH_FBKC_LIMIT ROM_CONFIG;

//Engine load limit that enables FBKC CEL flashing
volatile const float CFG_CEL_FLASH_FBKC_LOAD_LIMIT ROM_CONFIG;

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

#if defined(ORIG_CEL_TRIGGER_OUTER_FUNCTION_ADDRESS)
//CEL trigger outer function. Switches dashboard CEL on/off
void_fn_ptr celTrigger ROM_DATA;
#endif