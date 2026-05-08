# Jour 14 - Tests automatiques et debug en C

## Objectif

Ce jour sert a apprendre une competence tres importante : tester son code.

Jusqu ici, on compilait et on lancait les programmes.

Maintenant, on va verifier automatiquement que les fonctions donnent les bons resultats.

## Pourquoi c est important ?

Quand un projet devient grand, tu ne peux pas tout tester a la main.

Les tests permettent de verifier rapidement :

- si une fonction marche
- si une modification casse quelque chose
- si les cas particuliers sont geres
- si le projet reste stable

## Ce que tu vas creer

- un mini framework de test en C
- des fonctions a tester
- des fichiers de tests
- un executable unit_tests
- un Makefile
- un script PowerShell automatique

## Fonctions testees

- my_strlen
- my_strcmp
- my_atoi
- my_is_number
- array_sum

## Principe

Un test compare un resultat attendu avec un resultat obtenu.

Exemple :

expected = 8
actual = my_strlen("RlxTechs")

Si expected == actual, le test passe.

Sinon, le test echoue.

## Commande de test

powershell -ExecutionPolicy Bypass -File .\tools\check_day14.ps1
