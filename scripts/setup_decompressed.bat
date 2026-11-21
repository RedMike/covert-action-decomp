@echo off
rem Make decompressed/ from the retail game in original/: a copy with every
rem EXEPACK'd executable replaced by its unpacked form, which is what a build
rem is validated against. original/ is only read.
rem
rem Any flag build_decompressed.py takes is passed through:
rem setup_decompressed.bat --dry-run
setlocal
pushd "%~dp0.."
wsl python3 scripts/setup/build_decompressed.py %*
set RC=%ERRORLEVEL%
popd
echo.
echo build_decompressed.py exited with code %RC%
pause
exit /b %RC%
