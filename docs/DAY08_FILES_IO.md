# Jour 08 - Fichiers et entrees/sorties

## Objectif

Ce jour sert a comprendre comment un programme C peut lire et ecrire dans des fichiers.

Tu vas apprendre :

- ouvrir un fichier
- lire un fichier caractere par caractere
- compter les caracteres
- compter les lignes
- compter les mots
- copier un fichier
- ecrire dans un fichier
- ajouter du texte a la fin d un fichier
- lire une configuration simple

## Pourquoi c est important ?

Les fichiers sont essentiels pour les vrais projets :

- logs
- configurations
- sauvegardes
- outils terminal
- mini cat
- mini wc
- analyseurs de texte
- gestionnaires de donnees

## Fonctions utilisees

fopen : ouvrir un fichier
fclose : fermer un fichier
fgetc : lire un caractere
fputc : ecrire un caractere
fputs : ecrire une chaine
fgets : lire une ligne

## Regle importante

Chaque fichier ouvert avec fopen doit etre ferme avec fclose.

## Exercices

### ex00_cat_file.c
Afficher le contenu d un fichier.

### ex01_file_size.c
Compter le nombre de caracteres d un fichier.

### ex02_count_lines.c
Compter le nombre de lignes.

### ex03_count_words.c
Compter les mots.

### ex04_wc_simple.c
Afficher lignes, mots et caracteres.

### ex05_copy_file.c
Copier un fichier vers un autre.

### ex06_append_log.c
Ajouter une ligne dans un fichier log.

### ex07_read_config.c
Lire une configuration simple cle=valeur.

## Commande de test

powershell -ExecutionPolicy Bypass -File .\tools\check_day08.ps1
