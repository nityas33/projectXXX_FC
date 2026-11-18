#!/bin/bash
#
# bcu.sh
# Copyright (C) 2021 Robert Bosch GmbH. All rights reserved.
#
# This file is part of the Bosch BCU Framework
#

# This script tries to autodetect the root of the BCU framework.
# But you may override this by pointing the variable BCU_FRAMEWORK_DIR your desired BCU root:
# export BCU_FRAMEWORK_DIR=/mnt/c/toolbase/bcu/x.x.x

# Adjust the variables below to use correct IDs
# export FMU_MODEL_ID=todo-set-fmu-model-id

# -------------------------------------------------------------------------

NO_COLOR='\033[0m'
ERROR_COLOR='\033[0;31m'

# -------------------------------------------------------------------------

# Get the directory where this file is located.
BASEDIR="$(dirname "$0")"
if [ "$(printf '%s' "$BASEDIR" | cut -c1)" != '/' ]; then
    BASEDIR="$PWD/$BASEDIR" # relative path
fi

# Find the BCU Framework root directory.
if [ ! -e "$BCU_FRAMEWORK_DIR/bcu.sh" ]; then
    # Get version number from bcu.cmd.
    BCU_VERSION="$(grep BCU_VERSION "$BASEDIR/bcu.cmd" | head -n1 | cut -d'=' -f2 | tr -d '\r\n')"
    if [ -n "$BCU_VERSION" ]; then
        # Try Bosch-OSD path.
        export BCU_FRAMEWORK_DIR="/mnt/c/toolbase/bcu/$BCU_VERSION"
    fi
fi

# Ensure that 'bcu.sh' exists at the specified location.
if [ ! -e "$BCU_FRAMEWORK_DIR/bcu.sh" ]; then
    echo -e "${ERROR_COLOR}ERROR: '$BCU_FRAMEWORK_DIR/bcu.sh' does not exist. Please set 'BCU_FRAMEWORK_DIR' to the correct location.${NO_COLOR}" >&2; exit 1
fi

"$BCU_FRAMEWORK_DIR/bcu.sh" "$@"
