#include <stdlib.h>
#include <stdio.h>
#include "types.h"
#include "plateau.h"
#include <SDL2/SDL.h>

#define TILE_SIZE 40
#define BOARD_SIZE 15

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

// Fonction de dessin du plateau avec SDL2
void drawBoard(SDL_Renderer* renderer, plateau_t* p) {
    for (int i = 0; i < p->y; i++) {
        for (int j = 0; j < p->x; j++) {
            SDL_Rect tile = {j * TILE_SIZE, i * TILE_SIZE, TILE_SIZE, TILE_SIZE};
            case_t current_case = p->plateau[i][j];

            // Choisir la couleur en fonction de la valeur du mot
            if (current_case.valeurMot == 3) {
                SDL_SetRenderDrawColor(renderer, 223, 30, 13, 0); // Lettre compte triple (Rouge)
            } else if (current_case.valeurMot == 2) {
                SDL_SetRenderDrawColor(renderer, 215, 162, 146, 0); // Mot compte double (Bleu)
            } else if (current_case.valeurLettre == 2) {
                SDL_SetRenderDrawColor(renderer, 144, 184, 209, 0); // Lettre compte double (Vert)
            } else if (current_case.valeurLettre == 3) {
                SDL_SetRenderDrawColor(renderer, 54, 181, 208, 0); // Lettre compte triple (Jaune)
            } else {
                SDL_SetRenderDrawColor(renderer, 21, 124, 107, 0); // Case normale (Gris clair)
            }

            SDL_RenderFillRect(renderer, &tile);
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Bordures noires
            SDL_RenderDrawRect(renderer, &tile);
        }
    }
}

// int main(int argc, char* argv[]) {
//     if (SDL_Init(SDL_INIT_VIDEO) != 0) {
//         printf("Erreur SDL: %s\n", SDL_GetError());
//         return 1;
//     }

//     SDL_Window* window = SDL_CreateWindow("Plateau Scrabble", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
//                                           TILE_SIZE * BOARD_SIZE, TILE_SIZE * BOARD_SIZE, SDL_WINDOW_SHOWN);
//     if (!window) {
//         printf("Erreur création fenêtre: %s\n", SDL_GetError());
//         SDL_Quit();
//         return 1;
//     }

//     SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
//     if (!renderer) {
//         printf("Erreur création renderer: %s\n", SDL_GetError());
//         SDL_DestroyWindow(window);
//         SDL_Quit();
//         return 1;
//     }

//     plateau_t* plateau = creerPlateauFr(); // Création du plateau

//     int running = 1;
//     SDL_Event event;

//     while (running) {
//         while (SDL_PollEvent(&event)) {
//             if (event.type == SDL_QUIT) {
//                 running = 0;
//             }
//         }

//         SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // Fond blanc
//         SDL_RenderClear(renderer);

//         drawBoard(renderer, plateau); // Dessiner le plateau

//         SDL_RenderPresent(renderer);
//     }

//     libererPlateau(plateau); // Libérer la mémoire allouée pour le plateau

//     SDL_DestroyRenderer(renderer);
//     SDL_DestroyWindow(window);
//     SDL_Quit();

//     return 0;
// }







