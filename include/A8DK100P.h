// This is an independent project of an individual developer. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

/*This file is part of 2Boost
*
*2Boost is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
*
*This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
*/

#define CALID "A8DK100P"

#define ORIG_CALC_3D_FUNCTION_ADDRESS (0x00002160)
#define ORIG_TABLE_TARGET_BOOST_ADRESS (0x0008996C)

#define P_CRUISE_STATE_ADDRESS (0xFFFF66DA) /* Cruise system flag variable RAM address */
#define P_CRUISE_STATE ((unsigned char*)P_CRUISE_STATE_ADDRESS)

/* 4-th bit set when cruise disabled cleared when enabled */
#define P_CRUISE_STATE_MASK_CRUISE_DISABLED ((unsigned char)8)

//Where to place binary in ROM
//Not used in code, but needed by linker
#define ROM_HOLE (0x0008F000)
//RAM address for our variables
#define RAM_HOLE (0xFFFF9900)

/* Tables */

#define TBL_TARGET_BOOST2_X_AXIS {11.7, 19.5, 30.0, 40.0, 50.0, 60.0, 70.0, 80.0}
#define TBL_TARGET_BOOST2_Y_AXIS {800, 1200, 1600, 2000, 2400, 3200, 3600, 4400, 5600, 6000, 6400}

#define TARGET_BOOST_X_COUNT 8
#define TARGET_BOOST_Y_COUNT 11

#include "common.h"
