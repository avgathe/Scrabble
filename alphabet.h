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

/**
 * Initialise les valeurs de l'alphabet personalisé
 *
 * @param alphabet : tableau de 26 entiers représentant les valeurs des lettres de l'alphabet personnalisé
 * @param alphabet_perso : tableau de 26 piece représentant les valeurs des lettres de l'alphabet personnalisé
 */
alphabet_t *initAlphabetPersonnalise();

#endif // ALPHABET_H_INCLUDED