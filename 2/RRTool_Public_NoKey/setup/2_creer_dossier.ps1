# Dreww - cree le dossier de licence.
$d = Join-Path $env:LOCALAPPDATA "Dreww"
New-Item -ItemType Directory -Path $d -Force | Out-Null
Write-Host ""
Write-Host "Dossier pret :"
Write-Host $d
Write-Host ""
Write-Host "Place licence.dat ici, sans le renommer, puis lance START.bat en administrateur."
Write-Host ""
Start-Process explorer.exe $d
