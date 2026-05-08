# Module 08 - Collision Physics

## Objectif

Ce module ajoute une base physique simple pour jeux 2D.

Tu vas apprendre :

- position
- vitesse
- acceleration
- gravite
- mise a jour avec delta time
- collision rectangle/rectangle
- collision cercle/cercle
- collision point/rectangle
- rebond sur les limites du monde
- simulation automatique
- tests unitaires

## Pourquoi c est important ?

Les jeux 2D utilisent presque toujours une base physique :

- un joueur tombe avec la gravite
- une balle rebondit
- un personnage ne traverse pas un mur
- un projectile touche un ennemi
- une hitbox detecte une collision

## Concepts

Position : ou se trouve l objet.

Vitesse : dans quelle direction et a quelle vitesse il bouge.

Acceleration : ce qui modifie la vitesse, comme la gravite.

Delta time : temps ecoule entre deux frames.

## Commande de test

powershell -ExecutionPolicy Bypass -File .\modules\module08_collision_physics\check.ps1
