Write-Host "=== Configuration du PATH GCC MSYS2 ===" -ForegroundColor Cyan

$gccPath = "C:\msys64\ucrt64\bin"

if (!(Test-Path $gccPath)) {
    Write-Host "Chemin introuvable : $gccPath" -ForegroundColor Red
    Write-Host "Installe MSYS2 avant de lancer ce script." -ForegroundColor Yellow
    exit 1
}

$currentPath = [Environment]::GetEnvironmentVariable("Path", "User")

if ($currentPath -like "*$gccPath*") {
    Write-Host "GCC est deja dans le PATH utilisateur." -ForegroundColor Green
} else {
    [Environment]::SetEnvironmentVariable("Path", "$currentPath;$gccPath", "User")
    Write-Host "Chemin ajoute : $gccPath" -ForegroundColor Green
    Write-Host "Ferme puis rouvre PowerShell." -ForegroundColor Yellow
}

Write-Host "Test a lancer ensuite : gcc --version" -ForegroundColor Cyan
