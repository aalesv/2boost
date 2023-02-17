// This is an independent project of an individual developer. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

/*This file is part of 2Boost
*
*2Boost is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
*
*This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
*/

#include "map_switch.h"

//Returns 0 is must use original ROM map, 1 if must use 1st map, 2 if must use 2nd map, 3 if must use 3d map
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

//How to switch between maps
//do not switch - stock map will be used
//use Cruise On/Off switch
//or use Si-Drive switch (if supported by ROM)
unsigned char globalMapSwitchSource () {
	//This const is defined in global varibles file
	return CFG_GLOBAL_MAP_SWITCH_SOURCE;
}

