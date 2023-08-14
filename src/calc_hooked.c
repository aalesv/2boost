// This is an independent project of an individual developer. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

/*This file is part of 2Boost
*
*2Boost is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
*
*This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
*/

#include "calc_hooked.h"

//NUMBER_OF_REGULAR_TABLES - number of tables for each hack section
//Defined in macros.h

//3D UINT tables
#if defined ORIG_TABLE_TARGET_BOOST_ADDRESS
	//Create Overtake table and table pointer structure for Target Boost table
	CREATE_TABLE_3D_UINT(1,tblTargetBoostOvertake, TABLE_TARGET_BOOST_X_COUNT, TABLE_TARGET_BOOST_Y_COUNT, TABLE_TARGET_BOOST_DATA_TYPE, TABLE_TARGET_BOOST_MULTIPLIER, TABLE_TARGET_BOOST_OFFSET);
	
	//Create table and table pointer structure for Target Boost tables
	CREATE_TABLE_3D_UINT(NUMBER_OF_REGULAR_TABLES, tblTargetBoost, TABLE_TARGET_BOOST_X_COUNT, TABLE_TARGET_BOOST_Y_COUNT, TABLE_TARGET_BOOST_DATA_TYPE, TABLE_TARGET_BOOST_MULTIPLIER, TABLE_TARGET_BOOST_OFFSET);
#endif //ORIG_TABLE_TARGET_BOOST_ADDRESS

#if defined ORIG_TABLE_INIT_WGDC_ADDRESS
	//Create Overtake table and table pointer structure for Initial WGDC table
	CREATE_TABLE_3D_UINT(1, tblInitWGDCOvertake, TABLE_INIT_WGDC_X_COUNT, TABLE_INIT_WGDC_Y_COUNT, TABLE_INIT_WGDC_DATA_TYPE, TABLE_INIT_WGDC_MULTIPLIER, TABLE_INIT_WGDC_OFFSET);

	//Create table and table pointer structure for Initial WGDC tables
	CREATE_TABLE_3D_UINT(NUMBER_OF_REGULAR_TABLES, tblInitWGDC, TABLE_INIT_WGDC_X_COUNT, TABLE_INIT_WGDC_Y_COUNT, TABLE_INIT_WGDC_DATA_TYPE, TABLE_INIT_WGDC_MULTIPLIER, TABLE_INIT_WGDC_OFFSET);
#endif //ORIG_TABLE_INIT_WGDC_ADDRESS

#if defined ORIG_TABLE_MAX_WGDC_ADDRESS
	//Create Overtake table and table pointer structure for Max WGDC tables
	CREATE_TABLE_3D_UINT(1, tblMaxWGDCOvertake, TABLE_MAX_WGDC_X_COUNT, TABLE_MAX_WGDC_Y_COUNT, TABLE_MAX_WGDC_DATA_TYPE, TABLE_MAX_WGDC_MULTIPLIER, TABLE_MAX_WGDC_OFFSET);

	//Create table and table pointer structure for Max WGDC tables
	CREATE_TABLE_3D_UINT(NUMBER_OF_REGULAR_TABLES, tblMaxWGDC, TABLE_MAX_WGDC_X_COUNT, TABLE_MAX_WGDC_Y_COUNT, TABLE_MAX_WGDC_DATA_TYPE, TABLE_MAX_WGDC_MULTIPLIER, TABLE_MAX_WGDC_OFFSET);
#endif //ORIG_TABLE_MAX_WGDC_ADDRESS

#if defined ORIG_TABLE_PRIMARY_OL_A_ADDRESS
	//Create Overtake table and table pointer structure for Primary Open Loop Fueling tables
	CREATE_TABLE_3D_UINT(1, tblPrimaryOLOvertake, TABLE_PRIMARY_OL_X_COUNT, TABLE_PRIMARY_OL_Y_COUNT, TABLE_PRIMARY_OL_DATA_TYPE, TABLE_PRIMARY_OL_MULTIPLIER, TABLE_PRIMARY_OL_OFFSET);

	//Create table and table pointer structure for Primary Open Loop Fueling A tables
	CREATE_TABLE_3D_UINT(NUMBER_OF_REGULAR_TABLES, tblPrimaryOLA, TABLE_PRIMARY_OL_X_COUNT, TABLE_PRIMARY_OL_Y_COUNT, TABLE_PRIMARY_OL_DATA_TYPE, TABLE_PRIMARY_OL_MULTIPLIER, TABLE_PRIMARY_OL_OFFSET);
#endif //ORIG_TABLE_PRIMARY_OL_A_ADDRESS

#if defined ORIG_TABLE_PRIMARY_OL_B_ADDRESS
	//Create table and table pointer structure for Primary Open Loop Fueling B tables
	CREATE_TABLE_3D_UINT(NUMBER_OF_REGULAR_TABLES, tblPrimaryOLB, TABLE_PRIMARY_OL_X_COUNT, TABLE_PRIMARY_OL_Y_COUNT, TABLE_PRIMARY_OL_DATA_TYPE, TABLE_PRIMARY_OL_MULTIPLIER, TABLE_PRIMARY_OL_OFFSET);
#endif

#if defined ORIG_TABLE_BASE_TIMING_A_ADDRESS
	//Create Overtake table and table pointer structure for Base Timing tables
	CREATE_TABLE_3D_UINT(1, tblBaseTimingOvertake, TABLE_BASE_TIMING_X_COUNT, TABLE_BASE_TIMING_Y_COUNT, TABLE_BASE_TIMING_DATA_TYPE, TABLE_BASE_TIMING_MULTIPLIER, TABLE_BASE_TIMING_OFFSET);

	//Create table and table pointer structure for Base Timing A tables
	CREATE_TABLE_3D_UINT(NUMBER_OF_REGULAR_TABLES, tblBaseTimingA, TABLE_BASE_TIMING_X_COUNT, TABLE_BASE_TIMING_Y_COUNT, TABLE_BASE_TIMING_DATA_TYPE, TABLE_BASE_TIMING_MULTIPLIER, TABLE_BASE_TIMING_OFFSET);
#endif //ORIG_TABLE_BASE_TIMING_A_ADDRESS

#if defined ORIG_TABLE_BASE_TIMING_B_ADDRESS
	//Create table and table pointer structure for Base Timing B tables
	CREATE_TABLE_3D_UINT(NUMBER_OF_REGULAR_TABLES, tblBaseTimingB, TABLE_BASE_TIMING_X_COUNT, TABLE_BASE_TIMING_Y_COUNT, TABLE_BASE_TIMING_DATA_TYPE, TABLE_BASE_TIMING_MULTIPLIER, TABLE_BASE_TIMING_OFFSET);
#endif
#if defined ORIG_TABLE_BASE_TIMING_C_ADDRESS
	//Create table and table pointer structure for Base Timing C tables
	CREATE_TABLE_3D_UINT(NUMBER_OF_REGULAR_TABLES, tblBaseTimingC, TABLE_BASE_TIMING_X_COUNT, TABLE_BASE_TIMING_Y_COUNT, TABLE_BASE_TIMING_DATA_TYPE, TABLE_BASE_TIMING_MULTIPLIER, TABLE_BASE_TIMING_OFFSET);
#endif
#if defined ORIG_TABLE_BASE_TIMING_D_ADDRESS
	//Create table and table pointer structure for Base Timing D tables
	CREATE_TABLE_3D_UINT(NUMBER_OF_REGULAR_TABLES, tblBaseTimingD, TABLE_BASE_TIMING_X_COUNT, TABLE_BASE_TIMING_Y_COUNT, TABLE_BASE_TIMING_DATA_TYPE, TABLE_BASE_TIMING_MULTIPLIER, TABLE_BASE_TIMING_OFFSET);
#endif

#if defined ORIG_TABLE_INTAKE_AVCS_A_ADDRESS
	//Create Overtake table and table pointer structure for Intake AVCS tables
	CREATE_TABLE_3D_UINT(1, tblIntakeAvcsOvertake, TABLE_INTAKE_AVCS_X_COUNT, TABLE_INTAKE_AVCS_Y_COUNT, TABLE_INTAKE_AVCS_DATA_TYPE, TABLE_INTAKE_AVCS_MULTIPLIER, TABLE_INTAKE_AVCS_OFFSET);

	//Create table and table pointer structure for Intake AVCS A tables
	CREATE_TABLE_3D_UINT(NUMBER_OF_REGULAR_TABLES, tblIntakeAvcsA, TABLE_INTAKE_AVCS_X_COUNT, TABLE_INTAKE_AVCS_Y_COUNT, TABLE_INTAKE_AVCS_DATA_TYPE, TABLE_INTAKE_AVCS_MULTIPLIER, TABLE_INTAKE_AVCS_OFFSET);
#endif //ORIG_TABLE_INTAKE_AVCS_A_ADDRESS

#if defined ORIG_TABLE_INTAKE_AVCS_B_ADDRESS
	//Create table and table pointer structure for Intake AVCS B tables
	CREATE_TABLE_3D_UINT(NUMBER_OF_REGULAR_TABLES, tblIntakeAvcsB, TABLE_INTAKE_AVCS_X_COUNT, TABLE_INTAKE_AVCS_Y_COUNT, TABLE_INTAKE_AVCS_DATA_TYPE, TABLE_INTAKE_AVCS_MULTIPLIER, TABLE_INTAKE_AVCS_OFFSET);
#endif

#if defined ORIG_TABLE_EXHAUST_AVCS_A_ADDRESS
	//Create Overtake table and table pointer structure for Exhaust AVCS tables
	CREATE_TABLE_3D_UINT(1, tblExhaustAvcsOvertake, TABLE_EXHAUST_AVCS_X_COUNT, TABLE_EXHAUST_AVCS_Y_COUNT, TABLE_EXHAUST_AVCS_DATA_TYPE, TABLE_EXHAUST_AVCS_MULTIPLIER, TABLE_EXHAUST_AVCS_OFFSET);
	
	//Create table and table pointer structure for Exhaust AVCS A tables
	CREATE_TABLE_3D_UINT(NUMBER_OF_REGULAR_TABLES, tblExhaustAvcsA, TABLE_EXHAUST_AVCS_X_COUNT, TABLE_EXHAUST_AVCS_Y_COUNT, TABLE_EXHAUST_AVCS_DATA_TYPE, TABLE_EXHAUST_AVCS_MULTIPLIER, TABLE_EXHAUST_AVCS_OFFSET);
#endif
#if defined ORIG_TABLE_EXHAUST_AVCS_B_ADDRESS
 //Create table and table pointer structure for Exhaust AVCS B tables
CREATE_TABLE_3D_UINT(NUMBER_OF_REGULAR_TABLES, tblExhaustAvcsB, TABLE_EXHAUST_AVCS_X_COUNT, TABLE_EXHAUST_AVCS_Y_COUNT, TABLE_EXHAUST_AVCS_DATA_TYPE, TABLE_EXHAUST_AVCS_MULTIPLIER, TABLE_EXHAUST_AVCS_OFFSET);
#endif

#if defined ORIG_TABLE_TARGET_THROTTLE_POSITION_A_ADDRESS
	//Create Overtake table and table pointer structure for Target Throttle Plate Position tables
	CREATE_TABLE_3D_UINT(1, tblTargetThrPosOvertake, TABLE_THROTTLE_POSITION_X_COUNT, TABLE_THROTTLE_POSITION_Y_COUNT, TABLE_THROTTLE_POSITION_DATA_TYPE, TABLE_THROTTLE_POSITION_MULTIPLIER, TABLE_THROTTLE_POSITION_OFFSET);
	
	//Create table and table pointer structure for Target Throttle Plate Position A tables
	CREATE_TABLE_3D_UINT(NUMBER_OF_REGULAR_TABLES, tblTargetThrPosA, TABLE_THROTTLE_POSITION_X_COUNT, TABLE_THROTTLE_POSITION_Y_COUNT, TABLE_THROTTLE_POSITION_DATA_TYPE, TABLE_THROTTLE_POSITION_MULTIPLIER, TABLE_THROTTLE_POSITION_OFFSET);
#endif
#if defined ORIG_TABLE_TARGET_THROTTLE_POSITION_B_ADDRESS
 //Create table and table pointer structure for Target Throttle Plate Position B tables
CREATE_TABLE_3D_UINT(NUMBER_OF_REGULAR_TABLES, tblTargetThrPosB, TABLE_THROTTLE_POSITION_X_COUNT, TABLE_THROTTLE_POSITION_Y_COUNT, TABLE_THROTTLE_POSITION_DATA_TYPE, TABLE_THROTTLE_POSITION_MULTIPLIER, TABLE_THROTTLE_POSITION_OFFSET);
#endif

//Create Requested Torque (Accelerator Pedal) tables
#if defined P_SI_DRVIE_STATE
	//For Si-Drive cars create only Overtake table
	#if defined ORIG_TABLE_REQUESTED_TORQUE_ACCELERATOR_PEDAL_A_ADDRESS
		CREATE_TABLE_3D_UINT(1, tblReqTorqueAccPedalOvertake, TABLE_REQUESTED_TORQUE_ACCELERATOR_PEDAL_X_COUNT, TABLE_REQUESTED_TORQUE_ACCELERATOR_PEDAL_Y_COUNT, TABLE_REQUESTED_TORQUE_ACCELERATOR_PEDAL_DATA_TYPE, TABLE_REQUESTED_TORQUE_ACCELERATOR_PEDAL_MULTIPLIER, TABLE_REQUESTED_TORQUE_ACCELERATOR_PEDAL_OFFSET);
	#endif //ORIG_TABLE_REQUESTED_TORQUE_ACCELERATOR_PEDAL_A_ADDRESS
#else
	//For non Si-Drive cars create all tables
	#if defined ORIG_TABLE_REQUESTED_TORQUE_ACCELERATOR_PEDAL_A_ADDRESS
		CREATE_TABLE_3D_UINT(1, tblReqTorqueAccPedalOvertake, TABLE_REQUESTED_TORQUE_ACCELERATOR_PEDAL_X_COUNT, TABLE_REQUESTED_TORQUE_ACCELERATOR_PEDAL_Y_COUNT, TABLE_REQUESTED_TORQUE_ACCELERATOR_PEDAL_DATA_TYPE, TABLE_REQUESTED_TORQUE_ACCELERATOR_PEDAL_MULTIPLIER, TABLE_REQUESTED_TORQUE_ACCELERATOR_PEDAL_OFFSET);

		CREATE_TABLE_3D_UINT(NUMBER_OF_REGULAR_TABLES, tblReqTorqueAccPedalA, TABLE_REQUESTED_TORQUE_ACCELERATOR_PEDAL_X_COUNT, TABLE_REQUESTED_TORQUE_ACCELERATOR_PEDAL_Y_COUNT, TABLE_REQUESTED_TORQUE_ACCELERATOR_PEDAL_DATA_TYPE, TABLE_REQUESTED_TORQUE_ACCELERATOR_PEDAL_MULTIPLIER, TABLE_REQUESTED_TORQUE_ACCELERATOR_PEDAL_OFFSET);
	#endif //ORIG_TABLE_REQUESTED_TORQUE_ACCELERATOR_PEDAL_A_ADDRESS
	#if defined ORIG_TABLE_REQUESTED_TORQUE_ACCELERATOR_PEDAL_B_ADDRESS
		CREATE_TABLE_3D_UINT(NUMBER_OF_REGULAR_TABLES, tblReqTorqueAccPedalB, TABLE_REQUESTED_TORQUE_ACCELERATOR_PEDAL_X_COUNT, TABLE_REQUESTED_TORQUE_ACCELERATOR_PEDAL_Y_COUNT, TABLE_REQUESTED_TORQUE_ACCELERATOR_PEDAL_DATA_TYPE, TABLE_REQUESTED_TORQUE_ACCELERATOR_PEDAL_MULTIPLIER, TABLE_REQUESTED_TORQUE_ACCELERATOR_PEDAL_OFFSET);
	#endif //ORIG_TABLE_REQUESTED_TORQUE_ACCELERATOR_PEDAL_B_ADDRESS
	#if defined ORIG_TABLE_REQUESTED_TORQUE_ACCELERATOR_PEDAL_C_ADDRESS
		CREATE_TABLE_3D_UINT(NUMBER_OF_REGULAR_TABLES, tblReqTorqueAccPedalC, TABLE_REQUESTED_TORQUE_ACCELERATOR_PEDAL_X_COUNT, TABLE_REQUESTED_TORQUE_ACCELERATOR_PEDAL_Y_COUNT, TABLE_REQUESTED_TORQUE_ACCELERATOR_PEDAL_DATA_TYPE, TABLE_REQUESTED_TORQUE_ACCELERATOR_PEDAL_MULTIPLIER, TABLE_REQUESTED_TORQUE_ACCELERATOR_PEDAL_OFFSET);
	#endif //ORIG_TABLE_REQUESTED_TORQUE_ACCELERATOR_PEDAL_C_ADDRESS
#endif //P_SI_DRVIE_STATE
	

//2D UINT tables

//All Throttle Tip-in Enrichment tables maps to A1, A2, A3 tables
#if defined ORIG_TABLE_THROTTLE_TIP_IN_ENRICHMENT_A_ADDRESS
	//Create Overtake table and table pointer structure for Throttle Tip-in Enrichment tables
	CREATE_TABLE_2D_UINT(1, tblThrTipInOvertake, TABLE_THROTTLE_TIP_IN_X_COUNT, TABLE_THROTTLE_TIP_IN_DATA_TYPE, TABLE_THROTTLE_TIP_IN_MULTIPLIER, TABLE_THROTTLE_TIP_IN_OFFSET);

	//Create table and table pointer structure for Throttle Tip-in Enrichment A tables
	CREATE_TABLE_2D_UINT(NUMBER_OF_REGULAR_TABLES, tblThrTipInA, TABLE_THROTTLE_TIP_IN_X_COUNT, TABLE_THROTTLE_TIP_IN_DATA_TYPE, TABLE_THROTTLE_TIP_IN_MULTIPLIER, TABLE_THROTTLE_TIP_IN_OFFSET);
#endif

//Lookup table 3D UINT
//[][0] element contains orig table address
//[][1] element contains table 1 address
//[][2] element contains table 2 address
//[][3] element contains table 3 address
//[][4] element contains Overtake table address
//Array of pointers
static const table_3d_uint_t * const LUT_3D_UINT[][LUT_COLUMN_COUNT] = {
	#if defined ORIG_TABLE_TARGET_BOOST_ADDRESS
		CREATE_LUT_ENTRY(NUMBER_OF_REGULAR_TABLES, table_3d_uint_t, ORIG_TABLE_TARGET_BOOST_ADDRESS, &tblTargetBoost, &tblTargetBoostOvertake),
	#endif //ORIG_TABLE_TARGET_BOOST_ADDRESS

	#if defined ORIG_TABLE_INIT_WGDC_ADDRESS
		CREATE_LUT_ENTRY(NUMBER_OF_REGULAR_TABLES, table_3d_uint_t, ORIG_TABLE_INIT_WGDC_ADDRESS, &tblInitWGDC, &tblInitWGDCOvertake),
	#endif //ORIG_TABLE_INIT_WGDC_ADDRESS

	#if defined ORIG_TABLE_MAX_WGDC_ADDRESS
		CREATE_LUT_ENTRY(NUMBER_OF_REGULAR_TABLES, table_3d_uint_t, ORIG_TABLE_MAX_WGDC_ADDRESS, &tblMaxWGDC, &tblMaxWGDCOvertake),
	#endif //ORIG_TABLE_MAX_WGDC_ADDRESS

	#if defined ORIG_TABLE_PRIMARY_OL_A_ADDRESS
		CREATE_LUT_ENTRY(NUMBER_OF_REGULAR_TABLES, table_3d_uint_t, ORIG_TABLE_PRIMARY_OL_A_ADDRESS, &tblPrimaryOLA, &tblPrimaryOLOvertake),
	#endif //ORIG_TABLE_PRIMARY_OL_A_ADDRESS
	#if defined ORIG_TABLE_PRIMARY_OL_B_ADDRESS
		CREATE_LUT_ENTRY(NUMBER_OF_REGULAR_TABLES, table_3d_uint_t, ORIG_TABLE_PRIMARY_OL_B_ADDRESS, &tblPrimaryOLB, &tblPrimaryOLOvertake),
	#endif //ORIG_TABLE_PRIMARY_OL_B_ADDRESS

	#if defined ORIG_TABLE_BASE_TIMING_A_ADDRESS
		CREATE_LUT_ENTRY(NUMBER_OF_REGULAR_TABLES, table_3d_uint_t, ORIG_TABLE_BASE_TIMING_A_ADDRESS, &tblBaseTimingA, &tblBaseTimingOvertake),
	#endif //ORIG_TABLE_BASE_TIMING_A_ADDRESS
	#if defined ORIG_TABLE_BASE_TIMING_B_ADDRESS
		CREATE_LUT_ENTRY(NUMBER_OF_REGULAR_TABLES, table_3d_uint_t, ORIG_TABLE_BASE_TIMING_B_ADDRESS, &tblBaseTimingB, &tblBaseTimingOvertake),
	#endif //ORIG_TABLE_BASE_TIMING_B_ADDRESS
	#if defined ORIG_TABLE_BASE_TIMING_C_ADDRESS
		CREATE_LUT_ENTRY(NUMBER_OF_REGULAR_TABLES, table_3d_uint_t, ORIG_TABLE_BASE_TIMING_C_ADDRESS, &tblBaseTimingC, &tblBaseTimingOvertake),
	#endif //ORIG_TABLE_BASE_TIMING_C_ADDRESS
	#if defined ORIG_TABLE_BASE_TIMING_D_ADDRESS
		CREATE_LUT_ENTRY(NUMBER_OF_REGULAR_TABLES, table_3d_uint_t, ORIG_TABLE_BASE_TIMING_D_ADDRESS, &tblBaseTimingD, &tblBaseTimingOvertake),
	#endif //ORIG_TABLE_BASE_TIMING_D_ADDRESS

	#if defined ORIG_TABLE_INTAKE_AVCS_A_ADDRESS
		CREATE_LUT_ENTRY(NUMBER_OF_REGULAR_TABLES, table_3d_uint_t, ORIG_TABLE_INTAKE_AVCS_A_ADDRESS, &tblIntakeAvcsA, &tblIntakeAvcsOvertake),
	#endif //ORIG_TABLE_INTAKE_AVCS_A_ADDRESS
	#if defined ORIG_TABLE_INTAKE_AVCS_B_ADDRESS
		CREATE_LUT_ENTRY(NUMBER_OF_REGULAR_TABLES, table_3d_uint_t, ORIG_TABLE_INTAKE_AVCS_B_ADDRESS, &tblIntakeAvcsB, &tblIntakeAvcsOvertake),
	#endif //ORIG_TABLE_INTAKE_AVCS_B_ADDRESS
	
	#if defined ORIG_TABLE_EXHAUST_AVCS_A_ADDRESS
		CREATE_LUT_ENTRY(NUMBER_OF_REGULAR_TABLES, table_3d_uint_t, ORIG_TABLE_EXHAUST_AVCS_A_ADDRESS, &tblExhaustAvcsA, &tblExhaustAvcsOvertake),
	#endif //ORIG_TABLE_EXHAUST_AVCS_A_ADDRESS
	#if defined ORIG_TABLE_EXHAUST_AVCS_B_ADDRESS
		CREATE_LUT_ENTRY(NUMBER_OF_REGULAR_TABLES, table_3d_uint_t, ORIG_TABLE_EXHAUST_AVCS_B_ADDRESS, &tblExhaustAvcsB, &tblExhaustAvcsOvertake),
	#endif //ORIG_TABLE_EXHAUST_AVCS_B_ADDRESS
	
	#if defined ORIG_TABLE_TARGET_THROTTLE_POSITION_A_ADDRESS
		CREATE_LUT_ENTRY(NUMBER_OF_REGULAR_TABLES, table_3d_uint_t, ORIG_TABLE_TARGET_THROTTLE_POSITION_A_ADDRESS, &tblTargetThrPosA, &tblTargetThrPosOvertake),
	#endif //ORIG_TABLE_TARGET_THROTTLE_POSITION_A_ADDRESS
	#if defined ORIG_TABLE_TARGET_THROTTLE_POSITION_B_ADDRESS
		CREATE_LUT_ENTRY(NUMBER_OF_REGULAR_TABLES, table_3d_uint_t, ORIG_TABLE_TARGET_THROTTLE_POSITION_B_ADDRESS, &tblTargetThrPosB, &tblTargetThrPosOvertake),
	#endif //ORIG_TABLE_TARGET_THROTTLE_POSITION_B_ADDRESS

	//Requested Torque Accelerator Pedal
	#if defined P_SI_DRVIE_STATE
		//Si-Drive cars already have tables for Si-Drive modes
		//Return same tables for all modes except Overtake
		#if defined ORIG_TABLE_REQUESTED_TORQUE_ACCELERATOR_PEDAL_A_ADDRESS
			CREATE_LUT_ENTRY_EXTRA_ONLY(NUMBER_OF_REGULAR_TABLES, table_3d_uint_t, ORIG_TABLE_REQUESTED_TORQUE_ACCELERATOR_PEDAL_A_ADDRESS, &tblReqTorqueAccPedalOvertake),
		#endif //ORIG_TABLE_REQUESTED_TORQUE_ACCELERATOR_PEDAL_A_ADDRESS
		#if defined ORIG_TABLE_REQUESTED_TORQUE_ACCELERATOR_PEDAL_B_ADDRESS
			CREATE_LUT_ENTRY_EXTRA_ONLY(NUMBER_OF_REGULAR_TABLES, table_3d_uint_t, ORIG_TABLE_REQUESTED_TORQUE_ACCELERATOR_PEDAL_B_ADDRESS, &tblReqTorqueAccPedalOvertake),
		#endif //ORIG_TABLE_REQUESTED_TORQUE_ACCELERATOR_PEDAL_B_ADDRESS
		#if defined ORIG_TABLE_REQUESTED_TORQUE_ACCELERATOR_PEDAL_C_ADDRESS
			CREATE_LUT_ENTRY_EXTRA_ONLY(NUMBER_OF_REGULAR_TABLES, table_3d_uint_t, ORIG_TABLE_REQUESTED_TORQUE_ACCELERATOR_PEDAL_C_ADDRESS, &tblReqTorqueAccPedalOvertake),
		#endif //ORIG_TABLE_REQUESTED_TORQUE_ACCELERATOR_PEDAL_C_ADDRESS
	#else
		#if defined ORIG_TABLE_REQUESTED_TORQUE_ACCELERATOR_PEDAL_A_ADDRESS
			CREATE_LUT_ENTRY(NUMBER_OF_REGULAR_TABLES, table_3d_uint_t, ORIG_TABLE_REQUESTED_TORQUE_ACCELERATOR_PEDAL_A_ADDRESS, &tblReqTorqueAccPedalA, &tblReqTorqueAccPedalOvertake),
		#endif //ORIG_TABLE_REQUESTED_TORQUE_ACCELERATOR_PEDAL_A_ADDRESS
		#if defined ORIG_TABLE_REQUESTED_TORQUE_ACCELERATOR_PEDAL_B_ADDRESS
			CREATE_LUT_ENTRY(NUMBER_OF_REGULAR_TABLES, table_3d_uint_t, ORIG_TABLE_REQUESTED_TORQUE_ACCELERATOR_PEDAL_B_ADDRESS, &tblReqTorqueAccPedalB, &tblReqTorqueAccPedalOvertake),
		#endif //ORIG_TABLE_REQUESTED_TORQUE_ACCELERATOR_PEDAL_B_ADDRESS
		#if defined ORIG_TABLE_REQUESTED_TORQUE_ACCELERATOR_PEDAL_C_ADDRESS
			CREATE_LUT_ENTRY(NUMBER_OF_REGULAR_TABLES, table_3d_uint_t, ORIG_TABLE_REQUESTED_TORQUE_ACCELERATOR_PEDAL_A_ADDRESS, &tblReqTorqueAccPedalC, &tblReqTorqueAccPedalOvertake),
		#endif //ORIG_TABLE_REQUESTED_TORQUE_ACCELERATOR_PEDAL_C_ADDRESS
	#endif //P_SI_DRVIE_STATE
			

};

//Lookup table for 2D UINT tables
//[][0] element contains orig table address
//[][1] element contains table 1 address
//[][2] element contains table 2 address
//[][3] element contains table 3 address
//[][last] element contains overtake table address
//Array of pointers
static const table_2d_uint_t * const LUT_2D_UINT[][LUT_COLUMN_COUNT] = {
	//All Throttle Tip-in Enrichment tables maps to A1, A2, A3 tables
	#if defined ORIG_TABLE_THROTTLE_TIP_IN_ENRICHMENT_A_ADDRESS
		CREATE_LUT_ENTRY(NUMBER_OF_REGULAR_TABLES, table_2d_uint_t, ORIG_TABLE_THROTTLE_TIP_IN_ENRICHMENT_A_ADDRESS, &tblThrTipInA, &tblThrTipInOvertake),
	#endif
	#if defined ORIG_TABLE_THROTTLE_TIP_IN_ENRICHMENT_B_ADDRESS
		CREATE_LUT_ENTRY(NUMBER_OF_REGULAR_TABLES, table_2d_uint_t, ORIG_TABLE_THROTTLE_TIP_IN_ENRICHMENT_B_ADDRESS, &tblThrTipInA, &tblThrTipInOvertake),
	#endif
};

//This function replaces original calc 3D UINT table function
//x - X axis value
//y - Y axis value
//*tablePointer - pointer to structure that desctibes 3D table
//Returns Z axis value
//
//According to SH CPU ABI specification, 
//registers R4-R7, FR4-FR11 used for parameter passing.
//Thus x stored in FR4, y stored in FR5, tablePointer stored in R4
//the same as original function.
float
calc_3d_uint_to_float_hooked (const float x, 
							  const float y, 
							  const table_3d_uint_t *tablePointer)
{
	//Get pointer from LUT	
	tablePointer = 
		(const table_3d_uint_t *)getPointerFromLut((generic_lut_t)LUT_3D_UINT
													, COUNT_OF(LUT_3D_UINT)
													, (int)tablePointer);

	//Call calc 3D function and return result
	//x passes through FR4, y passes through FR5, tablePointer passes through R4
	//as original function expects
	return calc_3d_uint_to_float(x, y, tablePointer);
}

//This function replaces original calc 2D UINT table function
//x - X axis value
//*tablePointer - pointer to structure that desctibes 2D table
//Returns Y axis value
float
calc_2d_uint_to_float_hooked (const float x, 
							  const table_2d_uint_t *tablePointer)
{
	//Get pointer from LUT
	tablePointer = 
		(const table_2d_uint_t *)getPointerFromLut((generic_lut_t)LUT_2D_UINT
													, COUNT_OF(LUT_2D_UINT)
													, (int)tablePointer);

	//Call calc 2D function and return result
	//x passes through FR4, y passes through FR5, tablePointer passes through R4
	//as original function expects
	return calc_2d_uint_to_float(x, tablePointer);
}

//Lookup universal function
//LUT - two-dimensional array with LUT_COLUMN_COUNT rows
//lutRowCount - LUT row count
//elementToFind - what it needs to find in zero column
//Returns row number if element is found and -1 otherwise
static int 
getLutRowNumber (const int LUT[][LUT_COLUMN_COUNT], 
				 int lutRowCount, 
				 int elementToFind)
{
	int i,
	fail = -1;

	for (i=0; i < lutRowCount; i++)
	{
		if(LUT[i][0] == elementToFind)
		{
			return i;
		}
	}

	return fail;
}

//Lookup universal function
//LUT - two-dimensional array with LUT_COLUMN_COUNT rows
//lutRowCount - LUT row count
//elementToFind - what it needs to find in zero column
//Returns LUT element if elementToFind is present in LUT's first column
//or unchanged elementToFind
static int 
getPointerFromLut (const int LUT[][LUT_COLUMN_COUNT], 
				   int lutRowCount, 
				   int elementToFind)
{
	int i;
	
	//Get LUT row number
	//Returns -1 if table not found, LUT row number otherwise
	i = getLutRowNumber(LUT, lutRowCount, elementToFind);

	//If table is in LUT, substitute its address
	//Otherwise don't touch anything
	if (i >= 0)
	{
		//If table is in LUT, do the lookup
		uint8 j = globalMapSwitch();
		//Just in case let's do additional check to prevent array overrun.
		j = sanitizeLutSecondIndex(j);
		//Current selected map number
		RAM_VARIABLES->mapSelected = j;
		//Careful, array overrun may occur
		elementToFind = LUT[i][j];
	}
	
	return elementToFind;
}

//Prevent LUT array overrun condition
static inline
uint8 sanitizeLutSecondIndex (uint8 index)
{
	if (index > LUT_COLUMN_COUNT - 1)
	{
		//This should never happen!
		//Zeroing second LUT index will disable all hacks
		index = 0;
	}
	
	return index;
}

#if defined(BUILD_TESTS)

//Test LUT 3D lookup
//Test first element of LUT
//Test last element of LUT
//Test garbage
void
test_getLutRowNumber_3d()
{
	int lut3dUintSize;

	lut3dUintSize = COUNT_OF(LUT_3D_UINT);

	DEBUG_VARIABLES->A = lut3dUintSize;
	//First element
	//Casting to generic_lut_t needed to remove 'incompatible pointer type' warning
	DEBUG_VARIABLES->B = getLutRowNumber((generic_lut_t)LUT_3D_UINT
											, lut3dUintSize
											, (int)LUT_3D_UINT[0][0]);
	//Last element
	DEBUG_VARIABLES->C = getLutRowNumber((generic_lut_t)LUT_3D_UINT
											, lut3dUintSize
											, (int)LUT_3D_UINT[lut3dUintSize-1][0]);
	//Garbage, expect -1
	DEBUG_VARIABLES->D = getLutRowNumber((generic_lut_t)LUT_3D_UINT
											, lut3dUintSize, 0);
}

//Test LUT 2D lookup
//Test first element of LUT
//Test last element of LUT
//Test garbage
void
test_getLutRowNumber_2d()
{
	int lut2dUintSize;

	lut2dUintSize = COUNT_OF(LUT_2D_UINT);

	DEBUG_VARIABLES->A = lut2dUintSize;
	//First element
	//Casting to generic_lut_t needed to remove 'incompatible pointer type' warning
	DEBUG_VARIABLES->B = getLutRowNumber((generic_lut_t)LUT_2D_UINT
											, lut2dUintSize, (int)LUT_2D_UINT[0][0]);
	//Last element
	DEBUG_VARIABLES->C = getLutRowNumber((generic_lut_t)LUT_2D_UINT
											, lut2dUintSize, (int)LUT_2D_UINT[lut2dUintSize-1][0]);
	//Garbage, expect -1
	DEBUG_VARIABLES->D = getLutRowNumber((generic_lut_t)LUT_2D_UINT
											, lut2dUintSize, 0);
}

void
test_getPointerFromLut_3d()
{
	int lut3dUintSize;

	lut3dUintSize = COUNT_OF(LUT_3D_UINT);

	DEBUG_VARIABLES->A = lut3dUintSize;

	//First element
	//Casting to generic_lut_t needed to remove 'incompatible pointer type' warning
	DEBUG_VARIABLES->B = getPointerFromLut((generic_lut_t)LUT_3D_UINT
											, lut3dUintSize
											, (int)LUT_3D_UINT[0][0]);
	//Last element
	DEBUG_VARIABLES->C = getPointerFromLut((generic_lut_t)LUT_3D_UINT
											, lut3dUintSize
											, (int)LUT_3D_UINT[lut3dUintSize-1][0]);
	//Garbage, expect same address as input
	DEBUG_VARIABLES->D = getPointerFromLut((generic_lut_t)LUT_3D_UINT
											, lut3dUintSize
											, 0xDEADBEEF);
}

#endif
