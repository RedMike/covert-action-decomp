@echo off
rem Full DOS build: every module, MSC 5.1 and MASM 5.1 through DOSBox under WSL.
rem A run with no module named resets rebuilt/ from decompressed/ first.
rem
rem Name modules to build only those: dos_build.bat GAME TAC
rem Any other flag build.py takes is passed through: dos_build.bat -j 1
setlocal
pushd "%~dp0.."
wsl python3 scripts/build/build.py --log-long-tracebacks --log-console-level INFO %*
set RC=%ERRORLEVEL%
popd
echo.
echo build.py exited with code %RC%
pause
exit /b %RC%
