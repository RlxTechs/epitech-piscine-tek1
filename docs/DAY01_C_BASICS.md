# Jour 01 - Bases du langage C

## Objectif

Le but de ce jour est de comprendre les bases du C :

- compiler un fichier C
- afficher du texte
- afficher un caractere
- utiliser une boucle
- utiliser une condition
- creer une fonction
- comprendre les bases des pointeurs
- compiler plusieurs exercices avec un Makefile

## Exercices du jour

### ex00_hello.c
Afficher un message simple.

### ex01_putchar.c
Creer une fonction my_putchar qui affiche un caractere.

### ex02_print_alphabet.c
Afficher alphabet de a a z avec une boucle.

### ex03_print_digits.c
Afficher les chiffres de 0 a 9.

### ex04_is_negative.c
Afficher N si le nombre est negatif, sinon P.

### ex05_print_numbers.c
Afficher les nombres de 0 a une limite donnee.

### ex06_my_strlen.c
Recreer une fonction qui compte la longueur d une chaine.

### ex07_swap.c
Echanger deux variables avec des pointeurs.

## Commandes

Aller dans le dossier :

cd $env:USERPROFILE\Desktop\MesProjets\epitech-piscine-tek1\days\day01_c_basics

Compiler avec make :

make

Nettoyer :

make clean

Recompiler proprement :

make re

Tester automatiquement :

powershell -ExecutionPolicy Bypass -File .\tools\check_day01.ps1
