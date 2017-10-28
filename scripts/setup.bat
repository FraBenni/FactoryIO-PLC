@echo off

:: Setup the Visual Studio environment
:: NOTE modify variable to own path
:: NOTE have this be called by the bash script (ideally just call the statement below and csc)
:: call "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Auxiliary\Build\vcvars32.bat"

:: Check if the scene exists
set "base_dir=C:\Users\Matt Potok\Documents\Research\Smart Manufacturing\factory-io"
set "scene=%base_dir%\scenes\%1"

if not exist "%scene%" (
	echo Scene %scene% could not be found.
	exit /b
)

::Compile source
set "bin=%scene%\bin"
set "obj=%scene%\obj"
set "ladder=%scene%\ladder"
set "src=%scene%\src"

set "iec=%base_dir%\lib\iec"

echo %ladder%

if not exist "%bin%" mkdir "%bin%"
if not exist "%obj%" mkdir "%obj%"

echo Compiling programs
csc /reference:"%bin%\EngineIO.dll" /platform:x64 "%src%\Program.cs" "%src%\Interface.cs" /out:"%bin%\Program.exe"