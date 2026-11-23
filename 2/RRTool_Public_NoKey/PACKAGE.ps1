# Dreww - fabrique le paquet client dans dist\.
# Usage: PACKAGE.ps1 [-Version 1.0.0]
param([string]$Version = "1.0.0")
$ErrorActionPreference = "Stop"
$src = Split-Path -Parent $MyInvocation.MyCommand.Path
$dist = Join-Path $src "dist"
$stage = Join-Path $dist ("Dreww_" + $Version)
$zip = $stage + ".zip"

if (-not (Test-Path (Join-Path $src "1_run\RobRunPort.exe"))) {
    Write-Host "[STOP] script hors du dossier produit"
    exit 1
}

Write-Host "1/4  Nettoyage"
if (Test-Path $stage) { Remove-Item $stage -Recurse -Force }
if (Test-Path $zip) { Remove-Item $zip -Force }
New-Item -ItemType Directory -Path $stage -Force | Out-Null

Write-Host "2/4  Copie"
robocopy (Join-Path $src "1_run") (Join-Path $stage "1_run") /E /XD (Join-Path $src "1_run\payload") /XF "*.log" "*.orig" "masq.txt" "robrun_runtime.txt" /NFL /NDL /NJH /NJS /NP | Out-Null
robocopy (Join-Path $src "setup") (Join-Path $stage "setup") /E /NFL /NDL /NJH /NJS /NP | Out-Null
New-Item -ItemType Directory -Path (Join-Path $stage "docs") -Force | Out-Null
Copy-Item (Join-Path $src "docs\INSTALLATION_CLIENT.md") (Join-Path $stage "docs") -Force
Copy-Item (Join-Path $src "INSTALLER.ps1") $stage -Force
Copy-Item (Join-Path $src "INSTALLER.cmd") $stage -Force

Write-Host "3/4  Compression"
Compress-Archive -Path (Join-Path $stage "*") -DestinationPath $zip -CompressionLevel Optimal

Write-Host "4/4  Empreinte"
$z = Get-Item $zip
$h = (Get-FileHash $zip -Algorithm SHA256).Hash
Write-Host ""
Write-Host ("Paquet : " + $z.FullName)
Write-Host ("Taille : " + $z.Length + " octets")
Write-Host ("SHA256 : " + $h)
Write-Host ""
Write-Host "Verifie: installe le paquet sur une machine propre avant de l envoyer."
Write-Host ("A envoyer avec une licence.dat distincte par acheteur.")
