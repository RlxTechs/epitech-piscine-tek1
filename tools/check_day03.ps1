$ErrorActionPreference = "Stop"

Write-Host "=== Test automatique - Day 03 Pointers and Arrays ===" -ForegroundColor Cyan

$root = Split-Path -Parent $PSScriptRoot
$folder = Join-Path $root "days\day03_pointers_arrays"
Set-Location $folder

Write-Host "Nettoyage..." -ForegroundColor Yellow
make fclean

Write-Host "Compilation avec Makefile..." -ForegroundColor Yellow
make

if ($LASTEXITCODE -ne 0) {
    Write-Host "Erreur de compilation." -ForegroundColor Red
    exit 1
}

$programs = @(
    ".\ex00_address.exe",
    ".\ex01_set_value.exe",
    ".\ex02_swap.exe",
    ".\ex03_print_array.exe",
    ".\ex04_array_sum.exe",
    ".\ex05_min_max.exe",
    ".\ex06_reverse_array.exe",
    ".\ex07_sort_array.exe"
)

foreach ($program in $programs) {
    Write-Host ""
    Write-Host "Execution : $program" -ForegroundColor Cyan
    & $program
}

Write-Host ""
Write-Host "Day 03 termine : tous les exercices compilent et se lancent." -ForegroundColor Green
