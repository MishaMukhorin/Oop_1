@echo off

echo Test 1
REM Test positive integer
radix.exe 10 16 12345 > test-data\output.txt
if %errorlevel% == 1 ( goto err)
fc test-data\test1_pattern.txt test-data\output.txt
if %errorlevel% == 1 ( goto err)

echo Test 2
REM Test negative integer
radix.exe 10 16 -12345 > test-data\output.txt
if %errorlevel% == 1 ( goto err)
fc test-data\test2_pattern.txt test-data\output.txt
if %errorlevel% == 1 ( goto err)

echo Test 3
REM Test zero
radix.exe 10 16 0 > test-data\output.txt
if %errorlevel% == 1 ( goto err)
fc test-data\test3_pattern.txt test-data\output.txt
if %errorlevel% == 1 ( goto err)

echo Test 4
REM Test maximum integer
radix.exe 10 16 2147483647 > test-data\output.txt
if %errorlevel% == 1 ( goto err)
fc test-data\test4_pattern.txt test-data\output.txt
if %errorlevel% == 1 ( goto err)

echo Test 5
REM Test minimum input
radix.exe 10 16 -2147483647 > test-data\output.txt
if %errorlevel% == 1 ( goto err)
fc test-data\test5_pattern.txt test-data\output.txt
if %errorlevel% == 1 ( goto err)

echo Test 6
REM Test non-integer value
radix.exe 10 16 12.34 > test-data\output.txt
if %errorlevel% == 0 ( goto err)
fc test-data\test6_pattern.txt test-data\output.txt
if %errorlevel% == 1 ( goto err)

echo Test 7
REM Test non-existent source notation
radix.exe 37 16 12345 > test-data\output.txt
if %errorlevel% == 0 ( goto err)
fc test-data\test7_pattern.txt test-data\output.txt
if %errorlevel% == 1 ( goto err)

echo Test 8
REM Test non-existent destination notation
radix.exe 10 37 12345 > test-data\output.txt
if %errorlevel% == 0 ( goto err)
fc test-data\test8_pattern.txt test-data\output.txt
if %errorlevel% == 1 ( goto err)

echo Test 9
REM Test invalid value in source notation
radix.exe 16 10 1234G > test-data\output.txt
if %errorlevel% == 0 ( goto err)
fc test-data\test9_pattern.txt test-data\output.txt
if %errorlevel% == 1 ( goto err)

echo Test 10
REM Test invalid number of arguments
radix.exe 16 10 > test-data\output.txt
if %errorlevel% == 0 ( goto err)
fc test-data\test10_pattern.txt test-data\output.txt
if %errorlevel% == 1 ( goto err)

echo Test 11
REM Test max source notation
radix.exe 36 10 ZEBRA > test-data\output.txt
if %errorlevel% == 1 ( goto err)
fc test-data\test11_pattern.txt test-data\output.txt
if %errorlevel% == 1 ( goto err)

echo Test 12
REM Test max destination notation
radix.exe 10 36 1234567 > test-data\output.txt
if %errorlevel% == 1 ( goto err)
fc test-data\test12_pattern.txt test-data\output.txt
if %errorlevel% == 1 ( goto err)

echo Test 13
REM Test integer minimum
radix.exe 16 10 -80000000 > test-data\output.txt
if %errorlevel% == 1 ( goto err)
fc test-data\test13_pattern.txt test-data\output.txt
if %errorlevel% == 1 ( goto err)

echo Success!
exit /B 1

:err
echo Program testing failed
exit 1
