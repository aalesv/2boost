// This is an independent project of an individual developer. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

/*This file is part of 2Boost
*
*2Boost is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
*
*This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
*/

/* If you want to use non-standard sized tables
 * that will be incompatible with existing definitions,
 * please set last two digits of version to something different from zero.
*/

//Version string
volatile const char VERSION[] __attribute__((used)) ROM_METADATA = "2Boost " CALID " 0002.00.00";
//Map switch source (no switching / cruise button / Si-Srive switch) option. Can be modified by tuner.
volatile const unsigned char CFG_GLOBAL_MAP_SWITCH_SOURCE ROM_CONFIG = MAP_SWITCH_SOURCE_NONE;

//Declare RAM variables and place them at RAM hole
ram_variables_t *RAM_VARIABLES = ((ram_variables_t*)RAM_HOLE);

/*Headers include by specifying -include option for gcc*/

//Calc 3D function is located at ORIG_CALC_3D_FUNCTION_ADDRESS
calc_3d_float_t calc_3d_float = ((calc_3d_float_t)ORIG_CALC_3D_FUNCTION_ADDRESS); //-V566

#if defined ORIG_TABLE_TARGET_BOOST_ADDRESS
 //Create table and table pointer structure for Target Boost tables
CREATE_TABLE_3D_FLOAT(NUMBER_OF_TABLES, tblTargetBoost, TABLE_TARGET_BOOST_X_COUNT, TABLE_TARGET_BOOST_Y_COUNT, TABLE_TARGET_BOOST_DATA_TYPE, TABLE_TARGET_BOOST_MULTIPLIER, TABLE_TARGET_BOOST_OFFSET);
#endif

#if defined ORIG_TABLE_INIT_WGDC_ADDRESS
 //Create table and table pointer structure for Initial WGDC tables
CREATE_TABLE_3D_FLOAT(NUMBER_OF_TABLES, tblInitWGDC, TABLE_INIT_WGDC_X_COUNT, TABLE_INIT_WGDC_Y_COUNT, TABLE_INIT_WGDC_DATA_TYPE, TABLE_INIT_WGDC_MULTIPLIER, TABLE_INIT_WGDC_OFFSET);
#endif
#if defined ORIG_TABLE_MAX_WGDC_ADDRESS
 //Create table and table pointer structure for Max WGDC tables
CREATE_TABLE_3D_FLOAT(NUMBER_OF_TABLES, tblMaxWGDC, TABLE_MAX_WGDC_X_COUNT, TABLE_MAX_WGDC_Y_COUNT, TABLE_MAX_WGDC_DATA_TYPE, TABLE_MAX_WGDC_MULTIPLIER, TABLE_MAX_WGDC_OFFSET);
#endif

#if defined ORIG_TABLE_PRIMARY_OL_A_ADDRESS
 //Create table and table pointer structure for Primary Open Loop Fueling A tables
CREATE_TABLE_3D_FLOAT(NUMBER_OF_TABLES, tblPrimaryOLA, TABLE_PRIMARY_OL_X_COUNT, TABLE_PRIMARY_OL_Y_COUNT, TABLE_PRIMARY_OL_DATA_TYPE, TABLE_PRIMARY_OL_MULTIPLIER, TABLE_PRIMARY_OL_OFFSET);
#endif
#if defined ORIG_TABLE_PRIMARY_OL_B_ADDRESS
 //Create table and table pointer structure for Primary Open Loop Fueling B tables
CREATE_TABLE_3D_FLOAT(NUMBER_OF_TABLES, tblPrimaryOLB, TABLE_PRIMARY_OL_X_COUNT, TABLE_PRIMARY_OL_Y_COUNT, TABLE_PRIMARY_OL_DATA_TYPE, TABLE_PRIMARY_OL_MULTIPLIER, TABLE_PRIMARY_OL_OFFSET);
#endif

#if defined ORIG_TABLE_BASE_TIMING_A_ADDRESS
//Create table and table pointer structure for Base Timing A tables
CREATE_TABLE_3D_FLOAT(NUMBER_OF_TABLES, tblBaseTimingA, TABLE_BASE_TIMING_X_COUNT, TABLE_BASE_TIMING_Y_COUNT, TABLE_BASE_TIMING_DATA_TYPE, TABLE_BASE_TIMING_MULTIPLIER, TABLE_BASE_TIMING_OFFSET);
#endif
#if defined ORIG_TABLE_BASE_TIMING_B_ADDRESS
//Create table and table pointer structure for Base Timing B tables
CREATE_TABLE_3D_FLOAT(NUMBER_OF_TABLES, tblBaseTimingB, TABLE_BASE_TIMING_X_COUNT, TABLE_BASE_TIMING_Y_COUNT, TABLE_BASE_TIMING_DATA_TYPE, TABLE_BASE_TIMING_MULTIPLIER, TABLE_BASE_TIMING_OFFSET);
#endif
#if defined ORIG_TABLE_BASE_TIMING_C_ADDRESS
//Create table and table pointer structure for Base Timing C tables
CREATE_TABLE_3D_FLOAT(NUMBER_OF_TABLES, tblBaseTimingC, TABLE_BASE_TIMING_X_COUNT, TABLE_BASE_TIMING_Y_COUNT, TABLE_BASE_TIMING_DATA_TYPE, TABLE_BASE_TIMING_MULTIPLIER, TABLE_BASE_TIMING_OFFSET);
#endif
#if defined ORIG_TABLE_BASE_TIMING_D_ADDRESS
//Create table and table pointer structure for Base Timing D tables
CREATE_TABLE_3D_FLOAT(NUMBER_OF_TABLES, tblBaseTimingD, TABLE_BASE_TIMING_X_COUNT, TABLE_BASE_TIMING_Y_COUNT, TABLE_BASE_TIMING_DATA_TYPE, TABLE_BASE_TIMING_MULTIPLIER, TABLE_BASE_TIMING_OFFSET);
#endif

#if defined ORIG_TABLE_INTAKE_AVCS_A_ADDRESS
 //Create table and table pointer structure for Intake AVCS A tables
CREATE_TABLE_3D_FLOAT(NUMBER_OF_TABLES, tblIntakeAvcsA, TABLE_INTAKE_AVCS_X_COUNT, TABLE_INTAKE_AVCS_Y_COUNT, TABLE_INTAKE_AVCS_DATA_TYPE, TABLE_INTAKE_AVCS_MULTIPLIER, TABLE_INTAKE_AVCS_OFFSET);
#endif
#if defined ORIG_TABLE_INTAKE_AVCS_B_ADDRESS
 //Create table and table pointer structure for Intake AVCS B tables
CREATE_TABLE_3D_FLOAT(NUMBER_OF_TABLES, tblIntakeAvcsB, TABLE_INTAKE_AVCS_X_COUNT, TABLE_INTAKE_AVCS_Y_COUNT, TABLE_INTAKE_AVCS_DATA_TYPE, TABLE_INTAKE_AVCS_MULTIPLIER, TABLE_INTAKE_AVCS_OFFSET);
#endif

#if defined ORIG_TABLE_EXHAUST_AVCS_A_ADDRESS
 //Create table and table pointer structure for Exhaust AVCS A tables
CREATE_TABLE_3D_FLOAT(NUMBER_OF_TABLES, tblExhaustAvcsA, TABLE_EXHAUST_AVCS_X_COUNT, TABLE_EXHAUST_AVCS_Y_COUNT, TABLE_EXHAUST_AVCS_DATA_TYPE, TABLE_EXHAUST_AVCS_MULTIPLIER, TABLE_EXHAUST_AVCS_OFFSET);
#endif
#if defined ORIG_TABLE_EXHAUST_AVCS_B_ADDRESS
 //Create table and table pointer structure for Exhaust AVCS B tables
CREATE_TABLE_3D_FLOAT(NUMBER_OF_TABLES, tblExhaustAvcsB, TABLE_EXHAUST_AVCS_X_COUNT, TABLE_EXHAUST_AVCS_Y_COUNT, TABLE_EXHAUST_AVCS_DATA_TYPE, TABLE_EXHAUST_AVCS_MULTIPLIER, TABLE_EXHAUST_AVCS_OFFSET);
#endif

#if defined ORIG_TABLE_TARGET_THROTTLE_POSITION_A_ADDRESS
 //Create table and table pointer structure for Target Throttle Plate Position A tables
CREATE_TABLE_3D_FLOAT(NUMBER_OF_TABLES, tblTargetThrPosA, TABLE_THROTTLE_POSITION_X_COUNT, TABLE_THROTTLE_POSITION_Y_COUNT, TABLE_THROTTLE_POSITION_DATA_TYPE, TABLE_THROTTLE_POSITION_MULTIPLIER, TABLE_THROTTLE_POSITION_OFFSET);
#endif
#if defined ORIG_TABLE_TARGET_THROTTLE_POSITION_B_ADDRESS
 //Create table and table pointer structure for Target Throttle Plate Position B tables
CREATE_TABLE_3D_FLOAT(NUMBER_OF_TABLES, tblTargetThrPosB, TABLE_THROTTLE_POSITION_X_COUNT, TABLE_THROTTLE_POSITION_Y_COUNT, TABLE_THROTTLE_POSITION_DATA_TYPE, TABLE_THROTTLE_POSITION_MULTIPLIER, TABLE_THROTTLE_POSITION_OFFSET);
#endif

//Lookup table
//[][0] element contains orig table address
//[][1] element contains table 1 address
//[][2] element contains table 2 address
//[][3] element contains table 3 address
//Array of pointers
static const table_3d_float_t * const FLOAT_3D_LUT[][NUMBER_OF_TABLES+1] ROM_LUT = {
	#if defined ORIG_TABLE_TARGET_BOOST_ADDRESS
	CREATE_LUT_ENTRY(NUMBER_OF_TABLES, table_3d_float_t, ORIG_TABLE_TARGET_BOOST_ADDRESS, &tblTargetBoost),
	#endif
	#if defined ORIG_TABLE_INIT_WGDC_ADDRESS
	CREATE_LUT_ENTRY(NUMBER_OF_TABLES, table_3d_float_t, ORIG_TABLE_INIT_WGDC_ADDRESS, &tblInitWGDC),
	#endif
	#if defined ORIG_TABLE_MAX_WGDC_ADDRESS
	CREATE_LUT_ENTRY(NUMBER_OF_TABLES, table_3d_float_t, ORIG_TABLE_MAX_WGDC_ADDRESS, &tblMaxWGDC),
	#endif
	#if defined ORIG_TABLE_PRIMARY_OL_A_ADDRESS
	CREATE_LUT_ENTRY(NUMBER_OF_TABLES, table_3d_float_t, ORIG_TABLE_PRIMARY_OL_A_ADDRESS, &tblPrimaryOLA),
	#endif
	#if defined ORIG_TABLE_PRIMARY_OL_B_ADDRESS
	CREATE_LUT_ENTRY(NUMBER_OF_TABLES, table_3d_float_t, ORIG_TABLE_PRIMARY_OL_B_ADDRESS, &tblPrimaryOLB),
	#endif
	#if defined ORIG_TABLE_BASE_TIMING_A_ADDRESS
	CREATE_LUT_ENTRY(NUMBER_OF_TABLES, table_3d_float_t, ORIG_TABLE_BASE_TIMING_A_ADDRESS, &tblBaseTimingA),
	#endif
	#if defined ORIG_TABLE_BASE_TIMING_B_ADDRESS
	CREATE_LUT_ENTRY(NUMBER_OF_TABLES, table_3d_float_t, ORIG_TABLE_BASE_TIMING_B_ADDRESS, &tblBaseTimingB),
	#endif
	#if defined ORIG_TABLE_BASE_TIMING_C_ADDRESS
	CREATE_LUT_ENTRY(NUMBER_OF_TABLES, table_3d_float_t, ORIG_TABLE_BASE_TIMING_C_ADDRESS, &tblBaseTimingC),
	#endif
	#if defined ORIG_TABLE_BASE_TIMING_D_ADDRESS
	CREATE_LUT_ENTRY(NUMBER_OF_TABLES, table_3d_float_t, ORIG_TABLE_BASE_TIMING_D_ADDRESS, &tblBaseTimingD),
	#endif
	#if defined ORIG_TABLE_INTAKE_AVCS_A_ADDRESS
	CREATE_LUT_ENTRY(NUMBER_OF_TABLES, table_3d_float_t, ORIG_TABLE_INTAKE_AVCS_A_ADDRESS, &tblIntakeAvcsA),
	#endif
	#if defined ORIG_TABLE_INTAKE_AVCS_B_ADDRESS
	CREATE_LUT_ENTRY(NUMBER_OF_TABLES, table_3d_float_t, ORIG_TABLE_INTAKE_AVCS_B_ADDRESS, &tblIntakeAvcsB),
	#endif
	#if defined ORIG_TABLE_EXHAUST_AVCS_A_ADDRESS
	CREATE_LUT_ENTRY(NUMBER_OF_TABLES, table_3d_float_t, ORIG_TABLE_EXHAUST_AVCS_A_ADDRESS, &tblExhaustAvcsA),
	#endif
	#if defined ORIG_TABLE_EXHAUST_AVCS_B_ADDRESS
	CREATE_LUT_ENTRY(NUMBER_OF_TABLES, table_3d_float_t, ORIG_TABLE_EXHAUST_AVCS_B_ADDRESS, &tblExhaustAvcsB),
	#endif
	#if defined ORIG_TABLE_TARGET_THROTTLE_POSITION_A_ADDRESS
	CREATE_LUT_ENTRY(NUMBER_OF_TABLES, table_3d_float_t, ORIG_TABLE_TARGET_THROTTLE_POSITION_A_ADDRESS, &tblTargetThrPosA),
	#endif
	#if defined ORIG_TABLE_TARGET_THROTTLE_POSITION_B_ADDRESS
	CREATE_LUT_ENTRY(NUMBER_OF_TABLES, table_3d_float_t, ORIG_TABLE_TARGET_THROTTLE_POSITION_B_ADDRESS, &tblTargetThrPosB),
	#endif

};

//This function replaces original calc 3D table function
//According to SH CPU ABI specification, 
//registers R4-R7, FR4-FR11 are used for parameter passing.
//Thus x stored in FR4, y stored in FR5, tablePointer stored in R4
//the same as original function.
float calc_3d_float_hooked (const float x, const float y, const table_3d_float_t *tablePointer){
	int i;
	
	//Run through the LUT
	for (i=0; i < COUNT_OF(FLOAT_3D_LUT); i++) {
		//Break flag
		unsigned char f = 0;
		if (FLOAT_3D_LUT[i][0] == tablePointer) {
			//If table is in LUT, do the lookup
			unsigned char j = globalMapSwitch();
			//Careful, array overrun may occur
			tablePointer = FLOAT_3D_LUT[i][j];
			//GNUSH v13.01 GCC produces strange code if break is uncommented
			//break;
			//Use break flag instead
			f = 1;
		}
		
		//Break if entry is found
		if (f == 1)
			break;
	}

	//Call calc 3D function and return result
	//x passes through FR4, y passes through FR5, tablePointer passes through R4
	//as original function expects
	return calc_3d_float(x, y, tablePointer);
}

//Returns 1 if must use 1st map, 2 if must use 2nd map, 3 if must use 3d map
//This function is used as array index and can produce array overrun
unsigned char globalMapSwitch(){
	unsigned char res;
	
	switch (globalMapSwitchSource()) {
		//Map switching is disabled
		case MAP_SWITCH_SOURCE_NONE:
			res = 0;
			break;
		#if defined(P_CRUISE_STATE)
		//Cruise on/off based map switching
		//When Si-Drive support in enabled, 2boost switches between Intelligent and Sport maps in this case
		case MAP_SWITCH_SOURCE_CRUISE:
			//cruiseStateEnabled returns 0 or 1
			//Set map switch if cruise is enabled
			res = cruiseStateEnabled() + 1;
			break;
		#endif //P_CRUISE_STATE
		#if defined(P_SI_DRVIE_STATE)
		//Si-Drive based map switching 
		case MAP_SWITCH_SOURCE_SI_DRIVE:
			res = siDriveState();
			break;
		#endif //P_SI_DRVIE_STATE
		//In case of misconfiguration don't do map switching.
		default:
			res = 0;
			break;
	}
	
	//Place map number in RAM so it can be read with logger
	RAM_VARIABLES->globalMapSwitch = res;
	return res;
}

#if defined P_CRUISE_STATE_MASK_CRUISE_ENABLED
//Returns 1 if cruise is enabled, 0 otherwise
//Straight cruise logic
unsigned char cruiseStateEnabled (){
	if ((*P_CRUISE_STATE & P_CRUISE_STATE_MASK_CRUISE_ENABLED) == P_CRUISE_STATE_MASK_CRUISE_ENABLED) {
		//Cruise mode is enabled
		return 1;
	} else if ((*P_CRUISE_STATE & P_CRUISE_STATE_MASK_CRUISE_ENABLED) == 0) {
		//Cruise mode is disabled
		return 0;
	} else {
		//Think cruise mode is disabled
		return 0;
	}
}
#endif //P_CRUISE_STATE_MASK_CRUISE_ENABLED

#if defined P_CRUISE_STATE_MASK_CRUISE_DISABLED
//Returns 1 if cruise is enabled, 0 otherwise
//Reverse cruise logic
unsigned char cruiseStateEnabled (){
	if ((*P_CRUISE_STATE & P_CRUISE_STATE_MASK_CRUISE_DISABLED) == P_CRUISE_STATE_MASK_CRUISE_DISABLED) {
		//Cruise mode is disabled
		return 0;
	} else if ((*P_CRUISE_STATE & P_CRUISE_STATE_MASK_CRUISE_DISABLED) == 0) {
		//Cruise mode is enabled
		return 1;
	} else {
		//Think cruise mode is disabled
		return 0;
	}
}
#endif //P_CRUISE_STATE_MASK_CRUISE_DISABLED

//How to switch between maps
//do not switch - stock map will be used
//use Cruise On/Off switch
//or use Si-Drive switch (if supported by ROM)
unsigned char globalMapSwitchSource () {
	//This const is defined earlier
	return CFG_GLOBAL_MAP_SWITCH_SOURCE;
}

#if defined P_SI_DRVIE_STATE
//Return Si-Drive switch state
//Return SI_DRIVE_STATE_NONE if Si-Drive error
unsigned char siDriveState () {
	unsigned char res;
	
	switch (*P_SI_DRVIE_STATE) {
		case 3:
		case 16:
			res = SI_DRIVE_STATE_INTELLIGENT;
			break;
		case 1:
			res = SI_DRIVE_STATE_SPORT;
			break;
		case 2:
		case 8:
			res = SI_DRIVE_STATE_SPORT_SHARP;
			break;
		default:
			res = SI_DRIVE_STATE_NONE;
			break;
	}
	
	return res;
}
#endif //P_SI_DRVIE_STATE

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