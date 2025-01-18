#ifndef ALPHABET_H_INCLUDED
#define ALPHABET_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include "types.h"

typedef struct {
    piece_t *alphabet;
    int taille;
} alphabet_t;

/**
 * Initialise les valeurs de l'alphabet
 * 
 * @param alphabet : tableau de 26 entiers représentant les valeurs des lettres de l'alphabet
 */
void initAlphabetFrancais(piece_t alphabet[26]);

/// @brief fonction qui demande a l'utilisateur de choisir un alphabet
/// @return l'alphabet choisi
alphabet_t *initAlphabetPersonnalise();

#endif // ALPHABET_H_INCLUDED