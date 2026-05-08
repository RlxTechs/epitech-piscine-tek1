$ErrorActionPreference = "Stop"

Write-Host "=== Creation automatique du Makefile 00_start_here ===" -ForegroundColor Cyan

$root = Split-Path -Parent $PSScriptRoot
$target = Join-Path $root "00_start_here\Makefile"
$tab = [char]9

$content = @(
    'CC = gcc',
    'CFLAGS = -Wall -Wextra -Werror',
    'NAME = hello',
    'SRC = hello.c',
    '',
    'all: $(NAME)',
    '',
    '$(NAME): $(SRC)',
    ($tab + '$(CC) $(CFLAGS) $(SRC) -o $(NAME)'),
    '',
    'clean:',
    ($tab + 'rm -f $(NAME).exe'),
    ($tab + 'rm -f $(NAME)'),
    '',
    'fclean: clean',
    '',
    're: fclean all'
)

Set-Content -Path $target -Encoding ASCII -Value $content

Write-Host "Makefile corrige : $target" -ForegroundColor Green
