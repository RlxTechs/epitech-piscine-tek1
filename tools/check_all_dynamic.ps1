$ErrorActionPreference = "Stop"

Write-Host "=== Verification dynamique du projet complet ===" -ForegroundColor Cyan

$root = Split-Path -Parent $PSScriptRoot
Set-Location $root

Write-Host ""
Write-Host "1. Verification des days..." -ForegroundColor Cyan
$dayChecks = Get-ChildItem -Path ".\tools" -Filter "check_day*.ps1" | Sort-Object Name

foreach ($check in $dayChecks) {
    Write-Host ""
    Write-Host "Lancement : $($check.Name)" -ForegroundColor Yellow
    powershell -ExecutionPolicy Bypass -File $check.FullName
}

Write-Host ""
Write-Host "2. Verification des modules..." -ForegroundColor Cyan
powershell -ExecutionPolicy Bypass -File ".\tools\check_modules.ps1"

Write-Host ""
Write-Host "Projet complet verifie avec succes." -ForegroundColor Green
