# Patch to Subaru ROMs based on SuperH CPU

### Target Boost map switching by pressing Cruise button or Si-Drive switch

To build you'll need [2Boost Toolchain](https://github.com/aalesv/2boost-toolchain) version 12.3.0-0 (preferred) or [GCC 12.3.0](https://gcc.gnu.org/) and [Binutils 2.4.0](https://www.gnu.org/software/binutils/) or [GNUSH toolchain](https://llvm-gcc-renesas.com/) (not recommended, but supported). Also you'll need python3 with lxml to generate definitions (included with [2Boost Toolchain](https://github.com/aalesv/2boost-toolchain)).

To patch you'll need [Swiss File Knife](https://sourceforge.net/projects/swissfileknife/) (included with [2Boost Toolchain](https://github.com/aalesv/2boost-toolchain))

For static analysis you'll need PVS-Studio

To tune you'll need [RomRaider](https://github.com/RomRaider/RomRaider) 1.0.0 or later 

**ROMs not included**

For more information please refer to [2Boost wiki](https://github.com/aalesv/2boost/wiki)

#### Caveats

- AZ1G900P

 Table switch works correctly only when engine runnig. It's because
 cruise mode not always turns on when engine is stopped.
