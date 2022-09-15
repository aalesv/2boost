// This is an independent project of an individual developer. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

/*This file is part of 2Boost
*
*2Boost is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
*
*This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
*/

#define CALID "A8DH100P"

#define ORIG_CALC_3D_FUNCTION_ADDRESS (0x00002150)
#define ORIG_TABLE_TARGET_BOOST_ADRESS (0x00084350)

#define P_DEFOG_SWITCH_ADDRESS (0xFFFF6A43) /* Defog button state variable RAM address */
#define P_CRUISE_FLAG_AADDRESS (0xFFFF6508) /* Cruise button flag variable RAM address */

#define P_DEFOG_SWITCH ((unsigned char*)P_DEFOG_SWITCH_ADDRESS)
#define P_CRUISE_FLAG ((unsigned char*)P_CRUISE_FLAG_AADDRESS)
/* Cruise flag reflects state of cruise control buttons - whether they are pressed or not */
#define CRUISE_FLAG_IS_BUTTON_FLAG

#define P_DEFOG_MASK ((unsigned char)0x20)
#define P_CRUISE_MASK_BUTTON_PRESSED ((unsigned char)0x1)
#define P_CRUISE_MASK_CRUISE_ENABLED ((unsigned char)0x80)

/* Our variables */
#define ROM_HOLE (0x0008F000)
#define RAM_HOLE (0xFFFF9900)

/* Tables */
#define TBL_TARGET_BOOST2_X_AXIS {11.7, 19.5, 30.0, 40.0, 50.0, 60.0, 70.0, 80.0}
#define TBL_TARGET_BOOST2_Y_AXIS {800.0, 1200.0, 1600.0, 2000.0, 2400.0, 3200.0, 3600.0, 4400.0, 5600.0, 6000.0, 6400.0}

#define TARGET_BOOST_X_COUNT 8
#define TARGET_BOOST_Y_COUNT 11

#include "common.h"
