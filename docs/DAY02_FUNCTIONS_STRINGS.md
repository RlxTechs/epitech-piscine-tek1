# Jour 02 - Fonctions et strings

## Objectif

Le but de ce jour est de commencer a penser comme en piscine C :

- creer ses propres fonctions
- eviter de tout mettre dans main
- manipuler les chaines de caracteres
- comprendre les boucles sur les strings
- comprendre le caractere de fin de chaine \0
- utiliser les pointeurs de base avec char *
- compiler tous les exercices avec un Makefile

## Notion importante : string en C

En C, une string est un tableau de caracteres termine par le caractere special \0.

Exemple :

R l x T e c h s \0

Donc pour parcourir une chaine :

while (str[i] != '\0')

## Exercices

### ex00_my_putchar.c
Afficher un caractere avec write.

### ex01_my_putstr.c
Afficher une chaine caractere par caractere.

### ex02_my_strlen.c
Compter la longueur d une chaine.

### ex03_my_strcpy.c
Copier une chaine dans une autre.

### ex04_my_strcmp.c
Comparer deux chaines.

### ex05_my_str_isalpha.c
Verifier si une chaine contient seulement des lettres.

### ex06_my_strupcase.c
Transformer une chaine en majuscules.

### ex07_my_put_nbr.c
Afficher un nombre sans printf.

## Commande de test

powershell -ExecutionPolicy Bypass -File .\tools\check_day02.ps1
