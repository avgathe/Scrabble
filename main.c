#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "alphabet.h"
#include "gestion_tour_jeu.h"


int main(int argc, char *argv[]) {
    const char *path = "mot_scrabble_ods.txt";
    int nb_mot = count_words_in_file(path);
    if (nb_mot <= 0) {
        fprintf(stderr, "Error: No words found in file or file could not be read\n");
        return 1;
    }

    char *my_word = "AGATHE";
    char **dict = load_words_from_file(path, &nb_mot);
    if (!dict) {
        fprintf(stderr, "Error: Failed to load words from file\n");
        return 1;
    }

    printf("Le nombre de mots dans le dictionnaire est de %d\n", nb_mot);
    printf("Le mot à chercher est %s\n", my_word);

    if (is_word_in_dico(my_word, dict, nb_mot)) {
        printf("Le mot %s est dans le dictionnaire\n", my_word);
    } else {
        printf("Le mot %s n'est pas dans le dictionnaire\n", my_word);
    }

    // Libération de l'allocation mémoire
    for (int i = 0; i < nb_mot; i++) {
        free(dict[i]);
    }
    free(dict);

    return 0;
}