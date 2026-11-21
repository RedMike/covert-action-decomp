@echo off
rem Portable build: every module's C alone, gcc under WSL with PORT_MODERN
rem defined and the .ASM untouched. Counts only, because the whole tree's
rem diagnostics do not fit a console; ask for a module to read those.
rem
rem Name modules for their diagnostics: portable_build.bat GAME
rem Any other flag portable.py takes is passed through.
setlocal
pushd "%~dp0.."
if "%~1"=="" (
    wsl python3 scripts/build/portable.py --all --log-long-tracebacks --log-console-level INFO
) else (
    wsl python3 scripts/build/portable.py --log-long-tracebacks --log-console-level DEBUG %*
)
set RC=%ERRORLEVEL%
popd
echo.
echo portable.py exited with code %RC%
pause
exit /b %RC%
