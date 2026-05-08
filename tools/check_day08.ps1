$ErrorActionPreference = "Stop"

Write-Host "=== Test automatique - Day 08 Files IO ===" -ForegroundColor Cyan

$root = Split-Path -Parent $PSScriptRoot
$folder = Join-Path $root "days\day08_files_io"
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
Write-Host "Execution : ex00_cat_file" -ForegroundColor Cyan
& ".\ex00_cat_file.exe" ".\inputs\sample.txt"

Write-Host ""
Write-Host "Execution : ex01_file_size" -ForegroundColor Cyan
& ".\ex01_file_size.exe" ".\inputs\sample.txt"

Write-Host ""
Write-Host "Execution : ex02_count_lines" -ForegroundColor Cyan
& ".\ex02_count_lines.exe" ".\inputs\sample.txt"

Write-Host ""
Write-Host "Execution : ex03_count_words" -ForegroundColor Cyan
& ".\ex03_count_words.exe" ".\inputs\sample.txt"

Write-Host ""
Write-Host "Execution : ex04_wc_simple" -ForegroundColor Cyan
& ".\ex04_wc_simple.exe" ".\inputs\sample.txt"

Write-Host ""
Write-Host "Execution : ex05_copy_file" -ForegroundColor Cyan
& ".\ex05_copy_file.exe" ".\inputs\sample.txt" ".\inputs\copy_sample.txt"

Write-Host ""
Write-Host "Verification copie :" -ForegroundColor Cyan
& ".\ex01_file_size.exe" ".\inputs\copy_sample.txt"

Write-Host ""
Write-Host "Execution : ex06_append_log" -ForegroundColor Cyan
& ".\ex06_append_log.exe" ".\inputs\log.txt" "Day08 first log line"
& ".\ex06_append_log.exe" ".\inputs\log.txt" "Day08 second log line"
& ".\ex00_cat_file.exe" ".\inputs\log.txt"

Write-Host ""
Write-Host "Execution : ex07_read_config" -ForegroundColor Cyan
& ".\ex07_read_config.exe" ".\inputs\config.txt" "name"
& ".\ex07_read_config.exe" ".\inputs\config.txt" "project"

Write-Host ""
Write-Host "Day 08 termine : tous les exercices compilent et se lancent." -ForegroundColor Green
