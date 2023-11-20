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

#if defined(SPEED_DENSITY)

//Volumetric Efficiency table X count
#define VE_X_COUNT (32)
//Volumetric Efficiency table Y count
#define VE_Y_COUNT (30)

//VE Tip-in table X count
#define VE_TIP_IN_X_COUNT (16)
//VE Tip-in table Y count
#define VE_TIP_IN_Y_COUNT (16)

//MAF/SD Blending table X count
#define MAF_SD_BLEND_X_COUNT (16)
//MAF/SD Blending table Y count
#define MAF_SD_BLEND_Y_COUNT (16)

//VE table X axis
static const float tblVe_x_axis [VE_X_COUNT] ROM_3D_TABLE_DATA;
//VE table Y axis
static const float tblVe_y_axis [VE_Y_COUNT] ROM_3D_TABLE_DATA;
//VE table data
static const UINT_0x8000000 tblVe_data [VE_X_COUNT * VE_Y_COUNT] ROM_3D_TABLE_DATA;
//VE table structure
const table_3d_uint_t tblVe ROM_TABLE_PTR;

//VE Tip-in table X axis
static const float tblVeTipIn_x_axis [VE_TIP_IN_X_COUNT] ROM_3D_TABLE_DATA;
//VE Tip-in table Y axis
static const float tblVeTipIn_y_axis [VE_TIP_IN_Y_COUNT] ROM_3D_TABLE_DATA;
//VE Tip-in table data
static const UINT_0x8000000 tblVeTipIn_data [VE_TIP_IN_X_COUNT * VE_TIP_IN_Y_COUNT] ROM_3D_TABLE_DATA;
//VE Tip-in table structure
const table_3d_uint_t tblVeTipIn ROM_TABLE_PTR;

//MAF/SD blending table X axis
static const float tblMafSdBlend_x_axis [MAF_SD_BLEND_X_COUNT] ROM_3D_TABLE_DATA;
//MAF/SD blending table Y axis
static const float tblMafSdBlend_y_axis [MAF_SD_BLEND_Y_COUNT] ROM_3D_TABLE_DATA;
//MAF/SD blending table data
//0 - MAF only, 1 - SD only
static const  UINT_0x8000000 tblMafSdBlend_data [MAF_SD_BLEND_X_COUNT * MAF_SD_BLEND_Y_COUNT] ROM_3D_TABLE_DATA;
//MAF/SD blending table structure
 const table_3d_uint_t tblMafSdBlend ROM_TABLE_PTR;

//Speed Density constant 0.0038728181
static const float speedDensityConstant ROM_DATA_CONST;

//This function replaces original calc MAF table function
float massAirflow_hooked(float mafVoltage, const table_2d_noconv_t *tablePointerMAF) ROM_CODE;

//Engine displacement, liters
extern float CFG_ENGINE_DISPLACEMENT;
//MAF/SD blending mode on/off
extern uint8 CFG_MAF_SD_BLENDING;
//RAM variables.
extern ram_variables_t *RAM_VARIABLES;

//Calc 2D function. float only, no conversion.
extern calc_2d_float_to_float_t calc_2d_float_to_float;
//Calc 3D function, data type uint only
extern calc_3d_uint_to_float_t calc_3d_uint_to_float;

#endif