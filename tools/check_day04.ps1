$ErrorActionPreference = "Stop"

Write-Host "=== Test automatique - Day 04 Libmy Intro ===" -ForegroundColor Cyan

$root = Split-Path -Parent $PSScriptRoot
$folder = Join-Path $root "days\day04_libmy_intro"
Set-Location $folder

Write-Host "Nettoyage..." -ForegroundColor Yellow
make fclean

Write-Host "Compilation de libmy et du programme de test..." -ForegroundColor Yellow
make

if ($LASTEXITCODE -ne 0) {
    Write-Host "Erreur de compilation." -ForegroundColor Red
    exit 1
}

if (!(Test-Path ".\libmy.a")) {
    Write-Host "Erreur : libmy.a n a pas ete cree." -ForegroundColor Red
    exit 1
}

Write-Host "libmy.a cree avec succes." -ForegroundColor Green

Write-Host ""
Write-Host "Execution du programme de test :" -ForegroundColor Cyan

if (Test-Path ".\test_libmy.exe") {
    .\test_libmy.exe
} elseif (Test-Path ".\test_libmy") {
    .\test_libmy
} else {
    Write-Host "Programme test_libmy introuvable." -ForegroundColor Red
    exit 1
}

Write-Host ""
Write-Host "Day 04 termine : libmy compile et fonctionne." -ForegroundColor Green
