$ErrorActionPreference = "Stop"

Write-Host "=== Module 09 - Game Project Runner ===" -ForegroundColor Cyan

$moduleRoot = Split-Path -Parent $MyInvocation.MyCommand.Path
$repoRoot = Resolve-Path (Join-Path $moduleRoot "..\..")

$dependencies = @(
    "modules\module04_terminal_game_engine",
    "modules\module05_grid_games",
    "modules\module06_snake_terminal",
    "modules\module07_ai_game_logic",
    "modules\module08_collision_physics"
)

Write-Host ""
Write-Host "Compilation des modules dependants..." -ForegroundColor Cyan
foreach ($dep in $dependencies) {
    $path = Join-Path $repoRoot $dep
    if (Test-Path $path) {
        Write-Host "Build dependency: $dep" -ForegroundColor Yellow
        Push-Location $path
        make
        if ($LASTEXITCODE -ne 0) {
            Pop-Location
            Write-Host "Erreur compilation dependance : $dep" -ForegroundColor Red
            exit 1
        }
        Pop-Location
    } else {
        Write-Host "Dependance introuvable : $dep" -ForegroundColor Red
        exit 1
    }
}

Set-Location $moduleRoot

Write-Host ""
Write-Host "Nettoyage module09..." -ForegroundColor Yellow
make fclean

Write-Host "Compilation module09..." -ForegroundColor Yellow
make

if ($LASTEXITCODE -ne 0) {
    Write-Host "Erreur compilation module09." -ForegroundColor Red
    exit 1
}

Write-Host ""
Write-Host "Tests unitaires..." -ForegroundColor Cyan
& ".\unit_tests.exe"

if ($LASTEXITCODE -ne 0) {
    Write-Host "Tests unitaires echoues." -ForegroundColor Red
    exit 1
}

Write-Host ""
Write-Host "Liste des modules..." -ForegroundColor Cyan
& ".\game_runner.exe" "--list"

Write-Host ""
Write-Host "Demo rapide avec AI Game Logic..." -ForegroundColor Cyan
& ".\game_runner.exe" "--run" "4"

Write-Host ""
Write-Host "Module 09 termine avec succes." -ForegroundColor Green
