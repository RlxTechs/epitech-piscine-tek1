# Module 10 - Level Loader

## Objectif

Ce module sert a charger des niveaux de jeu depuis des fichiers texte.

Au lieu de coder la map directement dans le C, on peut maintenant creer des fichiers .txt modifiables.

## Exemple de niveau

##########
#P..*...X#
#..##....#
##########

## Symboles

# : mur
. : sol
P : joueur
* : piece
X : sortie

## Ce que le module verifie

- le fichier existe
- le niveau n est pas vide
- toutes les lignes ont la meme largeur
- il y a exactement un joueur P
- il y a exactement une sortie X
- il y a au moins une piece *
- les bords sont fermes par des murs #
- les symboles sont valides
- un chemin existe entre le joueur et la sortie

## Pourquoi c est important ?

Les vrais jeux utilisent souvent des niveaux externes.

Cela permet de modifier les maps sans recompiler le programme.

Ce module prepare :

- jeux de labyrinthe
- snake avec niveaux
- puzzle game
- rogue-like
- editeur de niveaux
- validation automatique de maps

## Commande de test

powershell -ExecutionPolicy Bypass -File .\modules\module10_level_loader\check.ps1
