$ErrorActionPreference = "Stop"

Write-Host "=== Module 05 - Grid Games ===" -ForegroundColor Cyan

$moduleRoot = Split-Path -Parent $MyInvocation.MyCommand.Path
Set-Location $moduleRoot

Write-Host "Nettoyage..." -ForegroundColor Yellow
make fclean

Write-Host "Compilation..." -ForegroundColor Yellow
make

if ($LASTEXITCODE -ne 0) {
    Write-Host "Erreur compilation module05." -ForegroundColor Red
    exit 1
}

Write-Host ""
Write-Host "Tests unitaires..." -ForegroundColor Cyan
& ".\unit_tests.exe"

if ($LASTEXITCODE -ne 0) {
    Write-Host "Tests unitaires echoues." -ForegroundColor Red
    exit 1
}

Write-Host ""
Write-Host "Demo automatique du grid game..." -ForegroundColor Cyan
& ".\grid_game.exe" "--demo"

Write-Host ""
Write-Host "Module 05 termine avec succes." -ForegroundColor Green
