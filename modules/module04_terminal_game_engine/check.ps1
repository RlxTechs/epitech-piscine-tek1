$ErrorActionPreference = "Stop"

Write-Host "=== Module 04 - Terminal Game Engine ===" -ForegroundColor Cyan

$moduleRoot = Split-Path -Parent $MyInvocation.MyCommand.Path
Set-Location $moduleRoot

Write-Host "Nettoyage..." -ForegroundColor Yellow
make fclean

Write-Host "Compilation..." -ForegroundColor Yellow
make

if ($LASTEXITCODE -ne 0) {
    Write-Host "Erreur compilation module04." -ForegroundColor Red
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
Write-Host "Demo automatique du jeu..." -ForegroundColor Cyan
& ".\terminal_game.exe" "--script"

Write-Host ""
Write-Host "Module 04 termine avec succes." -ForegroundColor Green
