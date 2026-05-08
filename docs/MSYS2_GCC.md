# MSYS2, GCC et environnement C sur Windows

## A quoi sert MSYS2 ?

MSYS2 sert a ajouter sur Windows un vrai environnement de developpement pour apprendre le C.

PowerShell permet de lancer des commandes et automatiser le projet, mais Windows ne fournit pas directement gcc.

Pour apprendre la piscine TEK1, on a besoin de plusieurs outils :

- gcc : compiler les fichiers C
- make : utiliser des Makefile
- gdb : debugger les programmes
- pacman : installer des outils dans MSYS2
- outils Unix : travailler comme dans un environnement proche Linux

## Ce que nous avons fait

1. Installation de MSYS2
2. Ajout du chemin C:\msys64\ucrt64\bin au PATH utilisateur Windows
3. Verification avec gcc --version
4. Compilation du premier programme C
5. Execution de hello.exe

## Commandes utilisees

Verifier gcc :

gcc --version

Compiler le premier programme :

cd $env:USERPROFILE\Desktop\MesProjets\epitech-piscine-tek1\00_start_here
gcc hello.c -o hello
.\hello.exe

## Resultat obtenu

Hello, Piscine TEK1!

## Pourquoi c est important ?

Ce projet doit former aux bases de la programmation C, donc le compilateur est indispensable.
Chaque exercice C devra pouvoir etre compile, teste, documente et sauvegarde avec Git.
