@echo off
setlocal EnableExtensions EnableDelayedExpansion

set "SCRIPT_DIR=%~dp0"
set "OVERALL_EXIT=0"
set "REBUILD_BEFORE_TEST=0"

if "%~1"=="" goto :show_usage

:: ====== Main argument loop - processes modes in order ======
:arg_loop
if "%~1"=="" goto :done

if /I "%~1"=="clean" (
    call :run_clean
    if !ERRORLEVEL! neq 0 (
        set /a OVERALL_EXIT=!ERRORLEVEL!
        goto :done
    )
    shift
    goto :arg_loop
)

if /I "%~1"=="stubit" (
    call :run_stubit
    if !ERRORLEVEL! neq 0 (
        set /a OVERALL_EXIT=!ERRORLEVEL!
        goto :done
    )
    shift
    goto :arg_loop
)

if /I "%~1"=="run" (
    call :run_tests
    if !ERRORLEVEL! neq 0 (
        set /a OVERALL_EXIT=!ERRORLEVEL!
        goto :done
    )
    shift
    goto :arg_loop
)

if /I "%~1"=="list" (
    call :run_list
    if !ERRORLEVEL! neq 0 (
        set /a OVERALL_EXIT=!ERRORLEVEL!
        goto :done
    )
    shift
    goto :arg_loop
)

if /I "%~1"=="error_check" (
    set "LOG_FILE="
    set "ERROR_FILE="
    set "CONSUMED_LOG=0"
    set "CONSUMED_ERR=0"

    :: Check if %2 is a file path (not a mode keyword)
    if not "%~2"=="" (
        set "IS_KEYWORD=0"
        if /I "%~2"=="clean" set "IS_KEYWORD=1"
        if /I "%~2"=="stubit" set "IS_KEYWORD=1"
        if /I "%~2"=="run" set "IS_KEYWORD=1"
        if /I "%~2"=="list" set "IS_KEYWORD=1"
        if /I "%~2"=="error_check" set "IS_KEYWORD=1"
        if "!IS_KEYWORD!"=="0" (
            set "LOG_FILE=%~2"
            set "CONSUMED_LOG=1"
            :: Check if %3 is a file path (not a mode keyword)
            if not "%~3"=="" (
                set "IS_KEYWORD=0"
                if /I "%~3"=="clean" set "IS_KEYWORD=1"
                if /I "%~3"=="stubit" set "IS_KEYWORD=1"
                if /I "%~3"=="run" set "IS_KEYWORD=1"
                if /I "%~3"=="list" set "IS_KEYWORD=1"
                if /I "%~3"=="error_check" set "IS_KEYWORD=1"
                if "!IS_KEYWORD!"=="0" (
                    set "ERROR_FILE=%~3"
                    set "CONSUMED_ERR=1"
                )
            )
        )
    )

    call :do_error_check "!LOG_FILE!" "!ERROR_FILE!"
    if !ERRORLEVEL! neq 0 (
        set /a OVERALL_EXIT=!ERRORLEVEL!
        goto :done
    )
    shift
    if "!CONSUMED_LOG!"=="1" shift
    if "!CONSUMED_ERR!"=="1" shift
    goto :arg_loop
)

:: Not a mode keyword - collect remaining args as testcase name(s)
set "TESTCASE_ARGS="
:collect_testcase
if "%~1"=="" goto :do_testcase
if /I "%~1"=="-re" (
    set "REBUILD_BEFORE_TEST=1"
) else (
    if not defined TESTCASE_ARGS (
        set "TESTCASE_ARGS=%~1"
    ) else (
        set "TESTCASE_ARGS=!TESTCASE_ARGS! %~1"
    )
)
shift
goto :collect_testcase
:do_testcase
if "!REBUILD_BEFORE_TEST!"=="1" (
    call :rebuild
    if errorlevel 1 (
        set "OVERALL_EXIT=!ERRORLEVEL!"
        goto :done
    )
)
call :run_testcase !TESTCASE_ARGS!
set /a OVERALL_EXIT=!ERRORLEVEL%
goto :done

:done
exit /b %OVERALL_EXIT%

:: ============ Functions ============

:show_usage
echo Usage: %~nx0 ^<mode...^> ^<testcase-name^>
echo.
echo Modes:
echo    clean       - Execute clean.cmd
echo    stubit      - Execute run_stubit.cmd
echo    run         - Execute run_tests_cunit.cmd
echo    list        - List available tests via bcu.exe -list
echo    error_check - Scan log file for errors [log-file] [error-file]
echo    -re         - Rebuild with SRV_MDG=2 before running a testcase
echo    ^<testcase-name^> - Run individual test via bcu.exe
echo.
echo Multiple modes can be combined and execute in order:
echo    %~nx0 clean stubit          - clean.cmd, then run_stubit.cmd
echo    %~nx0 stubit clean run      - run_stubit.cmd, then clean.cmd, then run_tests_cunit.cmd
echo    %~nx0 clean run error_check - clean.cmd, then run_tests_cunit.cmd, then error check
echo    %~nx0 list                   - List available tests
echo    %~nx0 list run               - List tests, then run_tests_cunit.cmd
echo.
echo Single testcase:
echo    %~nx0 ^<testcase-name^> [-re]
echo    %~nx0 ^<testcase-name^> -re  - rebuild with SRV_MDG=2, then run the testcase
echo    %~nx0 error_check [log-file] [error-file]
echo.
echo ================================================================
echo  Prompt to run and fix the errors:
echo  Execute the .\run_individual_cunit_test.cmd ^<TESTCASE_NAME^> and analyse
echo  the errors after execution and implement the best solution
echo ================================================================
exit /b 2

:run_clean
set "CLEAN_CMD=%SCRIPT_DIR%clean.cmd"
if not exist "!CLEAN_CMD!" (
    echo ERROR: "!CLEAN_CMD!" does not exist.
    exit /b 2
)
echo [clean] Executing clean.cmd...
call "!CLEAN_CMD!"
exit /b %ERRORLEVEL%

:run_stubit
set "STUBIT_CMD=%SCRIPT_DIR%run_stubit.cmd"
if not exist "!STUBIT_CMD!" (
    echo ERROR: "!STUBIT_CMD!" does not exist.
    exit /b 2
)
echo [stubit] Executing run_stubit.cmd...
call "!STUBIT_CMD!"
exit /b %ERRORLEVEL%

:run_tests
set "RUN_CMD=%SCRIPT_DIR%run_tests_cunit.cmd"
if not exist "!RUN_CMD!" (
    echo ERROR: "!RUN_CMD!" does not exist.
    exit /b 2
)
echo [run] Executing run_tests_cunit.cmd...
call "!RUN_CMD!"
exit /b %ERRORLEVEL%

:rebuild
set "BCU_CMD=%SCRIPT_DIR%bcu.cmd"
if not exist "!BCU_CMD!" (
    echo ERROR: "!BCU_CMD!" does not exist. Cannot rebuild.
    exit /b 2
)
echo [rebuild] Setting SRV_MDG=2 and rebuilding the 32-bit debug executable...
pushd "%SCRIPT_DIR%"
set "SRV_MDG=2"
call ".\bcu.cmd" -ctc -exe -m32 make
set "BUILD_ERRORLEVEL=!ERRORLEVEL!"
popd
if not "!BUILD_ERRORLEVEL!"=="0" (
    echo ERROR: Rebuild failed with exit code !BUILD_ERRORLEVEL!.
    exit /b !BUILD_ERRORLEVEL!
)
echo [rebuild] Build completed successfully.
exit /b 0

:do_error_check
set "LOG_FILE=%~1"
if "!LOG_FILE!"=="" set "LOG_FILE=%SCRIPT_DIR%bcu.log"
set "ERROR_FILE=%~2"
if "!ERROR_FILE!"=="" set "ERROR_FILE=%SCRIPT_DIR%bcu_errors.txt"

if not exist "!LOG_FILE!" (
    echo ERROR: Log file "!LOG_FILE!" does not exist.
    exit /b 2
)
echo [error_check] Scanning "!LOG_FILE!" for errors...
findstr /I /C:"error" /C:"failed" /C:"failure" /C:"fatal" "!LOG_FILE!" > "!ERROR_FILE!"
if errorlevel 2 (
    echo ERROR: Could not read "!LOG_FILE!".
    exit /b 1
)
if errorlevel 1 (
    type nul > "!ERROR_FILE!"
    echo No errors found in "!LOG_FILE!".
) else (
    echo Errors written to "!ERROR_FILE!".
    type "!ERROR_FILE!"
)
exit /b 0

:run_list
set "BCU_EXE=%SCRIPT_DIR%_gen\exe_mingw_x86\bcu.exe"
if not exist "%BCU_EXE%" (
    echo ERROR: "%BCU_EXE%" does not exist. Build the 32-bit EXE first.
    exit /b 2
)
echo [list] Listing available tests...
"%BCU_EXE%" -list
exit /b %ERRORLEVEL%

:run_testcase
set "BCU_EXE=%SCRIPT_DIR%_gen\exe_mingw_x86\bcu.exe"
if not exist "%BCU_EXE%" (
    echo ERROR: "%BCU_EXE%" does not exist. Build the 32-bit EXE first.
    exit /b 2
)
echo [test] Running testcase: %*
"%BCU_EXE%" -test %* -verbose
exit /b %ERRORLEVEL%