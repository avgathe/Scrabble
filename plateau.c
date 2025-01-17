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


    plateau_t* p = (plateau_t*)malloc(sizeof(plateau_t));
    if (p == NULL) {
        printf("Erreur d'allocation de mémoire pour le plateau.\n");
        return NULL;
    }

    p->x = 15; 
    p->y = 15; 


    p->plateau = (case_t**)malloc(p->y * sizeof(case_t*));
    if (p->plateau == NULL) {
        free(p);
        printf("Erreur d'allocation de mémoire pour les lignes du plateau.\n");
        return NULL;
    }

    for (int i = 0; i < p->y; i++) {
        p->plateau[i] = (case_t*)malloc(p->x * sizeof(case_t));
        if (p->plateau[i] == NULL) {
            for (int j = 0; j < i; j++) {
                free(p->plateau[j]);
            }
            free(p->plateau);
            free(p);
            printf("Erreur d'allocation de mémoire pour une ligne du plateau.\n");
            return NULL;
        }


        for (int j = 0; j < p->x; j++) {
            p->plateau[i][j].x = j;
            p->plateau[i][j].y = i;


            if (grilleSpeciale[i][j] == 1) {
                p->plateau[i][j].valeurLettre = 1;
                p->plateau[i][j].valeurMot = 1;
            } else if (grilleSpeciale[i][j] == 2) {
                p->plateau[i][j].valeurLettre = 2;
                p->plateau[i][j].valeurMot = 1;
            } else if (grilleSpeciale[i][j] == 3) {
                p->plateau[i][j].valeurLettre = 3;
                p->plateau[i][j].valeurMot = 1;
            } else if (grilleSpeciale[i][j] == 4) {
                p->plateau[i][j].valeurLettre = 1;
                p->plateau[i][j].valeurMot = 2;
            } else if (grilleSpeciale[i][j] == 5) {
                p->plateau[i][j].valeurLettre = 1;
                p->plateau[i][j].valeurMot = 3;
            }

            p->plateau[i][j].piece.lettre = '\0'; 
            p->plateau[i][j].piece.point = 0;   
        }
    }

    return p;
}

/*initialise un tableau avec une taille de plateau et des cases personnalisées*/
plateau_t* creerPlateauPersonnalise(int x, int y) {

    plateau_t* p = (plateau_t*)malloc(sizeof(plateau_t));
    if (p == NULL) {
        return NULL;
    }

    p->x = x;
    p->y = y;

    p->plateau = (case_t**)malloc(y * sizeof(case_t*));
    if (p->plateau == NULL) {
        free(p); 
        return NULL;
    }


    for (int i = 0; i < y; i++) {
        p->plateau[i] = (case_t*)malloc(x * sizeof(case_t));
        if (p->plateau[i] == NULL) {

            for (int j = 0; j < i; j++) {
                free(p->plateau[j]);
            }
            free(p->plateau);
            free(p);
            return NULL;
        }

        for (int j = 0; j < x; j++) {
            printf("Configurer la case (%d, %d):\n", i, j);
            printf("1. Case simple\n");
            printf("2. Mot compte double\n");
            printf("3. Mot compte triple\n");
            printf("4. Lettre compte double\n");
            printf("5. Lettre compte triple\n");
            printf("Choix : ");
            int choix;
            scanf("%d", &choix);

            p->plateau[i][j].valeurLettre = 1;
            p->plateau[i][j].valeurMot = 1;
            p->plateau[i][j].x = j;
            p->plateau[i][j].y = i;
            p->plateau[i][j].piece.lettre = '\0';
            p->plateau[i][j].piece.point = 0;


            switch (choix) {
                case 1: // Case simple
                    break;
                case 2: // Mot compte double
                    p->plateau[i][j].valeurMot = 2;
                    break;
                case 3: // Mot compte triple
                    p->plateau[i][j].valeurMot = 3;
                    break;
                case 4: // Lettre compte double
                    p->plateau[i][j].valeurLettre = 2;
                    break;
                case 5: // Lettre compte triple
                    p->plateau[i][j].valeurLettre = 3;
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
        for (int i = 0; i < p->y; i++) {
            free(p->plateau[i]); 
        }
        free(p->plateau); 
        free(p);     
    }
}





