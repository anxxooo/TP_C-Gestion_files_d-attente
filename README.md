# Gestion et Simulation des Files d'Attente

## Description
Ce projet implémente un programme permettant de gérer et simuler des files d'attente. Le système inclut un centre avec plusieurs guichets/agents recevant et traitant les requêtes des clients, avec un guichet d'accueil pour la distribution initiale.

## Fonctionnalités
- Ajout de clients à la file d'attente via un guichet d'accueil.
- Réception et traitement des clients par les guichets.
- Redirection de clients d'un guichet à un autre.
- Affichage des files d'attente par guichet.
- Opérations avancées sur les files d'attente :
  - Redistribution équilibrée des clients.
  - Fusion et redirection de files d'attente.
  - Réinitialisation des numéros de tickets sans perturber l'ordre d'arrivée.

## Installation et Compilation
### Prérequis
- Un compilateur compatible avec le langage C.
- Un environnement de développement (Code::Blocks, GCC, Clang, etc.).

### Compilation
Placez tous les fichiers sources dans un même dossier et utilisez la commande :
```sh
gcc -o main.exe main.c TP_header.h 
```

### Exécution
Lancer l'exécutable généré :
```sh
./gestion_files
```

## Utilisation
### Menu principal
1. **Ajouter des clients**
   - Saisir le nom du client.
   - Choisir le guichet de destination.
2. **Réception des clients**
   - Sélectionner un guichet.
   - Afficher la file d'attente associée.
   - Traiter ou rediriger un client.
3. **Afficher toutes les files d'attente**
   - Voir la liste complète des clients et leur guichet attribué.
4. **Opérations avancées**
   - Redirection et fusion de files.
   - Rééquilibrage des guichets.
   - Réinitialisation des numéros de tickets.

## Dépendances
Aucune dépendance externe n'est requise. Le programme repose uniquement sur les bibliothèques standards.
