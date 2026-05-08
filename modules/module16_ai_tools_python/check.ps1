$ErrorActionPreference = "Stop"

Write-Host "=== Module 16 - AI Tools Python ===" -ForegroundColor Cyan

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
Write-Host "Demo IA locale..." -ForegroundColor Cyan
python .\app.py --demo

Write-Host ""
Write-Host "Test question directe..." -ForegroundColor Cyan
python .\app.py "tv 32 dispo ?"

Write-Host ""
Write-Host "Module 16 termine avec succes." -ForegroundColor Green
