# Dreww - coupe l hyperviseur et tout ce qui bloque le pilote.
# S eleve tout seul en administrateur, puis redemarre a la fin.
param([switch]$NoReboot)
$ErrorActionPreference = "SilentlyContinue"

function Test-Admin {
    $id = [Security.Principal.WindowsIdentity]::GetCurrent()
    (New-Object Security.Principal.WindowsPrincipal($id)).IsInRole(
        [Security.Principal.WindowsBuiltInRole]::Administrator)
}

if (-not (Test-Admin)) {
    $a = @("-NoProfile", "-ExecutionPolicy", "Bypass", "-File", $PSCommandPath)
    if ($NoReboot) { $a += "-NoReboot" }
    Start-Process powershell -Verb RunAs -ArgumentList $a
    return
}

Write-Host ""
Write-Host "1/5  Integrite de la memoire (HVCI)"
reg add "HKLM\SYSTEM\CurrentControlSet\Control\DeviceGuard\Scenarios\HypervisorEnforcedCodeIntegrity" /v Enabled /t REG_DWORD /d 0 /f | Out-Null

Write-Host "2/5  Hyperviseur au demarrage"
bcdedit /set hypervisorlaunchtype off | Out-Null

Write-Host "3/5  Fonctionnalites Windows"
foreach ($f in "Microsoft-Hyper-V-All", "VirtualMachinePlatform", "HypervisorPlatform", "Containers-DisposableClientVM", "Microsoft-Windows-Subsystem-Linux") {
    dism /online /quiet /norestart /disable-feature /featurename:$f | Out-Null
}

Write-Host "4/5  Services de virtualisation"
foreach ($s in "vmcompute", "HvHost", "vmms", "WslService") {
    sc.exe stop $s | Out-Null
    sc.exe config $s start= disabled | Out-Null
}

Write-Host "5/5  Docker"
Get-Process "Docker Desktop" | Stop-Process -Force

Write-Host ""
Write-Host "Termine. Redemarrage dans 15 secondes, Ctrl+C pour annuler."
Write-Host "Si Windows redemande l integrite de la memoire apres coup, relance ce script."
if (-not $NoReboot) { shutdown /r /t 15 }
