// This is an independent project of an individual developer. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

/*This file is part of 2Boost
*
*2Boost is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
*
*This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
*/

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
	//Current selected map number
	unsigned char mapSelected;
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
