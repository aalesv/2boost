// This is an independent project of an individual developer. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

/*This file is part of 2Boost
*
*2Boost is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
*
*This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
*/

#include "calc_hooked.h"

//NUMBER_OF_TABLES - number of tables for each hack section
//Defined in macros.h

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
static const table_3d_float_t * const FLOAT_3D_LUT[][NUMBER_OF_TABLES+1] = {
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
//x - X axis value
//y - Y axis value
//*tablePointer - pointer to structure that desctibes 3D table
//Returns Z axis value
//
//According to SH CPU ABI specification, 
//registers R4-R7, FR4-FR11 used for parameter passing.
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
			#if defined(LUT_CHECK_OVERRUN)
				//Just in case let's do additional check to prevent array overrun.
				j = sanitizeLutSecondIndex(j);
			#endif //LUT_CHECK_OVERRUN
			//Current selected map number
			RAM_VARIABLES -> mapSelected = j;
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

//Prevent LUT array overrun condition
static inline unsigned char sanitizeLutSecondIndex (unsigned char index) {
	if (index > NUMBER_OF_TABLES) {
		//This should never happen!
		//Zeroing second LUT index will disable all hacks
		index = 0;
	}
	
	return index;
}
