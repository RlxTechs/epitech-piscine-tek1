$ErrorActionPreference = "Stop"

Write-Host "=== Verification modules Python/Web 11-16 ===" -ForegroundColor Cyan

$root = Split-Path -Parent $PSScriptRoot
$modules = @(
    "module11_python_graphics_tkinter",
    "module12_python_pygame_arcade",
    "module13_web_canvas_games",
    "module14_python_desktop_tools",
    "module15_data_visualization_python",
    "module16_ai_tools_python"
)

foreach ($module in $modules) {
    $check = Join-Path $root "modules\$module\check.ps1"

    if (Test-Path $check) {
        Write-Host ""
        Write-Host "Lancement : $module" -ForegroundColor Yellow
        powershell -ExecutionPolicy Bypass -File $check
    } else {
        Write-Host "check.ps1 introuvable pour $module" -ForegroundColor Red
        exit 1
    }
}

Write-Host ""
Write-Host "Tous les modules Python/Web sont OK." -ForegroundColor Green

