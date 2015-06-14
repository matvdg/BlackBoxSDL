#ifndef DESSINERSDL_H_INCLUDED
#define DESSINERSDL_H_INCLUDED


#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include "constantes.h"

void drawBoard(SDL_Surface *ecran, int taillePlateau, int** plateau, int atomes, int score);

#endif
