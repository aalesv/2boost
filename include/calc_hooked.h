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

//Lookup table for 3D UINT tables
//[][0] element contains orig table address
//[][1] element contains table 1 address
//[][2] element contains table 2 address
//[][3] element contains table 3 address
//[][last] element contains overtake table address
//Array of pointers
static const table_3d_uint_t * const LUT_3D_UINT[][LUT_COLUMN_COUNT] ROM_LUT;

//Lookup table for 2D UINT tables
//[][0] element contains orig table address
//[][1] element contains table 1 address
//[][2] element contains table 2 address
//[][3] element contains table 3 address
//[][last] element contains overtake table address
//Array of pointers
static const table_2d_uint_t * const LUT_2D_UINT[][LUT_COLUMN_COUNT] ROM_LUT;

//This function replaces original calc 3D table function
//x - X axis value
//y - Y axis value
//*tablePointer - pointer to structure that describes 3D table. uint only
//Returns Z axis value converted to float
float calc_3d_uint_to_float_hooked (const float x, const float y, 
									const table_3d_uint_t *tablePointer) ROM_CODE;

//This function replaces original calc 2D table function
//x - X axis value
//*tablePointer - pointer to structure that describes 2D table. uint only
//Returns Y axis value converted to float
float calc_2d_uint_to_float_hooked (const float x, 
									const table_2d_uint_t *tablePointer) ROM_CODE;

//Lookup universal function
//LUT - two-dimensional array with LUT_COLUMN_COUNT rows
//lutRowCount - LUT row count
//elementToFind - what it needs to find in zero column
//Returns row index if element is found and -1 otherwise
//
//I found that GCC 4.7 from GNUSH v13.01 toolchain
//sometimes produces incorrect code when getLutRowNumber is inlined.
//GCC 12.2 that I compiled from sources does not have this issue.
#if __GNUC__ >= GNUC_MIN_ACTUAL_VERSION
	//New GCC, inline
 inline
#endif //__GNUC__
	static int getLutRowNumber (const int LUT[][LUT_COLUMN_COUNT], 
								int lutRowCount, 
								int elementToFind) OPTIMIZE("O3") ROM_CODE
#if __GNUC__ >= GNUC_MIN_ACTUAL_VERSION
	//New GCC, inline always
	//Test build won't inline this function without this attribute
		ALWAYS_INLINE
#else
	//Old GCC, never inline
		NOINLINE
#endif //__GNUC__
;

//Lookup universal function
//LUT - two-dimensional array with LUT_COLUMN_COUNT rows
//lutRowCount - LUT row count
//elementToFind - what it needs to find in zero column
//Returns LUT element if elementToFind is present in LUT's first column
//or unchanged elementToFind
static int getPointerFromLut (const int LUT[][LUT_COLUMN_COUNT], 
							int lutRowCount, 
							int elementToFind) OPTIMIZE("O3") ROM_CODE;

//Prevent LUT array overrun condition
//Function always will inlined
static inline uint8 sanitizeLutSecondIndex (uint8 index) ALWAYS_INLINE ROM_CODE;

//Calc 3D function, data type uint only
extern calc_3d_uint_to_float_t calc_3d_uint_to_float;

//Calc 2D function, data type uint only
extern calc_2d_uint_to_float_t calc_2d_uint_to_float;
//RAM variables.
extern ram_variables_t *RAM_VARIABLES;

//What map to use
extern uint8 globalMapSwitch(void);

#if defined(BUILD_TESTS)
	//Test LUT 3D lookup
	void test_getLutRowNumber_3d(void) ROM_TESTS_CODE;
	//Test LUT 2D lookup
	void test_getLutRowNumber_2d(void) ROM_TESTS_CODE;
	//Test LUT 3D lookup
	void test_getPointerFromLut_3d(void) ROM_TESTS_CODE;

    extern debug_variables_t *DEBUG_VARIABLES;
#endif
