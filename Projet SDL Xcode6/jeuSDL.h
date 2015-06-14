#ifndef JEUSDL_H_INCLUDED
#define JEUSDL_H_INCLUDED


#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include "constantes.h"
#include "gestionRayon.h"
#include "dessinerSDL.h"

void jouerUnJoueur(int **plateau, int taillePlateau, int nbrAtomes);
int verifierFin(int* score, int status, int taillePlateau, int* nombreAtomeRestantATrouver);
#endif
