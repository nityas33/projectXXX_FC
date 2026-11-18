@echo off
setlocal enableextensions
setlocal enabledelayedexpansion

for /F "tokens=1,2 delims=#" %%a in ('"prompt #$H#$E# & echo on & for %%b in (1) do rem"') do set ESC=%%b

set NO_COLOR=%ESC%[0m
set ERROR_COLOR=%ESC%[0;31m

rem Specify the CTC Report Option: mcdc,m,d,f,s or mcdc or m or d or f or s
set CTC_REPORT_OPTION=mcdc

rem Specify the SRV_MDG option: 0(BCU Service library)/1(MDG Service library)/2(MDGEvo Service library)
set SRV_MDG=2

set MON_SYM=
set MON_DAT=
set FINAL_ERRORLEVEL=0
set SCENARIO=
set UNDERSCORE=

rem [BCU-GeneratedCommand-Start]
call :run_bcu_cmd %*
if %ERRORLEVEL% EQU 1 exit /b 1
if %ERRORLEVEL% NEQ 0 set FINAL_ERRORLEVEL=%ERRORLEVEL%
rem [BCU-GeneratedCommand-End]
call "%~dp0\bcu.cmd" -exe -m32 zip
if %FINAL_ERRORLEVEL% EQU 3 (
    echo %ERROR_COLOR%ERROR: Testcases failed %NO_COLOR% 1>&2
    echo ERROR: Testcases failed >> bcu.log
)

exit /b %FINAL_ERRORLEVEL%

:run_bcu_cmd
set FC_UNITTEST_REPORT=my_fc_unittest_report%UNDERSCORE%%SCENARIO%
set REPORT_HTML_FILE=bcu_unittest_report%UNDERSCORE%%SCENARIO%.html
set CTC_HTML_REPORT=CTC-HTML-REPORT%UNDERSCORE%%SCENARIO%
set MON_SYM=%MON_SYM% %cd%\%FC_UNITTEST_REPORT%\MON.sym
set MON_DAT=%MON_DAT% %cd%\%FC_UNITTEST_REPORT%\MON.dat
call "%~dp0\bcu.cmd" -ctc -exe -m32 %* make run getcov

endlocal
