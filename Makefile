#This file is part of 2Boost
#
#2Boost is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
#
#This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

#Windows expected path
WINBIN="C:\Program Files (x86)\Renesas\Hew\Tools\KPIT\GNUSH-ELF\v13.01\sh-elf\bin"
#*nix expexted path
NIXBIN=/usr/share/gnush_v13.01_elf-1/bin

#Patching with help of Swiss File Knife
SFK=sfkx64

#PVS-Studio variables
PVSDIR="C:\Program Files (x86)\PVS-Studio"

ifeq (${OS}, Windows_NT)
	WINDOWS=1
else
	WINDOWS=0
endif

ifeq ($(WINDOWS), 1)
	BIN=$(WINBIN)
	PATHSEP=$(subst ",,\")
	FINDSEP=$() $()
	CP=copy
	RM=del
	NEWLINE=.
	GREP=findstr
else
	BIN=$(NIXBIN)
	PATHSEP=/
	FINDSEP=|
	CP=cp
	RM=rm -f
	GREP=grep -E
endif

CC=$(BIN)$(PATHSEP)sh-elf-gcc
CFLAGS=-g -c -m4 -mrenesas -m4-single-only
LD=$(BIN)$(PATHSEP)sh-elf-ld
READELF=$(BIN)$(PATHSEP)sh-elf-readelf
OBJCOPY=$(BIN)$(PATHSEP)sh-elf-objcopy
OBJCOPYFLAGS=-O binary --only-section=.text --only-section=.rodata --only-section=.data
BUILD=.$(PATHSEP)build
ROM=.$(PATHSEP)ROM
INCLUDE=.$(PATHSEP)include
#Exclude common.h
EXCLUDE="common$(FINDSEP)functions"

PVS=$(PVSDIR)$(PATHSEP)x64$(PATHSEP)PVS-Studio
PLOGCONVERTER=$(PVSDIR)$(PATHSEP)PlogConverter
LOGREAD=$(PVSDIR)$(PATHSEP)Standalone
PVS-WORK-DIR=.$(PATHSEP)pvs-studio
PVS-CFG=$(PVS-WORK-DIR)$(PATHSEP)PVS-Studio.cfg
PLOGCONVERTERFLAGS=-t plog -o $(PVS-WORK-DIR)

INFILE=.$(PATHSEP)src$(PATHSEP)boost_switch_cruise.c

SYMBOLS="VERSION$(FINDSEP)tblTargetBoost2_"

# Offset where you will place your binary in ROM
# It needs for correct calculation of addresses of references to tables
# It MUST correspond to addresses in XML definition file
# Take offset from .h file
ifeq ($(WINDOWS), 1)
define find-rom-hole-addr
$(shell for /f "tokens=2 delims=()" %%i in ('findstr ROM_HOLE $(INCLUDE)$(PATHSEP)$@.h') do echo %%i)
endef
else
define find-rom-hole-addr
$(shell grep ROM_HOLE $(INCLUDE)$(PATHSEP)$@.h | awk -F"\(|\)" '{print $$2}')
endef
endif

# Find all possible targets
# List all include\*.h files,
# remove .h extension, remove unnecessary names
ifeq ($(WINDOWS), 1)
	all-targets:=$(shell for %%f in ("$(INCLUDE)$(PATHSEP)*.h") do @echo %%~nf | findstr /v $(EXCLUDE))
else
	all-targets:=$(shell ls -1 $(INCLUDE)$(PATHSEP) | awk -F"." '{print $$1}' | $(GREP) -v $(EXCLUDE))
endif
# Default target to build
.PHONY: help

help:
	@echo make all	- Build all CAL IDs. Specify DOPATCH=-yes to patch your ROM.
	@echo make analyze	- Do static analysis with PVS-Studio (must be installed).
	@echo			  Specify CALID=CALID.
	@echo make analyze-clean - Delete files needed for static analysis
	@echo make CALID	- Specify CALID to build only that target,
	@echo 		  for example 'make A8DK100P' will build
	@echo 		  files only for A8DK100P. Specify DOPATCH=-yes to patch your ROM.
	@echo make clean	- Clean build directory.
	@echo make help	- This message.
	@echo make list	- List for possible CAL IDs.

# Any word can be a target
# Assume that user typed CAL ID
# Set variables
%: BASE=$(find-rom-hole-addr)
%: ofile=$(BUILD)$(PATHSEP)2Boost-$@.o
%: outfile=$(BUILD)$(PATHSEP)2Boost-$@.out
%: binfile=$(BUILD)$(PATHSEP)2Boost-$@.bin
%: orig-rom=$(ROM)$(PATHSEP)$@.bin
%: patched-rom=$(BUILD)$(PATHSEP)$@-patched.bin
# Let's check that this is CAL ID and right .h file exists
%: $(INCLUDE)$(PATHSEP)%.h
	@echo =====================================================================================
	@echo$(NEWLINE)
	@echo Building $@
	@echo$(NEWLINE)
	@$(CC) $(CFLAGS) -include $(INCLUDE)$(PATHSEP)$@.h -o $(ofile) $(INFILE)
	@$(LD) -Ttext=$(BASE) -o $(outfile) $(ofile)
	@$(OBJCOPY) $(OBJCOPYFLAGS) $(outfile) $(binfile)
	@echo Addresses for objects are:
	@$(READELF) -s $(outfile) | $(GREP) $(SYMBOLS)
	@echo$(NEWLINE)
	$(CP) $(orig-rom) $(patched-rom)
# To actually patch specify DOPATCH=-yes on command line
	$(SFK) -verbose partcopy $(binfile) -allfrom 0 $(patched-rom) $(BASE) $(DOPATCH)

# Build all targets
# $(all-targets) expands to all .h file names except excluded
# Then every target processed individually by rule above
all: $(all-targets)

# Clean build directory
clean:
	$(RM) $(BUILD)$(PATHSEP)*.bin $(BUILD)$(PATHSEP)*.i $(BUILD)$(PATHSEP)*.o $(BUILD)$(PATHSEP)*.out

# Static analysis with PVS-Studio
# CALID=your-cal-id must be specified on command line
analyze: ifile=$(BUILD)$(PATHSEP)2Boost-$(CALID).i
analyze: logfile=$(CALID).log
analyze: pvs-logfile=$(PVS-WORK-DIR)$(PATHSEP)$(logfile)
analyze: $(INCLUDE)$(PATHSEP)$(CALID).h
	$(CC) $(CFLAGS) -include $(INCLUDE)$(PATHSEP)$(CALID).h -E -o $(ifile) $(INFILE)
	$(PVS) --cfg $(PVS-CFG) --i-file $(ifile) --source-file $(INFILE) > $(pvs-logfile)
	$(PLOGCONVERTER) $(pvs-logfile) $(PLOGCONVERTERFLAGS)

# Delete files needed for static analysis
analyze-clean:
	$(RM) $(BUILD)$(PATHSEP)*.i $(PVS-WORK-DIR)$(PATHSEP)*.log $(PVS-WORK-DIR)$(PATHSEP)*.plog

list:
	@echo Can build for CAL IDs:
	@echo $(all-targets)
