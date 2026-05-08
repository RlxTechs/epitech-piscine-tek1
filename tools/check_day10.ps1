$ErrorActionPreference = "Stop"

Write-Host "=== Test automatique - Day 10 Mini ls intro ===" -ForegroundColor Cyan

$root = Split-Path -Parent $PSScriptRoot
$folder = Join-Path $root "days\day10_mini_ls_intro"
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
Write-Host "Execution : ex00_list_current" -ForegroundColor Cyan
& ".\ex00_list_current.exe"

Write-Host ""
Write-Host "Execution : ex01_list_path" -ForegroundColor Cyan
& ".\ex01_list_path.exe" ".\inputs\sample_dir"

Write-Host ""
Write-Host "Execution : ex02_count_entries" -ForegroundColor Cyan
& ".\ex02_count_entries.exe" ".\inputs\sample_dir"

Write-Host ""
Write-Host "Execution : ex03_show_hidden" -ForegroundColor Cyan
& ".\ex03_show_hidden.exe" ".\inputs\sample_dir"

Write-Host ""
Write-Host "Execution : ex04_file_type" -ForegroundColor Cyan
& ".\ex04_file_type.exe" ".\inputs\sample_dir"

Write-Host ""
Write-Host "Execution : ex05_join_path" -ForegroundColor Cyan
& ".\ex05_join_path.exe"

Write-Host ""
Write-Host "Execution : ex06_mini_ls normal" -ForegroundColor Cyan
& ".\ex06_mini_ls.exe" ".\inputs\sample_dir"

Write-Host ""
Write-Host "Execution : ex06_mini_ls -a" -ForegroundColor Cyan
& ".\ex06_mini_ls.exe" "-a" ".\inputs\sample_dir"

Write-Host ""
Write-Host "Execution : ex07_recursive_preview" -ForegroundColor Cyan
& ".\ex07_recursive_preview.exe" ".\inputs\sample_dir"

Write-Host ""
Write-Host "Day 10 termine : tous les exercices compilent et se lancent." -ForegroundColor Green
