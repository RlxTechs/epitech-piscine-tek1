Write-Host "=== Compilation avec Makefile ===" -ForegroundColor Cyan

$root = Split-Path -Parent $PSScriptRoot
$folder = Join-Path $root "00_start_here"
Set-Location $folder

if (!(Test-Path "Makefile")) {
    Write-Host "Aucun Makefile trouve dans 00_start_here." -ForegroundColor Red
    exit 1
}

Write-Host "Nettoyage..." -ForegroundColor Yellow
make fclean

Write-Host "Compilation..." -ForegroundColor Yellow
make

if ($LASTEXITCODE -ne 0) {
    Write-Host "Erreur pendant make." -ForegroundColor Red
    exit 1
}

Write-Host "Compilation reussie avec make." -ForegroundColor Green

if (Test-Path ".\hello.exe") {
    .\hello.exe
} elseif (Test-Path ".\hello") {
    .\hello
}
