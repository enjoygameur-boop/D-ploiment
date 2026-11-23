@echo off
setlocal
cd /d "%~dp0"
rem Genere un jeton automatiquement, sans aucune saisie.
rem Args optionnels: [serie] [jours] [empreinte]
set "SERIE=%~1"
set "JOURS=%~2"
set "FP=%~3"
if "%JOURS%"=="" set "JOURS=30"
if "%FP%"=="" set "FP=FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF"
if not "%SERIE%"=="" goto pret
if exist "SERIE.txt" (for /f "usebackq delims=" %%A in ("SERIE.txt") do set "DERNIER=%%A")
if "%DERNIER%"=="" set "DERNIER=1000"
set /a SERIE=%DERNIER%+1
:pret
> "SERIE.txt" echo %SERIE%
powershell -NoProfile -ExecutionPolicy Bypass -File "%~dp0keygen.ps1" -Fingerprint "%FP%" -Days %JOURS% -Serial %SERIE% -Out "%~dp0licence.dat"
if not exist "%~dp0licence.dat" echo [STOP] echec & pause & exit /b 1
copy /Y "%~dp0licence.dat" "%~dp0%SERIE%.txt" >nul
echo.
echo Serie %SERIE% - %JOURS% jours
echo Fichier a envoyer : %~dp0licence.dat
echo Copie de trace   : %~dp0%SERIE%.txt
echo.
start "" explorer.exe /select,"%~dp0licence.dat"
