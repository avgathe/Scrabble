#ifndef PLATEAU_H_INCLUDED
#define PLATEAU_H_INCLUDED

#include "types.h"

/**
 * créé et initialise un plateau tel le Scrabble français classique
 * 
 * @return plateau initialisé
 */
plateau_t * creerPlateauFr();

/**
 * Initialise un plateau en demandant à l'utilisateur de configurer chaque case
 *
 * @param x : nombre de colonne du plateau
 * @param y : nombre de lignes du plateau
 * @return plateau initialisé ou NULL en cas d'erreur
 */
plateau_t * creerPlateauPersonnalise(int x, int y);

/**
 * Libère la mémoire allouée pour un plateau
 *
 * @param p Pointeur vers le plateau à libérer
 */
void libererPlateau(plateau_t * p);

#endif //PLATEAU_H_INCLUDED