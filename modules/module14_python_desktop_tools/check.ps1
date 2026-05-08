$ErrorActionPreference = "Stop"

Write-Host "=== Module 14 - Python Desktop Tools ===" -ForegroundColor Cyan

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
Write-Host "Demo headless..." -ForegroundColor Cyan
python .\app.py --headless

Write-Host ""
Write-Host "Module 14 termine avec succes." -ForegroundColor Green
Write-Host "Pour lancer l'interface : python .\app.py" -ForegroundColor Yellow
