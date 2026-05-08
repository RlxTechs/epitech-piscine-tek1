$ErrorActionPreference = "Stop"

Write-Host "=== Module 03 - Math for Games ===" -ForegroundColor Cyan

$moduleRoot = Split-Path -Parent $MyInvocation.MyCommand.Path
Set-Location $moduleRoot

Write-Host "Nettoyage..." -ForegroundColor Yellow
make fclean

Write-Host "Compilation..." -ForegroundColor Yellow
make

if ($LASTEXITCODE -ne 0) {
    Write-Host "Erreur compilation module03." -ForegroundColor Red
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
Write-Host "Execution demo math_game_demo..." -ForegroundColor Cyan
& ".\math_game_demo.exe"

Write-Host ""
Write-Host "Module 03 termine avec succes." -ForegroundColor Green
