#This file is part of 2Boost
#
#2Boost is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
#
#This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

BIN="C:\Program Files (x86)\Renesas\Hew\Tools\KPIT\GNUSH-ELF\v13.01\sh-elf\bin"
CC=$(BIN)\"sh-elf-gcc.exe"
CFLAGS=-g -c -m4 -mrenesas
LD=$(BIN)\"sh-elf-ld.exe"
READELF=$(BIN)\"sh-elf-readelf.exe"
OBJCOPY=$(BIN)\"sh-elf-objcopy.exe"
OBJCOPYFLAGS=-O binary --only-section=.text --only-section=.rodata --only-section=.data
BUILD=".\build"
ROM=".\ROM"
INCLUDE=".\include"
#Exclude common.h
EXCLUDE=common

#Patching with help of Swiss File Knife
SFK="sfkx64.exe"

#PVS-Studio variables
PVSDIR="C:\Program Files (x86)\PVS-Studio"
PVS=$(PVSDIR)\"x64\PVS-Studio.exe"
PLOGCONVERTER=$(PVSDIR)\"PlogConverter.exe"
LOGREAD=$(PVSDIR)\"Standalone.exe"
PVS-WORK-DIR=.\pvs-studio
PVS-CFG=$(PVS-WORK-DIR)\PVS-Studio.cfg
PLOGCONVERTERFLAGS=-t plog -o $(PVS-WORK-DIR)

INFILE=.\src\boost_switch_cruise.c

SYMBOLS="VERSION tblTargetBoost2_"

# Offset where you will place your binary in ROM
# It needs for correct calculation of addresses of references to tables
# It MUST correspond to addresses in XML definition file
# Take offset from .h file
define find-rom-hole-addr
$(shell for /f "tokens=2 delims=()" %%i in ('findstr ROM_HOLE $(INCLUDE)\$@.h') do echo %%i)
endef

# Find all possible targets
# List all include\*.h files,
# remove .h extension, remove unnecessary names
all-targets:=$(shell for %%f in ("$(INCLUDE)\*.h") do @echo %%~nf | findstr /v $(EXCLUDE))

# Default target to build
.PHONY: help

help:
	@echo make all	- Build all CAL IDs. Specify DOPATCH=-yes to patch your ROM.
	@echo make analyze	- Do static analysis with PVS-Studio (must be installed).
	@echo make CALID	- Specify CALID to build only that target,
	@echo 		  for example 'make A2WC420F' will build
	@echo 		  files only for A2WC420F. Specify DOPATCH=-yes to patch your ROM.
	@echo make clean	- Clean build directory.
	@echo			  Specify CALID=CALID.
	@echo make help	- This message.
	@echo make list	- List for possible CAL IDs.

# Any word can be a target
# Assume that user typed CAL ID
# Set variables
%: BASE=$(find-rom-hole-addr)
%: ofile=$(BUILD)\2Boost-$@.o
%: outfile=$(BUILD)\2Boost-$@.out
%: binfile=$(BUILD)\2Boost-$@.bin
%: orig-rom=$(ROM)\$@.bin
%: patched-rom=$(BUILD)\$@-patched.bin
# Let's check that this is CAL ID and right .h file exists
%: .\include\%.h
	@echo =====================================================================================
	@echo.
	@echo Building $@
	@echo.
	@$(CC) $(CFLAGS) -include $(INCLUDE)\$@.h -o $(ofile) $(INFILE)
	@$(LD) -Ttext=$(BASE) -o $(outfile) $(ofile)
	@$(OBJCOPY) $(OBJCOPYFLAGS) $(outfile) $(binfile)
	@echo Addresses for objects are:
	@$(READELF) -s $(outfile) | findstr $(SYMBOLS)
	@echo.
	copy $(orig-rom) $(patched-rom)
# To actually patch specify DOPATCH=-yes on command line
	$(SFK) -verbose partcopy $(binfile) -allfrom 0 $(patched-rom) $(BASE) $(DOPATCH)

# Build all targets
# $(all-targets) expands to all .h file names except excluded
# Then every target processed individually by rule above
all: $(all-targets)

# Clean build directory
clean:
	del $(BUILD)\*.bin $(BUILD)\*.i $(BUILD)\*.o $(BUILD)\*.out

# Static analysis with PVS-Studio
# CALID=your-cal-id must be specified on command line
analyze: ifile=$(BUILD)\2Boost-$(CALID).i
analyze: logfile=$(CALID).log
analyze: pvs-logfile=$(PVS-WORK-DIR)\$(logfile)
analyze: .\include\$(CALID).h
	$(CC) $(CFLAGS) -include $(INCLUDE)\$(CALID).h -E -o $(ifile) $(INFILE)
	$(PVS) --cfg $(PVS-CFG) --i-file $(ifile) --source-file $(INFILE) > $(pvs-logfile)
	$(PLOGCONVERTER) $(pvs-logfile) $(PLOGCONVERTERFLAGS)

# Delete files needed for static analysis
analyze-clean:
	del $(BUILD)\*.i $(PVS-WORK-DIR)\*.log $(PVS-WORK-DIR)\*.plog

list:
	@echo Can build for CAL IDs:
	@echo $(all-targets)
