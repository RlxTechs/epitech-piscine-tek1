# Module 04 - Terminal Game Engine

## Objectif

Ce module pose les bases d un mini moteur de jeu terminal en C.

On ne fait pas encore un jeu graphique complexe.
On cree une base claire et testable pour comprendre :

- une boucle de jeu
- une grille ASCII
- un joueur
- un ennemi
- une piece a ramasser
- un score
- des vies
- des collisions
- une logique de mouvement
- une demo automatique
- des tests unitaires

## Commandes du jeu

w : monter
s : descendre
a : gauche
d : droite
q : quitter

## Symboles

# : mur
. : sol
P : joueur
E : ennemi
* : piece

## Pourquoi c est important ?

Un jeu, meme simple, force a organiser la logique :

- etat du jeu
- rendu
- input
- update
- collision
- score
- fin de partie

Ce module prepare les futurs jeux :

- snake
- labyrinthe
- rogue-like
- mini pacman
- jeux 2D web

## Commande de test

powershell -ExecutionPolicy Bypass -File .\modules\module04_terminal_game_engine\check.ps1
