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

#Detect OS
ifeq (${OS}, Windows_NT)
	WINDOWS=1
else
	WINDOWS=0
endif

#Set OS specific stuff
ifeq ($(WINDOWS), 1)
	BIN=$(WINBIN)
#Path separator. $() is empty variable
	PATHSEP=$()\$()
#Find separator
	FINDSEP=$() $()
	CP=copy
	RM=del
	NEWLINE=.
	GREP=findstr /R
#Sort starting from 10th symbol
	SORTFLAGS=/+10
else
	BIN=$(NIXBIN)
#Path separator
	PATHSEP=/
#Find separator for regexp
	FINDSEP=|
	CP=cp
	RM=rm -f
	GREP=grep -E
#Sort by 2nd column
	SORTFLAGS=--key=2
endif

CC=$(BIN)$(PATHSEP)sh-elf-gcc
CFLAGS=-g -c -m4 -mrenesas -m4-single-only
LD=$(BIN)$(PATHSEP)sh-elf-ld
#LD script for linking ROM
LD_COMMON_SCRIPT=$(SRC)$(PATHSEP)2boost.txt
LDFLAGS=-T $(LD_COMMON_SCRIPT)
READELF=$(BIN)$(PATHSEP)sh-elf-readelf
OBJCOPY=$(BIN)$(PATHSEP)sh-elf-objcopy
#Copy to bin file only specified sections
OBJCOPYFLAGS=-O binary --only-section=ROM_HOLE_CODE --only-section=ROM_HOLE_DATA --only-section=ROM_HOLE_TESTS
SORT=sort

#Dirs
BUILD=.$(PATHSEP)build
ROM=.$(PATHSEP)ROM
INCLUDE=.$(PATHSEP)include
SRC=.$(PATHSEP)src
#Exclude common.h
EXCLUDE="common$(FINDSEP)functions"

#PVS-Studio
PVS=$(PVSDIR)$(PATHSEP)x64$(PATHSEP)PVS-Studio
PLOGCONVERTER=$(PVSDIR)$(PATHSEP)PlogConverter
LOGREAD=$(PVSDIR)$(PATHSEP)Standalone
PVS-WORK-DIR=.$(PATHSEP)pvs-studio
PVS-CFG=$(PVS-WORK-DIR)$(PATHSEP)PVS-Studio.cfg
PLOGCONVERTERFLAGS=-t plog -o $(PVS-WORK-DIR)

#Symbols to search in non-stripped binary
#Version, config bytes, tables, tests
SYMBOLS="VERSION$(FINDSEP)CFG_$(FINDSEP)_tbl.*_$(FINDSEP)_test_"

MAKEFLAGS+=--no-print-directory

#All .c files
ifeq ($(WINDOWS), 1)
define ALL-C-FILES
$(shell dir /b $(SRC)$(PATHSEP)*.c )
endef
else
define ALL-C-FILES
$(shell basename -a $(SRC)$(PATHSEP)*.c)
endef
endif

#All .o files
ALL-O-FILES=$(ALL-C-FILES:.c=.o)
#All .i files, needed for PVS-Studio
ALL-I-FILES=$(ALL-C-FILES:.c=.i)

# Offset where you will place your binary in ROM
# It needs for correct calculation of addresses of references to tables
# It MUST correspond to addresses in XML definition file
# Take offset from linker script .txt file
ifeq ($(WINDOWS), 1)
define find-rom-hole-addr
$(shell for /f "tokens=2 delims='=;'" %%i in ('findstr ROM_HOLE $(INCLUDE)$(PATHSEP)$@.txt') do echo %%i)
endef
else
define find-rom-hole-addr
$(shell grep ROM_HOLE $(INCLUDE)$(PATHSEP)$@.txt | awk -F"=|\;" '{print $$2}')
endef
endif

# Find all possible targets
# List all include\*.h files,
# remove .h extension, remove unnecessary names
ifeq ($(WINDOWS), 1)
	all-targets:=$(shell for %%f in ("$(INCLUDE)$(PATHSEP)*.h") do @echo %%~nf | findstr /v $(EXCLUDE))
else
	all-targets:=$(shell basename -a $(INCLUDE)$(PATHSEP)*.h | awk -F"." '{print $$1}' | $(GREP) -v $(EXCLUDE))
endif

# Default target to build
.PHONY: help

help:
	@echo make all	- Build all CAL IDs. Specify DOPATCH=-yes to patch your ROM.
	@echo make analyze	- Do static analysis with PVS-Studio, must be installed.
	@echo			  Specify CALID=CALID.
	@echo make analyze-clean - Delete files needed for static analysis
	@echo make CALID	- Specify CALID to build only that target,
	@echo 		  for example 'make A8DK100P' will build
	@echo 		  files only for A8DK100P. Specify DOPATCH=-yes to patch your ROM.
	@echo make clean	- Clean build directory.
	@echo make help	- This message.
	@echo make list	- List for possible CAL IDs.
	@echo make tests	- Test build for emulator testing only.
	@echo			  Specify CALID=CALID for building CALID or all for build all ROMs.

#Build .o file
#Call make recursive to build file every time
#Pass target .h file via ADDITIONAL-CFLAGS variable
#Pass target name via TARGET variable
%.o: ofile=$(BUILD)$(PATHSEP)2Boost-$(TARGET)-$@
%.o: $(SRC)$(PATHSEP)%.c
	@echo Building $@...
	@$(CC) $(CFLAGS) $(ADDITIONAL-CFLAGS) -o $(ofile) $<

# Form target list from CLAID header file names
# Set variables
#ROM hole address
$(all-targets): BASE=$(find-rom-hole-addr)
#Non-sripped linked binary aligned at ROM hole address
$(all-targets): outfile=$(BUILD)$(PATHSEP)2Boost-$@.out
#Stripped binary file ready to patch
$(all-targets): binfile=$(BUILD)$(PATHSEP)2Boost-$@.bin
#Stock ROM file
$(all-targets): orig-rom=$(ROM)$(PATHSEP)$@.bin
#Patched ROM file
$(all-targets): patched-rom=$(BUILD)$(PATHSEP)$@-patched.bin
#LD script for particular target
$(all-targets): ld-script-target=$(INCLUDE)$(PATHSEP)$@.txt
#Add `.\build\` directory and rename .o file to correspond current target
$(all-targets): all-o-files-with-dir=$(addprefix $(BUILD)$(PATHSEP)2Boost-$@-, $(ALL-O-FILES))
#Target CALID header file
$(all-targets): target-header-file=$(INCLUDE)$(PATHSEP)$@.h
#No prerequisites because target list made of existing files
$(all-targets):
	@echo =====================================================================================
	@echo$(NEWLINE)
	@echo Building $@
	@echo$(NEWLINE)
# Call make recursively
	@$(MAKE) $(ALL-O-FILES) TARGET=$@ ADDITIONAL-CFLAGS="-include $(target-header-file)"
	@echo Linking...
	@$(LD) $(LDFLAGS) -T $(ld-script-target) -o $(outfile) $(all-o-files-with-dir)
	@echo Stripping binary...
	@$(OBJCOPY) $(OBJCOPYFLAGS) $(outfile) $(binfile)
	@echo Addresses for objects are:
	@$(READELF) -s $(outfile) | $(GREP) $(SYMBOLS) | $(SORT) $(SORTFLAGS)
	@echo$(NEWLINE)
	@echo Patching ROM...
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

#Build .i file and pass it to PVS-Studio
#Don't forget to set pvs-logfile, ADDITIONAL-CFLAGS, TARGET variables
%.i: i-file=$(BUILD)$(PATHSEP)2Boost-$(TARGET)-$@
%.i: $(SRC)$(PATHSEP)%.c
	$(CC) $(CFLAGS) $(ADDITIONAL-CFLAGS) -E -o $(i-file) $<
	$(PVS) --cfg $(PVS-CFG) --i-file $(i-file) --source-file $< >> $(pvs-logfile)

# Static analysis with PVS-Studio
# CALID=your-cal-id must be specified on command line
analyze: logfile=$(CALID).log
analyze: pvs-logfile=$(PVS-WORK-DIR)$(PATHSEP)$(logfile)
analyze: $(INCLUDE)$(PATHSEP)$(CALID).h
	$(RM) $(pvs-logfile)
# Call make recursively
	$(MAKE) $(ALL-I-FILES) TARGET=$(CALID) ADDITIONAL-CFLAGS="-include $<" pvs-logfile=$(pvs-logfile)
	$(PLOGCONVERTER) $(pvs-logfile) $(PLOGCONVERTERFLAGS)

# Delete files needed for static analysis
analyze-clean:
	$(RM) $(BUILD)$(PATHSEP)*.i $(PVS-WORK-DIR)$(PATHSEP)*.log $(PVS-WORK-DIR)$(PATHSEP)*.plog

list:
	@echo Can build for CAL IDs:
	@echo $(all-targets)

#Build with tests. Specify CALID=all to build all targets
#Define tests symbol and overwrite CFLAGS variable
tests: cflags_testing="$(CFLAGS) -DBUILD_TESTS"
tests:
	@echo Building test build for $(CALID)
	@$(MAKE) $(CALID) CFLAGS=$(cflags_testing) DOPATCH=$(DOPATCH)
