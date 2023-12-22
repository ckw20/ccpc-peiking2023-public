:loop
gen.exe>data.txt
std_new.exe<data.txt>1.txt
bf.exe<data.txt>2.txt
fc 1.txt 2.txt
if not errorlevel 1 goto loop
pause