// This is an independent project of an individual developer. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

/*This file is part of 2Boost
*
*2Boost is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
*
*This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
*/

#define CALID "AZ1G202G"

//Calc 3D function ROM address.
//X     - float
//Y     - float
//Data  - uint only.
//Converts to float.
#define ORIG_CALC_3D_UINT_TO_FLOAT_FUNCTION_ADDRESS (0x000BE8B8)

//Calc 2D function ROM address.
//X     - float
//Data  - float only.
//No conversion, returns float
#define ORIG_CALC_2D_FLOAT_TO_FLOAT_FUNCTION_ADDRESS (0x000BE804)

//Calc 2D function ROM address.
//X     - float
//Data  - uint only.
//Converts to float.
#define ORIG_CALC_2D_UINT_TO_FLOAT_FUNCTION_ADDRESS ORIG_CALC_2D_FLOAT_TO_FLOAT_FUNCTION_ADDRESS

//3D Tables

//Target Boost
#define ORIG_TABLE_TARGET_BOOST_ADDRESS (0x00086C50)

#define TABLE_TARGET_BOOST_X_COUNT 14
#define TABLE_TARGET_BOOST_Y_COUNT 14

#define TABLE_TARGET_BOOST_DATA_TYPE 0x8000000
#define TABLE_TARGET_BOOST_MULTIPLIER 1.0f
#define TABLE_TARGET_BOOST_OFFSET 0

//Initial WGDC
#define ORIG_TABLE_INIT_WGDC_ADDRESS (0x86C34)

#define TABLE_INIT_WGDC_X_COUNT 11
#define TABLE_INIT_WGDC_Y_COUNT 10

#define TABLE_INIT_WGDC_DATA_TYPE 0x8000000
#define TABLE_INIT_WGDC_MULTIPLIER 0.00390625f
#define TABLE_INIT_WGDC_OFFSET 0

//Max WGDC
#define ORIG_TABLE_MAX_WGDC_ADDRESS (0x86C18)

#define TABLE_MAX_WGDC_X_COUNT 11
#define TABLE_MAX_WGDC_Y_COUNT 10

#define TABLE_MAX_WGDC_DATA_TYPE 0x8000000
#define TABLE_MAX_WGDC_MULTIPLIER 0.00390625f
#define TABLE_MAX_WGDC_OFFSET 0

//Primary Open Loop Fueling
#define ORIG_TABLE_PRIMARY_OL_A_ADDRESS (0x89024)

#define TABLE_PRIMARY_OL_X_COUNT 19
#define TABLE_PRIMARY_OL_Y_COUNT 18

#define TABLE_PRIMARY_OL_DATA_TYPE 0x4000000
#define TABLE_PRIMARY_OL_MULTIPLIER 0.0078125f
#define TABLE_PRIMARY_OL_OFFSET 0

//Base Timing
#define ORIG_TABLE_BASE_TIMING_A_ADDRESS (0x00089BA0) //Base Timing Primary Cruise
#define ORIG_TABLE_BASE_TIMING_B_ADDRESS (0x00089BBC) //Base Timing Primary Non-Cruise
#define ORIG_TABLE_BASE_TIMING_C_ADDRESS (0x00089BD8) //Base Timing Reference Cruise (AVCS related)
#define ORIG_TABLE_BASE_TIMING_D_ADDRESS (0x00089BF4) //Base Timing Reference Non-Cruise (AVCS related) 

#define TABLE_BASE_TIMING_X_COUNT 22
#define TABLE_BASE_TIMING_Y_COUNT 18

#define TABLE_BASE_TIMING_DATA_TYPE 0x4000000
#define TABLE_BASE_TIMING_MULTIPLIER 0.3515625f
#define TABLE_BASE_TIMING_OFFSET -20.0

//Intake AVCS
#define ORIG_TABLE_INTAKE_AVCS_A_ADDRESS (0x8B0F8) //Intake Cam Advance Angle Cruise
#define ORIG_TABLE_INTAKE_AVCS_B_ADDRESS (0x8B114) //Intake Cam Advance Angle Non-Cruise

#define TABLE_INTAKE_AVCS_X_COUNT 19
#define TABLE_INTAKE_AVCS_Y_COUNT 18

#define TABLE_INTAKE_AVCS_DATA_TYPE 0x8000000
#define TABLE_INTAKE_AVCS_MULTIPLIER 0.0054931641f
#define TABLE_INTAKE_AVCS_OFFSET 0

//Exhaust AVCS
#define ORIG_TABLE_EXHAUST_AVCS_A_ADDRESS (0x8B1BC) //Exhaust Cam Advance Angle Cruise
#define ORIG_TABLE_EXHAUST_AVCS_B_ADDRESS (0x8B1D8) //Exhaust Cam Advance Angle Non-Cruise

#define TABLE_EXHAUST_AVCS_X_COUNT 19
#define TABLE_EXHAUST_AVCS_Y_COUNT 18

#define TABLE_EXHAUST_AVCS_DATA_TYPE 0x8000000
#define TABLE_EXHAUST_AVCS_MULTIPLIER 0.0054931641f
#define TABLE_EXHAUST_AVCS_OFFSET 0

//Requested Torque (Accelerator Pedal)
//Because it's Si-Drive ROM, no tables will be defined
//except Overtake table 

//Requested Torque (Accelerator Pedal) Sport
#define ORIG_TABLE_REQUESTED_TORQUE_ACCELERATOR_PEDAL_A_ADDRESS (0x0008A9D8) 
//Requested Torque (Accelerator Pedal) Sport Sharp
#define ORIG_TABLE_REQUESTED_TORQUE_ACCELERATOR_PEDAL_B_ADDRESS (0x0008A9F4)
//Requested Torque (Accelerator Pedal) Intelligent
#define ORIG_TABLE_REQUESTED_TORQUE_ACCELERATOR_PEDAL_C_ADDRESS (0x0008AA10)

#define TABLE_REQUESTED_TORQUE_ACCELERATOR_PEDAL_X_COUNT 16
#define TABLE_REQUESTED_TORQUE_ACCELERATOR_PEDAL_Y_COUNT 17

#define TABLE_REQUESTED_TORQUE_ACCELERATOR_PEDAL_DATA_TYPE 0x8000000
#define TABLE_REQUESTED_TORQUE_ACCELERATOR_PEDAL_MULTIPLIER 0.0078125f
#define TABLE_REQUESTED_TORQUE_ACCELERATOR_PEDAL_OFFSET 0

//2D tables

//Throttle Tip-in Enrichment
#define ORIG_TABLE_THROTTLE_TIP_IN_ENRICHMENT_A_ADDRESS (0x00088D24)
#define ORIG_TABLE_THROTTLE_TIP_IN_ENRICHMENT_B_ADDRESS (0x00088D38)

#define TABLE_THROTTLE_TIP_IN_X_COUNT 18

#define TABLE_THROTTLE_TIP_IN_DATA_TYPE 0x800
#define TABLE_THROTTLE_TIP_IN_MULTIPLIER 4.0f
#define TABLE_THROTTLE_TIP_IN_OFFSET 0

//Speed Density

//MAF table address
#define ORIG_TABLE_MAF_ADDRESS (0x0008AB64)

//Manifold absolute pressure address
//SSM Routine P7
#define P_MANIFOLD_PRESSURE_ADDRESS (0xFFFF63FC)
//Manifold absolute pressure, mmHg
#define P_MANIFOLD_PRESSURE ((float*)P_MANIFOLD_PRESSURE_ADDRESS)

//Engine speed address
//SSM Routine P8
#define P_ENGINE_SPEED_ADDRESS (0xFFFF6810)
//Engine speed, RPM
#define P_ENGINE_SPEED ((float*)P_ENGINE_SPEED_ADDRESS)

//Intake air temperature address
//SSM Routine P11
#define P_IAT_ADDRESS (0xFFFF4124)
//Intake air temperature, Celsius
#define P_IAT ((float*)P_IAT_ADDRESS)

//Throttle plate angle change address
//Tip-in routine
#define P_THROTTLE_ANGLE_CHANGE_ADDRESS (0xFFFF64D4)
//Throttle plate angle change, degrees
#define P_THROTTLE_ANGLE_CHANGE ((float*)P_THROTTLE_ANGLE_CHANGE_ADDRESS)

//Enable Speed Density
#define SPEED_DENSITY

//Overtake Button

//Cruise Cancel switch
//SSM Routine S154
#define P_CRUISE_CANCEL_SWITCH_ADDRESS (0xFFFF61CA)
#define P_CRUISE_CANCEL_SWITCH ((unsigned char*)P_CRUISE_CANCEL_SWITCH_ADDRESS)
//Cruise Cancel switch mask
#define P_CRUISE_CANCEL_SWITCH_MASK (1)

//Accelerator pedal angle
//SSM Routine P30
#define P_ACCELERATOR_PEDAL_ANGLE_ADDRESS (0xFFFF66C4)
#define P_ACCELERATOR_PEDAL_ANGLE ((float *)P_ACCELERATOR_PEDAL_ANGLE_ADDRESS)

//Cruise state
#define P_CRUISE_STATE_ADDRESS (0xFFFF61BE) /* Cruise system flag variable RAM address */
#define P_CRUISE_STATE ((unsigned char*)P_CRUISE_STATE_ADDRESS)

/* 0th bit set when cruise enabled cleared when disabled */
#define P_CRUISE_STATE_MASK_CRUISE_ENABLED ((unsigned char)1)

//Si-Drive state
#define P_SI_DRVIE_STATE_ADDRESS (0xFFFF611E) /* SI-Drive system flag variable RAM address */
#define P_SI_DRVIE_STATE ((unsigned char*)P_SI_DRVIE_STATE_ADDRESS)

//Brake pedal switch
//SSM Routine S67
#define P_BRAKE_PEDAL_SWITCH_ADDRESS (0xFFFF61B8)
#define P_BRAKE_PEDAL_SWITCH ((unsigned char*)P_BRAKE_PEDAL_SWITCH_ADDRESS)
//Brake pedal switch mask
#define P_BRAKE_PEDAL_SWITCH_MASK 1

//CEL Flash
//ROM CEL Trigger outer function
#define ORIG_CEL_TRIGGER_OUTER_FUNCTION_ADDRESS (0x0007C846)
//ROM CEL status
#define P_CEL_LIGHT_STATUS_OEM_ADDRESS (0xFFFF9B3A)
#define P_CEL_LIGHT_STATUS_OEM ((unsigned char*)P_CEL_LIGHT_STATUS_OEM_ADDRESS)

//Engine load, E32
#define P_ENGINE_LOAD_ADDRESS (0xFFFF65D4)
#define P_ENGINE_LOAD ((float*)P_ENGINE_LOAD_ADDRESS)

//FBKC, E39
#define P_FBKC_ADDRESS  (0xFFFF7C40)
#define P_FBKC ((float*)P_FBKC_ADDRESS)

//RAM address for our variables
#define RAM_HOLE (0xFFFFA900)


