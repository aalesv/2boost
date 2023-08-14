#### .\target\*.h

Settings for each CAL Id.

#### .\target\*.txt

Linker script include files for each CAL Id. Currently each file contain ROM hole address needed by linker to correctly align binary.

#### 2boost.h

Functions that are entry points for Calc 2D/3D and Mass Airflow Calc routines

#### calc_hooked.h

Functions that hook the original tables calculation ROM functions.

#### global_vars.h

Global variables, constants etc.

#### macros.h

All macros definitions. Number of tables for each hack section also defined here.

#### map_switch.h

Map switching related functions. Cruise and Si-Drive state functions also located here.

#### speed_density.h

Speed density related functions and tables.

#### tests.h

Test suite. It emulates Cruise state on/off and Si-Drive switching and then calls hooked functions. Use with emulator.
Safe for production ROM but not accessible in usual way. Currently only Timing tables tested.

#### types.h

All user defined types.
