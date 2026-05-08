$ErrorActionPreference = "Stop"

Write-Host "=== Test automatique - Day 14 C tests and debug ===" -ForegroundColor Cyan

$root = Split-Path -Parent $PSScriptRoot
$folder = Join-Path $root "days\day14_c_tests_debug"
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
Write-Host "Execution des tests unitaires :" -ForegroundColor Cyan

if (Test-Path ".\unit_tests.exe") {
    .\unit_tests.exe
} elseif (Test-Path ".\unit_tests") {
    .\unit_tests
} else {
    Write-Host "Programme unit_tests introuvable." -ForegroundColor Red
    exit 1
}

if ($LASTEXITCODE -ne 0) {
    Write-Host "Des tests ont echoue." -ForegroundColor Red
    exit 1
}

Write-Host ""
Write-Host "Day 14 termine : tous les tests passent." -ForegroundColor Green
