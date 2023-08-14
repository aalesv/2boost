// This is an independent project of an individual developer. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

/*This file is part of 2Boost
*
*2Boost is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
*
*This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
*/

#if !defined(MACROS_H)
#define MACROS_H

//This is for proper VS Code functioning
 #ifdef __INTELLISENSE__
 #include "AZ1G202G.h"
 #endif

 //GCC minimal actual version which don't need workarounds to produce valid assembler code
 #define GNUC_MIN_ACTUAL_VERSION 12

//Number of auto-generated tables for each hack section
//Overtake button tables are generated separately 
#if defined(P_SI_DRVIE_STATE)
 #define NUMBER_OF_REGULAR_TABLES 3
#elif defined(P_CRUISE_STATE) //P_SI_DRVIE_STATE
 #define NUMBER_OF_REGULAR_TABLES 2
#endif //P_CRUISE_STATE

//Number of columns in each lookup table
 //We have extra overtake table
 #define LUT_COLUMN_COUNT (NUMBER_OF_REGULAR_TABLES+2)
 //Overtake map LUT column index
 #define LUT_OVERTAKE_MAP_COLUMN_NUMBER (LUT_COLUMN_COUNT - 1)

//Define binary file sections. Vars and functions with no section specified will be stripped - controlled by Makefile.
//Entry points
#define ROM_ENTRY_POINT_CALC_3D			LD_SECTION("ROM_ENTRY_POINT_CALC_3D", 4)
#define ROM_ENTRY_POINT_CALC_2D			LD_SECTION("ROM_ENTRY_POINT_CALC_2D", 4)
#define ROM_ENTRY_POINT_SPEED_DENSITY 	LD_SECTION("ROM_ENTRY_POINT_SPEED_DENSITY", 4)
//Main ROM code
#define ROM_CODE  		LD_SECTION("ROM_CODE", 4)
//ROM metadata - version etc.
#define ROM_METADATA	LD_SECTION("ROM_METADATA", 4)
//ROM internal variables
#define ROM_DATA		LD_SECTION("ROM_DATA", 4)
#define ROM_DATA_CONST	LD_SECTION("ROM_DATA_CONST", 4)
//ROM config data that can be modified by tuner
#define ROM_CONFIG		LD_SECTION("ROM_CONFIG", 1)
//Tables pointer structures
#define ROM_TABLE_PTR	LD_SECTION("ROM_TABLE_PTR", 4)
//Tables themselves
#define ROM_TABLE_DATA  LD_SECTION("ROM_TABLE_DATA", 4)
//Lookup tables
#define ROM_LUT			LD_SECTION("ROM_LUT", 4)
//ROM other data
#define ROM_OTHER_DATA	LD_SECTION("ROM_OTHER_DATA", 1)
//Tests
#define ROM_TESTS_CODE	LD_SECTION("ROM_TESTS_CODE", 4)
//Tests internal variables
#define ROM_TESTS_DATA	LD_SECTION("ROM_TESTS_DATA", 4)

//A section definition
#define LD_SECTION(SECTION, ALIGN) __attribute__ ((section (SECTION),aligned(ALIGN)))

//Optimization level macros
#define OPTIMIZE(LEVEL) __attribute__((optimize(LEVEL)))

//Specify this to always inline a function
#define ALWAYS_INLINE __attribute__((always_inline))

//Specify this to not inline a function
#define NOINLINE __attribute__ ((noinline))

//Array size macro
#define COUNT_OF(x) \
	((sizeof(x)/sizeof(0[x])) / ((unsigned int)(!(sizeof(x) % sizeof(0[x])))))

//Data types. Used in tables autogeneration
#define uint16 unsigned short
//3D tables type
#define UINT_0x8000000 uint16
#define UINT_0x08000000 uint16
//2D tables type
#define UINT_0x800 uint16
#define UINT_0x0800 uint16

#define uint8 unsigned char
//3D tables type
#define UINT_0x4000000 uint8
#define UINT_0x04000000 uint8
//2D tables type
#define UINT_0x400 uint8
#define UINT_0x0400 uint8

//Macro for creating table structures
//Type def for 3D table
//Data type short (uint16) or char (uint8) only
//X axis is float
//Y axis is float
//Data is byte or word converted to float at runtime
//NUM - number of tables
//NAME - tables will be named NAME1, NAME2, NAME3
//X_COUNT, Y_COUNT - count of elements in X and Y axis
//DATA_TYPE - hex number as specified in ROM table pointer structure
//			For example for 3D tables it may be
//			0x8000000 for uint16
//			0x4000000 for uint8
//			Will be auto converted to proper type declaration
//MULTIPLIER - data cel is multiplied by this number and then ...
//OFFSET - ... added with this number
#define CREATE_TABLE_3D_UINT(NUM, NAME, X_COUNT, Y_COUNT, DATA_TYPE, MULTIPLIER, OFFSET) \
	_CREATE_TABLE_3D_UINT(NUM, NAME, X_COUNT, Y_COUNT, DATA_TYPE, MULTIPLIER, OFFSET)
//Needed for correct macro stringifying
#define _CREATE_TABLE_3D_UINT(NUM, NAME, X_COUNT, Y_COUNT, DATA_TYPE, MULTIPLIER, OFFSET) \
	CREATE_TABLE_3D_UINT_##NUM(NAME, X_COUNT, Y_COUNT, DATA_TYPE, MULTIPLIER, OFFSET)

//Create 2 tables - NAME1, NAME2
#define CREATE_TABLE_3D_UINT_2(NAME, X_COUNT, Y_COUNT, DATA_TYPE, MULTIPLIER, OFFSET) \
	CREATE_TABLE_3D_UINT_1(NAME##1, X_COUNT, Y_COUNT, DATA_TYPE, MULTIPLIER, OFFSET); \
	CREATE_TABLE_3D_UINT_1(NAME##2, X_COUNT, Y_COUNT, DATA_TYPE, MULTIPLIER, OFFSET)
	
//Create 3 tables - NAME1, NAME2, NAME3
#define CREATE_TABLE_3D_UINT_3(NAME, X_COUNT, Y_COUNT, DATA_TYPE, MULTIPLIER, OFFSET) \
	CREATE_TABLE_3D_UINT_1(NAME##1, X_COUNT, Y_COUNT, DATA_TYPE, MULTIPLIER, OFFSET); \
	CREATE_TABLE_3D_UINT_1(NAME##2, X_COUNT, Y_COUNT, DATA_TYPE, MULTIPLIER, OFFSET); \
	CREATE_TABLE_3D_UINT_1(NAME##3, X_COUNT, Y_COUNT, DATA_TYPE, MULTIPLIER, OFFSET)

//Create 1 table - NAME
#define CREATE_TABLE_3D_UINT_1(NAME, X_COUNT, Y_COUNT, DATA_TYPE, MULTIPLIER, OFFSET) \
	_CREATE_TABLE_3D_UINT_1(NAME, X_COUNT, Y_COUNT, DATA_TYPE, MULTIPLIER, OFFSET)
//Needed for correct macro stringifying
#define _CREATE_TABLE_3D_UINT_1(NAME, X_COUNT, Y_COUNT, DATA_TYPE, MULTIPLIER, OFFSET) \
	static const float NAME##_x_axis [X_COUNT] ROM_TABLE_DATA = {0}; \
	static const float NAME##_y_axis [Y_COUNT] ROM_TABLE_DATA = {0}; \
	static const UINT_##DATA_TYPE NAME##_data [X_COUNT * Y_COUNT] ROM_TABLE_DATA = {0}; \
\
	const table_3d_uint_t NAME ROM_TABLE_PTR = { \
		.x_len = X_COUNT, \
		.y_len = Y_COUNT, \
		.x_axis_ptr = & NAME##_x_axis, \
		.y_axis_ptr = & NAME##_y_axis, \
		.data_ptr = & NAME##_data, \
		.data_type = DATA_TYPE, \
		.multiplier = MULTIPLIER, \
		.offset = OFFSET \
	}

//Macro for creating table structures
//Type def for 2D table
//Data type short (uint16) or char (uint8) only
//X axis is float
//Data is byte or word converted to float at runtime
//NUM - number of tables
//NAME - tables will be named NAME1, NAME2, NAME3
//X_COUNT - count of elements in X axis
//DATA_TYPE - hex number as specified in ROM table pointer structure
//			For example for 2D tables it may be
//			0x800 for uint16
//			0x400 for uint8
//			Will be auto converted to proper type declaration
//MULTIPLIER - data cel is multiplied by this number and then ...
//OFFSET - ... added with this number
#define CREATE_TABLE_2D_UINT(NUM, NAME, X_COUNT, DATA_TYPE, MULTIPLIER, OFFSET) \
	_CREATE_TABLE_2D_UINT(NUM, NAME, X_COUNT, DATA_TYPE, MULTIPLIER, OFFSET)
//Needed for correct macro stringifying
#define _CREATE_TABLE_2D_UINT(NUM, NAME, X_COUNT, DATA_TYPE, MULTIPLIER, OFFSET) \
	CREATE_TABLE_2D_UINT_##NUM(NAME, X_COUNT, DATA_TYPE, MULTIPLIER, OFFSET)

//Create 2 tables - NAME1, NAME2
#define CREATE_TABLE_2D_UINT_2(NAME, X_COUNT, DATA_TYPE, MULTIPLIER, OFFSET) \
	CREATE_TABLE_2D_UINT_1(NAME##1, X_COUNT, DATA_TYPE, MULTIPLIER, OFFSET); \
	CREATE_TABLE_2D_UINT_1(NAME##2, X_COUNT, DATA_TYPE, MULTIPLIER, OFFSET)
	
//Create 3 tables - NAME1, NAME2, NAME3
#define CREATE_TABLE_2D_UINT_3(NAME, X_COUNT, DATA_TYPE, MULTIPLIER, OFFSET) \
	CREATE_TABLE_2D_UINT_1(NAME##1, X_COUNT, DATA_TYPE, MULTIPLIER, OFFSET); \
	CREATE_TABLE_2D_UINT_1(NAME##2, X_COUNT, DATA_TYPE, MULTIPLIER, OFFSET); \
	CREATE_TABLE_2D_UINT_1(NAME##3, X_COUNT, DATA_TYPE, MULTIPLIER, OFFSET)

//Create 1 table - NAME
#define CREATE_TABLE_2D_UINT_1(NAME, X_COUNT, DATA_TYPE, MULTIPLIER, OFFSET) \
	_CREATE_TABLE_2D_UINT_1(NAME, X_COUNT, DATA_TYPE, MULTIPLIER, OFFSET)
//Needed for correct macro stringifying
#define _CREATE_TABLE_2D_UINT_1(NAME, X_COUNT, DATA_TYPE, MULTIPLIER, OFFSET) \
	static const float NAME##_x_axis [X_COUNT] ROM_TABLE_DATA = {0}; \
	static const UINT_##DATA_TYPE NAME##_data [X_COUNT] ROM_TABLE_DATA = {0}; \
\
	const table_2d_uint_t NAME ROM_TABLE_PTR = { \
		.x_len = X_COUNT, \
		.data_type = DATA_TYPE, \
		.x_axis_ptr = & NAME##_x_axis, \
		.data_ptr = & NAME##_data, \
		.multiplier = MULTIPLIER, \
		.offset = OFFSET \
	}

//Macro for creatig Lookup Table entry
//It's just array of pointers explicitly cast to TYPE
//NUM - number of tables
#define CREATE_LUT_ENTRY(NUM, TYPE, ORIG, REPL, EXTRA) \
	_CREATE_LUT_ENTRY(NUM, TYPE, ORIG, REPL, EXTRA)
//Needed for correct macro stringifying
#define _CREATE_LUT_ENTRY(NUM, TYPE, ORIG, REPL, EXTRA) \
	CREATE_LUT_ENTRY_##NUM(TYPE, ORIG, REPL, EXTRA)

//Create 2 entries - REPL1, REPL2
#define CREATE_LUT_ENTRY_2(TYPE, ORIG, REPL, EXTRA) \
	(TYPE *)ORIG, REPL##1, REPL##2, EXTRA
//Create 3 entries - REPL1, REPL2, REPL3
#define CREATE_LUT_ENTRY_3(TYPE, ORIG, REPL, EXTRA) \
	(TYPE *)ORIG, REPL##1, REPL##2, REPL##3, EXTRA

//Create Lookup Table entry where all addresses except EXTRA are the same
#define CREATE_LUT_ENTRY_EXTRA_ONLY(NUM, TYPE, ORIG, EXTRA) \
	_CREATE_LUT_ENTRY_EXTRA_ONLY(NUM, TYPE, ORIG, EXTRA)
#define _CREATE_LUT_ENTRY_EXTRA_ONLY(NUM, TYPE, ORIG, EXTRA) \
	CREATE_LUT_ENTRY_EXTRA_ONLY_##NUM(TYPE, ORIG, EXTRA)

#define CREATE_LUT_ENTRY_EXTRA_ONLY_2(TYPE, ORIG, EXTRA) \
	(TYPE *)ORIG, (TYPE *)ORIG, (TYPE *)ORIG, EXTRA
#define CREATE_LUT_ENTRY_EXTRA_ONLY_3(TYPE, ORIG, EXTRA) \
	(TYPE *)ORIG, (TYPE *)ORIG, (TYPE *)ORIG,  (TYPE *)ORIG, EXTRA

#endif //MACROS_H
