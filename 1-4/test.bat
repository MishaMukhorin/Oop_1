@echo off

set INPUT_FILE=test-data\test1.txt
set OUTPUT_FILE=test-data\output1.txt

echo Test 1
replace.exe %INPUT_FILE% %OUTPUT_FILE% "1231234" "not" || goto err
rem todo
fc test-data\test1_pattern.txt %OUTPUT_FILE%
if %errorlevel% == 1 ( goto err )

echo Test 2
replace.exe %INPUT_FILE% %OUTPUT_FILE% "dog" "dogdogdog" || goto err
fc test-data\test2_pattern.txt %OUTPUT_FILE%
if %errorlevel% == 1 ( goto err )

echo Test 3
replace.exe %INPUT_FILE% %OUTPUT_FILE% "has" "don't have" || goto err
fc test-data\test3_pattern.txt %OUTPUT_FILE%
if %errorlevel% == 1 ( goto err )

echo Test 4
replace.exe %INPUT_FILE% %OUTPUT_FILE% "cats" "oops" || goto err
fc test-data\test1.txt %OUTPUT_FILE%
if %errorlevel% == 1 ( goto err )

echo Test 5
replace.exe %INPUT_FILE% %OUTPUT_FILE% "" "oops" || goto err
fc test-data\test1.txt %OUTPUT_FILE%
if %errorlevel% == 1 ( goto err )

echo Test 6
replace.exe %INPUT_FILE% "" "ahahaha"
if %errorlevel% == 0 ( goto err )
fc test-data\test1.txt %OUTPUT_FILE%
if %errorlevel% == 1 ( goto err )

echo Success!
exit /B 0

:err
echo Program testing failed
exit 1