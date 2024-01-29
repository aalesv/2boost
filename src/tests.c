// This is an independent project of an individual developer. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

/*This file is part of 2Boost
*
*2Boost is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
*
*This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
*/

#include "tests.h"

#if defined __INTELLISENSE__
#define BUILD_TESTS
#endif

#if defined(BUILD_TESTS)
//This is test suite
//Tests LUT lookup
//Emulates Cruise on/off, Si-Drive switching, pressing the Overtake button
//Results placed in RAM
//For emulator testing only

//Set proper cruise on/off flags
#if defined(P_CRUISE_STATE_ADDRESS)
 #if defined(P_CRUISE_STATE_MASK_CRUISE_DISABLED)
  #define CRUISE_DISABLED P_CRUISE_STATE_MASK_CRUISE_DISABLED
  #define CRUISE_ENABLED 0
 #elif defined(P_CRUISE_STATE_MASK_CRUISE_ENABLED) //P_CRUISE_STATE_MASK_CRUISE_DISABLED
  #define CRUISE_DISABLED 0
  #define CRUISE_ENABLED P_CRUISE_STATE_MASK_CRUISE_ENABLED
 #endif //P_CRUISE_STATE_MASK_CRUISE_ENABLED
#endif //P_CRUISE_STATE_ADDRESS

//Declare debug output
//Place debug vars right after RAM vars
debug_variables_t *DEBUG_VARIABLES 
			= ((debug_variables_t*)((int)RAM_HOLE+sizeof(ram_variables_t)));

//Set defaults
void
test_set_default_ram_vars(void)
{
	#if defined(P_CRUISE_STATE)
		*P_CRUISE_STATE = CRUISE_DISABLED;
	#endif //P_CRUISE_STATE

	#if defined(P_SI_DRVIE_STATE)
		*P_SI_DRVIE_STATE = 3; //Intelligent
	#endif //P_SI_DRVIE_STATE

	#if defined(P_CRUISE_CANCEL_SWITCH)
		*P_CRUISE_CANCEL_SWITCH = 0;
	#endif //P_CRUISE_CANCEL_SWITCH

	#if defined(P_ACCELERATOR_PEDAL_ANGLE)
		*P_ACCELERATOR_PEDAL_ANGLE=0.0f;
	#endif //P_ACCELERATOR_PEDAL_ANGLE

	#if defined(P_CEL_LIGHT_STATUS_OEM)
		*P_CEL_LIGHT_STATUS_OEM = 0;
	#endif //P_CEL_LIGHT_STATUS_OEM

	#if defined(P_BRAKE_PEDAL_SWITCH)
		*P_BRAKE_PEDAL_SWITCH = 0;
	#endif //P_BRAKE_PEDAL_SWITCH

	#if defined(P_ENGINE_LOAD)
		*P_ENGINE_LOAD = 0.1f;
	#endif //P_ENGINE_LOAD

	#if defined(P_FBKC)
		*P_FBKC = 0.0f;
	#endif
}

//Test everything
void
test_everything()
{
	test_set_default_ram_vars();

	test_getLutRowNumber_3d();

	test_getLutRowNumber_2d();

	test_globalMapSwitch();

	//Not comfortable to test
	//Must step in this function
	test_getPointerFromLut_all_modes();
	
	test_set_default_ram_vars();
	DEBUG_VARIABLES->count = 0;

	#if defined(ORIG_TABLE_BASE_TIMING_A_ADDRESS)
		test_calc_3d_uint_to_float_entry_point_all_tables_and_modes();
	#endif //ORIG_TABLE_BASE_TIMING_A_ADDRESS
	
	test_set_default_ram_vars();
	DEBUG_VARIABLES->count = 0;

	//Test calc_2d_uint_to_float for Tip-in table
	#if defined(ORIG_TABLE_THROTTLE_TIP_IN_ENRICHMENT_A_ADDRESS)
		test_calc_2d_uint_to_float_entry_point_tip_in();
	#endif

	test_set_default_ram_vars();
	DEBUG_VARIABLES->count = 0;

	#if defined(SPEED_DENSITY)
		test_massAirflow_entry_point();
	#endif //SPEED_DENSITY

	test_set_default_ram_vars();

	#if defined(P_CRUISE_CANCEL_SWITCH)
		test_cruiseCancelPressed();
	#endif //P_CRUISE_CANCEL_SWITCH

	test_set_default_ram_vars();

	test_overtakeMapSwitch_press_and_hold();
	test_overtakeMapSwitch_press_and_release();

	test_set_default_ram_vars();

	//Test globalMapSwitch() with Overtake button on/off
	test_globalMapSwitch_overtake_press_and_hold();
	test_globalMapSwitch_overtake_press_and_release();

	//Test CEL Flash
	//This tests only function return for now
	test_celFlash_outer_entry_point();
}

//Test globalMapSwitch()
void
test_globalMapSwitch()
{
	#if defined(P_CRUISE_STATE)
		*P_CRUISE_STATE = CRUISE_DISABLED;
		DEBUG_VARIABLES->A = globalMapSwitch();

		*P_CRUISE_STATE = CRUISE_ENABLED;
		DEBUG_VARIABLES->B = globalMapSwitch();
	#endif //P_CRUISE_STATE

	#if defined(P_SI_DRVIE_STATE)
		*P_SI_DRVIE_STATE = 1; //Sport
		DEBUG_VARIABLES->C = globalMapSwitch();
		
		*P_SI_DRVIE_STATE = 8; //Sport Sharp
		DEBUG_VARIABLES->D = globalMapSwitch();
	#endif //P_SI_DRVIE_STATE
}

//Test getPointerFromLut()
//for all modes - Cruise on/off, all Si-Drive modes
void
test_getPointerFromLut_all_modes()
{
 //Test Base Timing tables if defined
 #if defined(ORIG_TABLE_BASE_TIMING_A_ADDRESS)
  //Test cruise on/off if defined
  #if defined(P_CRUISE_STATE_ADDRESS)
	*P_CRUISE_STATE = CRUISE_DISABLED;
	test_getPointerFromLut_3d();
	*P_CRUISE_STATE = CRUISE_ENABLED;
	test_getPointerFromLut_3d();
  #endif //P_CRUISE_STATE_ADDRESS
  
  //Test Si-Drive if supported
  #if defined(P_SI_DRVIE_STATE)
	//Intelligent
	*P_SI_DRVIE_STATE = 3;
	test_getPointerFromLut_3d();
	*P_SI_DRVIE_STATE = 16;
	test_getPointerFromLut_3d();

	//Sport
	*P_SI_DRVIE_STATE = 1;
	test_getPointerFromLut_3d();

	//Sport Sharp
	*P_SI_DRVIE_STATE = 2;
	test_getPointerFromLut_3d();
	*P_SI_DRVIE_STATE = 8;
	test_getPointerFromLut_3d();

	//Garbage, must choose orig table 
	*P_SI_DRVIE_STATE = 0;
	test_getPointerFromLut_3d();
  #endif //P_SI_DRVIE_STATE
 #endif //ORIG_TABLE_BASE_TIMING_A_ADDRESS
}

//Test calc_3d_uint_to_float_entry_point() call for all defined tables
//and modes - Cruise on/off, all Si-Drive modes
void
test_calc_3d_uint_to_float_entry_point_all_tables_and_modes()
{
 //Test Base Timing tables if defined
 #if defined(ORIG_TABLE_BASE_TIMING_A_ADDRESS)
  //Test cruise on/off if defined
  #if defined(P_CRUISE_STATE_ADDRESS)
	*P_CRUISE_STATE = CRUISE_DISABLED;
	test_calc_3d_uint_to_float_entry_point_timing();
	*P_CRUISE_STATE = CRUISE_ENABLED;
	test_calc_3d_uint_to_float_entry_point_timing();
  #endif //P_CRUISE_STATE_ADDRESS
  
  //Test Si-Drive if supported
  #if defined(P_SI_DRVIE_STATE)
	//Intelligent
	*P_SI_DRVIE_STATE = 3;
	test_calc_3d_uint_to_float_entry_point_timing();
	*P_SI_DRVIE_STATE = 16;
	test_calc_3d_uint_to_float_entry_point_timing();

	//Sport
	*P_SI_DRVIE_STATE = 1;
	test_calc_3d_uint_to_float_entry_point_timing();

	//Sport Sharp
	*P_SI_DRVIE_STATE = 2;
	test_calc_3d_uint_to_float_entry_point_timing();
	*P_SI_DRVIE_STATE = 8;
	test_calc_3d_uint_to_float_entry_point_timing();

	//Garbage, must choose orig table 
	*P_SI_DRVIE_STATE = 0;
	test_calc_3d_uint_to_float_entry_point_timing();
  #endif //P_SI_DRVIE_STATE
 #endif //ORIG_TABLE_BASE_TIMING_A_ADDRESS

 #if defined(ORIG_TABLE_REQUESTED_TORQUE_ACCELERATOR_PEDAL_A_ADDRESS)
  //Test cruise on/off if defined
  #if defined(P_CRUISE_STATE_ADDRESS)
	*P_CRUISE_STATE = CRUISE_DISABLED;
	test_calc_3d_uint_to_float_entry_point_req_torque();
	*P_CRUISE_STATE = CRUISE_ENABLED;
	test_calc_3d_uint_to_float_entry_point_req_torque();
  #endif //P_CRUISE_STATE_ADDRESS
  
  //Test Si-Drive if supported
  #if defined(P_SI_DRVIE_STATE)
	//Intelligent
	*P_SI_DRVIE_STATE = 3;
	test_calc_3d_uint_to_float_entry_point_req_torque();
	*P_SI_DRVIE_STATE = 16;
	test_calc_3d_uint_to_float_entry_point_req_torque();

	//Sport
	*P_SI_DRVIE_STATE = 1;
	test_calc_3d_uint_to_float_entry_point_req_torque();

	//Sport Sharp
	*P_SI_DRVIE_STATE = 2;
	test_calc_3d_uint_to_float_entry_point_req_torque();
	*P_SI_DRVIE_STATE = 8;
	test_calc_3d_uint_to_float_entry_point_req_torque();

	//Garbage, must choose orig table 
	*P_SI_DRVIE_STATE = 0;
	test_calc_3d_uint_to_float_entry_point_req_torque();
  #endif //P_SI_DRVIE_STATE
 #endif //ORIG_TABLE_REQUESTED_TORQUE_ACCELERATOR_PEDAL_A_ADDRESS
}

#if defined(ORIG_TABLE_THROTTLE_TIP_IN_ENRICHMENT_A_ADDRESS)
//Test calc_2d_uint_to_float for Tip-in table
void
test_calc_2d_uint_to_float_entry_point_tip_in()
{
	//Test sets
	const float x_min = 0;
	const float x_max = 30;

	#if defined(P_CRUISE_STATE)
		*P_CRUISE_STATE = CRUISE_DISABLED;
		DEBUG_VARIABLES->result[DEBUG_VARIABLES->count++]=calc_2d_uint_to_float_entry_point(x_min, (table_2d_uint_t *)ORIG_TABLE_THROTTLE_TIP_IN_ENRICHMENT_A_ADDRESS);
		DEBUG_VARIABLES->result[DEBUG_VARIABLES->count++]=calc_2d_uint_to_float_entry_point(x_max, (table_2d_uint_t *)ORIG_TABLE_THROTTLE_TIP_IN_ENRICHMENT_A_ADDRESS);
		*P_CRUISE_STATE = CRUISE_ENABLED;
		DEBUG_VARIABLES->result[DEBUG_VARIABLES->count++]=calc_2d_uint_to_float_entry_point(x_min, (table_2d_uint_t *)ORIG_TABLE_THROTTLE_TIP_IN_ENRICHMENT_A_ADDRESS);
		DEBUG_VARIABLES->result[DEBUG_VARIABLES->count++]=calc_2d_uint_to_float_entry_point(x_max, (table_2d_uint_t *)ORIG_TABLE_THROTTLE_TIP_IN_ENRICHMENT_A_ADDRESS);
	#endif //P_CRUISE_STATE

	//Test Si-Drive if supported
	#if defined(P_SI_DRVIE_STATE)
		//Intelligent
		*P_SI_DRVIE_STATE = 3;
		DEBUG_VARIABLES->result[DEBUG_VARIABLES->count++]=calc_2d_uint_to_float_entry_point(x_min, (table_2d_uint_t *)ORIG_TABLE_THROTTLE_TIP_IN_ENRICHMENT_A_ADDRESS);
		DEBUG_VARIABLES->result[DEBUG_VARIABLES->count++]=calc_2d_uint_to_float_entry_point(x_max, (table_2d_uint_t *)ORIG_TABLE_THROTTLE_TIP_IN_ENRICHMENT_A_ADDRESS);

		//Sport
		*P_SI_DRVIE_STATE = 1;
		DEBUG_VARIABLES->result[DEBUG_VARIABLES->count++]=calc_2d_uint_to_float_entry_point(x_min, (table_2d_uint_t *)ORIG_TABLE_THROTTLE_TIP_IN_ENRICHMENT_A_ADDRESS);
		DEBUG_VARIABLES->result[DEBUG_VARIABLES->count++]=calc_2d_uint_to_float_entry_point(x_max, (table_2d_uint_t *)ORIG_TABLE_THROTTLE_TIP_IN_ENRICHMENT_A_ADDRESS);

		//Sport Sharp
		*P_SI_DRVIE_STATE = 2;
		DEBUG_VARIABLES->result[DEBUG_VARIABLES->count++]=calc_2d_uint_to_float_entry_point(x_min, (table_2d_uint_t *)ORIG_TABLE_THROTTLE_TIP_IN_ENRICHMENT_A_ADDRESS);
		DEBUG_VARIABLES->result[DEBUG_VARIABLES->count++]=calc_2d_uint_to_float_entry_point(x_max, (table_2d_uint_t *)ORIG_TABLE_THROTTLE_TIP_IN_ENRICHMENT_A_ADDRESS);

		//Garbage, must choose orig table 
		*P_SI_DRVIE_STATE = 0;
		DEBUG_VARIABLES->result[DEBUG_VARIABLES->count++]=calc_2d_uint_to_float_entry_point(x_min, (table_2d_uint_t *)ORIG_TABLE_THROTTLE_TIP_IN_ENRICHMENT_A_ADDRESS);
		DEBUG_VARIABLES->result[DEBUG_VARIABLES->count++]=calc_2d_uint_to_float_entry_point(x_max, (table_2d_uint_t *)ORIG_TABLE_THROTTLE_TIP_IN_ENRICHMENT_A_ADDRESS);

	#endif //P_SI_DRVIE_STATE

}
#endif //ORIG_TABLE_THROTTLE_TIP_IN_ENRICHMENT_A_ADDRESS

#if defined(SPEED_DENSITY)
void
test_massAirflow_entry_point()
{
	float mafVoltage=1.8f;
	int tablePointerMAF=ORIG_TABLE_MAF_ADDRESS;
	*P_MANIFOLD_PRESSURE=0.5f*750.0f; //-0.5 bar relative = 0.5 bar absolute, convert to mmHg
	*P_ENGINE_SPEED=1800.0f;
	*P_IAT=20.0f;
	*P_THROTTLE_ANGLE_CHANGE=5.0f;

	DEBUG_VARIABLES->result[DEBUG_VARIABLES->count++] = massAirflow_entry_point(mafVoltage, (table_2d_noconv_t *)ORIG_TABLE_MAF_ADDRESS);
}
#endif //SPEED_DENSITY

//Test Base Timing tables if defined
#if defined(ORIG_TABLE_BASE_TIMING_A_ADDRESS)
//Test calc_3d_uint_to_float_entry_point() for timing tables
void
test_calc_3d_uint_to_float_entry_point_timing()
{
	//Test sets
	const float x_min = 0.0f;
	const float y_min = 0.0f;
	const float x_max = 4.0f;
	const float y_max = 7000.0f;
	
	//Call calc_3d_uint_to_float_entry_point with first set
	//Increment counter
	DEBUG_VARIABLES->result[DEBUG_VARIABLES->count++] = calc_3d_uint_to_float_entry_point(x_min, y_min, (table_3d_uint_t *)ORIG_TABLE_BASE_TIMING_A_ADDRESS);
	//Call calc_3d_uint_to_float_entry_point with second set
	//Increment counter
	DEBUG_VARIABLES->result[DEBUG_VARIABLES->count++] = calc_3d_uint_to_float_entry_point(x_max, y_max, (table_3d_uint_t *)ORIG_TABLE_BASE_TIMING_A_ADDRESS);
	//And so on...
 #if defined(ORIG_TABLE_BASE_TIMING_B_ADDRESS)
	DEBUG_VARIABLES->result[DEBUG_VARIABLES->count++] = calc_3d_uint_to_float_entry_point(x_min, y_min, (table_3d_uint_t *)ORIG_TABLE_BASE_TIMING_B_ADDRESS);
	DEBUG_VARIABLES->result[DEBUG_VARIABLES->count++] = calc_3d_uint_to_float_entry_point(x_max, y_max, (table_3d_uint_t *)ORIG_TABLE_BASE_TIMING_B_ADDRESS);
 #endif //ORIG_TABLE_BASE_TIMING_B_ADDRESS
 #if defined(ORIG_TABLE_BASE_TIMING_C_ADDRESS)
	DEBUG_VARIABLES->result[DEBUG_VARIABLES->count++] = calc_3d_uint_to_float_entry_point(x_min, y_min, (table_3d_uint_t *)ORIG_TABLE_BASE_TIMING_C_ADDRESS);
	DEBUG_VARIABLES->result[DEBUG_VARIABLES->count++] = calc_3d_uint_to_float_entry_point(x_max, y_max, (table_3d_uint_t *)ORIG_TABLE_BASE_TIMING_C_ADDRESS);
 #endif //ORIG_TABLE_BASE_TIMING_C_ADDRESS
 #if defined(ORIG_TABLE_BASE_TIMING_D_ADDRESS)
	DEBUG_VARIABLES->result[DEBUG_VARIABLES->count++] = calc_3d_uint_to_float_entry_point(x_min, y_min, (table_3d_uint_t *)ORIG_TABLE_BASE_TIMING_D_ADDRESS);
	DEBUG_VARIABLES->result[DEBUG_VARIABLES->count++] = calc_3d_uint_to_float_entry_point(x_max, y_max, (table_3d_uint_t *)ORIG_TABLE_BASE_TIMING_D_ADDRESS);
 #endif //ORIG_TABLE_BASE_TIMING_D_ADDRESS
}
#endif //ORIG_TABLE_BASE_TIMING_A_ADDRESS

//Test Requested Torque (Accelerato Pedal) tables if defined
#if defined(ORIG_TABLE_REQUESTED_TORQUE_ACCELERATOR_PEDAL_A_ADDRESS)
//Test calc_3d_uint_to_float_entry_point() for requested torque tables
void
test_calc_3d_uint_to_float_entry_point_req_torque()
{
	//Test sets
	const float x_min = 0.0f;
	const float y_min = 0.0f;
	const float x_max = 100.0f;
	const float y_max = 6800.0f;
	
	//Call calc_3d_uint_to_float_entry_point with first set
	//Increment counter
	DEBUG_VARIABLES->result[DEBUG_VARIABLES->count++] = calc_3d_uint_to_float_entry_point(x_min, y_min, (table_3d_uint_t *)ORIG_TABLE_REQUESTED_TORQUE_ACCELERATOR_PEDAL_A_ADDRESS);
	//Call calc_3d_uint_to_float_entry_point with second set
	//Increment counter
	DEBUG_VARIABLES->result[DEBUG_VARIABLES->count++] = calc_3d_uint_to_float_entry_point(x_max, y_max, (table_3d_uint_t *)ORIG_TABLE_REQUESTED_TORQUE_ACCELERATOR_PEDAL_A_ADDRESS);
	//And so on...
 #if defined(ORIG_TABLE_REQUESTED_TORQUE_ACCELERATOR_PEDAL_B_ADDRESS)
	DEBUG_VARIABLES->result[DEBUG_VARIABLES->count++] = calc_3d_uint_to_float_entry_point(x_min, y_min, (table_3d_uint_t *)ORIG_TABLE_REQUESTED_TORQUE_ACCELERATOR_PEDAL_B_ADDRESS);
	DEBUG_VARIABLES->result[DEBUG_VARIABLES->count++] = calc_3d_uint_to_float_entry_point(x_max, y_max, (table_3d_uint_t *)ORIG_TABLE_REQUESTED_TORQUE_ACCELERATOR_PEDAL_B_ADDRESS);
 #endif //ORIG_TABLE_REQUESTED_TORQUE_ACCELERATOR_PEDAL_B_ADDRESS
 #if defined(ORIG_TABLE_REQUESTED_TORQUE_ACCELERATOR_PEDAL_C_ADDRESS)
	DEBUG_VARIABLES->result[DEBUG_VARIABLES->count++] = calc_3d_uint_to_float_entry_point(x_min, y_min, (table_3d_uint_t *)ORIG_TABLE_REQUESTED_TORQUE_ACCELERATOR_PEDAL_C_ADDRESS);
	DEBUG_VARIABLES->result[DEBUG_VARIABLES->count++] = calc_3d_uint_to_float_entry_point(x_max, y_max, (table_3d_uint_t *)ORIG_TABLE_REQUESTED_TORQUE_ACCELERATOR_PEDAL_C_ADDRESS);
 #endif //ORIG_TABLE_REQUESTED_TORQUE_ACCELERATOR_PEDAL_C_ADDRESS
}
#endif //ORIG_TABLE_REQUESTED_TORQUE_ACCELERATOR_PEDAL_A_ADDRESS

//Test overtake button if enabled
#if defined(P_CRUISE_CANCEL_SWITCH)
//Test cruiseCancelPressed()
void
test_cruiseCancelPressed()
{
	
	*P_CRUISE_CANCEL_SWITCH = 0;
	DEBUG_VARIABLES->A = cruiseCancelPressed();

	*P_CRUISE_CANCEL_SWITCH = P_CRUISE_CANCEL_SWITCH_MASK;
	DEBUG_VARIABLES->B = cruiseCancelPressed();
}
#endif //P_CRUISE_CANCEL_SWITCH

void test_overtakeMapSwitch_press_and_hold(){
	float 	accLo=10.0f, //Accelerator slightly pressed
			accHi=50.0f; //Accelerator strongly pressed

	*P_CRUISE_CANCEL_SWITCH = 0;
	*P_ACCELERATOR_PEDAL_ANGLE = accLo;
	DEBUG_VARIABLES->A = overtakeMapSwitch();

	*P_CRUISE_CANCEL_SWITCH = 0;
	*P_ACCELERATOR_PEDAL_ANGLE = accHi;
	DEBUG_VARIABLES->B = overtakeMapSwitch();

	*P_CRUISE_CANCEL_SWITCH = P_CRUISE_CANCEL_SWITCH_MASK;
	*P_ACCELERATOR_PEDAL_ANGLE = accLo;
	DEBUG_VARIABLES->C = overtakeMapSwitch();

	*P_CRUISE_CANCEL_SWITCH = P_CRUISE_CANCEL_SWITCH_MASK;
	*P_ACCELERATOR_PEDAL_ANGLE = accHi;
	DEBUG_VARIABLES->D = overtakeMapSwitch();
}

void test_overtakeMapSwitch_press_and_release(){
	float 	accLo=10.0f, //Accelerator slightly pressed
			accHi=50.0f; //Accelerator strongly pressed

	*P_CRUISE_CANCEL_SWITCH = 0;
	*P_ACCELERATOR_PEDAL_ANGLE = accLo;
	DEBUG_VARIABLES->A = overtakeMapSwitch();

	*P_CRUISE_CANCEL_SWITCH = 0;
	*P_ACCELERATOR_PEDAL_ANGLE = accHi;
	DEBUG_VARIABLES->B = overtakeMapSwitch();

	*P_CRUISE_CANCEL_SWITCH = P_CRUISE_CANCEL_SWITCH_MASK;
	*P_ACCELERATOR_PEDAL_ANGLE = accLo;
	DEBUG_VARIABLES->C = overtakeMapSwitch();

	*P_CRUISE_CANCEL_SWITCH = 0;
	*P_ACCELERATOR_PEDAL_ANGLE = 0.0f;
	*P_BRAKE_PEDAL_SWITCH = P_BRAKE_PEDAL_SWITCH_MASK;
	DEBUG_VARIABLES->D = overtakeMapSwitch();
}

void
test_globalMapSwitch_overtake_press_and_release()
{
		float 	accLo=10.0f, //Accelerator slightly pressed
				accHi=50.0f; //Accelerator strongly pressed

	*P_CRUISE_CANCEL_SWITCH = 0;
	*P_ACCELERATOR_PEDAL_ANGLE = accLo;
	DEBUG_VARIABLES->A = globalMapSwitch();

	*P_CRUISE_CANCEL_SWITCH = 0;
	*P_ACCELERATOR_PEDAL_ANGLE = accHi;
	DEBUG_VARIABLES->B = globalMapSwitch();

	*P_CRUISE_CANCEL_SWITCH = P_CRUISE_CANCEL_SWITCH_MASK;
	*P_ACCELERATOR_PEDAL_ANGLE = accLo;
	DEBUG_VARIABLES->C = globalMapSwitch();

	*P_CRUISE_CANCEL_SWITCH = 0;
	*P_ACCELERATOR_PEDAL_ANGLE = 0.0f;
	*P_BRAKE_PEDAL_SWITCH = P_BRAKE_PEDAL_SWITCH_MASK;
	DEBUG_VARIABLES->D = globalMapSwitch();
}

void
test_globalMapSwitch_overtake_press_and_hold()
{
		float 	accLo=10.0f, //Accelerator slightly pressed
				accHi=50.0f; //Accelerator strongly pressed

	*P_CRUISE_CANCEL_SWITCH = 0;
	*P_ACCELERATOR_PEDAL_ANGLE = accLo;
	DEBUG_VARIABLES->A = globalMapSwitch();

	*P_CRUISE_CANCEL_SWITCH = 0;
	*P_ACCELERATOR_PEDAL_ANGLE = accHi;
	DEBUG_VARIABLES->B = globalMapSwitch();

	*P_CRUISE_CANCEL_SWITCH = P_CRUISE_CANCEL_SWITCH_MASK;
	*P_ACCELERATOR_PEDAL_ANGLE = accLo;
	DEBUG_VARIABLES->C = globalMapSwitch();

	*P_CRUISE_CANCEL_SWITCH = P_CRUISE_CANCEL_SWITCH_MASK;
	*P_ACCELERATOR_PEDAL_ANGLE = accHi;
	DEBUG_VARIABLES->D = globalMapSwitch();
}
#if defined(P_CEL_LIGHT_STATUS_OEM) && defined(ORIG_CEL_TRIGGER_OUTER_FUNCTION_ADDRESS)
//Test CEL flash
void
test_celFlash_outer_entry_point()
{
	celFlash_outer_entry_point();
}
#endif //P_CEL_LIGHT_STATUS_OEM && ORIG_CEL_TRIGGER_OUTER_FUNCTION_ADDRESS

#endif //BUILD_TESTS