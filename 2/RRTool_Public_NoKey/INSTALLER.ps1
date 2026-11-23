# Dreww - installateur.
# Copie le produit dans C:\Dreww, demande la licence, coupe l hyperviseur, pose un raccourci.
# A lancer par clic droit > Executer avec PowerShell. S eleve tout seul.
$ErrorActionPreference = "Stop"
$src = $PSScriptRoot
$dst = "C:\Dreww"

function Test-Admin {
    $id = [Security.Principal.WindowsIdentity]::GetCurrent()
    (New-Object Security.Principal.WindowsPrincipal($id)).IsInRole(
        [Security.Principal.WindowsBuiltInRole]::Administrator)
}

if (-not (Test-Admin)) {
    Start-Process powershell -Verb RunAs -ArgumentList @(
        "-NoProfile", "-ExecutionPolicy", "Bypass", "-File", $PSCommandPath)
    return
}

Write-Host ""
Write-Host "=== Installation de Dreww ==="
Write-Host ""

if (-not (Test-Path (Join-Path $src "1_run\RobRunPort.exe"))) {
    Write-Host "[STOP] Ce script doit rester dans le dossier livre, a cote de 1_run."
    Read-Host "Entree pour fermer"
    return
}

Write-Host "1/4  Copie vers $dst"
if (Test-Path $dst) {
    Write-Host "     Le dossier existe deja, contenu remplace."
}
robocopy $src $dst /E /XD "$src\_licence" "$src\.git" "$src\_archive" /XF "*.log" /NFL /NDL /NJH /NJS /NP | Out-Null

Write-Host "2/4  Dossier de licence"
$lic = Join-Path $env:LOCALAPPDATA "Dreww"
New-Item -ItemType Directory -Path $lic -Force | Out-Null
Write-Host "     Choisis le fichier licence.dat recu apres achat."
Add-Type -AssemblyName System.Windows.Forms
$dlg = New-Object System.Windows.Forms.OpenFileDialog
$dlg.Title = "Selectionne licence.dat"
$dlg.Filter = "Licence (licence.dat)|*.dat|Tous les fichiers|*.*"
if ($dlg.ShowDialog() -eq "OK") {
    Copy-Item $dlg.FileName (Join-Path $lic "licence.dat") -Force
    Write-Host "     Licence installee."
} else {
    Write-Host "     Aucun fichier choisi. Depose licence.dat dans $lic puis relance START.bat."
}

Write-Host "3/4  Protection du pilote"
reg add "HKLM\SYSTEM\CurrentControlSet\Control\DeviceGuard\Scenarios\HypervisorEnforcedCodeIntegrity" /v Enabled /t REG_DWORD /d 0 /f | Out-Null
bcdedit /set hypervisorlaunchtype off | Out-Null
foreach ($f in "Microsoft-Hyper-V-All", "VirtualMachinePlatform", "HypervisorPlatform", "Containers-DisposableClientVM", "Microsoft-Windows-Subsystem-Linux") {
    dism /online /quiet /norestart /disable-feature /featurename:$f | Out-Null
}
foreach ($s in "vmcompute", "HvHost", "vmms", "WslService") {
    sc.exe stop $s | Out-Null
    sc.exe config $s start= disabled | Out-Null
}
Get-Process "Docker Desktop" | Stop-Process -Force

Write-Host "4/4  Raccourci"
$ws = New-Object -ComObject WScript.Shell
$lnk = $ws.CreateShortcut((Join-Path ([Environment]::GetFolderPath("Desktop")) "Dreww.lnk"))
$lnk.TargetPath = Join-Path $dst "START.bat"
$lnk.WorkingDirectory = $dst
$lnk.Save()

Write-Host ""
Write-Host "Installe. Il reste a redemarrer, puis lancer Dreww par le raccourci."
Write-Host "Redemarrage dans 20 secondes, Ctrl+C pour annuler."
shutdown /r /t 20
