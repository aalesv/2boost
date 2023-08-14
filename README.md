# Patch to Subaru ROMs based on SuperH CPU

### Target Boost map switching by pressing Cruise button

To build you'll need GCC 12.2.0 (preferred) https://gcc.gnu.org/ and Binutils 2.4.0 (preferred) https://www.gnu.org/software/binutils/ or GNUSH toolchain (not recommended, but supported) https://llvm-gcc-renesas.com/

To patch you'll need Swiss File Knife https://sourceforge.net/projects/swissfileknife/

For static analysis you'll need PVS-Studio

**ROMs not included**

For more details please see [2Boost Wiki](https://github.com/aalesv/2boost/wiki)

#### Caveats

- AZ1G900P

 Table switch works correctly only when engine runnig. It's because
 cruise mode not always turns on when engine is stopped.
