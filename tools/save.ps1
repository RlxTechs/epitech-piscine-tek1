param(
    [string]$Message = ""
)

Write-Host "=== Sauvegarde Git rapide ===" -ForegroundColor Cyan

$root = Split-Path -Parent $PSScriptRoot
Set-Location $root

if ([string]::IsNullOrWhiteSpace($Message)) {
    $Message = Read-Host "Message du commit"
}

if (!(Test-Path ".git")) {
    Write-Host "Ce dossier n est pas encore un repository Git." -ForegroundColor Red
    exit 1
}

git status
git add .

$changes = git status --porcelain

if ([string]::IsNullOrWhiteSpace(($changes -join ""))) {
    Write-Host "Aucune modification a commit." -ForegroundColor Yellow
} else {
    git commit -m "$Message"
}

$remotes = git remote

if ($remotes -contains "origin") {
    git push
} else {
    Write-Host "Aucun remote GitHub configure." -ForegroundColor Red
    Write-Host "Lance : .\tools\git_first_push.ps1" -ForegroundColor Yellow
}
