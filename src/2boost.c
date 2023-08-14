// This is an independent project of an individual developer. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

/*This file is part of 2Boost
*
*2Boost is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
*
*This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
*/

#include "2boost.h"

//Entry point for Calc 3D routine. Calls hooked function that does all the work.
//Do not place any other code here!
float
calc_3d_uint_to_float_entry_point (const float x, 
                                    const float y, 
                                    const table_3d_uint_t *tablePointer)
{
    return calc_3d_uint_to_float_hooked(x, y, tablePointer);
}

//Entry point for Calc 2D routine. Calls hooked function that does all the work.
//Do not place any other code here!
float 
calc_2d_uint_to_float_entry_point (const float x, 
                                    const table_2d_uint_t *tablePointer) 
{
    return calc_2d_uint_to_float_hooked (x, tablePointer);
}

#if defined SPEED_DENSITY
//Entry point for Mass Airflow routine. Calls hooked function that does all the work.
//Do not place any other code here!
float 
massAirflow_entry_point (float mafVoltage, 
                        const table_2d_noconv_t *tablePointerMAF) 
{
    return massAirflow_hooked(mafVoltage, tablePointerMAF);
}
#endif //SPEED_DENSITY
