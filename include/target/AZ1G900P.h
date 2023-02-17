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

//Target Boost
#define ORIG_TABLE_TARGET_BOOST_ADDRESS (0x00084BB4)

#define TABLE_TARGET_BOOST_X_COUNT 11
#define TABLE_TARGET_BOOST_Y_COUNT 15

#define TABLE_TARGET_BOOST_DATA_TYPE 0x8000000
#define TABLE_TARGET_BOOST_MULTIPLIER 1.0
#define TABLE_TARGET_BOOST_OFFSET 0

//Initial WGDC
#define ORIG_TABLE_INIT_WGDC_ADDRESS (0x84B98)

#define TABLE_INIT_WGDC_X_COUNT 15
#define TABLE_INIT_WGDC_Y_COUNT 13

#define TABLE_INIT_WGDC_DATA_TYPE 0x8000000
#define TABLE_INIT_WGDC_MULTIPLIER 0.00390625
#define TABLE_INIT_WGDC_OFFSET 0

//Max WGDC
#define ORIG_TABLE_MAX_WGDC_ADDRESS (0x084B7C)

#define TABLE_MAX_WGDC_X_COUNT 15
#define TABLE_MAX_WGDC_Y_COUNT 13

#define TABLE_MAX_WGDC_DATA_TYPE 0x8000000
#define TABLE_MAX_WGDC_MULTIPLIER 0.00390625
#define TABLE_MAX_WGDC_OFFSET 0

//Primary Open Loop Fueling
#define ORIG_TABLE_PRIMARY_OL_A_ADDRESS (0x86FB8)

#define TABLE_PRIMARY_OL_X_COUNT 15
#define TABLE_PRIMARY_OL_Y_COUNT 18

#define TABLE_PRIMARY_OL_DATA_TYPE 0x4000000
#define TABLE_PRIMARY_OL_MULTIPLIER 0.0078125
#define TABLE_PRIMARY_OL_OFFSET 0

//Base Timing
#define ORIG_TABLE_BASE_TIMING_A_ADDRESS (0x00087B64) //Base Timing Primary Cruise
#define ORIG_TABLE_BASE_TIMING_B_ADDRESS (0x00087B80) //Base Timing Primary Non-Cruise
#define ORIG_TABLE_BASE_TIMING_C_ADDRESS (0x00087B9C) //Base Timing Reference Cruise (AVCS related)
#define ORIG_TABLE_BASE_TIMING_D_ADDRESS (0x00087BB8) //Base Timing Reference Non-Cruise (AVCS related)

#define TABLE_BASE_TIMING_X_COUNT 15
#define TABLE_BASE_TIMING_Y_COUNT 18

#define TABLE_BASE_TIMING_DATA_TYPE 0x4000000
#define TABLE_BASE_TIMING_MULTIPLIER 0.3515625
#define TABLE_BASE_TIMING_OFFSET -20.0

//Intake AVCS
#define ORIG_TABLE_INTAKE_AVCS_A_ADDRESS (0x88FE0) //Intake Cam Advance Angle Cruise
#define ORIG_TABLE_INTAKE_AVCS_B_ADDRESS (0x88FFC) //Intake Cam Advance Angle Non-Cruise

#define TABLE_INTAKE_AVCS_X_COUNT 15
#define TABLE_INTAKE_AVCS_Y_COUNT 16

#define TABLE_INTAKE_AVCS_DATA_TYPE 0x8000000
#define TABLE_INTAKE_AVCS_MULTIPLIER 0.0054931641
#define TABLE_INTAKE_AVCS_OFFSET 0

//Target Throttle Plate Position
#define ORIG_TABLE_TARGET_THROTTLE_POSITION_A_ADDRESS (0x000888F4) //Target Throttle Plate Position Cruise
#define ORIG_TABLE_TARGET_THROTTLE_POSITION_B_ADDRESS (0x00088910) //Target Throttle Plate Position Non-Cruise

#define TABLE_THROTTLE_POSITION_X_COUNT 16
#define TABLE_THROTTLE_POSITION_Y_COUNT 16

#define TABLE_THROTTLE_POSITION_DATA_TYPE 0x8000000
#define TABLE_THROTTLE_POSITION_MULTIPLIER 0.0019073486
#define TABLE_THROTTLE_POSITION_OFFSET 0

//Cruise state
#define P_CRUISE_STATE_ADDRESS (0xFFFF6212) /* Cruise system flag variable RAM address */
#define P_CRUISE_STATE ((unsigned char*)P_CRUISE_STATE_ADDRESS)

/* 1st bit set when cruise enabled cleared when disabled */
#define P_CRUISE_STATE_MASK_CRUISE_ENABLED ((unsigned char)1)

//RAM address for our variables
#define RAM_HOLE (0xFFFFA900)


