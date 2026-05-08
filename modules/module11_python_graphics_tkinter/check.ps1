$ErrorActionPreference = "Stop"

Write-Host "=== Module 11 - Python Graphics Tkinter ===" -ForegroundColor Cyan

$moduleRoot = Split-Path -Parent $MyInvocation.MyCommand.Path
Set-Location $moduleRoot

Write-Host "Verification Python..." -ForegroundColor Yellow
python --version

Write-Host ""
Write-Host "Tests unitaires Python..." -ForegroundColor Cyan
python -m unittest discover -s tests -v

if ($LASTEXITCODE -ne 0) {
    Write-Host "Tests Python echoues." -ForegroundColor Red
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
Write-Host "Module 11 termine avec succes." -ForegroundColor Green
Write-Host "Pour lancer la fenetre graphique : python .\app.py" -ForegroundColor Yellow
