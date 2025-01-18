#ifndef GESTION_TOUR_JEU_H
#define GESTION_TOUR_JEU_H

#include "types.h"

#define MAX_WORD_LENGTH 50 //Mot le plus long dans le dictionnaire


/******************************************************************** */
/* 3) */
/******************************************************************** */

/// @brief compte le nombre de mots dans un fichier
/// @param filename 
/// @return le nombre de mots dans le fichier placé en paramètre
int count_words_in_file(const char *filename);

/// @brief charge les mots du fichier placé en paramètre
/// @param filename
/// @param word_count
/// @return un tableau des mots du fichier
char **load_words_from_file(const char *filename, int *word_count);

/// @brief fonction qui met en majuscule un mot
/// @param word 
/// @return le mot en majuscule, il fait un malloc donc il faut free après utilisation
char *to_upper(char *word);

/// @brief vérifie si le mot est dans le dictionnaire français
/// @param word 
/// @param dico 
/// @param taille_dico 
/// @return true si c'est vrai, false sinon
bool is_word_in_dico(char *word, char *dico[], int taille_dico);



#endif