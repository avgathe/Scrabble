#include <stdio.h>
#include "types.h"
#include "alphabet.h"


int main(int argc, char *argv[]) {

    piece_t alphabet[26];
    initAlphabetFrancais(alphabet);

    for (int i = 0; i < 26; i++) {
        printf("Lettre : %c, Point : %d\n", getLettre(&alphabet[i]), getPoint(&alphabet[i]));
    }


    return 0;
}