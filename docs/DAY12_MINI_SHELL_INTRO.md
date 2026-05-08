# Jour 12 - Mini shell intro

## Objectif

Ce jour introduit un mini shell en C.

Un shell est un programme qui lit une commande, l analyse, puis execute une action.

Dans cette version simple, on apprend :

- lire une ligne avec fgets
- supprimer le retour a la ligne
- comparer des strings
- detecter des commandes internes
- implementer help
- implementer echo
- implementer pwd
- implementer cd
- implementer clear
- implementer exit
- executer une commande externe simple avec system

## Pourquoi c est important ?

Le mini shell prépare plusieurs notions TEK1 :

- parsing
- boucles infinies controlees
- gestion d etat
- commandes internes
- organisation multi-fichiers
- headers
- Makefile
- tests automatiques

## Difference avec un vrai minishell

Un vrai minishell utilise souvent fork, execve, env, pipes, redirections et signaux.

Ici, on fait une version pédagogique compatible Windows/MSYS2.

On utilise system() pour les commandes externes simples.

## Commandes supportees

help : affiche l aide
echo texte : affiche le texte
pwd : affiche le dossier actuel
cd chemin : change de dossier
clear : nettoie l ecran
exit : quitte le shell

## Commande de test

powershell -ExecutionPolicy Bypass -File .\tools\check_day12.ps1
