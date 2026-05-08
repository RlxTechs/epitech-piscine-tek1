$ErrorActionPreference = "Stop"

Write-Host "=== Module 13 - Web Canvas Games ===" -ForegroundColor Cyan

$moduleRoot = Split-Path -Parent $MyInvocation.MyCommand.Path
Set-Location $moduleRoot

Write-Host "Tests de structure..." -ForegroundColor Cyan
python -m unittest discover -s tests -v

if ($LASTEXITCODE -ne 0) {
    Write-Host "Tests echoues." -ForegroundColor Red
    exit 1
}

Write-Host ""
Write-Host "Module 13 termine avec succes." -ForegroundColor Green
Write-Host "Pour lancer : start .\index.html" -ForegroundColor Yellow
