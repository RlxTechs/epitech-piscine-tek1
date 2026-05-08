# Automatisation PowerShell

## Objectif

Chaque action importante doit avoir un script PowerShell.

Cela permet de refaire rapidement les memes etapes sans tout retaper.

## Scripts crees

### check_tools.ps1

Verifie si Git, GCC, Make et Python sont disponibles.

### setup_gcc_path.ps1

Ajoute C:\msys64\ucrt64\bin au PATH utilisateur Windows.

### compile_hello.ps1

Compile et lance le premier programme C.

### git_first_push.ps1

Configure le remote GitHub et pousse la branche main.

### save.ps1

Ajoute les fichiers, commit et push automatiquement.

## Comment lancer un script

Depuis PowerShell :

.\tools\check_tools.ps1

Si PowerShell bloque :

powershell -ExecutionPolicy Bypass -File .\tools\check_tools.ps1
