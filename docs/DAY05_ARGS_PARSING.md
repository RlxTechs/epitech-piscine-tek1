# Jour 05 - Arguments et parsing

## Objectif

Ce jour sert a comprendre comment un programme C peut recevoir des informations depuis le terminal.

Exemple :

.\programme.exe 10 + 5

Ici, le programme recoit plusieurs arguments :

- programme.exe
- 10
- +
- 5

## Notions importantes

### argc

argc contient le nombre d arguments recus par le programme.

### argv

argv est un tableau de chaines de caracteres.

argv[0] contient le nom du programme.
argv[1] contient le premier vrai argument.
argv[2] contient le deuxieme vrai argument.

## Exercices

### ex00_show_args.c
Afficher tous les arguments recus.

### ex01_my_atoi.c
Transformer une string en int.

### ex02_is_number.c
Verifier si une string represente un nombre valide.

### ex03_sum_args.c
Additionner tous les nombres passes en arguments.

### ex04_max_arg.c
Trouver le plus grand nombre passe en argument.

### ex05_count_words.c
Compter les mots dans une phrase.

### ex06_split_preview.c
Afficher les mots d une phrase un par un.

### ex07_calculator_args.c
Creer une mini calculatrice terminal.

## Commande de test

powershell -ExecutionPolicy Bypass -File .\tools\check_day05.ps1

## Pourquoi c est important ?

Les arguments et le parsing sont essentiels pour les futurs projets :

- mini_printf
- my_ls
- minishell
- convertisseurs
- outils terminal
- programmes automatises
