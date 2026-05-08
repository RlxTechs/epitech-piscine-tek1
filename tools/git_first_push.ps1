param(
    [string]$RepoUrl = "https://github.com/RlxTechs/epitech-piscine-tek1.git"
)

Write-Host "=== Configuration GitHub remote ===" -ForegroundColor Cyan

$root = Split-Path -Parent $PSScriptRoot
Set-Location $root

if (!(Test-Path ".git")) {
    git init
    git branch -M main
}

$remotes = git remote

if ($remotes -contains "origin") {
    git remote set-url origin $RepoUrl
} else {
    git remote add origin $RepoUrl
}

git remote -v
git push -u origin main
