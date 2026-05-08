$ErrorActionPreference = "Stop"

Write-Host "=== Test automatique - Day 01 C Basics ===" -ForegroundColor Cyan

$root = Split-Path -Parent $PSScriptRoot
$folder = Join-Path $root "days\day01_c_basics"
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
    ".\ex00_hello.exe",
    ".\ex01_putchar.exe",
    ".\ex02_print_alphabet.exe",
    ".\ex03_print_digits.exe",
    ".\ex04_is_negative.exe",
    ".\ex05_print_numbers.exe",
    ".\ex06_my_strlen.exe",
    ".\ex07_swap.exe"
)

foreach ($program in $programs) {
    Write-Host ""
    Write-Host "Execution : $program" -ForegroundColor Cyan
    & $program
}

Write-Host ""
Write-Host "Day 01 termine : tous les exercices compilent et se lancent." -ForegroundColor Green
