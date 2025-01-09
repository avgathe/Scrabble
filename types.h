#ifndef TYPES_H_INCLUDED
#define TYPES_H_INCLUDED

/***********************************************************/
/***************************TYPES***************************/
/***********************************************************/

/**
 * représente une pièce du jeu
 * 
 * @param lettre : lettre inscrite sur la pièce
 * @param point : valeur de la pièce
 */
typedef struct
{
    char lettre;
    int point;

}piece;

/** 
* représente une case du plateau
*
* @param valeur : 0 si c'est une case simple, 2 pour une case double et 3 pour une case triple
* @param x : position de la case en x
* @param y : position de la case en y
**/
typedef struct
{
    int valeurLettre;
    int valeurMot;
    int x;
    int y;
    piece piece; 

}Case;

/**
 * représente le plateau de jeu
 * 
 * @param x : largeur du plateau (nombre de colonnes)
 * @param y : longueur du plateau (nombre de lignes)
 * @param plateau : tableau en deux dimensions représentant le plateau
 */
typedef struct
{
    int x;
    int y;
    Case** plateau;

}plateau;



#endif //TYPES_H_INCLUDED