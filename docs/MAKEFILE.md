# Make et Makefile

## A quoi sert make ?

make sert a automatiser la compilation.

Au lieu de taper :

gcc -Wall -Wextra -Werror hello.c -o hello

on peut taper simplement :

make

## Pourquoi c est important ?

En C, surtout dans une logique piscine / TEK1, les projets sont souvent compiles avec des Makefile.

## Commandes classiques

make
make clean
make fclean
make re

## Attention tres importante

DANS UN MAKEFILE, LES COMMANDES DOIVENT COMMENCER PAR UNE VRAIE TABULATION.

Dans PowerShell, si on colle une tabulation directement, elle peut etre transformee en auto-completion.

Pour eviter ce probleme, dans nos scripts PowerShell, on utilise :

$tab = [char]9

Puis on genere les lignes de Makefile avec :

($tab + '$(CC) $(CFLAGS) $(SRC) -o $(NAME)')

## Script utile

Pour recreer automatiquement le Makefile du dossier 00_start_here :

powershell -ExecutionPolicy Bypass -File .\tools\create_makefile_start_here.ps1

Pour compiler avec make :

powershell -ExecutionPolicy Bypass -File .\tools\compile_with_make.ps1
