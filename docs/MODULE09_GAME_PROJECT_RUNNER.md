# Module 09 - Game Project Runner

## Objectif

Ce module crée un launcher terminal pour centraliser les modules jeux.

Au lieu d aller dans chaque dossier manuellement, on peut lancer les démos depuis une seule interface.

## Modules lancés

- module04_terminal_game_engine
- module05_grid_games
- module06_snake_terminal
- module07_ai_game_logic
- module08_collision_physics

## Commandes

Lister les modules :

.\game_runner.exe --list

Lancer un module :

.\game_runner.exe --run 3

Lancer toutes les démos :

.\game_runner.exe --demo

Lancer le menu interactif :

.\game_runner.exe

## Pourquoi c est important ?

Ce module apprend à créer un outil de gestion de projets.

On commence à penser comme un développeur qui organise plusieurs projets dans un même workspace.

## Commande de test

powershell -ExecutionPolicy Bypass -File .\modules\module09_game_project_runner\check.ps1
