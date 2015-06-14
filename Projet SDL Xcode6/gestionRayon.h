#ifndef GESTIONRAYON_H_INCLUDED
#define GESTIONRAYON_H_INCLUDED

#include <stdio.h>
#include "constantes.h"


void gestionClic(int x, int y, int** plateau, int taillePlateau, int* status);
void lancerRayon(int x, int y, int** plateau, int taillePlateau);
int verifAtome(int x, int y, int** plateau);
void calculerRayon(int x, int y, int** plateau, int direction, int taillePlateau);
void bougerVersDirection(int* x, int* y, int direction, int taillePlateau);
void calculerAdjacent(int x, int y, int** plateau, int direction, int taillePlateau, int initX, int initY);

#endif /* defined(__SDL__gestionRayon__) */
