# Module 17 - Local JSON API

## Objectif

Créer une mini API locale en Python, sans dépendance externe.

Ce module prépare les futurs projets :

- ERP local
- dashboard admin
- boutique avec produits
- gestion de stock
- système de commandes
- app desktop connectée à une base JSON
- site web connecté à une API locale

## Pourquoi JSON ?

JSON est simple, lisible et pratique pour apprendre.

Exemple :

{
  "products": [],
  "orders": []
}

## Routes prévues

GET /health

GET /products

POST /products

GET /orders

POST /orders

## Commandes

Tester :

powershell -ExecutionPolicy Bypass -File .\modules\module17_local_json_api\check.ps1

Lancer la démo :

python .\modules\module17_local_json_api\app.py --demo

Lancer le serveur :

python .\modules\module17_local_json_api\app.py --serve

Ensuite ouvrir :

http://localhost:8080/health
