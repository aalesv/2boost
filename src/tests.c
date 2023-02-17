// This is an independent project of an individual developer. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

/*This file is part of 2Boost
*
*2Boost is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
*
*This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
*/

#include "tests.h"

#if defined(BUILD_TESTS)
//This is test suite
//It emulates Cruise on/off and Si-Drive switching
//Results placed in RAM
//Use with emulator
//Safe for production ROM but not accessible

typedef struct {
	//Number of tests done
	int count;
	//Test each table with two parameters sets
	float	testA1,
			testA2,
			testB1,
			testB2,
			testC1,
			testC2,
			testD1,
			testD2;
} debug_variables_t;

//Declare debug output
debug_variables_t *DEBUG_VARIABLES ROM_TESTS_DATA;
debug_variables_t *DEBUG_VARIABLES = ((debug_variables_t*)(int)RAM_HOLE+sizeof(ram_variables_t));

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

//Test calc_3d_float_hooked() call for all defined tables
//and modes - Cruise on/off, all Si-Drive modes
void test_calc_3d_float_hooked_all_tables_and_modes() {

 //Test Base Timing tables if defined
 #if defined(ORIG_TABLE_BASE_TIMING_A_ADDRESS)
  //Test cruise on/off if defined
  #if defined(P_CRUISE_STATE_ADDRESS)
	*P_CRUISE_STATE = CRUISE_DISABLED;
	test_calc_3d_float_hooked_timing();
	*P_CRUISE_STATE = CRUISE_ENABLED;
	test_calc_3d_float_hooked_timing();
  #endif //P_CRUISE_STATE_ADDRESS
  
  //Test Si-Drive if supported
  #if defined(P_SI_DRVIE_STATE)
	//Intelligent
	*P_SI_DRVIE_STATE = 3;
	test_calc_3d_float_hooked_timing();
	*P_SI_DRVIE_STATE = 16;
	test_calc_3d_float_hooked_timing();

	//Sport
	*P_SI_DRVIE_STATE = 1;
	test_calc_3d_float_hooked_timing();

	//Sport Sharp
	*P_SI_DRVIE_STATE = 2;
	test_calc_3d_float_hooked_timing();
	*P_SI_DRVIE_STATE = 8;
	test_calc_3d_float_hooked_timing();

	//Garbage, must choose orig table 
	*P_SI_DRVIE_STATE = 0;
	test_calc_3d_float_hooked_timing();
  #endif //P_SI_DRVIE_STATE
 #endif //ORIG_TABLE_BASE_TIMING_A_ADDRESS

}

//Test Base Timing tables if defined
#if defined(ORIG_TABLE_BASE_TIMING_A_ADDRESS)
//Test calc_3d_float_hooked() for timing tables
void test_calc_3d_float_hooked_timing() {
	//Test sets
	const float x_min = 0;
	const float y_min = 0;
	const float x_max = 4;
	const float y_max = 7000;
	
	//Reset counter
	DEBUG_VARIABLES->count=0;
	
	//Call calc_3d_float_hooked with first set
	DEBUG_VARIABLES->testA1 = calc_3d_float_hooked(x_min, y_min, (table_3d_float_t *)ORIG_TABLE_BASE_TIMING_A_ADDRESS);
	//Increment counter
	DEBUG_VARIABLES->count++;
	//Call calc_3d_float_hooked with second set
	DEBUG_VARIABLES->testA2 = calc_3d_float_hooked(x_max, y_max, (table_3d_float_t *)ORIG_TABLE_BASE_TIMING_A_ADDRESS);
	//Increment counter
	DEBUG_VARIABLES->count++;
	//And so on...
 #if defined(ORIG_TABLE_BASE_TIMING_B_ADDRESS)
	DEBUG_VARIABLES->count++;
	DEBUG_VARIABLES->testB1 = calc_3d_float_hooked(x_min, y_min, (table_3d_float_t *)ORIG_TABLE_BASE_TIMING_B_ADDRESS);
	DEBUG_VARIABLES->count++;
	DEBUG_VARIABLES->testB2 = calc_3d_float_hooked(x_max, y_max, (table_3d_float_t *)ORIG_TABLE_BASE_TIMING_B_ADDRESS);
 #endif //ORIG_TABLE_BASE_TIMING_B_ADDRESS
 #if defined(ORIG_TABLE_BASE_TIMING_C_ADDRESS)
	DEBUG_VARIABLES->count++;
	DEBUG_VARIABLES->testC1 = calc_3d_float_hooked(x_min, y_min, (table_3d_float_t *)ORIG_TABLE_BASE_TIMING_C_ADDRESS);
	DEBUG_VARIABLES->count++;
	DEBUG_VARIABLES->testC2 = calc_3d_float_hooked(x_max, y_max, (table_3d_float_t *)ORIG_TABLE_BASE_TIMING_C_ADDRESS);
 #endif //ORIG_TABLE_BASE_TIMING_C_ADDRESS
 #if defined(ORIG_TABLE_BASE_TIMING_D_ADDRESS)
	DEBUG_VARIABLES->count++;
	DEBUG_VARIABLES->testD1 = calc_3d_float_hooked(x_min, y_min, (table_3d_float_t *)ORIG_TABLE_BASE_TIMING_D_ADDRESS);
	DEBUG_VARIABLES->count++;
	DEBUG_VARIABLES->testD2 = calc_3d_float_hooked(x_max, y_max, (table_3d_float_t *)ORIG_TABLE_BASE_TIMING_D_ADDRESS);
 #endif //ORIG_TABLE_BASE_TIMING_D_ADDRESS
}
#endif //ORIG_TABLE_BASE_TIMING_A_ADDRESS
#endif //BUILD_TESTS