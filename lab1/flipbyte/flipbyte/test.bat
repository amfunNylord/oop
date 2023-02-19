@echo off

set PROGRAM="%~1"

set OUT="%TEMP%\out.txt"

:: ���� � 96
%PROGRAM% 96 %OUT% || goto err
fc %OUT% test1-out.txt || goto err
:: ���� � 256
%PROGRAM% 256 %OUT% || goto err
fc %OUT% test2-out.txt || goto err
:: ���� � Hello
%PROGRAM% Hello %OUT% || goto err
fc %OUT% test3-out.txt || goto err

echo All tests passed
exit /B 0

:err
echo Program testing failed
exit /B 1 
