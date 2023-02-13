// This is an independent project of an individual developer. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

/*This file is part of 2Boost
*
*2Boost is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
*
*This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
*/

#if defined(P_CRUISE_STATE_MASK_CRUISE_ENABLED) && defined(P_CRUISE_STATE_MASK_CRUISE_DISABLED)
#error Only one of P_CRUISE_STATE_MASK_CRUISE_ENABLED and P_CRUISE_STATE_MASK_CRUISE_DISABLED must be defined
#endif

#if !defined(P_CRUISE_STATE_MASK_CRUISE_ENABLED) && !defined(P_CRUISE_STATE_MASK_CRUISE_DISABLED)
#error P_CRUISE_STATE_MASK_CRUISE_ENABLED or P_CRUISE_STATE_MASK_CRUISE_DISABLED must be defined
#endif

#if defined(P_CRUISE_STATE_MASK_CRUISE_ENABLED)
#pragma message "P_CRUISE_STATE_MASK_CRUISE_ENABLED is defined, using straight cruise logic"
#endif

#if defined(P_CRUISE_STATE_MASK_CRUISE_DISABLED)
#pragma message "P_CRUISE_STATE_MASK_CRUISE_DISABLED is defined, using reverse cruise logic"
#endif

//Number of tables for each hack section
#if defined(P_SI_DRVIE_STATE)
 #define NUMBER_OF_TABLES 3
#elif defined(P_CRUISE_STATE) //P_SI_DRVIE_STATE
 #define NUMBER_OF_TABLES 2
#endif //P_CRUISE_STATE

//Define binary file sections. Vars and functions with no section specified will be stripped!
//Main ROM code
#define ROM_CODE  		LD_SECTION("RomHole_Code", 4)
//ROM metadata - version etc.
#define ROM_METADATA	LD_SECTION("RomHole_Metadata", 4)
//ROM internal variables
#define ROM_DATA		LD_SECTION("RomHole_Data", 4)
//ROM config data that can be modified by tuner
#define ROM_CONFIG		LD_SECTION("RomHole_Config", 1)
//Tables pointer structures
#define ROM_TABLE_PTR	LD_SECTION("RomHole_TablePtr", 4)
//Tables themselves
#define ROM_TABLE_DATA  LD_SECTION("RomHole_TableData", 4)
//Lookup tables
#define ROM_LUT			LD_SECTION("RomHole_LUT", 4)
//Tests
#define ROM_TESTS_CODE	LD_SECTION("RomHole_TestsCode", 4)
//Tests internal variables
#define ROM_TESTS_DATA	LD_SECTION("RomHole_TestsData", 4)

//A section definition
#define LD_SECTION(SECTION, ALIGN) __attribute__ ((section (SECTION),aligned(ALIGN)))

//Optimization level macros
#define OPTIMIZE(LEVEL) __attribute__((optimize(LEVEL)))

//Specify this to always inline a function
#define ALWAYS_INLINE __attribute__((always_inline))

//Array size macro
#define COUNT_OF(x) ((sizeof(x)/sizeof(0[x])) / ((unsigned int)(!(sizeof(x) % sizeof(0[x])))))

//Data types. Used in tables autogeneration
#define UINT_16 unsigned short
#define UINT_0x8000000 UINT_16
#define UINT_0x08000000 UINT_16

#define UINT_8 unsigned char
#define UINT_0x4000000 UINT_8
#define UINT_0x04000000 UINT_8

//Macro for creating table structures
//X axis is float
//Y axis is float
//Data is byte converted to float at runtime
//NUM - number of tables
#define CREATE_TABLE_3D_FLOAT(NUM, NAME, X_COUNT, Y_COUNT, DATA_TYPE, MULTIPLIER, OFFSET) _CREATE_TABLE_3D_FLOAT(NUM, NAME, X_COUNT, Y_COUNT, DATA_TYPE, MULTIPLIER, OFFSET)
//Needed for correct macro stringifying
#define _CREATE_TABLE_3D_FLOAT(NUM, NAME, X_COUNT, Y_COUNT, DATA_TYPE, MULTIPLIER, OFFSET) CREATE_TABLE_3D_FLOAT_##NUM(NAME, X_COUNT, Y_COUNT, DATA_TYPE, MULTIPLIER, OFFSET)

//Create 2 tables - NAME1, NAME2
#define CREATE_TABLE_3D_FLOAT_2(NAME, X_COUNT, Y_COUNT, DATA_TYPE, MULTIPLIER, OFFSET) \
	CREATE_TABLE_3D_FLOAT_1(NAME##1, X_COUNT, Y_COUNT, DATA_TYPE, MULTIPLIER, OFFSET) \
	CREATE_TABLE_3D_FLOAT_1(NAME##2, X_COUNT, Y_COUNT, DATA_TYPE, MULTIPLIER, OFFSET)
	
//Create 3 tables - NAME1, NAME2, NAME3
#define CREATE_TABLE_3D_FLOAT_3(NAME, X_COUNT, Y_COUNT, DATA_TYPE, MULTIPLIER, OFFSET) \
	CREATE_TABLE_3D_FLOAT_1(NAME##1, X_COUNT, Y_COUNT, DATA_TYPE, MULTIPLIER, OFFSET) \
	CREATE_TABLE_3D_FLOAT_1(NAME##2, X_COUNT, Y_COUNT, DATA_TYPE, MULTIPLIER, OFFSET) \
	CREATE_TABLE_3D_FLOAT_1(NAME##3, X_COUNT, Y_COUNT, DATA_TYPE, MULTIPLIER, OFFSET)

//Create 1 table - NAME
#define CREATE_TABLE_3D_FLOAT_1(NAME, X_COUNT, Y_COUNT, DATA_TYPE, MULTIPLIER, OFFSET) _CREATE_TABLE_3D_FLOAT_1(NAME, X_COUNT, Y_COUNT, DATA_TYPE, MULTIPLIER, OFFSET)
//Needed for correct macro stringifying
#define _CREATE_TABLE_3D_FLOAT_1(NAME, X_COUNT, Y_COUNT, DATA_TYPE, MULTIPLIER, OFFSET) const float NAME##_x_axis [X_COUNT] ROM_TABLE_DATA = {0}; \
	const float NAME##_y_axis [Y_COUNT] ROM_TABLE_DATA = {0}; \
	const UINT_##DATA_TYPE NAME##_data [X_COUNT * Y_COUNT] ROM_TABLE_DATA = {0}; \
\
	const table_3d_float_t NAME ROM_TABLE_PTR = { \
		.x_len = X_COUNT, \
		.y_len = Y_COUNT, \
		.x_axis_ptr = & NAME##_x_axis, \
		.y_axis_ptr = & NAME##_y_axis, \
		.data_ptr = & NAME##_data, \
		.data_type = DATA_TYPE, \
		.multiplier = MULTIPLIER, \
		.offset = OFFSET \
	};

//Macro for creatig Lookup Table entry
//It's just array of pointers explicitly cast to TYPE
//NUM - number of tables
#define CREATE_LUT_ENTRY(NUM, TYPE, ORIG, REPL) _CREATE_LUT_ENTRY(NUM, TYPE, ORIG, REPL)
//Needed for correct macro stringifying
#define _CREATE_LUT_ENTRY(NUM, TYPE, ORIG, REPL) CREATE_LUT_ENTRY_##NUM(TYPE, ORIG, REPL)

//Create 2 entries - REPL1, REPL2
#define CREATE_LUT_ENTRY_2(TYPE, ORIG, REPL) {(TYPE *)ORIG, (TYPE *)REPL##1, (TYPE *)REPL##2}
//Create 3 entries - REPL1, REPL2, REPL3
#define CREATE_LUT_ENTRY_3(TYPE, ORIG, REPL) {(TYPE *)ORIG, (TYPE *)REPL##1, (TYPE *)REPL##2, (TYPE *)REPL##3}

enum MAP_SWITCH_SOURCE {
	MAP_SWITCH_SOURCE_NONE, //Turn off all hacks
	MAP_SWITCH_SOURCE_CRUISE, //Cruise on/off switch
	MAP_SWITCH_SOURCE_SI_DRIVE //Si-Drive switch
};

enum SI_DRIVE_STATE {
	SI_DRIVE_STATE_NONE, //Error
	SI_DRIVE_STATE_INTELLIGENT,
	SI_DRIVE_STATE_SPORT,
	SI_DRIVE_STATE_SPORT_SHARP
};
	

//Type def for our global variables
typedef struct {
	//0 if must use orig map, 1 if must use 1st mod map and so on
	unsigned char globalMapSwitch;
} ram_variables_t;

//Type def for 3D table
typedef struct {
	short x_len;
	short y_len;
	void *x_axis_ptr;
	void *y_axis_ptr;
	void *data_ptr;
	long data_type;
	float multiplier;
	float offset;
} table_3d_float_t;

//Type for calc 3D fuction
typedef float (*calc_3d_float_t)(float, float, const table_3d_float_t *);

//Calc 3D function. Address is set in 2boost_switch_cruise.c
extern calc_3d_float_t calc_3d_float ROM_DATA;

//RAM variables. Address is set in 2boost_switch_cruise.c
extern ram_variables_t *RAM_VARIABLES ROM_DATA;

//This function replaces original calc 3D table function
float calc_3d_float_hooked (const float x, const float y, const table_3d_float_t *tablePointer) OPTIMIZE("O") ROM_CODE;
//Returns 1 if must use 1st map, 2 if must use 2nd map, 3 if must use 3d map
unsigned char globalMapSwitch() OPTIMIZE("O") ROM_CODE;
//Returns 1 if cruise is enabled, 0 otherwise
unsigned char cruiseStateEnabled () OPTIMIZE("O") ROM_CODE;
//Returns map switch source defined in MAP_SWITCH_SOURCE enum
//As function will always be inlined, do not specify linker section and it will be stripped
inline static unsigned char globalMapSwitchSource () ALWAYS_INLINE OPTIMIZE("O");
//Returns 1 if I, 2 if S, 3 if S#, 0 otherwise
unsigned char siDriveState () OPTIMIZE("O") ROM_CODE;

#if defined(BUILD_TESTS)
	//Test calc_3d_float_hooked() call for all defined tables
	//and modes - Cruise on/off, all Si-Drive modes
	void test_calc_3d_float_hooked_all_tables_and_modes() OPTIMIZE("O") ROM_TESTS_CODE;
	#if defined(ORIG_TABLE_BASE_TIMING_A_ADDRESS)
		//Test calc_3d_float_hooked() call for Timing tables
		inline void test_calc_3d_float_hooked_timing() OPTIMIZE("O") ROM_TESTS_CODE;
	#endif //ORIG_TABLE_BASE_TIMING_A_ADDRESS
#endif //BUILD_TESTS

/* If you want to use non-standard sized tables
 * that will be incompatible with existing definitions,
 * please set last two digits of version to something different from zero.
*/

//Version string
extern volatile const char VERSION[];
//Map switch source (no switching / cruise button / Si-Srive switch) option. Can be modified by tuner.
extern volatile const unsigned char CFG_GLOBAL_MAP_SWITCH_SOURCE;
