# Upgrade automatisation

## Probleme avant

Avant, a chaque nouveau jour, il fallait modifier manuellement check_all_days.ps1.

Cela cree de la repetition.

## Solution maintenant

On ajoute un script dynamique :

tools/check_all_dynamic.ps1

Ce script trouve automatiquement tous les fichiers :

tools/check_day*.ps1

puis il lance aussi tous les modules qui ont un fichier :

modules/**/check.ps1

## Nouvelle commande principale

powershell -ExecutionPolicy Bypass -File .\tools\check_all_dynamic.ps1

## Nouvelle logique

- les days restent pour les bases
- les modules servent aux vrais projets structures
- les scripts globaux ne doivent plus etre reecrits a chaque fois
