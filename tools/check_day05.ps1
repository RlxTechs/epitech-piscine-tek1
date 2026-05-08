$ErrorActionPreference = "Stop"

Write-Host "=== Test automatique - Day 05 Args and Parsing ===" -ForegroundColor Cyan

$root = Split-Path -Parent $PSScriptRoot
$folder = Join-Path $root "days\day05_args_parsing"
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
Write-Host "Execution : ex00_show_args" -ForegroundColor Cyan
& ".\ex00_show_args.exe" "RLX" "TEK1" "C"

Write-Host ""
Write-Host "Execution : ex01_my_atoi" -ForegroundColor Cyan
& ".\ex01_my_atoi.exe" "-2026"

Write-Host ""
Write-Host "Execution : ex02_is_number" -ForegroundColor Cyan
& ".\ex02_is_number.exe" "12345"
& ".\ex02_is_number.exe" "12abc"

Write-Host ""
Write-Host "Execution : ex03_sum_args" -ForegroundColor Cyan
& ".\ex03_sum_args.exe" "10" "20" "-5" "7"

Write-Host ""
Write-Host "Execution : ex04_max_arg" -ForegroundColor Cyan
& ".\ex04_max_arg.exe" "4" "99" "-3" "42"

Write-Host ""
Write-Host "Execution : ex05_count_words" -ForegroundColor Cyan
& ".\ex05_count_words.exe" "RLX apprend la piscine TEK1"

Write-Host ""
Write-Host "Execution : ex06_split_preview" -ForegroundColor Cyan
& ".\ex06_split_preview.exe" "RLX apprend la piscine TEK1"

Write-Host ""
Write-Host "Execution : ex07_calculator_args" -ForegroundColor Cyan
& ".\ex07_calculator_args.exe" "10" "+" "5"
& ".\ex07_calculator_args.exe" "10" "x" "5"
& ".\ex07_calculator_args.exe" "10" "/" "2"

Write-Host ""
Write-Host "Day 05 termine : tous les exercices compilent et se lancent." -ForegroundColor Green
