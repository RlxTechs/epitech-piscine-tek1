$ErrorActionPreference = "Stop"

Write-Host "=== Test automatique - Day 06 Algorithms and Recursion ===" -ForegroundColor Cyan

$root = Split-Path -Parent $PSScriptRoot
$folder = Join-Path $root "days\day06_algorithms_recursion"
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
    ".\ex00_factorial_iterative.exe",
    ".\ex01_factorial_recursive.exe",
    ".\ex02_fibonacci.exe",
    ".\ex03_power.exe",
    ".\ex04_is_prime.exe",
    ".\ex05_gcd.exe",
    ".\ex06_binary_search.exe",
    ".\ex07_palindrome.exe"
)

foreach ($program in $programs) {
    Write-Host ""
    Write-Host "Execution : $program" -ForegroundColor Cyan
    & $program
}

Write-Host ""
Write-Host "Day 06 termine : tous les exercices compilent et se lancent." -ForegroundColor Green
