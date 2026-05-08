$ErrorActionPreference = "Stop"

Write-Host "=== Verification de tous les modules ===" -ForegroundColor Cyan

$root = Split-Path -Parent $PSScriptRoot
$modulesRoot = Join-Path $root "modules"

if (!(Test-Path $modulesRoot)) {
    Write-Host "Aucun dossier modules trouve." -ForegroundColor Yellow
    exit 0
}

$checks = Get-ChildItem -Path $modulesRoot -Filter check.ps1 -Recurse | Sort-Object FullName

if ($checks.Count -eq 0) {
    Write-Host "Aucun check.ps1 trouve dans les modules." -ForegroundColor Yellow
    exit 0
}

foreach ($check in $checks) {
    Write-Host ""
    Write-Host "Lancement module : $($check.FullName)" -ForegroundColor Yellow
    powershell -ExecutionPolicy Bypass -File $check.FullName
}

Write-Host ""
Write-Host "Tous les modules disponibles sont OK." -ForegroundColor Green
