Write-Host "Ouverture du dossier docs..." -ForegroundColor Cyan
$root = Split-Path -Parent $PSScriptRoot
Start-Process (Join-Path $root "docs")
