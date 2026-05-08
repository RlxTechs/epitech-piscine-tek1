$ErrorActionPreference = "Stop"

Write-Host "=== Module 15 - Data Visualization Python ===" -ForegroundColor Cyan

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
Write-Host "Generation rapport + graphique SVG..." -ForegroundColor Cyan
python .\app.py

if ($LASTEXITCODE -ne 0) {
    Write-Host "Generation rapport echouee." -ForegroundColor Red
    exit 1
}

Write-Host ""
Write-Host "Module 15 termine avec succes." -ForegroundColor Green
Write-Host "Ouvre : .\output\report.txt et .\output\revenue_by_category.svg" -ForegroundColor Yellow
