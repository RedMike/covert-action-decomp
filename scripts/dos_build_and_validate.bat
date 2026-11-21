@echo off
rem DOS build, then validation. A run with no module named builds and
rem validates every module.
rem
rem Name modules to build and validate only those: dos_build_and_validate.bat GAME TAC
rem Module names only; a build.py or validate.py flag goes through its own .bat.
setlocal
pushd "%~dp0.."
wsl python3 scripts/build/build.py --log-long-tracebacks --log-console-level INFO %*
set RC=%ERRORLEVEL%
if not "%RC%"=="0" (
    echo.
    echo build.py exited with code %RC%; nothing validated
    goto done
)
wsl python3 scripts/build/validate.py --log-long-tracebacks --log-console-level INFO %*
set RC=%ERRORLEVEL%
echo.
echo validate.py exited with code %RC%
:done
popd
pause
exit /b %RC%
