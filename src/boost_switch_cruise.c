// This is an independent project of an individual developer. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

/*This file is part of 2Boost
*
*2Boost is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
*
*This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
*/

/*Headers include by specifying -include option for gcc*/

/* Hack to make compiler produce mow.l instead of mov.w */
const int orig_calc_3d_function_address = ORIG_CALC_3D_FUNCTION_ADDRESS;

const float tblTargetBoost2_x_axis [TARGET_BOOST_X_COUNT] = TBL_TARGET_BOOST2_X_AXIS;
const float tblTargetBoost2_y_axis [TARGET_BOOST_Y_COUNT] = TBL_TARGET_BOOST2_Y_AXIS;
const unsigned short tblTargetBoost2_data [TARGET_BOOST_X_COUNT * TARGET_BOOST_Y_COUNT] = {0};

const table_3d_t tblTargetBoost2 = {
	.x_len = TARGET_BOOST_X_COUNT,
	.y_len = TARGET_BOOST_Y_COUNT,
	.x_axis_ptr = &tblTargetBoost2_x_axis,
	.y_axis_ptr = &tblTargetBoost2_y_axis,
	.data_ptr = &tblTargetBoost2_data,
	.data_type = 0x08000000,
	.miltiplier = 1.0,
	.offset = 0
};


void boost_switch_hack (){
	
	/* Push to stack */
	asm("mov.l   r1, @-r15");
	asm("mov.l   r2, @-r15");
	asm("mov.l   r3, @-r15");
	asm("mov.l   r5, @-r15");
	/* Push PR register because we will JSR later*/
	asm("sts.l   pr, @-r15");
	
	/* Init prevCruiseBtnState and boostHackEnable 
	 * It can be 0 or 1
	 */
	
	if (RAM_VARIABLES->prevCruiseBtnState > 1) { RAM_VARIABLES->prevCruiseBtnState = 0; }
	if (RAM_VARIABLES->boostHackEnable > 1) { RAM_VARIABLES->boostHackEnable = 0; }

	/* R4 contains table structure address */
	register int R4 __asm("r4");
	
	/* Proceed only if it's original Target Boost table */
	if (R4==ORIG_TABLE_TARGET_BOOST_ADRESS) {
		
#if defined CRUISE_FLAG_IS_BUTTON_FLAG

		/* When cruise system is not enabled yet or is not good, 8th bit is set to 0 */
		if ((*P_CRUISE_FLAG & P_CRUISE_MASK_CRUISE_ENABLED) == 0) {
			/* Ignition is just turned on or something is wrong with cruise system */
			/* Anyway, disabling boost hack */ 
			RAM_VARIABLES->boostHackEnable = 0;
		} else {
			/* Cruise system is OK */
			/* If button was not pressed, but now is pressed */
			if (((*P_CRUISE_FLAG & P_CRUISE_MASK_BUTTON_PRESSED) == 1) && (RAM_VARIABLES->prevCruiseBtnState == 0)) {
				/* Toggle boostHackEnable switch */
				RAM_VARIABLES->boostHackEnable ^= 1;
			}
		}

		/* Save previous cruise button state */
		RAM_VARIABLES->prevCruiseBtnState = *P_CRUISE_FLAG & P_CRUISE_MASK_BUTTON_PRESSED;
		
#elif defined CRUISE_FLAG_IS_CRUISE_SYSTEM_STATE

		/* When cruise system is not enabled yet or is not good, 4th bit is set to 1 */
		if ((*P_CRUISE_FLAG & P_CRUISE_MASK_CRUISE_DISABLED) != 0) {
			/* Cruise is disabled */
			/* Disable boost hack */ 
			RAM_VARIABLES->boostHackEnable = 0;
		} else if ((*P_CRUISE_FLAG & P_CRUISE_MASK_CRUISE_DISABLED) == 0) {
			/* Cruise is enabled */
			RAM_VARIABLES->boostHackEnable = 1;
		}
#else
#error CRUISE_FLAG_IS_BUTTON_FLAG or CRUISE_FLAG_IS_CRUISE_SYSTEM_STATE must be defined
#endif
		
		/* If hack enabled, switch the table*/
		if (RAM_VARIABLES->boostHackEnable == 1) {
			R4=(int)&tblTargetBoost2;
		} else if (RAM_VARIABLES->boostHackEnable != 0) { //-V547
			/* We should not get here */
			RAM_VARIABLES->boostHackEnable = 0;
		}
		
	}

	register int R5 __asm("r5");
	
	R5=orig_calc_3d_function_address;
	/* JSR changes PR register, so we must save it at procedure begin*/
	asm("jsr @r5");
	asm("nop");
	
	/* Pop from stack*/
	asm("lds.l   @r15+, pr"); //-V779
	asm("mov.l   @r15+, r5");
	asm("mov.l   @r15+, r3");
	asm("mov.l   @r15+, r2");
	asm("mov.l   @r15+, r1");
}
