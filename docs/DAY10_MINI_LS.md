# Jour 10 - Mini ls intro

## Objectif

Ce jour introduit un projet systeme simple : refaire une petite version de ls.

Le but est de comprendre comment un programme C peut lire le contenu d un dossier.

## Notions importantes

### opendir

Ouvre un dossier.

### readdir

Lit les elements d un dossier un par un.

### closedir

Ferme le dossier ouvert.

### stat

Permet de recuperer des informations sur un fichier ou un dossier.

## Exercices

### ex00_list_current.c
Lister le dossier courant.

### ex01_list_path.c
Lister un dossier donne en argument.

### ex02_count_entries.c
Compter les elements visibles d un dossier.

### ex03_show_hidden.c
Afficher aussi les fichiers caches.

### ex04_file_type.c
Afficher si chaque entree est un fichier ou un dossier.

### ex05_join_path.c
Construire un chemin complet dynamiquement.

### ex06_mini_ls.c
Mini ls avec option -a.

### ex07_recursive_preview.c
Premiere approche de parcours recursif.

## Pourquoi c est important ?

Ce jour prepare aux projets systeme :

- my_ls
- minishell
- gestion de fichiers
- exploration de dossiers
- outils terminal

## Commande de test

powershell -ExecutionPolicy Bypass -File .\tools\check_day10.ps1
