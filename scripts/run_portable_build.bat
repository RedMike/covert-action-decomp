@echo off
rem Start the portable Windows build of the game, portable\windows\covert.exe,
rem from the game's own directory. It runs what portable_build.bat has built
rem and builds nothing itself.
setlocal
set "ROOT=%~dp0.."
set "EXE=%ROOT%\portable\windows\covert.exe"
set "GAME=%ROOT%\rebuilt\MPS\COVERT"
if not exist "%EXE%" (
    echo %EXE% is not there. Build it first:
    echo     scripts\portable_build.bat
    exit /b 1
)
if not exist "%GAME%\FONTS.CV" (
    echo %GAME% holds no game files. A DOS build puts them there:
    echo     scripts\dos_build.bat
    exit /b 1
)
cd /d "%GAME%"
"%EXE%" %*
endlocal
