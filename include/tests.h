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
//Use with emulator
//Safe for production ROM but not accessible

#if defined(BUILD_TESTS)
	//Test calc_3d_float_hooked() call for all defined tables
	//Currently only Timing tables tested
	//and modes - Cruise on/off, all Si-Drive modes
	void test_calc_3d_float_hooked_all_tables_and_modes() OPTIMIZE("O") ROM_TESTS_CODE;
	#if defined(ORIG_TABLE_BASE_TIMING_A_ADDRESS)
		//Test calc_3d_float_hooked() call for Timing tables
		void test_calc_3d_float_hooked_timing() OPTIMIZE("O") ROM_TESTS_CODE;
	#endif //ORIG_TABLE_BASE_TIMING_A_ADDRESS
#endif //BUILD_TESTS

extern float calc_3d_float_hooked (const float x, const float y, const table_3d_float_t *tablePointer);
