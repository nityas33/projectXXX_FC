@echo off
setlocal enableextensions
setlocal enabledelayedexpansion

set BCU_VERSION=2.6.0
set BCU_LOCAL_FRAMEWORK=none
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
call %BCU_FRAMEWORK_DIR%\extras\stubit\stubit.exe gen bcu --pver-path ..\CDS26_EC3_DEMO___DEMO_ADR1KOR__0__CDS0026_CHRGN___DEMO_ADR1KOR__0__Build_2\CDS26_EC3_DEMO__DEMO_ADR1KOR0 --env SRV_MDG=2 --bcu-project-path "%~dp0."
if %ERRORLEVEL% EQU 1 exit /b 1
call %BCU_FRAMEWORK_DIR%\extras\stubit\stubit.exe run

endlocal