# Module 06 - Snake Terminal

## Objectif

Ce module transforme la logique de grille en vrai mini-jeu Snake dans le terminal.

## Notions apprises

- gérer un tableau de positions
- représenter le corps du serpent
- gérer une direction
- empêcher le demi-tour direct
- générer une nourriture
- faire grandir le serpent
- gérer le score
- détecter collision mur
- détecter collision corps
- créer une démo automatique
- tester automatiquement la logique du jeu

## Symboles

# : mur
. : sol
O : tête du serpent
o : corps du serpent
* : nourriture

## Commandes

w : haut
s : bas
a : gauche
d : droite
q : quitter

## Commande de test

powershell -ExecutionPolicy Bypass -File .\modules\module06_snake_terminal\check.ps1
