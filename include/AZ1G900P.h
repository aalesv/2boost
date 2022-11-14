// This is an independent project of an individual developer. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

/*This file is part of 2Boost
*
*2Boost is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
*
*This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
*/

#define CALID "AZ1G900P"

#define ORIG_CALC_3D_FUNCTION_ADDRESS (0x000BE8F8)
#define ORIG_TABLE_TARGET_BOOST_ADRESS (0x00084BB4)

#define P_CRUISE_STATE_ADDRESS (0xFFFF6212) /* Cruise system flag variable RAM address */
#define P_CRUISE_STATE ((unsigned char*)P_CRUISE_STATE_ADDRESS)

/* 1st bit set when cruise enabled cleared when disabled */
#define P_CRUISE_STATE_MASK_CRUISE_ENABLED ((unsigned char)1)

//Where to place binary in ROM
//Not used in code, but needed by linker
#define ROM_HOLE (0x0008F000)
//RAM address for our variables
#define RAM_HOLE (0xFFFFA900)

/* Tables */

#define TBL_TARGET_BOOST2_X_AXIS {0.0, 100.0, 165.0, 190.0, 220.0, 250.0, 280.0, 300.0, 310.0, 320.0, 330.0}
#define TBL_TARGET_BOOST2_Y_AXIS {800, 1200, 1600, 2000, 2400, 2800, 3200, 3600, 4000, 4400, 4800, 5200, 5600, 6000, 6400}

#define TARGET_BOOST_X_COUNT 0xB
#define TARGET_BOOST_Y_COUNT 0xF

#include "common.h"
