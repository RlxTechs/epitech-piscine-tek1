# Jour 04 - Introduction a Libmy

## Objectif

Le but de ce jour est de creer une premiere librairie personnelle en C.

Une librairie permet de ranger plusieurs fonctions reutilisables dans un seul fichier compile.

Dans ce jour, on va creer :

- un dossier include
- un fichier my.h
- un dossier src
- plusieurs fonctions C
- un fichier libmy.a
- un main.c qui utilise la librairie
- un Makefile complet
- un script de test automatique

## Structure

days/day04_libmy_intro/
  include/
    my.h
  src/
    my_putchar.c
    my_putstr.c
    my_strlen.c
    my_strcpy.c
    my_strcmp.c
    my_put_nbr.c
  main.c
  Makefile

## A quoi sert my.h ?

Le fichier my.h contient les prototypes des fonctions.

Exemple :

void my_putchar(char c);
int my_strlen(char *str);

Cela permet aux autres fichiers de connaitre les fonctions disponibles.

## A quoi sert libmy.a ?

libmy.a est une librairie statique.

Elle contient plusieurs fichiers .o regroupes ensemble.

Commande importante :

ar rc libmy.a fichier1.o fichier2.o

## Commandes utiles

Compiler :

make

Nettoyer les .o :

make clean

Tout nettoyer :

make fclean

Recompiler proprement :

make re

Tester automatiquement :

powershell -ExecutionPolicy Bypass -File .\tools\check_day04.ps1
