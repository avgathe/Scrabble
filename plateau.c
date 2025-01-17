#include <stdlib.h>
#include <stdio.h>
#include "types.h"
#include "plateau.h"

/*initialise un tableau de 15 sur 15 avec les cases spéciales au même endroit que pour le plateau de Crabble français*/
plateau_t* creerPlateauFr() {
    // Déclaration de la grille prédéfinie pour un plateau de Scrabble français
    const int grilleSpeciale[15][15] = {
        {5, 1, 1, 2, 1, 1, 1, 5, 1, 1, 1, 2, 1, 1, 5},
        {1, 4, 1, 1, 1, 3, 1, 1, 1, 3, 1, 1, 1, 4, 1},
        {1, 1, 4, 1, 1, 1, 2, 1, 2, 1, 1, 1, 4, 1, 1},
        {2, 1, 1, 4, 1, 1, 1, 2, 1, 1, 1, 4, 1, 1, 2},
        {1, 1, 1, 1, 4, 1, 1, 1, 1, 1, 4, 1, 1, 1, 1},
        {1, 3, 1, 1, 1, 3, 1, 1, 1, 3, 1, 1, 1, 3, 1},
        {1, 1, 2, 1, 1, 1, 2, 1, 2, 1, 1, 1, 2, 1, 1},
        {5, 1, 1, 2, 1, 1, 1, 4, 1, 1, 1, 2, 1, 1, 5},
        {1, 1, 2, 1, 1, 1, 2, 1, 2, 1, 1, 1, 2, 1, 1},
        {1, 3, 1, 1, 1, 3, 1, 1, 1, 3, 1, 1, 1, 3, 1},
        {1, 1, 1, 1, 4, 1, 1, 1, 1, 1, 4, 1, 1, 1, 1},
        {2, 1, 1, 4, 1, 1, 1, 2, 1, 1, 1, 4, 1, 1, 2},
        {1, 1, 4, 1, 1, 1, 2, 1, 2, 1, 1, 1, 4, 1, 1},
        {1, 4, 1, 1, 1, 3, 1, 1, 1, 3, 1, 1, 1, 4, 1},
        {5, 1, 1, 2, 1, 1, 1, 5, 1, 1, 1, 2, 1, 1, 5},
    };

    // Allocation du plateau
    plateau_t* p = (plateau_t*)malloc(sizeof(plateau_t));
    if (p == NULL) {
        printf("Erreur d'allocation de mémoire pour le plateau.\n");
        return NULL;
    }

    // Initialisation des dimensions
    setXPlateau(p, 15);
    setYPlateau(p, 15);

    // Allocation des lignes du plateau
    setPlateau(p, (case_t**)malloc(getYPlateau(p) * sizeof(case_t*)));
    if (getPlateau(p) == NULL) {
        free(p);
        printf("Erreur d'allocation de mémoire pour les lignes du plateau.\n");
        return NULL;
    }

    // Allocation et initialisation des cases
    for (int i = 0; i < getYPlateau(p); i++) {
        getPlateau(p)[i] = (case_t*)malloc(getXPlateau(p) * sizeof(case_t));
        if (getPlateau(p)[i] == NULL) {
            for (int j = 0; j < i; j++) {
                free(getPlateau(p)[j]);
            }
            free(getPlateau(p));
            free(p);
            printf("Erreur d'allocation de mémoire pour une ligne du plateau.\n");
            return NULL;
        }

        for (int j = 0; j < getXPlateau(p); j++) {
            // Initialisation des coordonnées de la case
            setXPiece(&getPlateau(p)[i][j], j);
            setYPiece(&getPlateau(p)[i][j], i);

            // Initialisation des valeurs spéciales de la case
            if (grilleSpeciale[i][j] == 1) {
                setValeurLettre(&getPlateau(p)[i][j], 1);
                setValeurMot(&getPlateau(p)[i][j], 1);
            } else if (grilleSpeciale[i][j] == 2) {
                setValeurLettre(&getPlateau(p)[i][j], 2);
                setValeurMot(&getPlateau(p)[i][j], 1);
            } else if (grilleSpeciale[i][j] == 3) {
                setValeurLettre(&getPlateau(p)[i][j], 3);
                setValeurMot(&getPlateau(p)[i][j], 1);
            } else if (grilleSpeciale[i][j] == 4) {
                setValeurLettre(&getPlateau(p)[i][j], 1);
                setValeurMot(&getPlateau(p)[i][j], 2);
            } else if (grilleSpeciale[i][j] == 5) {
                setValeurLettre(&getPlateau(p)[i][j], 1);
                setValeurMot(&getPlateau(p)[i][j], 3);
            }

            // Initialisation de la pièce vide
            piece_t pieceVide = { .lettre = '\0', .point = 0 };
            setPiece(&getPlateau(p)[i][j], pieceVide);
        }
    }

    return p;
}

/*initialise un tableau avec une taille de plateau et des cases personnalisées*/
plateau_t* creerPlateauPersonnalise(int x, int y) {
    // Allocation mémoire pour le plateau
    plateau_t* p = (plateau_t*)malloc(sizeof(plateau_t));
    if (p == NULL) {
        printf("Erreur d'allocation de mémoire pour le plateau.\n");
        return NULL;
    }

    // Initialisation des dimensions du plateau
    setXPlateau(p, x);
    setYPlateau(p, y);

    // Allocation des lignes du plateau
    setPlateau(p, (case_t**)malloc(getYPlateau(p) * sizeof(case_t*)));
    if (getPlateau(p) == NULL) {
        free(p);
        printf("Erreur d'allocation de mémoire pour les lignes du plateau.\n");
        return NULL;
    }

    // Allocation et configuration des cases
    for (int i = 0; i < getYPlateau(p); i++) {
        getPlateau(p)[i] = (case_t*)malloc(getXPlateau(p) * sizeof(case_t));
        if (getPlateau(p)[i] == NULL) {
            for (int j = 0; j < i; j++) {
                free(getPlateau(p)[j]);
            }
            free(getPlateau(p));
            free(p);
            return NULL;
        }

        for (int j = 0; j < getXPlateau(p); j++) {
            printf("Configurer la case (%d, %d):\n", i, j);
            printf("1. Case simple\n");
            printf("2. Mot compte double\n");
            printf("3. Mot compte triple\n");
            printf("4. Lettre compte double\n");
            printf("5. Lettre compte triple\n");
            printf("Choix : ");
            int choix;
            scanf("%d", &choix);

            // Initialisation par défaut de la case
            setValeurLettre(&getPlateau(p)[i][j], 1);
            setValeurMot(&getPlateau(p)[i][j], 1);
            setXPiece(&getPlateau(p)[i][j], j);
            setYPiece(&getPlateau(p)[i][j], i);

            // Initialisation d'une pièce vide
            piece_t pieceVide = { .lettre = '\0', .point = 0 };
            setPiece(&getPlateau(p)[i][j], pieceVide);

            // Modification selon le choix de l'utilisateur
            switch (choix) {
                case 1: // Case simple
                    break;
                case 2: // Mot compte double
                    setValeurMot(&getPlateau(p)[i][j], 2);
                    break;
                case 3: // Mot compte triple
                    setValeurMot(&getPlateau(p)[i][j], 3);
                    break;
                case 4: // Lettre compte double
                    setValeurLettre(&getPlateau(p)[i][j], 2);
                    break;
                case 5: // Lettre compte triple
                    setValeurLettre(&getPlateau(p)[i][j], 3);
                    break;
                default:
                    printf("Choix invalide. Case définie comme simple par défaut.\n");
                    break;
            }
        }
    }

    return p;
}


/*libère la mémoire allouée pour la création d'un plateau de jeu*/
void libererPlateau(plateau_t* p) {
    if (p != NULL) {
        // Libération de chaque ligne du plateau
        for (int i = 0; i < getYPlateau(p); i++) {
            free(getPlateau(p)[i]);
        }

        // Libération du tableau principal
        free(getPlateau(p));

        // Libération de la structure plateau
        free(p);
    }
}






