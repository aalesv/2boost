// This is an independent project of an individual developer. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

/*This file is part of 2Boost
*
*2Boost is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
*
*This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
*/

#define CALID "AZ1G202G"

#define ORIG_CALC_3D_FUNCTION_ADDRESS (0x000BE8B8)

//Target Boost
#define ORIG_TABLE_TARGET_BOOST_ADDRESS (0x00086C50)

#define TABLE_TARGET_BOOST_X_COUNT 14
#define TABLE_TARGET_BOOST_Y_COUNT 14

#define TABLE_TARGET_BOOST_DATA_TYPE 0x8000000
#define TABLE_TARGET_BOOST_MULTIPLIER 1.0
#define TABLE_TARGET_BOOST_OFFSET 0

//Initial WGDC
#define ORIG_TABLE_INIT_WGDC_ADDRESS (0x86C34)

#define TABLE_INIT_WGDC_X_COUNT 11
#define TABLE_INIT_WGDC_Y_COUNT 10

#define TABLE_INIT_WGDC_DATA_TYPE 0x8000000
#define TABLE_INIT_WGDC_MULTIPLIER 0.00390625
#define TABLE_INIT_WGDC_OFFSET 0

//Max WGDC
#define ORIG_TABLE_MAX_WGDC_ADDRESS (0x86C18)

#define TABLE_MAX_WGDC_X_COUNT 11
#define TABLE_MAX_WGDC_Y_COUNT 10

#define TABLE_MAX_WGDC_DATA_TYPE 0x8000000
#define TABLE_MAX_WGDC_MULTIPLIER 0.00390625
#define TABLE_MAX_WGDC_OFFSET 0

//Primary Open Loop Fueling
#define ORIG_TABLE_PRIMARY_OL_A_ADDRESS (0x89024)

#define TABLE_PRIMARY_OL_X_COUNT 19
#define TABLE_PRIMARY_OL_Y_COUNT 18

#define TABLE_PRIMARY_OL_DATA_TYPE 0x4000000
#define TABLE_PRIMARY_OL_MULTIPLIER 0.0078125
#define TABLE_PRIMARY_OL_OFFSET 0

//Base Timing
#define ORIG_TABLE_BASE_TIMING_A_ADDRESS (0x00089BA0) //Base Timing Primary Cruise
#define ORIG_TABLE_BASE_TIMING_B_ADDRESS (0x00089BBC) //Base Timing Primary Non-Cruise
#define ORIG_TABLE_BASE_TIMING_C_ADDRESS (0x00089BD8) //Base Timing Reference Cruise (AVCS related)
#define ORIG_TABLE_BASE_TIMING_D_ADDRESS (0x00089BF4) //Base Timing Reference Non-Cruise (AVCS related) 

#define TABLE_BASE_TIMING_X_COUNT 19
#define TABLE_BASE_TIMING_Y_COUNT 18

#define TABLE_BASE_TIMING_DATA_TYPE 0x4000000
#define TABLE_BASE_TIMING_MULTIPLIER 0.3515625
#define TABLE_BASE_TIMING_OFFSET -20.0

//Intake AVCS
#define ORIG_TABLE_INTAKE_AVCS_A_ADDRESS (0x8B0F8) //Intake Cam Advance Angle Cruise
#define ORIG_TABLE_INTAKE_AVCS_B_ADDRESS (0x8B114) //Intake Cam Advance Angle Non-Cruise

#define TABLE_INTAKE_AVCS_X_COUNT 19
#define TABLE_INTAKE_AVCS_Y_COUNT 18

#define TABLE_INTAKE_AVCS_DATA_TYPE 0x8000000
#define TABLE_INTAKE_AVCS_MULTIPLIER 0.0054931641
#define TABLE_INTAKE_AVCS_OFFSET 0

//Exhaust AVCS
#define ORIG_TABLE_EXHAUST_AVCS_A_ADDRESS (0x8B1BC) //Exhaust Cam Advance Angle Cruise
#define ORIG_TABLE_EXHAUST_AVCS_B_ADDRESS (0x8B1D8) //Exhaust Cam Advance Angle Non-Cruise

#define TABLE_EXHAUST_AVCS_X_COUNT 19
#define TABLE_EXHAUST_AVCS_Y_COUNT 18

#define TABLE_EXHAUST_AVCS_DATA_TYPE 0x8000000
#define TABLE_EXHAUST_AVCS_MULTIPLIER 0.0054931641
#define TABLE_EXHAUST_AVCS_OFFSET 0

//Cruise state
#define P_CRUISE_STATE_ADDRESS (0xFFFF61BE) /* Cruise system flag variable RAM address */
#define P_CRUISE_STATE ((unsigned char*)P_CRUISE_STATE_ADDRESS)

/* 1st bit set when cruise enabled cleared when disabled */
#define P_CRUISE_STATE_MASK_CRUISE_ENABLED ((unsigned char)1)

//Si-Drive state
#define P_SI_DRVIE_STATE_ADDRESS (0xFFFF611E) /* SI-Drive system flag variable RAM address */
#define P_SI_DRVIE_STATE ((unsigned char*)P_SI_DRVIE_STATE_ADDRESS)

//RAM address for our variables
#define RAM_HOLE (0xFFFFA900)


