# Module 02 - Debug et memoire

## Objectif

Ce module sert a comprendre les erreurs memoire en C et a coder plus proprement.

En C, beaucoup de bugs viennent de :

- malloc non verifie
- pointeur NULL utilise
- oubli de free
- double free
- utilisation apres free
- buffer trop petit
- string non terminee par \0
- tableau utilise hors limites

## Objectifs pratiques

Dans ce module, on cree :

- safe_malloc
- SAFE_FREE
- my_strlen_safe
- safe_strdup
- safe_join
- create_int_array
- fill_sequence
- array_sum
- debug_print_ptr
- des tests unitaires
- un Makefile propre
- un check.ps1 automatique

## Regle importante

Quand on utilise malloc, il faut toujours verifier si le retour est NULL.

Exemple :

char *text = malloc(100);
if (text == NULL) {
    return 1;
}

## Regle importante 2

Chaque malloc doit avoir un free.

## Regle importante 3

Apres free, on met le pointeur a NULL quand c est possible.

Dans ce module, on utilise :

SAFE_FREE(ptr);

Ce macro libere la memoire puis met le pointeur a NULL.

## Pourquoi ce module est important ?

Avant de faire des gros projets comme mini_printf, my_ls ou minishell, il faut apprendre a ne pas casser la memoire.

Un bon developpeur C ne fait pas seulement marcher le code.
Il evite aussi les crashs, les fuites memoire et les comportements dangereux.

## Commande de test

powershell -ExecutionPolicy Bypass -File .\modules\module02_debug_memory\check.ps1
