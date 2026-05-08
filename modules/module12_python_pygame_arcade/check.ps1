$ErrorActionPreference = "Stop"

Write-Host "=== Module 12 - Python Pygame Arcade ===" -ForegroundColor Cyan

$moduleRoot = Split-Path -Parent $MyInvocation.MyCommand.Path
Set-Location $moduleRoot

Write-Host "Verification Python..." -ForegroundColor Yellow
python --version

Write-Host ""
Write-Host "Tests unitaires..." -ForegroundColor Cyan
python -m unittest discover -s tests -v

if ($LASTEXITCODE -ne 0) {
    Write-Host "Tests echoues." -ForegroundColor Red
    exit 1
}

Write-Host ""
Write-Host "Demo headless..." -ForegroundColor Cyan
python .\app.py --headless

if ($LASTEXITCODE -ne 0) {
    Write-Host "Demo headless echouee." -ForegroundColor Red
    exit 1
}

Write-Host ""
Write-Host "Module 12 termine avec succes." -ForegroundColor Green
Write-Host "Pour la fenetre graphique : python -m pip install pygame puis python .\app.py" -ForegroundColor Yellow
