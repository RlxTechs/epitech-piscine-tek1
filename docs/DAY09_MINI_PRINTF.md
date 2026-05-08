# Jour 09 - Mini printf intro

## Objectif

Ce jour introduit un vrai mini-projet classique en C : recoder une version simple de printf.

Le but n est pas encore de refaire tout printf, mais de comprendre la logique :

- lire une chaine format
- detecter les pourcentages
- recuperer des arguments variables
- afficher differents types
- retourner le nombre de caracteres affiches
- organiser le code en plusieurs fichiers
- utiliser un header
- utiliser un Makefile propre

## Notion importante : stdarg

En C, stdarg permet de creer une fonction qui accepte un nombre variable d arguments.

Exemple :

int my_printf(const char *format, ...)

Les outils principaux sont :

- va_list
- va_start
- va_arg
- va_end

## Formats geres dans ce jour

### %c
Afficher un caractere.

### %s
Afficher une chaine.

### %d
Afficher un entier signe.

### %i
Afficher un entier signe.

### %% 
Afficher le caractere pourcentage.

## Structure du projet

days/day09_mini_printf_intro/
  include/
    my_printf.h
  src/
    my_putchar.c
    my_putstr.c
    my_put_nbr.c
    my_printf.c
  main.c
  Makefile

## Commande de test

powershell -ExecutionPolicy Bypass -File .\tools\check_day09.ps1

## Pourquoi c est important ?

mini_printf force a comprendre :

- les strings
- les pointeurs
- les fonctions
- les arguments variables
- le parsing
- l organisation multi-fichiers
- la compilation propre
