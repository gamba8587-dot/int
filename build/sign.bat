@echo off
openfiles >nul 2>nul
if %errorlevel% neq 0 powershell -Command "Start-Process cmd -ArgumentList '/c %~s0' -Verb runAs" & exit /b
pushd "%~dp0"
cd /d "%~dp0signer\relapse-timestamper" & start "" "relapse-timestamper.exe"
cd /d "%~dp0%~dp0"
"%~dp0signer\relapse-signer.exe" -verification -certificate "%~dp0signer\cert.pfx" -password ".gg/skidding" -file "%~dp0module.dll"
taskkill /f /im relapse-timestamper.exe >nul 2>nul
exit