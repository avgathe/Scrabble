#include "types.h"

// Getters et setters pour piece
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

// Getters et setters pour Case
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