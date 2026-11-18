@echo off
setlocal enableextensions
setlocal enabledelayedexpansion

REM ice_ara2l		: 2024.1_3.9.0
REM rtarte   		: 12.0.0_a_spinlock
REM -actions 		: generate_adapter,generate_rte,generate_a2l,generate_interface  (or) all
REM -proj    		: project folder wherein all required autosar description files are available
REM -comp    		: component or composition name
REM -a2lfilepathlst	: path of additional a2l file.

if not defined TB_HOMEDIR (
    echo ERROR: 'Toolbase Client' not found. Please install 'Toolbase Client' via IT Service Portal.
    exit /b 1
) else if not defined TB_ECU.WORX_HOME (
    call tfind ecu.worx/latest
    if ERRORLEVEL 1 (
        tbexcmd -useEnv:dgs -command EnableTool ecu.worx/latest
        tbupdate -exec
    )

    call tini ecu.worx=latest
)

REM exit /b 0

SET RTARTE_VERSION=12.0.0_a_spinlock
if not defined TB_HOMEDIR (
    echo ERROR: 'Toolbase Client' not found. Please install 'Toolbase Client' via IT Service Portal.
    exit /b 1
) else if not defined TB_RTARTE_HOME (
    echo Setting up rtarte/%RTARTE_VERSION% ...
    call tfind rtarte/%RTARTE_VERSION%
    if ERRORLEVEL 1 (
        tbexcmd -useEnv:dgs -command EnableTool rtarte/%RTARTE_VERSION%
        tbupdate -exec
    )

    call tini rtarte=%RTARTE_VERSION%
)
REM exit /b 0

SET ICEARA2L_VERSION=2024.1_3.9.0
if not defined TB_HOMEDIR (
    echo ERROR: 'Toolbase Client' not found. Please install 'Toolbase Client' via IT Service Portal.
    exit /b 1
) else if not defined TB_ICE_ARA2L_HOME (
    echo Setting up ice_ara2l/%ICEARA2L_VERSION% ...
    call tfind ice_ara2l/%ICEARA2L_VERSION%
    if ERRORLEVEL 1 (
        tbexcmd -useEnv:dgs -command EnableTool ice_ara2l/%ICEARA2L_VERSION%
        tbupdate -exec
    )

    call tini ice_ara2l=%ICEARA2L_VERSION%
)
REM exit /b 0


set BCU_VERSION=2.6.0
set BCU_LOCAL_FRAMEWORK=none

cd /D "%~dp0"

rem Find the BCU Framework root directory.
if not defined BCU_FRAMEWORK_DIR (
    rem Try the local install using %BCU_LOCAL_FRAMEWORK%.
    if exist %BCU_LOCAL_FRAMEWORK%\extras\autosar\BCU_Autosar_Handler.exe (
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

REM SET COMP_NAME=

REM Autosar handler will be executed by "all" scenarios by default.The specific scenario names can also be specified with comma(,) seperated.
REM SCENARIO=Scenario1,Scenario2..
SET SCENARIO=all

if not defined COMP_NAME (
    echo ERROR: 'COMP_NAME' is not defined.
    exit /b 1
)
	 

%BCU_FRAMEWORK_DIR%\extras\autosar\BCU_Autosar_Handler.exe -vm C:\toolbase\java_jdk\11.0.16.1\bin\java.exe -consoleLog -actions=all -proj=%~dp0 -comp=%COMP_NAME% -scenarios=%SCENARIO% -a2lfilepathlst=


if exist "%~dp0\Dummies\Rte_*.h" (
echo Deleting the Rte files from dummies folder...
del /q %~dp0\Dummies\Rte_*.h
)

endlocal
exit /b 0
