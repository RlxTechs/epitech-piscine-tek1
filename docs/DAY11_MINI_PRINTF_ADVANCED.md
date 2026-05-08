# Jour 11 - Mini printf avance

## Objectif

Ce jour améliore le mini_printf du Day 09.

On ajoute les bases numériques :

- %u : entier non signe en base 10
- %x : hexadecimal minuscule
- %X : hexadecimal majuscule
- %o : octal
- %b : binaire

On garde aussi :

- %c
- %s
- %d
- %i
- %%

## Pourquoi c est important ?

mini_printf est un vrai exercice de parsing.

Il oblige a comprendre :

- les arguments variables avec stdarg
- les conversions de types
- les bases numériques
- la récursion
- les headers
- les fichiers sources séparés
- le comptage du nombre de caractères affichés

## Principe des bases

Un nombre peut être affiché en plusieurs bases.

Base 10 : 255
Base 16 : ff
Base 8 : 377
Base 2 : 11111111

## Structure

days/day11_mini_printf_advanced/
  include/
    my_printf.h
  src/
    my_putchar.c
    my_putstr.c
    my_put_nbr.c
    my_put_unsigned_base.c
    my_printf.c
  main.c
  Makefile

## Commande de test

powershell -ExecutionPolicy Bypass -File .\tools\check_day11.ps1
