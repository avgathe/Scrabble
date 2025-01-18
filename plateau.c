#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <stdlib.h>
#include "plateau.h"
#include "types.h"

/**********************************************************************************************************/
/*******************************************COMMANDE*COMPILATION*******************************************/
/**********************************************************************************************************/
/*gcc -o plateau_programme plateau.c types.c types.h `sdl2-config --cflags --libs` -lSDL2_ttf -lSDL2_image*/
/**********************************************************************************************************/



// Dimensions de la fenêtre
#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 600
#define CASE_SIZE 40 // Taille de chaque case du plateau

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





// Fonction pour afficher du texte
void afficherTexte(SDL_Renderer *renderer, TTF_Font *font, const char *texte, int x, int y) {
    SDL_Color couleur = {255, 255, 255, 255}; // Couleur du texte (blanc)
    SDL_Surface *surface = TTF_RenderText_Solid(font, texte, couleur);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);

    SDL_Rect rect = {x, y, surface->w, surface->h};
    SDL_RenderCopy(renderer, texture, NULL, &rect);

    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
}

// Fonction pour afficher un bouton avec texte
void afficherBouton(SDL_Renderer *renderer, TTF_Font *font, const char *texte, int x, int y, int width, int height) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255); // Bouton bleu
    SDL_Rect rect = {x, y, width, height};
    SDL_RenderFillRect(renderer, &rect);

    afficherTexte(renderer, font, texte, x + 10, y + 10); // Afficher le texte du bouton
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Bordure du bouton (noir)
    SDL_RenderDrawRect(renderer, &rect);
}
void afficherBouton(SDL_Renderer *renderer, TTF_Font *font, const char *texte, int x, int y) {
    // Calculer la taille du texte
    int textWidth, textHeight;
    TTF_SizeText(font, texte, &textWidth, &textHeight);

    // Définir la taille du bouton en fonction du texte
    int width = textWidth + 20;  // Ajouter un peu d'espace autour du texte
    int height = textHeight + 20;

    // Dessiner le bouton
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255); // Couleur du bouton (bleu)
    SDL_Rect rect = {x, y, width, height};
    SDL_RenderFillRect(renderer, &rect);

    // Afficher le texte au centre du bouton
    afficherTexte(renderer, font, texte, x + (width - textWidth) / 2, y + (height - textHeight) / 2);

    // Dessiner la bordure du bouton (noir)
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Bordure noire
    SDL_RenderDrawRect(renderer, &rect);
}


// Fonction pour afficher le plateau
void afficherPlateau(SDL_Renderer* renderer, plateau_t* plateau) {
    if (plateau == NULL || plateau->plateau == NULL) {
        printf("Erreur: Plateau non initialisé\n");
        return;
    }

    // Affichage des cases du plateau
    for (int i = 0; i < plateau->y; i++) {
        for (int j = 0; j < plateau->x; j++) {
            SDL_Rect rect = {j * CASE_SIZE, i * CASE_SIZE, CASE_SIZE, CASE_SIZE};
            // Couleur de fond selon la valeur de la case
            int valeurLettre = getValeurLettre(&plateau->plateau[i][j]);
            int valeurMot = getValeurMot(&plateau->plateau[i][j]);

            if (valeurLettre == 2) {
                SDL_SetRenderDrawColor(renderer, 144, 184, 209, 0); // Lettre compte double
            } else if (valeurLettre == 3) {
                SDL_SetRenderDrawColor(renderer, 54, 181, 208, 0); // Lettre compte triple
            } else if (valeurMot == 2) {
                SDL_SetRenderDrawColor(renderer, 215, 162, 146, 0); // Mot compte double
            } else if (valeurMot == 3) {
                SDL_SetRenderDrawColor(renderer, 223, 30, 13, 0); // Mot compte triple
            } else {
                SDL_SetRenderDrawColor(renderer, 21, 124, 107, 0); // Case simple
            }

            SDL_RenderFillRect(renderer, &rect);
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Bordure noire
            SDL_RenderDrawRect(renderer, &rect);
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






