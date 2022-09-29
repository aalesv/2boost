// This is an independent project of an individual developer. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

/*This file is part of 2Boost
*
*2Boost is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
*
*This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
*/

#define CALID "A2WC420F"

#define ORIG_CALC_3D_FUNCTION_ADDRESS (0x00002110)
#define ORIG_TABLE_TARGET_BOOST_ADRESS (0x000598EC)

#define P_CRUISE_BTN_FLAG_AADDRESS (0xFFFFAF70) /* Cruise button flag variable RAM address */
#define P_CRUISE_BTN_FLAG ((unsigned char*)P_CRUISE_BTN_FLAG_AADDRESS)
/* Cruise flag reflects state of cruise control buttons - whether they are pressed or not */
#define CRUISE_FLAG_IS_BUTTON_FLAG

//Alternate cruise system status
#define P_CRUISE_STATE_AADDRESS (0xFFFFB0C6) /* Cruise system flag variable RAM address */
#define P_CRUISE_STATE ((unsigned char*)P_CRUISE_STATE_AADDRESS)
/* Cruise flag reflects status of cruise system - whether cruise mode is enabled or it is disabled*/
//#define CRUISE_FLAG_IS_CRUISE_SYSTEM_STATE

#define P_DEFOG_MASK ((unsigned char)0x20)
#define P_CRUISE_BTN_MASK_BUTTON_PRESSED ((unsigned char)0x1)
#define P_CRUISE_BTN_MASK_CRUISE_ENABLED ((unsigned char)0x80)
/* 4-th bit set when cruise disabled cleared when enabled */
#define P_CRUISE_STATE_MASK_CRUISE_DISABLED ((unsigned char)8)

/* Our variables */
#define ROM_HOLE (0x0007F000)
#define RAM_HOLE (0xFFFF9B00)

/* Tables */

#define TBL_TARGET_BOOST2_X_AXIS {0, 20, 30.0, 40.0, 50.0, 60.0, 70.0, 80.0}
#define TBL_TARGET_BOOST2_Y_AXIS {1200.0, 1600.0, 2000.0, 2400.0, 2600.0, 2800.0, 3000, 3200.0, 3400.0, 3600.0, 5200.0, 6800.0}

#define TARGET_BOOST_X_COUNT 8
#define TARGET_BOOST_Y_COUNT 12

#include "common.h"
