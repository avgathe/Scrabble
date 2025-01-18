
#include "gestion_tour_jeu.h"

/*

    Le joueur peut demander à vérifier la validité du mot de son adversaire 
    pour instaurer une pénalité en cas de mot invalide.

 */

int count_words_in_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Impossible d'ouvrir le fichier %s\n", filename);
        exit(1);
    }

    int count = 0;
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word) != EOF) {
        count++;
    }

    fclose(file);
    return count;
}

char **load_words_from_file(const char *filename, int *word_count) {
    *word_count = count_words_in_file(filename);
    if (*word_count <= 0) {
        return NULL;
    }

    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Could not open file");
        return NULL;
    }

    char **dict = (char**)malloc(*word_count * sizeof(char *));
    if (!dict) {
        perror("Could not allocate memory");
        fclose(file);
        return NULL;
    }

    for (int i = 0; i < *word_count; i++){
        char word[MAX_WORD_LENGTH];
        fscanf(file, "%s", word);
        dict[i] = strdup(word);
    }

    fclose(file);
    return dict;
}

char *to_upper(char *word) {
    int len = strlen(word);
    char *s_up = (char*)malloc((len + 1) * sizeof(char));

    for (int i = 0; i<len; i++) {
        if ('a' <= word[i] && word[i] <= 'z') {
            s_up[i] = (char) (word[i] - 'a' + 'A');
        }
        else {
            s_up[i] = word[i];
        }
    }
    s_up[len] = '\0';
    return s_up;
}

bool is_word_in_dico(char *word, char *dico[], int taille_dico) {
    char *upper_word = to_upper(word);

    printf("is_word_in_dico : %s \n", upper_word);

    for (int i = 0; i < taille_dico; i++) {
        if (strcmp(upper_word, dico[i]) == 0) {
            return true;
        }
    }

    free(upper_word);
    return false;
}