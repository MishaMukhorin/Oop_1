@echo off

set INPUT_FILE=test-data\test1.txt
set OUTPUT_FILE=test-data\output.txt

echo Test 1
REM Test the identity matrix3
invert.exe test-data\test1.txt > %OUTPUT_FILE% || goto err
fc test-data\test1_pattern.txt %OUTPUT_FILE%
if %errorlevel% == 1 ( goto err)

echo Test 2
REM Test a matrix3 with all zeros
invert.exe test-data\test2.txt > %OUTPUT_FILE%
if %errorlevel% == 0 ( goto err)
fc test-data\test2_pattern.txt %OUTPUT_FILE%
if %errorlevel% == 1 ( goto err)

echo Test 3
REM Test a matrix3 with negative values
invert.exe test-data\test3.txt > %OUTPUT_FILE% || goto err
fc test-data\test3_pattern.txt %OUTPUT_FILE%
if %errorlevel% == 1 ( goto err)

echo Test 4
REM Test a matrix3 with a zero determinant
invert.exe test-data\test4.txt > %OUTPUT_FILE%
if %errorlevel% == 0 ( goto err)
fc test-data\test4_pattern.txt %OUTPUT_FILE%
if %errorlevel% == 1 ( goto err)

echo Test 5
REM Test a matrix3 with a non-zero determinant
invert.exe test-data\test5.txt > %OUTPUT_FILE% || goto err
fc test-data\test5_pattern.txt %OUTPUT_FILE%
if %errorlevel% == 1 ( goto err)

echo Test 6
REM Test invalid input matrix3
invert.exe test-data\test6.txt > %OUTPUT_FILE%
if %errorlevel% == 0 ( goto err)
fc test-data\test6_pattern.txt %OUTPUT_FILE%
if %errorlevel% == 1 ( goto err)

echo Test 7
REM Test invalid input
invert.exe 12345 > %OUTPUT_FILE%
if %errorlevel% == 0 ( goto err)
fc test-data\test7_pattern.txt %OUTPUT_FILE%
if %errorlevel% == 1 ( goto err)

echo Success!
exit /B 1

:err
echo Program testing failed
exit 1
