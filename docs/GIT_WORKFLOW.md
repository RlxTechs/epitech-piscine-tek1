# Workflow Git et GitHub

## Role de Git

Git garde l historique du projet sur le PC.
Chaque commit est une sauvegarde propre avec un message.

## Role de GitHub

GitHub sauvegarde le projet en ligne.
Il permet de montrer le travail, partager le code et suivre la progression.

## Commandes de base

Voir l etat du projet :

git status

Ajouter les fichiers modifies :

git add .

Creer une sauvegarde locale :

git commit -m "Message clair"

Envoyer sur GitHub :

git push

## Premiere connexion a GitHub

Le remote correct du projet est :

https://github.com/RlxTechs/epitech-piscine-tek1.git

Commande utilisee pour corriger le remote :

git remote set-url origin https://github.com/RlxTechs/epitech-piscine-tek1.git
git push -u origin main

## Methode officielle du projet

A chaque nouvelle etape :

1. Coder
2. Tester
3. Documenter
4. Commit
5. Push

Commande rapide recommandee :

.\tools\save.ps1 "Message clair du commit"
