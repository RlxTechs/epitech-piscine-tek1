# Jour 03 - Pointeurs et tableaux

## Objectif

Ce jour est tres important pour progresser en C.

Tu vas apprendre :

- comprendre les adresses memoire
- utiliser un pointeur
- modifier une variable depuis une fonction
- echanger deux variables avec des pointeurs
- parcourir un tableau
- calculer une somme
- trouver le minimum et le maximum
- inverser un tableau
- trier un tableau

## Notion importante : adresse

En C, chaque variable est stockee quelque part en memoire.

Pour obtenir son adresse, on utilise :

&variable

## Notion importante : pointeur

Un pointeur est une variable qui contient une adresse.

Exemple :

int number = 42;
int *ptr = &number;

Pour lire la valeur pointee :

*ptr

Pour modifier la variable pointee :

*ptr = 100;

## Notion importante : tableau

Un tableau contient plusieurs valeurs du meme type.

Exemple :

int numbers[] = {5, 2, 9, 1};

La premiere valeur est :

numbers[0]

## Exercices

### ex00_address.c
Afficher une valeur, son adresse et la valeur via pointeur.

### ex01_set_value.c
Modifier une variable depuis une fonction avec un pointeur.

### ex02_swap.c
Echanger deux variables avec des pointeurs.

### ex03_print_array.c
Afficher toutes les valeurs d un tableau.

### ex04_array_sum.c
Calculer la somme d un tableau.

### ex05_min_max.c
Trouver le minimum et le maximum d un tableau.

### ex06_reverse_array.c
Inverser un tableau.

### ex07_sort_array.c
Trier un tableau par ordre croissant.

## Commande de test

powershell -ExecutionPolicy Bypass -File .\tools\check_day03.ps1
