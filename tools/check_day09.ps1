$ErrorActionPreference = "Stop"

Write-Host "=== Test automatique - Day 09 Mini printf intro ===" -ForegroundColor Cyan

$root = Split-Path -Parent $PSScriptRoot
$folder = Join-Path $root "days\day09_mini_printf_intro"
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
Write-Host "Execution du test mini_printf :" -ForegroundColor Cyan

if (Test-Path ".\mini_printf_test.exe") {
    .\mini_printf_test.exe
} elseif (Test-Path ".\mini_printf_test") {
    .\mini_printf_test
} else {
    Write-Host "Programme mini_printf_test introuvable." -ForegroundColor Red
    exit 1
}

Write-Host ""
Write-Host "Day 09 termine : mini_printf compile et fonctionne." -ForegroundColor Green
