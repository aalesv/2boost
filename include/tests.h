// This is an independent project of an individual developer. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

/*This file is part of 2Boost
*
*2Boost is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
*
*This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
*/

#include "macros.h"
#include "types.h"

//This is test suite
//It emulates Cruise on/off and Si-Drive switching
//Results placed in RAM
//For emulator testing only

#if defined(BUILD_TESTS)

//CEL ports
#define PDDR_W ((int*)0xFFFFF746)
#define PEDR_W ((int*)0xFFFFF754)
	
	//Declare debug output
	debug_variables_t *DEBUG_VARIABLES ROM_TESTS_DATA;

	//Prepare to test - set variables
	void test_set_default_ram_vars(void) NOINLINE ROM_TESTS_CODE;

	//Test everything
	void test_everything(void) NOINLINE ROM_TESTS_CODE;

	//Test maps switch
	void test_globalMapSwitch(void) NOINLINE ROM_TESTS_CODE;

	//Test Cruise cancel button
	void test_cruiseCancelPressed(void) NOINLINE ROM_TESTS_CODE;

	void test_overtakeMapSwitch_press_and_hold(void) NOINLINE ROM_TESTS_CODE;
	void test_overtakeMapSwitch_press_and_release(void) NOINLINE ROM_TESTS_CODE;

	void test_globalMapSwitch_overtake_press_and_hold(void) NOINLINE ROM_TESTS_CODE;
	void test_globalMapSwitch_overtake_press_and_release(void) NOINLINE ROM_TESTS_CODE;

	//Test calc_3d_uint_to_float_entry_point() call for all defined tables
	//and modes - Cruise on/off, all Si-Drive modes
	//Currently only Timing tables tested
	void test_calc_3d_uint_to_float_entry_point_all_tables_and_modes(void) NOINLINE ROM_TESTS_CODE;
	#if defined(ORIG_TABLE_BASE_TIMING_A_ADDRESS)
		//Test calc_3d_uint_to_float_entry_point() call for Timing tables
		void test_calc_3d_uint_to_float_entry_point_timing(void) NOINLINE ROM_TESTS_CODE;
		void test_getPointerFromLut_all_modes(void) NOINLINE ROM_TESTS_CODE;
	#endif //ORIG_TABLE_BASE_TIMING_A_ADDRESS

	#if defined(ORIG_TABLE_REQUESTED_TORQUE_ACCELERATOR_PEDAL_A_ADDRESS)
		//Test calc_3d_uint_to_float_entry_point() call for Requsted Torque
		void test_calc_3d_uint_to_float_entry_point_req_torque(void) NOINLINE ROM_TESTS_CODE;
	#endif //ORIG_TABLE_REQUESTED_TORQUE_ACCELERATOR_PEDAL_A_ADDRESS

	#if defined(ORIG_TABLE_THROTTLE_TIP_IN_ENRICHMENT_A_ADDRESS)
		void test_calc_2d_uint_to_float_entry_point_tip_in(void) NOINLINE ROM_TESTS_CODE;
	#endif

	//Test Speed Density
	void test_massAirflow_entry_point(void) NOINLINE ROM_TESTS_CODE;

	void test_celFlash_hooked(void) NOINLINE ROM_TESTS_CODE;

#endif //BUILD_TESTS

extern float calc_3d_uint_to_float_entry_point (const float x, 
							const float y, const table_3d_uint_t *tablePointer);
extern float calc_2d_uint_to_float_entry_point (const float x, 
										const table_2d_uint_t *tablePointer);
extern void test_getLutRowNumber_3d(void);
extern void test_getLutRowNumber_2d(void);
extern void test_getPointerFromLut_3d(void);
extern float massAirflow_entry_point(float mafVoltage, 
									const table_2d_noconv_t *tablePointerMAF);
extern uint8 overtakeMapSwitch(void);
extern uint8 cruiseCancelPressed(void);
extern uint8 globalMapSwitch(void);
extern void celTrigger_hooked(void);

