#include "alphabet.h"

void initAlphabetFrancais(piece_t alphabet[26]) {
    alphabet[0] = (piece_t) { .lettre = 'A', .point = 1 };
    alphabet[1] = (piece_t) { .lettre = 'B', .point = 3 };
    alphabet[2] = (piece_t) { .lettre = 'C', .point = 3 };
    alphabet[3] = (piece_t) { .lettre = 'D', .point = 2 };
    alphabet[4] = (piece_t) { .lettre = 'E', .point = 1 };
    alphabet[5] = (piece_t) { .lettre = 'F', .point = 4 };
    alphabet[6] = (piece_t) { .lettre = 'G', .point = 2 };
    alphabet[7] = (piece_t) { .lettre = 'H', .point = 4 };
    alphabet[8] = (piece_t) { .lettre = 'I', .point = 1 };
    alphabet[9] = (piece_t) { .lettre = 'J', .point = 8 };
    alphabet[10] = (piece_t) { .lettre = 'K', .point = 10 };
    alphabet[11] = (piece_t) { .lettre = 'L', .point = 1 };
    alphabet[12] = (piece_t) { .lettre = 'M', .point = 2 };
    alphabet[13] = (piece_t) { .lettre = 'N', .point = 1 };
    alphabet[14] = (piece_t) { .lettre = 'O', .point = 1 };
    alphabet[15] = (piece_t) { .lettre = 'P', .point = 3 };
    alphabet[16] = (piece_t) { .lettre = 'Q', .point = 8 };
    alphabet[17] = (piece_t) { .lettre = 'R', .point = 1 };
    alphabet[18] = (piece_t) { .lettre = 'S', .point = 1 };
    alphabet[19] = (piece_t) { .lettre = 'T', .point = 1 };
    alphabet[20] = (piece_t) { .lettre = 'U', .point = 1 };
    alphabet[21] = (piece_t) { .lettre = 'V', .point = 4 };
    alphabet[22] = (piece_t) { .lettre = 'W', .point = 10 };
    alphabet[23] = (piece_t) { .lettre = 'X', .point = 10 };
    alphabet[24] = (piece_t) { .lettre = 'Y', .point = 10 };
    alphabet[25] = (piece_t) { .lettre = 'Z', .point = 10 };
}