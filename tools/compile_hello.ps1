Write-Host "=== Compilation du premier programme C ===" -ForegroundColor Cyan

$root = Split-Path -Parent $PSScriptRoot
$folder = Join-Path $root "00_start_here"
$file = Join-Path $folder "hello.c"
$exe = Join-Path $folder "hello.exe"

if (!(Test-Path $file)) {
    Write-Host "Fichier introuvable : $file" -ForegroundColor Red
    exit 1
}

Write-Host "Compilation de hello.c..." -ForegroundColor Yellow
gcc $file -o $exe

if ($LASTEXITCODE -ne 0) {
    Write-Host "Erreur de compilation." -ForegroundColor Red
    exit 1
}

Write-Host "Compilation reussie." -ForegroundColor Green
Write-Host "Execution :" -ForegroundColor Cyan
& $exe
