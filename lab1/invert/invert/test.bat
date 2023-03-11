@echo off
chcp 65001
set PROGRAM="%~1"

set OUT="%TEMP%\out.txt"

:: ���� � ������ ��������������
%PROGRAM% test1.txt >%OUT% || goto err
fc %OUT% test1-out.txt || goto err
:: ���� � �������� ��������������
%PROGRAM% test3.txt >%OUT% || goto err
fc %OUT% test3-out.txt || goto err
:: ����, ���� ������������ ����� 0
%PROGRAM% test2.txt >%OUT% || goto err
fc %OUT% test2-out.txt || goto err

echo All tests passed
exit /B 0

:err
echo Program testing failed
exit /B 1