#### 2boost.txt

Main linker script

#### calc_hooked.c

Functions that hook the original tables calculation ROM functions.

#### global_vars.c

Global variables, constants etc.

#### map_switch.c

Map switching related functions. Cruise and Si-Drive state functions also located here.

#### tests.c

Test suite. It emulates Cruise state on/off and Si-Drive switching and then calls hooked functions. Use with emulator.
Safe for production ROM but not accessible in usual way. Currently only Timing tables tested.
