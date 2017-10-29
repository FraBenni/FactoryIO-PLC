@echo off

:: Setup the Visual Studio environment
:: NOTE modify variable to own path
:: call "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Auxiliary\Build\vcvars64.bat"

cl -clr -LD Wrapper.cpp Interface.cpp -Fo.\obj\ -Fe.\bin\
csc -reference:.\bin\Wrapper.dll /out:.\bin\Program.exe Program.cs