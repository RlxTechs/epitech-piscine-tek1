$ErrorActionPreference = "Stop"

Write-Host "=== Module 01 - Project Architecture ===" -ForegroundColor Cyan

$moduleRoot = Split-Path -Parent $MyInvocation.MyCommand.Path
Set-Location $moduleRoot

Write-Host "Nettoyage..." -ForegroundColor Yellow
make fclean

Write-Host "Compilation..." -ForegroundColor Yellow
make

if ($LASTEXITCODE -ne 0) {
    Write-Host "Erreur compilation module01." -ForegroundColor Red
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
Write-Host "Execution app sans argument..." -ForegroundColor Cyan
& ".\app_architecture.exe"

Write-Host ""
Write-Host "Execution app add..." -ForegroundColor Cyan
& ".\app_architecture.exe" "add" "10" "5"

Write-Host ""
Write-Host "Execution app mul..." -ForegroundColor Cyan
& ".\app_architecture.exe" "mul" "10" "5"

Write-Host ""
Write-Host "Module 01 termine avec succes." -ForegroundColor Green
