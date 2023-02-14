# Patch to Subaru ROMs based on SuperH CPU

### Version 1 branch is frozen.

No new features and tables will be added, only bug fixes and new CAL IDs.

### Target Boost map switching by pressing Cruise button

To build you'll need GNUSH toolchain https://llvm-gcc-renesas.com/

To patch you'll need Swiss File Knife https://sourceforge.net/projects/swissfileknife/

For static analysis you'll need PVS-Studio

**ROMs not included**

For more details please see [2Boost Wiki](https://github.com/aalesv/2boost/wiki)

#### Caveats

- AZ1G900P

 Table switch works correctly only when engine runnig. It's because
 cruise mode not always turns on when engine is stopped.
