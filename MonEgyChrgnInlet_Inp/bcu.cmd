@echo off
@rem
@rem bcu.cmd
@rem Copyright (C) 2019 Robert Bosch GmbH. All rights reserved.
@rem
@rem This file is part of the Bosch BCU Framework
@rem

setlocal enableextensions
setlocal enabledelayedexpansion

set BCU_VERSION=2.6.0
set BCU_LOCAL_FRAMEWORK=none
set FMU_MODEL_ID=bcu_test
set MSBUILD_PROJECT=bcu_test.sln

cd /D "%~dp0"

rem Find the BCU Framework root directory.
if not defined BCU_FRAMEWORK_DIR (
    rem Try the local install using %BCU_LOCAL_FRAMEWORK%.
    if exist %BCU_LOCAL_FRAMEWORK%\bcu.cmd (
        echo ----- Using local copy of the BCU Framework at %BCU_LOCAL_FRAMEWORK% -----
        set BCU_FRAMEWORK_DIR=%BCU_LOCAL_FRAMEWORK%
    ) else (
        rem Try to install BCU Framework via Toolbase Client.
        if not defined TB_HOMEDIR (
            echo ERROR: 'Toolbase Client' not found. Please install 'Toolbase Client' via IT Service Portal.
            exit /b 1
        ) else if not defined TB_BCU_HOME (
            echo Setting up bcu/%BCU_VERSION% ...
            call tfind bcu/%BCU_VERSION%
            if ERRORLEVEL 1 (
                tbexcmd -useEnv:dgs -command EnableTool bcu/%BCU_VERSION%
                tbupdate -exec
            )
            call tini bcu=%BCU_VERSION%
        )

        set BCU_FRAMEWORK_DIR=!TB_BCU_HOME!
    )
)

rem Ensure that 'bcu.cmd' exists at the specified location.
if not exist %BCU_FRAMEWORK_DIR%\bcu.cmd (
    echo ERROR: '%BCU_FRAMEWORK_DIR%\bcu.cmd' does not exist. Please set 'BCU_FRAMEWORK_DIR' to the correct location.
    exit /b 1
)

call %BCU_FRAMEWORK_DIR%\bcu.cmd %*
