// This is an independent project of an individual developer. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

/*This file is part of 2Boost
*
*2Boost is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
*
*This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
*/

typedef struct {
	unsigned char prevCruiseBtnState;
	unsigned char boostHackEnable;
} ram_variables_t;

typedef struct {
	short x_len;
	short y_len;
	void *x_axis_ptr;
	void *y_axis_ptr;
	void *data_ptr;
	long data_type;
	float miltiplier;
	float offset;
} table_3d_t;

ram_variables_t *RAM_VARIABLES = ((ram_variables_t*)RAM_HOLE);

/* If you want to use non-standard sized tables
 * that will be incompatible with existing definitions,
 * please set last two digits of version to something different from zero.
*/

static const char VERSION[] __attribute__((used)) __attribute__ ((aligned (0x200))) = "2Boost " CALID " 0001.00.00";
