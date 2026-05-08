$ErrorActionPreference = "Stop"
Write-Host "=== Installation de Make avec MSYS2 ===" -ForegroundColor Cyan

$bash = "C:\msys64\usr\bin\bash.exe"
$msysUsrPath = "C:\msys64\usr\bin"

if (!(Test-Path $bash)) {
    Write-Host "MSYS2 est introuvable. Installe MSYS2 avant de lancer ce script." -ForegroundColor Red
    exit 1
}

$env:MSYSTEM = "UCRT64"
& $bash -lc "pacman -S --needed --noconfirm make mingw-w64-ucrt-x86_64-make"

$currentPath = [Environment]::GetEnvironmentVariable("Path", "User")

if ($currentPath -notlike "*$msysUsrPath*") {
    [Environment]::SetEnvironmentVariable("Path", "$currentPath;$msysUsrPath", "User")
    Write-Host "Chemin ajoute au PATH utilisateur : $msysUsrPath" -ForegroundColor Green
    Write-Host "Ferme puis rouvre PowerShell avant de tester make." -ForegroundColor Yellow
} else {
    Write-Host "Le chemin MSYS2 usr/bin est deja dans le PATH." -ForegroundColor Green
}

Write-Host "Test a lancer ensuite : make --version" -ForegroundColor Cyan
