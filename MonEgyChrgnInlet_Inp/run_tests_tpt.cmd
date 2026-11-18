@echo off
setlocal enableextensions
setlocal enabledelayedexpansion

rem Specify the TPT version
set TPT_VERSION=tpt_20u1a

rem Specify the TPT testcase
set TPT_TESTCASE=Test.tpt

rem Specify the TPT report files and folders that should go into the .zip report
set TPT_REPORT_FILES=testdata

rem Specify the filename of the .zip report
set FC_UNITTEST_REPORT=my_fc_unittest_report

call "%~dp0\bcu.cmd" -tpt %* make run getcov zip

endlocal
