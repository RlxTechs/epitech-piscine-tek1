# Jour 07 - Malloc, memoire dynamique et structs

## Objectif

Ce jour introduit un gros morceau du C : la memoire dynamique.

Jusqu ici, beaucoup de variables etaient creees automatiquement.

Avec malloc, tu demandes toi-meme de la memoire au systeme.

## Notions importantes

### malloc

malloc reserve de la memoire.

Exemple :

int *number = malloc(sizeof(int));

### free

free libere la memoire reservee avec malloc.

Exemple :

free(number);

### NULL

Si malloc echoue, il retourne NULL.

Il faut donc toujours verifier :

if (ptr == NULL)

### struct

Une struct permet de creer un type compose.

Exemple :

struct student {
    char *name;
    int age;
};

## Exercices

### ex00_malloc_int.c
Allouer un int avec malloc.

### ex01_malloc_array.c
Allouer un tableau d entiers.

### ex02_my_strdup.c
Dupliquer une string avec malloc.

### ex03_join_strings.c
Joindre deux strings dans une nouvelle string dynamique.

### ex04_split_words.c
Decouper une phrase en mots avec malloc.

### ex05_struct_student.c
Creer une struct student dynamique.

### ex06_linked_list.c
Creer une mini liste chainee.

### ex07_memory_rules.c
Resumer les bonnes pratiques malloc/free.

## Regle importante

Chaque malloc doit avoir un free.

## Commande de test

powershell -ExecutionPolicy Bypass -File .\tools\check_day07.ps1
