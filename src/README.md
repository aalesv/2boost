#### 2boost.c

Functions that are entry points for Calc 2D/3D and Mass Airflow Calc routines

#### 2boost.txt

Main linker script

#### calc_hooked.c

Functions that hook the original tables calculation ROM functions.

#### cel_flash.h

Functions that hook ROM's CEL flash functions

#### global_vars.c

Global variables, constants etc.

#### map_switch.c

Map switching related functions. Cruise and Si-Drive state functions also located here.

#### speed_density.c

Speed density related functions and tables.

#### tests.c

Test suite. It emulates Cruise state on/off and Si-Drive switching and then calls hooked functions. Use with emulator.
Safe for production ROM but not accessible in usual way. Currently only Timing tables tested.
