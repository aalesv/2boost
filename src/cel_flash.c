// This is an independent project of an individual developer. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

/*This file is part of 2Boost
*
*2Boost is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
*
*This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
*/

#include "cel_flash.h"
#if defined(P_CEL_LIGHT_STATUS_OEM) && defined(ORIG_CEL_TRIGGER_OUTER_FUNCTION_ADDRESS)

//This function replaces original CEL flash outer function, Flash Hack #1
void
celTrigger_hooked(void)
{
	//Flash if in Overtake mode
	if (overtakeMapSwitch())
	{
		//Set initial parameters
		startFlash(CFG_CEL_FLASH_OVERTAKE_ON
				 , CFG_CEL_FLASH_OVERTAKE_OFF
				 , CFG_CEL_FLASH_OVERTAKE_CYCLES);
	}

	//Flash if FBKC conditions met
	if ((*P_FBKC <= CFG_CEL_FLASH_FBKC_LIMIT)
	 && (*P_ENGINE_LOAD > CFG_CEL_FLASH_FBKC_LOAD_LIMIT))
	{
		//Set initial parameters
		startFlash(CFG_CEL_FLASH_FBKC_ON
				 , CFG_CEL_FLASH_FBKC_OFF
				 ,CFG_CEL_FLASH_FBKC_CYCLES);
	}

	//Prepare to flash
	celFlash();

	//Call orig CEL flash function
	//Real flashing is done here
	celTrigger();
}

//This function sets CEL flash initial parameters
//but only if not flashing now
static inline void
startFlash(uint8 celFlashOnCount, uint8 celFlashOffCount, uint8 celFlashCyclesCount)
{
	if (!CFG_CEL_FLASH_ENABLED)
	{
		//Do no start flashing if flashing is globally disabled
		return;
	}
	if (!RAM_VARIABLES->celFlashEnabled)
	{
		//If not flashing, save CEL state
		RAM_VARIABLES->celLightSavedOemState = *P_CEL_LIGHT_STATUS_OEM;
		//Prevent misconfiguration
		if(celFlashOnCount>0 && celFlashOffCount>0 && celFlashCyclesCount>0)
		{
			//Enable flashing
			RAM_VARIABLES->celFlashEnabled = 1;
			//How long CEL is on
			RAM_VARIABLES->celFlashOnCount = celFlashOnCount;
			//How log CEL is off
			RAM_VARIABLES->celFlashOffCount = celFlashOffCount;
			//Init counter for on and off states
			RAM_VARIABLES->celFlashCounter = 0;
			//One cycle equals on time plus off time
			RAM_VARIABLES->celFlashCyclesCounter = 2*celFlashCyclesCount ;
		}
	}
}

//Main CEL flash function
//Place it to the main loop
static inline void
celFlash(void)
{
	//Do we need to flash?
	if (RAM_VARIABLES->celFlashEnabled)
	{
		//We did not started yet or we already completed some flashing stage
		if (RAM_VARIABLES->celFlashCounter == 0)
		{
			//If CEL is still on, proceed to off stage and vice versa
			RAM_VARIABLES->celFlashCounter = RAM_VARIABLES->celLightIsOn ?
											RAM_VARIABLES->celFlashOffCount
										  : RAM_VARIABLES->celFlashOnCount;
			//Decrement cycles counter
			RAM_VARIABLES->celFlashCyclesCounter--;
			//Save the state. This var must replace OEM CEL status var.
			//Do this via ROM editor.
			//Can't use ROM's CEL var because then it will light up other indicators.
			RAM_VARIABLES->celLightIsOn ^= 1;
		}
		RAM_VARIABLES->celFlashCounter--;
		//If we are done, stop flashing
		if (RAM_VARIABLES->celFlashCyclesCounter == 0)
		{
			RAM_VARIABLES->celFlashEnabled = 0;
		}
	}
	else
	{
        //Save OEM CEL status if not flashing
		RAM_VARIABLES->celLightIsOn = *P_CEL_LIGHT_STATUS_OEM;
	}
}
#endif //P_CEL_LIGHT_STATUS_OEM && ORIG_CEL_TRIGGER_OUTER_FUNCTION_ADDRESS