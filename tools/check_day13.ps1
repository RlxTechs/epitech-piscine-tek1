$ErrorActionPreference = "Stop"

Write-Host "=== Test automatique - Day 13 Mini grep intro ===" -ForegroundColor Cyan

$root = Split-Path -Parent $PSScriptRoot
$folder = Join-Path $root "days\day13_mini_grep_intro"
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
Write-Host "Execution : ex00_contains" -ForegroundColor Cyan
& ".\ex00_contains.exe"

Write-Host ""
Write-Host "Execution : ex01_count_occurrences" -ForegroundColor Cyan
& ".\ex01_count_occurrences.exe"

Write-Host ""
Write-Host "Execution : ex02_print_matching_lines" -ForegroundColor Cyan
& ".\ex02_print_matching_lines.exe" "C" ".\inputs\sample.txt"

Write-Host ""
Write-Host "Execution : ex03_count_matching_lines" -ForegroundColor Cyan
& ".\ex03_count_matching_lines.exe" "C" ".\inputs\sample.txt"

Write-Host ""
Write-Host "Execution : ex04_line_numbers" -ForegroundColor Cyan
& ".\ex04_line_numbers.exe" "C" ".\inputs\sample.txt"

Write-Host ""
Write-Host "Execution : ex05_case_insensitive" -ForegroundColor Cyan
& ".\ex05_case_insensitive.exe"

Write-Host ""
Write-Host "Execution : ex06_mini_grep normal" -ForegroundColor Cyan
& ".\ex06_mini_grep.exe" "C" ".\inputs\sample.txt"

Write-Host ""
Write-Host "Execution : ex06_mini_grep -n" -ForegroundColor Cyan
& ".\ex06_mini_grep.exe" "-n" "C" ".\inputs\sample.txt"

Write-Host ""
Write-Host "Execution : ex06_mini_grep -i" -ForegroundColor Cyan
& ".\ex06_mini_grep.exe" "-i" "rlx" ".\inputs\sample.txt"

Write-Host ""
Write-Host "Execution : ex06_mini_grep -in" -ForegroundColor Cyan
& ".\ex06_mini_grep.exe" "-in" "rlx" ".\inputs\sample.txt"

Write-Host ""
Write-Host "Execution : ex07_multi_file_grep" -ForegroundColor Cyan
& ".\ex07_multi_file_grep.exe" "RLX" ".\inputs\sample.txt" ".\inputs\second.txt"

Write-Host ""
Write-Host "Day 13 termine : mini grep intro compile et fonctionne." -ForegroundColor Green
