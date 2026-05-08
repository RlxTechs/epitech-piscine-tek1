$ErrorActionPreference = "Stop"

Write-Host "=== Module 17 - Local JSON API ===" -ForegroundColor Cyan

$moduleRoot = Split-Path -Parent $MyInvocation.MyCommand.Path
Set-Location $moduleRoot

python --version

Write-Host ""
Write-Host "Tests unitaires..." -ForegroundColor Cyan
python -m unittest discover -s tests -v

if ($LASTEXITCODE -ne 0) {
    Write-Host "Tests echoues." -ForegroundColor Red
    exit 1
}

Write-Host ""
Write-Host "Demo API locale..." -ForegroundColor Cyan
python .\app.py --demo

if ($LASTEXITCODE -ne 0) {
    Write-Host "Demo echouee." -ForegroundColor Red
    exit 1
}

Write-Host ""
Write-Host "Module 17 termine avec succes." -ForegroundColor Green
Write-Host "Pour lancer le serveur : python .\app.py --serve" -ForegroundColor Yellow
