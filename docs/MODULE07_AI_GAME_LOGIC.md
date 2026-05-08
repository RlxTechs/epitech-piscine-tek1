# Module 07 - AI Game Logic

## Objectif

Ce module introduit une IA simple pour les jeux.

Le but est de comprendre comment un ennemi peut prendre une decision selon la position du joueur.

## Notions apprises

- distance Manhattan
- direction vers une cible
- poursuite du joueur
- fuite du joueur
- patrouille
- comportement aleatoire controle
- decision selon un etat
- IA testable avec unit tests

## Comportements IA

### CHASE
L ennemi avance vers le joueur.

### FLEE
L ennemi s eloigne du joueur.

### PATROL
L ennemi suit une direction de patrouille.

### RANDOM
L ennemi choisit une direction pseudo-aleatoire.

## Pourquoi c est important ?

Les jeux avec bots utilisent souvent des decisions simples :

- si le joueur est proche, attaquer
- si la vie est faible, fuir
- si rien ne se passe, patrouiller
- si un mur bloque, choisir une autre direction

## Commande de test

powershell -ExecutionPolicy Bypass -File .\modules\module07_ai_game_logic\check.ps1
