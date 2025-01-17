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

} piece_t;

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
    piece_t piece;

} case_t;

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
    case_t **plateau;

} plateau_t;

/***********************************************************/
/*******************GETTERS/SETTERS*PIECE*******************/
/***********************************************************/

char getLettre(piece_t *p);
void setLettre(piece_t *p, char lettre);

int getPoint(piece_t *p);
void setPoint(piece_t *p, int point);

/***********************************************************/
/*******************GETTERS/SETTERS*PIECE*******************/
/***********************************************************/

int getValeurLettre(case_t *c);
void setValeurLettre(case_t *c, int valeurLettre);

int getValeurMot(case_t *c);
void setValeurMot(case_t *c, int valeurMot);

int getX(case_t *c);
void setX(case_t *c, int x);

int getY(case_t *c);
void setY(case_t *c, int y);

piece_t getPiece(case_t *c);
void setPiece(case_t *c, piece_t p);

/***********************************************************/
/******************GETTERS/SETTERS*TABLEAU******************/
/***********************************************************/

int getXPlateau(plateau_t *plateau);
void setXPlateau(plateau_t *plateau, int x);

int getYplateau(plateau_t *plateau);
void setYplateau(plateau_t *plateau, int y);

case_t **getPlateau(plateau_t *plateau);
void setPlateau(plateau_t *plateau, case_t **plateau_data);

#endif // TYPES_H_INCLUDED