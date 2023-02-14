// This is an independent project of an individual developer. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

/*This file is part of 2Boost
*
*2Boost is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
*
*This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
*/

//Declare RAM variables and place them at RAM hole
ram_variables_t *RAM_VARIABLES = ((ram_variables_t*)RAM_HOLE);

/*Headers include by specifying -include option for gcc*/

//Calc 3D function is located at ORIG_CALC_3D_FUNCTION_ADDRESS
calc_3d_t calc_3d = ((calc_3d_t)ORIG_CALC_3D_FUNCTION_ADDRESS); //-V566

//Define Target Boost map 2 table
const float tblTargetBoost2_x_axis [TARGET_BOOST_X_COUNT] = TBL_TARGET_BOOST2_X_AXIS;
const float tblTargetBoost2_y_axis [TARGET_BOOST_Y_COUNT] = TBL_TARGET_BOOST2_Y_AXIS;
const unsigned short tblTargetBoost2_data [TARGET_BOOST_X_COUNT * TARGET_BOOST_Y_COUNT] = {0};

//Table structure
const table_3d_t tblTargetBoost2 = {
	.x_len = TARGET_BOOST_X_COUNT,
	.y_len = TARGET_BOOST_Y_COUNT,
	.x_axis_ptr = &tblTargetBoost2_x_axis,
	.y_axis_ptr = &tblTargetBoost2_y_axis,
	.data_ptr = &tblTargetBoost2_data,
	.data_type = 0x08000000,
	.multiplier = 1.0,
	.offset = 0
};

//This function replaces original calc 3D table function
//According to SH CPU ABI specification, 
//registers R4-R7, FR4-FR11 are used for parameter passing.
//Thus x stored in FR4, y stored in FR5, tablePointer stored in R4
//the same as original function.
float boost_switch_hack (const float x, const float y, const table_3d_t *tablePointer){
	
	/* Proceed only if it's original Target Boost table */
	if ((int)tablePointer==ORIG_TABLE_TARGET_BOOST_ADDRESS) {
		
		/* If map switch enabled, switch the table*/
		if (globalMapSwitch() == 1) {
			//Switch to Target Boost map 2 table
			tablePointer=&tblTargetBoost2;
		}
	}

	//Call calc 3D function and return result
	//x passes through FR4, y passes through FR5, tablePointer passes through R4
	//as original function expects
	return calc_3d(x, y, tablePointer);
}

//Returns 0 if must use 1st map, 1 if must use 2nd map
char globalMapSwitch(){
	//pCruiseStateEnabled returns 0 or 1
	//Enable map switch if cruise is enabled
	RAM_VARIABLES->globalMapSwitch = pCruiseStateEnabled ();
	
	return RAM_VARIABLES->globalMapSwitch;
}

#if defined P_CRUISE_STATE_MASK_CRUISE_ENABLED
//Returns 1 if cruise is enabled, 0 otherwise
//Straight cruise logic
char pCruiseStateEnabled (){
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
char pCruiseStateEnabled (){
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
