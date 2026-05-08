$ErrorActionPreference = "Stop"

Write-Host "=== Test automatique - Day 07 Malloc and Structs ===" -ForegroundColor Cyan

$root = Split-Path -Parent $PSScriptRoot
$folder = Join-Path $root "days\day07_malloc_structs"
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
    ".\ex00_malloc_int.exe",
    ".\ex01_malloc_array.exe",
    ".\ex02_my_strdup.exe",
    ".\ex03_join_strings.exe",
    ".\ex04_split_words.exe",
    ".\ex05_struct_student.exe",
    ".\ex06_linked_list.exe",
    ".\ex07_memory_rules.exe"
)

foreach ($program in $programs) {
    Write-Host ""
    Write-Host "Execution : $program" -ForegroundColor Cyan
    & $program
}

Write-Host ""
Write-Host "Day 07 termine : tous les exercices compilent et se lancent." -ForegroundColor Green
