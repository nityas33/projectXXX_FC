#
# Makefile
# Copyright (C) Robert Bosch GmbH. All rights reserved.
#
# This file is part of the Bosch BCU Framework
#
# Note: For help on makefiles, see https://www.gnu.org/software/make/manual/ 
#

# Specify the root folder of your BCU project sources in 'BCU_TEST_DIR'
# This folder will be added to the compilers search path and to the VPATH variable.
BCU_TEST_DIR = My

# Specify the root folder of the BCU Framework in 'BCU_FRAMEWORK_DIR'
# Notes:
#   - Usually, the variable is derived from the environment variable 'TB_BCU_HOME',
#     which points to the BCU Framework in the toolbase after tini is run.
BCU_FRAMEWORK_DIR ?= $(TB_BCU_HOME)

# Specify the .c and .cpp of the project
# Notes:
#   - Do not add header files
#   - Separate multiple files with spaces
#   - Use forward slashes for Linux compatibility
# [BCU-Sources-Start]
SOURCES += My/my_main.c
SOURCES += My/my_stubs.c
SOURCES += My/my_pavast_stubs.c
CTCFLAGS += -C "NO_EXCLUDE = ..\..\MonEgyChrgnInlet_Inp_1.11.0\MonEgyChrgnInlet_Inp_1.11.0\_src\*"
SOURCES += Links/monegychrgninlet_inp.c
# [BCU-Sources-End]

# To remove files from the generated list above, use the following line
# SOURCES := $(filter-out folder/not_needed.c, $(SOURCES))

CPPFLAGS += -ILinks
CPPFLAG_DUMMIES += -IDummies

# Check for existence of the BCU_FRAMEWORK_DIR variable.
# Use '../..' as a backup, when run directly out of the BCU examples folder.
ifeq (,$(BCU_FRAMEWORK_DIR))
    ifneq (,$(wildcard ../../Makefile))
        BCU_FRAMEWORK_DIR = ../..
        $(warning warning: Using the BCU Framework at '$(BCU_FRAMEWORK_DIR)'. To avoid this warning, set the BCU_FRAMEWORK_DIR variable explicitly.)
    else
        ifeq ($(OS),Windows_NT)
            $(error error: 'BCU_FRAMEWORK_DIR' not defined. Try running 'tini bcu latest' to setup the BCU toolbase environment)
        else
            $(error error: 'BCU_FRAMEWORK_DIR' not defined. Set BCU_FRAMEWORK_DIR to the path of your BCU Framework folder, e.g. 'export BCU_FRAMEWORK_DIR=/mnt/c/toolbase/_ldata/bcu/x.x.x')
        endif
    endif
endif

# Include the BCU Framework makefile
include $(BCU_FRAMEWORK_DIR)/Makefile
