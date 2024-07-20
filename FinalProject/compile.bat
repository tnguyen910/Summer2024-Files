@echo off

:: Compile the source files
g++ main.cpp functions.cpp -o main.exe

:: Run the executable
main.exe

:: Remove the executable
del main.exe

:: Exit the script
exit /b 0
