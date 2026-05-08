$ErrorActionPreference = "Stop"

Write-Host "=== Test automatique - Day 02 Functions and Strings ===" -ForegroundColor Cyan

$root = Split-Path -Parent $PSScriptRoot
$folder = Join-Path $root "days\day02_functions_strings"
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
    ".\ex00_my_putchar.exe",
    ".\ex01_my_putstr.exe",
    ".\ex02_my_strlen.exe",
    ".\ex03_my_strcpy.exe",
    ".\ex04_my_strcmp.exe",
    ".\ex05_my_str_isalpha.exe",
    ".\ex06_my_strupcase.exe",
    ".\ex07_my_put_nbr.exe"
)

foreach ($program in $programs) {
    Write-Host ""
    Write-Host "Execution : $program" -ForegroundColor Cyan
    & $program
}

Write-Host ""
Write-Host "Day 02 termine : tous les exercices compilent et se lancent." -ForegroundColor Green
