# Module 05 - Grid Games

## Objectif

Ce module sert a apprendre les jeux sur grille.

Un jeu sur grille utilise des cases :

- mur
- sol
- joueur
- piece
- sortie

## Notions apprises

- representer une map avec un tableau 2D
- trouver le joueur dans une map
- compter les pieces
- bouger case par case
- bloquer le joueur contre les murs
- gerer le score
- detecter la victoire
- creer une demo automatique
- introduire un pathfinding BFS simple

## Symboles

# : mur
. : sol
P : joueur
* : piece
X : sortie

## Commandes

w : haut
s : bas
a : gauche
d : droite
q : quitter

## Pourquoi c est important ?

Beaucoup de jeux simples fonctionnent avec une grille :

- snake
- labyrinthe
- puzzle
- rogue-like
- mini pacman-like
- pathfinding

## Commande de test

powershell -ExecutionPolicy Bypass -File .\modules\module05_grid_games\check.ps1
