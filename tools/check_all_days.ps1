$ErrorActionPreference = "Stop"

Write-Host "=== Test global de tous les jours disponibles ===" -ForegroundColor Cyan

$root = Split-Path -Parent $PSScriptRoot
Set-Location $root

$scripts = @(
    ".\tools\check_day01.ps1",
    ".\tools\check_day02.ps1",
    ".\tools\check_day03.ps1",
    ".\tools\check_day04.ps1"
)

foreach ($script in $scripts) {
    if (Test-Path $script) {
        Write-Host ""
        Write-Host "Lancement : $script" -ForegroundColor Yellow
        powershell -ExecutionPolicy Bypass -File $script
    } else {
        Write-Host "Script introuvable : $script" -ForegroundColor Red
    }
}

Write-Host ""
Write-Host "Tous les tests disponibles sont termines." -ForegroundColor Green
