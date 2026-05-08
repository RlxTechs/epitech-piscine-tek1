$ErrorActionPreference = "Stop"
Write-Host "=== Verification des outils Piscine TEK1 ===" -ForegroundColor Cyan

function Test-Tool {
    param([string]$Name, [string]$Command)

    Write-Host ""
    Write-Host "Verification de $Name..." -ForegroundColor Yellow

    try {
        Invoke-Expression $Command
        Write-Host "$Name : OK" -ForegroundColor Green
    } catch {
        Write-Host "$Name : NON TROUVE" -ForegroundColor Red
    }
}

Test-Tool "Git" "git --version"
Test-Tool "GCC" "gcc --version"
Test-Tool "Make" "make --version"
Test-Tool "Python" "python --version"

Write-Host ""
Write-Host "Verification terminee." -ForegroundColor Cyan
