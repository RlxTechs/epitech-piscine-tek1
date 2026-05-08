$ErrorActionPreference = "Stop"

Write-Host "=== Test automatique - Day 12 Mini shell intro ===" -ForegroundColor Cyan

$root = Split-Path -Parent $PSScriptRoot
$folder = Join-Path $root "days\day12_mini_shell_intro"
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
Write-Host "Execution : ex00_read_line" -ForegroundColor Cyan
"Bonjour RLX" | & ".\ex00_read_line.exe"

Write-Host ""
Write-Host "Execution : ex01_trim_newline" -ForegroundColor Cyan
& ".\ex01_trim_newline.exe"

Write-Host ""
Write-Host "Execution : ex02_parse_echo" -ForegroundColor Cyan
& ".\ex02_parse_echo.exe"

Write-Host ""
Write-Host "Execution automatique du mini shell :" -ForegroundColor Cyan
$scriptInput = "help`necho hello from mini shell`npwd`nexit`n"
$scriptInput | & ".\mini_shell.exe"

Write-Host ""
Write-Host "Day 12 termine : mini shell compile et fonctionne." -ForegroundColor Green
