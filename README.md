# Patch to Subaru ROMs based on SuperH CPU

### Target Boost map switching by pressing Cruise button or Si-Drive switch

To build you'll need GCC 12.2.0 (preferred) https://gcc.gnu.org/ and Binutils 2.4.0 (preferred) https://www.gnu.org/software/binutils/ or GNUSH toolchain (not recommended, but supported) https://llvm-gcc-renesas.com/

To patch you'll need Swiss File Knife https://sourceforge.net/projects/swissfileknife/

For static analysis you'll need PVS-Studio

To tune you'll need RomRaider 1.0.0 or later https://github.com/RomRaider/RomRaider

**ROMs not included**

For more information please refer to [2Boost wiki](https://github.com/aalesv/2boost/wiki)

#### Caveats

- AZ1G900P

 Table switch works correctly only when engine runnig. It's because
 cruise mode not always turns on when engine is stopped.
