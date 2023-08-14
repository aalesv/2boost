// This is an independent project of an individual developer. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

/*This file is part of 2Boost
*
*2Boost is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
*
*This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
*/

#define CALID "A8DH100P"

//Calc 3D function ROM address.
//X     - float
//Y     - float
//Data  - uint only.
//Converts to float.
#define ORIG_CALC_3D_UINT_TO_FLOAT_FUNCTION_ADDRESS (0x00002150)

//Calc 2D function ROM address.
//X     - float
//Data  - float only.
//No conversion, returns float
#define ORIG_CALC_2D_FLOAT_TO_FLOAT_FUNCTION_ADDRESS (0x0000209C)

//Calc 2D function ROM address.
//X     - float
//Data  - uint only.
//Converts to float.
#define ORIG_CALC_2D_UINT_TO_FLOAT_FUNCTION_ADDRESS ORIG_CALC_2D_FLOAT_TO_FLOAT_FUNCTION_ADDRESS

//3D Tables

//Target Boost
#define ORIG_TABLE_TARGET_BOOST_ADDRESS (0x00084350)

#define TABLE_TARGET_BOOST_X_COUNT 8
#define TABLE_TARGET_BOOST_Y_COUNT 11

#define TABLE_TARGET_BOOST_DATA_TYPE 0x8000000
#define TABLE_TARGET_BOOST_MULTIPLIER 1.0f
#define TABLE_TARGET_BOOST_OFFSET 0

//Initial WGDC
#define ORIG_TABLE_INIT_WGDC_ADDRESS (0x842A8)

#define TABLE_INIT_WGDC_X_COUNT 8
#define TABLE_INIT_WGDC_Y_COUNT 8

#define TABLE_INIT_WGDC_DATA_TYPE 0x8000000
#define TABLE_INIT_WGDC_MULTIPLIER 0.00390625f
#define TABLE_INIT_WGDC_OFFSET 0

//Max WGDC
#define ORIG_TABLE_MAX_WGDC_ADDRESS (0x842E0)

#define TABLE_MAX_WGDC_X_COUNT 8
#define TABLE_MAX_WGDC_Y_COUNT 8

#define TABLE_MAX_WGDC_DATA_TYPE 0x8000000
#define TABLE_MAX_WGDC_MULTIPLIER 0.00390625f
#define TABLE_MAX_WGDC_OFFSET 0

//Primary Open Loop Fueling
#define ORIG_TABLE_PRIMARY_OL_A_ADDRESS (0x85B9C)

#define TABLE_PRIMARY_OL_X_COUNT 15
#define TABLE_PRIMARY_OL_Y_COUNT 18

#define TABLE_PRIMARY_OL_DATA_TYPE 0x4000000
#define TABLE_PRIMARY_OL_MULTIPLIER 0.0078125f
#define TABLE_PRIMARY_OL_OFFSET 0

//Base Timing
#define ORIG_TABLE_BASE_TIMING_A_ADDRESS (0x000863A8)

#define TABLE_BASE_TIMING_X_COUNT 15
#define TABLE_BASE_TIMING_Y_COUNT 18

#define TABLE_BASE_TIMING_DATA_TYPE 0x4000000
#define TABLE_BASE_TIMING_MULTIPLIER 0.3515625f
#define TABLE_BASE_TIMING_OFFSET -20.0

//Intake AVCS
#define ORIG_TABLE_INTAKE_AVCS_A_ADDRESS (0x871C8)

#define TABLE_INTAKE_AVCS_X_COUNT 15
#define TABLE_INTAKE_AVCS_Y_COUNT 16

#define TABLE_INTAKE_AVCS_DATA_TYPE 0x8000000
#define TABLE_INTAKE_AVCS_MULTIPLIER 0.0054931641f
#define TABLE_INTAKE_AVCS_OFFSET 0

//Target Throttle Plate Position
//Target Throttle Plate Position B map in this ROM is Maximum Target Throttle Plate Position, ignore it
#define ORIG_TABLE_TARGET_THROTTLE_POSITION_A_ADDRESS (0x00086C38)

#define TABLE_THROTTLE_POSITION_X_COUNT 17
#define TABLE_THROTTLE_POSITION_Y_COUNT 16

#define TABLE_THROTTLE_POSITION_DATA_TYPE 0x8000000
#define TABLE_THROTTLE_POSITION_MULTIPLIER 0.0019073486f
#define TABLE_THROTTLE_POSITION_OFFSET 0

//2D tables

//Throttle Tip-in Enrichment
#define ORIG_TABLE_THROTTLE_TIP_IN_ENRICHMENT_A_ADDRESS (0x000858C4)

#define TABLE_THROTTLE_TIP_IN_X_COUNT 18

#define TABLE_THROTTLE_TIP_IN_DATA_TYPE 0x800
#define TABLE_THROTTLE_TIP_IN_MULTIPLIER 4.0f
#define TABLE_THROTTLE_TIP_IN_OFFSET 0

//Speed Density

//MAF table address
#define ORIG_TABLE_MAF_ADDRESS (0x00086D94)

//Manifold absolute pressure address
//SSM Routine P7
#define P_MANIFOLD_PRESSURE_ADDRESS (0xFFFF66F4)
//Manifold absolute pressure, mmHg
#define P_MANIFOLD_PRESSURE ((float*)P_MANIFOLD_PRESSURE_ADDRESS)

//Engine speed address
//SSM Routine P8
#define P_ENGINE_SPEED_ADDRESS (0xFFFF6A74)
//Engine speed, RPM
#define P_ENGINE_SPEED ((float*)P_ENGINE_SPEED_ADDRESS)

//Intake air temperature address
//SSM Routine P11
#define P_IAT_ADDRESS (0xFFFF5C9C)
//Intake air temperature, Celsius
#define P_IAT ((float*)P_IAT_ADDRESS)

//Throttle plate angle change address
//Tip-in routine
#define P_THROTTLE_ANGLE_CHANGE_ADDRESS (0xFFFF67A0)
//Throttle plate angle change, degrees
#define P_THROTTLE_ANGLE_CHANGE ((float*)P_THROTTLE_ANGLE_CHANGE_ADDRESS)

//Enable Speed Density
#define SPEED_DENSITY

//Cruise state
#define P_CRUISE_STATE_ADDRESS (0xFFFF6662) /* Cruise system flag variable RAM address */
#define P_CRUISE_STATE ((unsigned char*)P_CRUISE_STATE_ADDRESS)

/* 3rd bit set when cruise disabled cleared when enabled */
#define P_CRUISE_STATE_MASK_CRUISE_DISABLED ((unsigned char)8)

//Overtake Button

//Cruise Cancel switch
//SSM Routine S154
#define P_CRUISE_CANCEL_SWITCH_ADDRESS (0xFFFF650B)
#define P_CRUISE_CANCEL_SWITCH ((unsigned char*)P_CRUISE_CANCEL_SWITCH_ADDRESS)
//Cruise Cancel switch mask
#define P_CRUISE_CANCEL_SWITCH_MASK (0x40)

//Accelerator pedal angle
//SSM Routine P30
#define P_ACCELERATOR_PEDAL_ANGLE_ADDRESS (0xFFFF6938)
#define P_ACCELERATOR_PEDAL_ANGLE ((float *)P_ACCELERATOR_PEDAL_ANGLE_ADDRESS)

//RAM address for our variables
#define RAM_HOLE (0xFFFF9900)


