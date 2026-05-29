// This is an independent project of an individual developer. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

/*This file is part of 2Boost
*
*2Boost is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
*
*This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
*/

#define CALID "ZA1JA02G"

//Calc 3D function ROM address.
//X     - float
//Y     - float
//Data  - uint only.
//Converts to float.
#define ORIG_CALC_3D_UINT_TO_FLOAT_FUNCTION_ADDRESS (0x0001140C)

//Calc 2D function ROM address.
//X     - float
//Data  - float only.
//No conversion, returns float
#define ORIG_CALC_2D_FLOAT_TO_FLOAT_FUNCTION_ADDRESS (0x00011388)

//Calc 2D function ROM address.
//X     - float
//Data  - uint only.
//Converts to float.
#define ORIG_CALC_2D_UINT_TO_FLOAT_FUNCTION_ADDRESS ORIG_CALC_2D_FLOAT_TO_FLOAT_FUNCTION_ADDRESS

//3D Tables

//Primary Open Loop Fueling
#define ORIG_TABLE_PRIMARY_OL_A_ADDRESS (0x000B5854)

#define TABLE_PRIMARY_OL_X_COUNT 17
#define TABLE_PRIMARY_OL_Y_COUNT 23

#define TABLE_PRIMARY_OL_DATA_TYPE 0x4000000
#define TABLE_PRIMARY_OL_MULTIPLIER 0.0078125f
#define TABLE_PRIMARY_OL_OFFSET 0

//Base Timing
#define ORIG_TABLE_BASE_TIMING_A_ADDRESS (0x000B6C2C) //Base Timing Primary Cruise
#define ORIG_TABLE_BASE_TIMING_B_ADDRESS (0x000B6C48) //Base Timing Primary Non-Cruise

#define TABLE_BASE_TIMING_X_COUNT 20
#define TABLE_BASE_TIMING_Y_COUNT 23

#define TABLE_BASE_TIMING_DATA_TYPE 0x4000000
#define TABLE_BASE_TIMING_MULTIPLIER 0.3515625f
#define TABLE_BASE_TIMING_OFFSET -30.0

//Intake AVCS
#define ORIG_TABLE_INTAKE_AVCS_A_ADDRESS (0x000B8DF8) //Intake Cam Advance Angle Normal

#define TABLE_INTAKE_AVCS_X_COUNT 22
#define TABLE_INTAKE_AVCS_Y_COUNT 24

#define TABLE_INTAKE_AVCS_DATA_TYPE 0x4000000
#define TABLE_INTAKE_AVCS_MULTIPLIER 1.0f
#define TABLE_INTAKE_AVCS_OFFSET -40.0f

//Exhaust AVCS
#define ORIG_TABLE_EXHAUST_AVCS_A_ADDRESS (0x000B8FD4) //Exhaust Cam Advance Angle Normal

#define TABLE_EXHAUST_AVCS_X_COUNT 22
#define TABLE_EXHAUST_AVCS_Y_COUNT 24

#define TABLE_EXHAUST_AVCS_DATA_TYPE 0x8000000
#define TABLE_EXHAUST_AVCS_MULTIPLIER 0.0015258789f
#define TABLE_EXHAUST_AVCS_OFFSET 0

//Requested Torque (Accelerator Pedal)
#define ORIG_TABLE_REQUESTED_TORQUE_ACCELERATOR_PEDAL_A_ADDRESS (0x000B26DC) //Requested Torque (Accelerator Pedal) Cruise
#define ORIG_TABLE_REQUESTED_TORQUE_ACCELERATOR_PEDAL_B_ADDRESS (0x000B7F64) //Requested Torque (Accelerator Pedal) Non-Cruise

#define TABLE_REQUESTED_TORQUE_ACCELERATOR_PEDAL_X_COUNT 16
#define TABLE_REQUESTED_TORQUE_ACCELERATOR_PEDAL_Y_COUNT 23

#define TABLE_REQUESTED_TORQUE_ACCELERATOR_PEDAL_DATA_TYPE 0x8000000
#define TABLE_REQUESTED_TORQUE_ACCELERATOR_PEDAL_MULTIPLIER 0.0078125f
#define TABLE_REQUESTED_TORQUE_ACCELERATOR_PEDAL_OFFSET 0

//2D tables

//Throttle Tip-in Enrichment
#define ORIG_TABLE_THROTTLE_TIP_IN_ENRICHMENT_A_ADDRESS (0x000B4768)
#define ORIG_TABLE_THROTTLE_TIP_IN_ENRICHMENT_B_ADDRESS (0x000B477C)

#define TABLE_THROTTLE_TIP_IN_X_COUNT 18

#define TABLE_THROTTLE_TIP_IN_DATA_TYPE 0x800
#define TABLE_THROTTLE_TIP_IN_MULTIPLIER 4.0f
#define TABLE_THROTTLE_TIP_IN_OFFSET 0

//Speed Density

#define ENGINE_DISPLACEMENT 1.998f

//MAF table address
#define ORIG_TABLE_MAF_ADDRESS (0x000B86E0)

//Manifold absolute pressure address
//SSM Routine P7
#define P_MANIFOLD_PRESSURE_ADDRESS (0xFFF88F74)
//Manifold absolute pressure, mmHg
#define P_MANIFOLD_PRESSURE ((float*)P_MANIFOLD_PRESSURE_ADDRESS)

//Engine speed address
//SSM Routine P8
#define P_ENGINE_SPEED_ADDRESS (0xFFF893EC)
//Engine speed, RPM
#define P_ENGINE_SPEED ((float*)P_ENGINE_SPEED_ADDRESS)

//Intake air temperature address
//SSM Routine P11
#define P_IAT_ADDRESS (0xFFF87C64)
//Intake air temperature, Celsius
#define P_IAT ((float*)P_IAT_ADDRESS)

//Throttle plate angle change address
//Tip-in routine
#define P_THROTTLE_ANGLE_CHANGE_ADDRESS (0xFFF89038)
//Throttle plate angle change, degrees
#define P_THROTTLE_ANGLE_CHANGE ((float*)P_THROTTLE_ANGLE_CHANGE_ADDRESS)

//Enable Speed Density
#define SPEED_DENSITY

//Cruise state
#define P_CRUISE_STATE_ADDRESS (0xFFF89386) /* Cruise system flag variable RAM address */
#define P_CRUISE_STATE ((unsigned char*)P_CRUISE_STATE_ADDRESS)

/* 0th bit set when cruise enabled cleared when disabled */
#define P_CRUISE_STATE_MASK_CRUISE_ENABLED ((unsigned char)1)

//Overtake Button

//Cruise Cancel switch
//SSM Routine S154
#define P_CRUISE_CANCEL_SWITCH_ADDRESS (0xFFF88CD1)
#define P_CRUISE_CANCEL_SWITCH ((unsigned char*)P_CRUISE_CANCEL_SWITCH_ADDRESS)
//Cruise Cancel switch mask
#define P_CRUISE_CANCEL_SWITCH_MASK (1)

//Accelerator pedal angle
//SSM Routine P30
#define P_ACCELERATOR_PEDAL_ANGLE_ADDRESS (0xFFF89148)
#define P_ACCELERATOR_PEDAL_ANGLE ((float *)P_ACCELERATOR_PEDAL_ANGLE_ADDRESS)

//Brake pedal switch
//SSM Routine S67
#define P_BRAKE_PEDAL_SWITCH_ADDRESS (0xFFF88CC0)
#define P_BRAKE_PEDAL_SWITCH ((unsigned char*)P_BRAKE_PEDAL_SWITCH_ADDRESS)
//Brake pedal switch mask
#define P_BRAKE_PEDAL_SWITCH_MASK (1)

//RAM address for our variables
#define RAM_HOLE (0xFFF8DE00)
