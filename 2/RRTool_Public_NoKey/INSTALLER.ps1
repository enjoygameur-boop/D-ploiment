# Dreww - installateur.
# Copie le produit dans C:\Dreww, installe la licence, coupe l hyperviseur, pose un raccourci.
# Clic droit > Executer avec PowerShell. S eleve seul. -NoReboot pour tester sans redemarrer.
param([switch]$NoReboot)
$ErrorActionPreference = "Stop"
$src = Split-Path -Parent $MyInvocation.MyCommand.Path
$dst = "C:\Dreww"

function Test-Admin {
    $id = [Security.Principal.WindowsIdentity]::GetCurrent()
    (New-Object Security.Principal.WindowsPrincipal($id)).IsInRole(
        [Security.Principal.WindowsBuiltInRole]::Administrator)
}

if (-not (Test-Admin)) {
    $a = @("-NoProfile", "-ExecutionPolicy", "Bypass", "-File", $MyInvocation.MyCommand.Path)
    if ($NoReboot) { $a += "-NoReboot" }
    Start-Process powershell -Verb RunAs -ArgumentList $a
    return
}

Write-Host ""
Write-Host "=== Installation de Dreww ==="
Write-Host ""

if (-not (Test-Path (Join-Path $src "1_run\RobRunPort.exe"))) {
    Write-Host "[STOP] Ce script doit rester dans le dossier livre."
    Read-Host "Entree pour fermer"
    return
}

Write-Host "1/4  Copie vers $dst"
New-Item -ItemType Directory -Path $dst -Force | Out-Null
foreach ($d in "1_run", "setup", "docs") {
    robocopy (Join-Path $src $d) (Join-Path $dst $d) /E /XF "PROCEDURE_LICENCES.md" "DEFAUTS.md" "RISQUES.md" /NFL /NDL /NJH /NJS /NP | Out-Null
    if ($LASTEXITCODE -ge 8) {
        Write-Host "[STOP] copie en echec sur $d (robocopy $LASTEXITCODE)"
        Read-Host "Entree pour fermer"
        return
    }
}
Copy-Item (Join-Path $src "INSTALLER.ps1") (Join-Path $dst "INSTALLER.ps1") -Force
Copy-Item (Join-Path $src "INSTALLER.cmd") (Join-Path $dst "INSTALLER.cmd") -Force

Write-Host "2/4  Licence"
$lic = Join-Path $env:LOCALAPPDATA "Dreww"
New-Item -ItemType Directory -Path $lic -Force | Out-Null
Add-Type -AssemblyName System.Windows.Forms
$dlg = New-Object System.Windows.Forms.OpenFileDialog
$dlg.Title = "Selectionne licence.dat"
$dlg.Filter = "Licence (licence.dat)|*.dat|Tous les fichiers|*.*"
if ($dlg.ShowDialog() -eq "OK") {
    try {
        $dstLic = Join-Path $lic "licence.dat"
        if ($dlg.FileName -ne $dstLic) { Copy-Item $dlg.FileName $dstLic -Force }
        Write-Host "     licence en place"
        Write-Host "     licence installee"
    } catch {
        Write-Host "     copie impossible : $($_.Exception.Message)"
    }
} else {
    Write-Host "     aucun fichier choisi, depose licence.dat dans $lic"
}

Write-Host "3/4  Protection du pilote"
$hv = Join-Path $dst "setup\1_couper_hyperviseur.ps1"
if (Test-Path $hv) {
    $pr = Start-Process powershell -Wait -PassThru -ArgumentList @("-NoProfile", "-ExecutionPolicy", "Bypass", "-File", $hv, "-NoReboot")
    if ($pr.ExitCode -ne 0) { Write-Host "     script hyperviseur code $($pr.ExitCode)" }
} else {
    Write-Host "     [ATTENTION] $hv absent, etape sautee"
}

Write-Host "4/4  Raccourci"
$ws = New-Object -ComObject WScript.Shell
$lnk = $ws.CreateShortcut((Join-Path ([Environment]::GetFolderPath("Desktop")) "Dreww.lnk"))
$lnk.TargetPath = Join-Path $dst "1_run\FFLoader.exe"
$lnk.WorkingDirectory = $dst
$lnk.Save()

Write-Host ""
if ($NoReboot) {
    Write-Host "Termine, sans redemarrage."
    Read-Host "Entree pour fermer"
} else {
    Write-Host "Installe. Redemarrage dans 20 secondes, Ctrl+C pour annuler."
    shutdown /r /t 20
}
