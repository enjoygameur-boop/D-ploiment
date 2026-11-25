@echo off
cd /d "%~dp0"
rem Lance l installateur sans dependre de la politique d execution.
powershell -NoProfile -ExecutionPolicy Bypass -File "%~dp0INSTALLER.ps1" %*
