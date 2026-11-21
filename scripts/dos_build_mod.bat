@echo off
rem DOS build with optional changes switched on: every argument is a define,
rem and the build names the modules a define can reach itself. Not
rem byte-identical, and the six game modules build in the medium model.
rem
rem     dos_build_mod.bat FIX_TAC_MOVE COVERT_MENU_OPTIONS
rem
rem It builds into the rebuilt/ a full build left, so run dos_build.bat first;
rem run it again afterwards to go back to the byte-identical build, which is
rem the only one dos_validate.bat measures.
setlocal EnableDelayedExpansion
if "%~1"=="" (
    echo usage: dos_build_mod.bat DEFINE [DEFINE ...]
    exit /b 2
)
set "DEFINES="
for %%d in (%*) do set "DEFINES=!DEFINES! --define %%d"
pushd "%~dp0.."
if not exist "rebuilt\MPS\COVERT" (
    echo rebuilt\ is not there yet. Run dos_build.bat first.
    popd
    exit /b 1
)
wsl python3 scripts/build/build.py COVERT BUG CHASE CODE FINAL GAME TAC%DEFINES% --log-long-tracebacks --log-console-level INFO
set RC=%ERRORLEVEL%
popd
echo.
echo build.py exited with code %RC%
pause
exit /b %RC%
