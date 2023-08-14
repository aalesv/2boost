// This is an independent project of an individual developer. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

/*This file is part of 2Boost
*
*2Boost is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
*
*This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
*/

#include "macros.h"
#include "types.h"

//These are entry points of mod.
//I did it for better compatibility between mod versions
//and for better compatibility between compiler versions
float calc_3d_uint_to_float_entry_point (const float x, 
                    const float y, 
                    const table_3d_uint_t *tablePointer) ROM_ENTRY_POINT_CALC_3D;
float calc_2d_uint_to_float_entry_point (const float x, 
                    const table_2d_uint_t *tablePointer) ROM_ENTRY_POINT_CALC_2D;
#if defined SPEED_DENSITY
float massAirflow_entry_point (float mafVoltage, 
        const table_2d_noconv_t *tablePointerMAF) ROM_ENTRY_POINT_SPEED_DENSITY;
#endif //SPEED_DENSITY

//This function replaces original calc 3D table function
extern float calc_3d_uint_to_float_hooked (const float x, 
                            const float y, const table_3d_uint_t *tablePointer);

//This function replaces original calc 2D table function
extern float calc_2d_uint_to_float_hooked (const float x, 
                                            const table_2d_uint_t *tablePointer);

//This function replaces original calc MAF table function
extern float massAirflow_hooked(float mafVoltage, 
                                const table_2d_noconv_t *tablePointerMAF);
