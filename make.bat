@echo off

if %1%==clean (
    echo "Cleaning ... "
    del main.obj
    del tests.obj
    del taswira.exe
    del tests.exe
    del *.bmp
)

if %1%==all (
    echo "Compiling All... "
    cl /EHsc /std:c++17 main.cpp /link /out:taswira.exe
    cl /EHsc /std:c++17 Tests\tests.cpp /link
)

if %1%==main (
    echo "Compiling All... "
    cl /EHsc /std:c++17 main.cpp /link /out:taswira.exe
)

if %1%==test (
    echo "Compiling Tests ... "
    cl /EHsc /std:c++17 Tests\tests.cpp /link
)

echo "... Done"