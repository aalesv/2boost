#if defined CRUISE_FLAG_IS_BUTTON_FLAG
//Returns cruise system state
char pCruiseBtnEnabled (){
	if ((*P_CRUISE_BTN_OK_FLAG & P_CRUISE_BTN_MASK_CRUISE_ENABLED) == 0) {
		// Ignition is just turned on or something is wrong with cruise system
		return 0;
	} else if ((*P_CRUISE_BTN_OK_FLAG & P_CRUISE_BTN_MASK_CRUISE_ENABLED) == P_CRUISE_BTN_MASK_CRUISE_ENABLED) {
		//Cruise system is OK
		return 1;
	} else {
		//Think cruise system is disabled
		return 0;
	}
}

//Returns cruise button state
char pCruiseBtnPressed (){
	if ((*P_CRUISE_BTN_FLAG & P_CRUISE_BTN_MASK_BUTTON_PRESSED) == P_CRUISE_BTN_MASK_BUTTON_PRESSED) {
		//Cruise button is pressed right now
		return 1;
	} else {
		//Cruise button is not pressed
		return 0;
	}
}
#endif

#if defined CRUISE_FLAG_IS_CRUISE_SYSTEM_STATE
//Returns cruise system state
#if defined P_CRUISE_STATE_MASK_CRUISE_ENABLED
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
#endif //CRUISE_FLAG_IS_CRUISE_SYSTEM_STATE

