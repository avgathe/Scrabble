#include <stdio.h>
#include "types.h"
#include "alphabet.h"


int main(int argc, char *argv[]) {

    alphabet_t *alphabet_perso = initAlphabetPersonnalise();
    piece_t *alphabet = alphabet_perso->alphabet;
    int taille_alphabet = alphabet_perso->taille;

    for (int i = 0; i < taille_alphabet; i++) {
        printf("Lettre : %c, Point : %d\n", getLettre(&alphabet[i]), getPoint(&alphabet[i]));
    }


    return 0;
}