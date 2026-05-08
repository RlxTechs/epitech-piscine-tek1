# Jour 13 - Mini grep intro

## Objectif

Ce jour introduit un nouvel outil terminal : mini_grep.

grep sert a chercher du texte dans un fichier.

Dans cette version pedagogique, on apprend :

- lire un fichier ligne par ligne
- chercher un mot dans une string
- compter les lignes qui correspondent
- afficher les lignes qui contiennent un motif
- afficher les numeros de ligne
- ignorer la difference majuscule/minuscule
- gerer plusieurs fichiers
- organiser le projet avec Makefile

## Commandes supportees

./mini_grep pattern file
./mini_grep -n pattern file
./mini_grep -i pattern file
./mini_grep -in pattern file

## Pourquoi c est important ?

mini_grep combine plusieurs notions deja vues :

- arguments argc argv
- strings
- fichiers
- parsing simple
- conditions
- fonctions
- Makefile

## Commande de test

powershell -ExecutionPolicy Bypass -File .\tools\check_day13.ps1
