@echo off
chcp 65001
set PROGRAM="%~1"

set OUT="%TEMP%\out.txt"
:: Тест на обычную ситуацию
%PROGRAM% test1.txt %OUT% Hello mama || goto err
fc %OUT% test1-out.txt || goto err
:: Тест с заменой на пустую строку
%PROGRAM% test1.txt %OUT% Hello "" || goto err
fc %OUT% test2-out.txt || goto err
:: Тест с заменой пустой строки 
%PROGRAM% test1.txt %OUT% "" Hello || goto err
fc %OUT% test3-out.txt || goto err
:: Тест с заменой многократного вхождения искомой строки в строку-заменитель
%PROGRAM% test1.txt %OUT% ma mama || goto err
fc %OUT% test4-out.txt || goto err
:: Тест с заменой подстроки 1231234 внутри текста 12312345
%PROGRAM% test1.txt %OUT% 1231234 h || goto err
fc %OUT% test5-out.txt || goto err

echo All tests passed
exit /B 0

:err
echo Program testing failed
exit /B 1