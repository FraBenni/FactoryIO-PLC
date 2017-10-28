@echo off

:: Setup the Visual Studio environment
:: NOTE modify variable to own path
:: NOTE have this be called by the bash script (ideally just call the statement below and csc)
:: call "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Auxiliary\Build\vcvars32.bat"

:: Check if the scene exists
echo Compiling programs
csc /reference:".\bin\EngineIO.dll" /platform:x64 ".\src\Program.cs" ".\src\FT-Con1.cs" ".\src\FT-Con2.cs" ".\src\FT-Con3.cs" ".\src\FT-Con4.cs" /out:".\bin\Program.exe"
