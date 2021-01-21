@echo off

if %1%==clean (
    echo "Cleaning ... "
    del main.obj
    del taswira.exe
    del *.bmp
)

if %1%==all (
    echo "Compiling ... "
    cl /EHsc main.cpp /link /out:taswira.exe
)

echo "... Done"