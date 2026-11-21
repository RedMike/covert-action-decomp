@echo off
rem Sync each module's copy of a shared body from src/shared/c/, never back: a
rem chunk is the text between a shared_include_start and shared_include_end
rem marker. Run it after editing anything under src/shared/c/, because a module
rem builds from its own copy and prevalidate refuses one that has drifted.
setlocal
pushd "%~dp0.."
wsl python3 scripts/build/shared_sync.py --replace %*
set RC=%ERRORLEVEL%
popd
echo.
echo shared_sync.py exited with code %RC%
pause
exit /b %RC%
