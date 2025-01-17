#include "types.h"

/***********************************************************/
/*******************GETTERS/SETTERS*PIECE*******************/
/***********************************************************/
char getLettre(piece_t *p) {
    return p->lettre;
}

void setLettre(piece_t *p, char lettre) {
    p->lettre = lettre;
}

int getPoint(piece_t *p) {
    return p->point;
}

void setPoint(piece_t *p, int point) {
    p->point = point;
}

/***********************************************************/
/*******************GETTERS/SETTERS*PIECE*******************/
/***********************************************************/

int getValeurLettre(case_t *c) {
    return c->valeurLettre;
}

void setValeurLettre(case_t *c, int valeurLettre) {
    c->valeurLettre = valeurLettre;
}

int getValeurMot(case_t *c) {
    return c->valeurMot;
}

void setValeurMot(case_t *c, int valeurMot) {
    c->valeurMot = valeurMot;
}

int getX(case_t *c) {
    return c->x;
}

void setX(case_t *c, int x) {
    c->x = x;
}

int getY(case_t *c) {
    return c->y;
}

void setY(case_t *c, int y) {
    c->y = y;
}

piece_t getPiece(case_t *c) {
    return c->piece;
}

void setPiece(case_t *c, piece_t p) {
    c->piece = p;
}

/***********************************************************/
/******************GETTERS/SETTERS*TABLEAU******************/
/***********************************************************/

// Getter pour x
int getXPlateau(plateau_t* plateau) {
    return plateau->x;
}
// Setter pour x
void setXPlateau(plateau_t* plateau, int x) {
    plateau->x = x;
}


// Getter pour y
int getYPlateau(plateau_t* plateau) {
    return plateau->y;
}
// Setter pour y
void setYPlateau(plateau_t* plateau, int y) {
    plateau->y = y;
}

// Getter pour plateau
case_t** getPlateau(plateau_t* plateau) {
    return plateau->plateau;
}
// Setter pour plateau
void setPlateau(plateau_t* plateau, case_t** plateau_data) {
    plateau->plateau = plateau_data;
}
