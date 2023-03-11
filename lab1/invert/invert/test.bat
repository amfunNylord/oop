@echo off
chcp 65001
set PROGRAM="%~1"

set OUT="%TEMP%\out.txt"

:: Тест с целыми коэффициентами
%PROGRAM% test1.txt >%OUT% || goto err
fc %OUT% test1-out.txt || goto err
:: Тест с нецелыми коэффициентами
%PROGRAM% test3.txt >%OUT% || goto err
fc %OUT% test3-out.txt || goto err
:: Тест, если определитель равен 0
%PROGRAM% test2.txt >%OUT% || goto err
fc %OUT% test2-out.txt || goto err

echo All tests passed
exit /B 0

:err
echo Program testing failed
exit /B 1