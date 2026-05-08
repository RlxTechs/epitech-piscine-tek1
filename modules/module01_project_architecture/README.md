# Module 01 - Project Architecture

## Objectif

Apprendre a organiser un vrai projet C.

## Structure

include/ : headers
src/ : code source principal
tests/ : tests unitaires
main.c : entree du programme
Makefile : compilation
check.ps1 : test automatique du module

## Commandes

Compiler :

make

Lancer l app :

.\app_architecture.exe

Lancer les tests :

.\unit_tests.exe

Tester automatiquement :

powershell -ExecutionPolicy Bypass -File .\check.ps1
