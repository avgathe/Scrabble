# Scrabble

## Auteurs :
  - Agathe VAUTIER
  - Solian HERRERA
  - Eric SORLUT
  - Luka TEXIER

## Description :
  Ce projet implémente un jeu de Scrabble en C, avec des fonctionnalités pour :
    - Créer et personnaliser un plateau de jeu
    - Gérer les tours de jeu
    - Vérifier les mots dans un dictionnaire

## Structure du projet :

├── .gitignore                  # Fichiers à exclure du suivi Git
├── .bin/                       # Dossier des fichiers binaires compilés
│   └── main.o                  # Fichier objet pour le programme principal
├── include/                    # Dossier des fichiers d'en-tête
│   ├── alphabet.h              # Gestion de l'alphabet du Scrabble
│   ├── gestionTourJeu.h        # Fonctions pour gérer les tours de jeu
│   ├── plateau.h               # Gestion du plateau de jeu
│   └── types.h                 # Déclarations de types partagés
├── src/                        # Dossier des fichiers sources
│   ├── alphabet.c              # Implémentation des fonctions liées à l'alphabet
│   ├── gestionTourJeu.c        # Implémentation des fonctions de gestion des tours
│   ├── main.c                  # Fichier principal du programme
│   ├── plateau.c               # Implémentation des fonctions liées au plateau
│   └── types.c                 # Définition des types et utilitaires
├── Makefile                    # Automatisation de la compilation
└── mot_scrabble_ods.txt        # Dictionnaire des mots valides au Scrabble
