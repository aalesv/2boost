// This is an independent project of an individual developer. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

/*This file is part of 2Boost
*
*2Boost is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
*
*This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
*/

#if !defined(TYPES_H)
#define TYPES_H

enum MAP_SWITCH_SOURCE
{
	MAP_SWITCH_SOURCE_NONE, //Turn off all hacks
	MAP_SWITCH_SOURCE_CRUISE, //Cruise on/off switch
	MAP_SWITCH_SOURCE_SI_DRIVE //Si-Drive switch
};

enum OVERTAKE_BUTTON_SOURCE
{
	OVERTAKE_BUTTON_SOURCE_NONE, //Overtake button disabled
	OVERTAKE_BUTTON_SOURCE_CRUISE_CANCEL_PRESS_AND_HOLD, //Cruise cancel switch. The mode remains active as long as the button is held down. 
	OVERTAKE_BUTTON_SOURCE_CRUISE_CANCEL_PRESS_AND_RELEASE //Cruise cancel switch. The mode remains active until brake pedal is pressed.
};


enum SI_DRIVE_STATE
{
	SI_DRIVE_STATE_NONE, //Error
	SI_DRIVE_STATE_INTELLIGENT,
	SI_DRIVE_STATE_SPORT,
	SI_DRIVE_STATE_SPORT_SHARP
};

enum MAF_SD_BLENDING
{
	MAF_SD_BLENDING_OFF,	//No blending, SD only
	MAF_SD_BLENDING_ON		//MAF/SD blending enabled
};

enum CEL_FLASH
{
	CEL_FLASH_DISABLED,		//CEL flash disabled
	CEL_FLASH_ENABLED		//CEL flash enbled
};

//Generic lookup table type
//This is needed to remove warnings when calling generic LUT lookup function
#define generic_lut_t const int (*)[LUT_COLUMN_COUNT]

//Type def for our global variables
typedef struct
{
	//0 if must use orig map, 1 if must use 1st mod map and so on
	uint8 globalMapSwitch;
	//Current selected map number
	uint8 mapSelected;
	//MAF/SD blending mode
	uint8 mafSdBlendMode;
	//Dashboard CEL light status, placed at (RAM_HOLE + 3) address, Flash Hack #2
	uint8 celLightIsOn;
	//Mass airflow from MAF sensor - only if Speed Density enabled
	float airFlowFromMaf;
	//Volumetric efficiency table value - only if Speed Density enabled
	float volumetricEfficiency;
	//Volumetric efficiency  tip-in table value - only if Speed Density enabled
	float volumetricEfficiencyTipIn;
	//MAF/SD blending table value - only if Speed Density enabled
	float mafSdBlendValue;
	//SD calculated mass airflow without blending
	float airFlowFromSdNotBlended;
	//SD calculated mass airflow
	float airFlowFromSD;
	//Overtake mode state
	uint8 OvertakeMode;
	//CEL flash enabled/disabled flag - do it needs to flash now
	uint8 celFlashEnabled;
	//ROM CEL saved state
	uint8 celLightSavedOemState;
	//Counter variable
    int celFlashCounter;
	//How long keep CEL light on
    int celFlashOnCount;
	//How long keep CEL light off
    int celFlashOffCount;
	//Counter variable for number of on-off cycles
	int celFlashCyclesCounter;

} ram_variables_t;

//Type def for 3D table
//Data type short (uint16) or char (uint8) only
//X axis is float
//Y axis is float
//Data is byte or word converted to float at runtime
//x_len - count of elements of X axis
//y_len - count of elements of Y axis
//x_axis_ptr - pointer to X axis array
//y_axis_ptr - pointer to Y axis array
//data_ptr - pointer to data array (Z axis)
//data_type - hex number as specified in ROM table pointer structure
//			For example for 3D tables it may be
//			0x8000000 for uint16
//			0x4000000 for uint8
//			Will be auto converted to proper type declaration
//multiplier - data cel is multiplied by this number and then ...
//offset - ... added with this number
typedef struct
{
	uint16 x_len;
	uint16 y_len;
	const void *x_axis_ptr;
	const void *y_axis_ptr;
	const void *data_ptr;
	long data_type;
	float multiplier;
	float offset;
} table_3d_uint_t;

//Type def for 2D table
//Data type short (uint16) or char (uint8) only
//X axis is float
//x_len - count of elements in X axis
//data_type - hex number as specified in ROM table pointer structure
//			For example for 2D tables it may be
//			0x800 for uint16
//			0x400 for uint8
//Data is byte or word converted to float at runtime
//x_axis_ptr - pointer to X axis array
//data_ptr - pointer to data array (Y axis)
//multiplier - data cel is multiplied by this number and then ...
//offset - ... added with this number
typedef struct
{
	uint16 x_len;
	uint16 data_type;
	const void *x_axis_ptr;
	const void *data_ptr;
	float multiplier;
	float offset;
} table_2d_uint_t;

//Type def for 2D table
//Data type short (uint16), char (uint8) or float
//X axis is float
//x_len - count of elements in X axis
//data_type - 0, no conversion
//x_axis_ptr - pointer to X axis array
//data_ptr - pointer to data array (Y axis)
//No conversion is done - number returns as is
//Use different functions for different data_ptr types
//Float data_ptr processed with same function as table_2d_uint_t
typedef struct
{
	uint16 x_len;
	uint16 data_type;
	const void *x_axis_ptr;
	const void *data_ptr;
} table_2d_noconv_t;

typedef struct
{
	//Number of tests done
	int count;
	int A,
		B,
		C,
		D;
	//Flexible array
	//Unsafe for production, but OK for emulators tests
	float result[];
} debug_variables_t;

//Type for calc 3D fuction, data type uint only
//Returns Z axis value converted to float
typedef float (*calc_3d_uint_to_float_t)(float, float, 
										const table_3d_uint_t *);

//Type for calc 2D fuction, data type uint only
//Returns Y axis value converted to float
typedef float (*calc_2d_uint_to_float_t)(float, const table_2d_uint_t *);

//Type for calc 2D fuction, data type float only
//Returns Y axis value as is
typedef float (*calc_2d_float_to_float_t)(float, const table_2d_noconv_t *);

//Type for calc 2D fuction, data type uint16 only
//Returns Y axis value as is
typedef uint16 (*calc_2d_uint16_to_uint16_noconv_t)(float, 
													const table_2d_noconv_t *);

//Type for 'void f(void)' function
typedef void (*void_fn_ptr)(void);
#endif //TYPES_H
