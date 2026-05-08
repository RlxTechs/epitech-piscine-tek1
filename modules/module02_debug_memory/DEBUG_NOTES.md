# Notes debug memoire

## Erreurs courantes en C

### 1. Utiliser un pointeur NULL

Erreur : utiliser un pointeur sans verifier s il est NULL.

Bonne pratique :

if (ptr == NULL) {
    return 1;
}

### 2. Oublier free

Chaque malloc doit etre libere.

### 3. Double free

Ne jamais faire free deux fois sur le meme pointeur.

Dans ce module, on utilise SAFE_FREE(ptr), qui met ptr a NULL apres free.

### 4. Utiliser apres free

Apres free, le contenu n est plus utilisable.

### 5. Depasser un tableau

Si un tableau a 5 cases, les index valides sont 0, 1, 2, 3, 4.

## Methode de debug simple

1. Reproduire l erreur
2. Lire le message exact
3. Ajouter des printf de trace
4. Verifier les pointeurs
5. Verifier les tailles
6. Verifier les malloc/free
7. Ecrire un test qui prouve la correction
