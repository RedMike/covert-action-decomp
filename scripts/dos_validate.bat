@echo off
rem Full validation: every module in rebuilt/ against decompressed/, the load
rem image byte for byte. It measures what build.py staged, and refuses a module
rem whose staged binary did not come from the source as it stands.
rem
rem Name one module to validate only that: dos_validate.bat INTRO
rem Any other flag validate.py takes is passed through: dos_validate.bat -q
setlocal
pushd "%~dp0.."
wsl python3 scripts/build/validate.py --log-long-tracebacks --log-console-level INFO %*
set RC=%ERRORLEVEL%
popd
echo.
echo validate.py exited with code %RC%
pause
exit /b %RC%
