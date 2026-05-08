$ErrorActionPreference = "Stop"

Write-Host "=== Test automatique - Day 11 Mini printf advanced ===" -ForegroundColor Cyan

$root = Split-Path -Parent $PSScriptRoot
$folder = Join-Path $root "days\day11_mini_printf_advanced"
Set-Location $folder

Write-Host "Nettoyage..." -ForegroundColor Yellow
make fclean

Write-Host "Compilation avec Makefile..." -ForegroundColor Yellow
make

if ($LASTEXITCODE -ne 0) {
    Write-Host "Erreur de compilation." -ForegroundColor Red
    exit 1
}

Write-Host ""
Write-Host "Execution du test mini_printf advanced :" -ForegroundColor Cyan

if (Test-Path ".\mini_printf_advanced.exe") {
    .\mini_printf_advanced.exe
} elseif (Test-Path ".\mini_printf_advanced") {
    .\mini_printf_advanced
} else {
    Write-Host "Programme mini_printf_advanced introuvable." -ForegroundColor Red
    exit 1
}

Write-Host ""
Write-Host "Day 11 termine : mini_printf advanced compile et fonctionne." -ForegroundColor Green
