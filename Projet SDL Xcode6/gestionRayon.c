//
//  gestionRayon.c
//  SDL
//
//  Created by oce_tah on 13/06/2015.
//  Copyright (c) 2015 Supinfo. All rights reserved.
//


#include <stdio.h>
#include <stdlib.h>
#include "gestionRayon.h"


void gestionClic(int x, int y, int** plateau, int taillePlateau, int* status){
    //printf("gestion clik\n");
	//printf("x= %d, y=%d\n",x,y);
	if (x == 0 || x == taillePlateau-1 || y == 0 || y == taillePlateau-1) {
		// on clique sur les bordures
		*status = SCORE;
		lancerRayon(x, y, plateau, taillePlateau);
		
	} else if (x > 0 && x < taillePlateau-1 & y > 0 && y < taillePlateau-1) {
		// on clique dans le plateau pour vérifier si la case est bien un atome
		if (verifAtome(x, y, plateau)) {
			*status = TROUVE;
		} else {
			*status = PERDU;
		}
		//TODO: décrémenter
		
	}


};

void lancerRayon(int x, int y, int** plateau, int taillePlateau) {
	//printf("lancer rayon\n");
	
	if ( y == 0 && (x != 0 && x != taillePlateau-1 )) {
		//RAYON VERS LE BAS
		//printf("vers le bas\n");
		calculerRayon(x, y, plateau, BAS, taillePlateau);
		
		
	} else if ( y == taillePlateau-1 && (x != 0 && x != taillePlateau-1 ) ) {
		//RAYON VERS LE HAUT
		//printf("vers le haut\n");
		calculerRayon(x, y, plateau, HAUT,taillePlateau);

		
	} else if ( x == 0 && (y != 0 && y != taillePlateau-1 ) ) {
		//RAYON VERS LA DROITE
		//printf("vers la droite\n");
		calculerRayon(x, y, plateau, DROITE, taillePlateau);

		
	} else if ( x == taillePlateau-1 && (y != 0 && y != taillePlateau-1 ) ) {
		//RAYON VERS LA GAUCHE
		//printf("vers la gauche\n");
		calculerRayon(x, y, plateau, GAUCHE, taillePlateau);

		
	}
	
};


int verifAtome(int x, int y, int** plateau) {
	if (plateau[x][y] == 2) {
		return 1;
	} else {
		return 0;
	}
};





void calculerRayon(int x, int y, int** plateau, int direction, int taillePlateau) {
	//enum {NOCLICK, VIDE, ATOM, ADJACENT, REFLECT, ZERO, UN, DEUX, TROIS, QUATRE, CINQ, SIX, SEPT, HUIT, NEUF, HIT, STRAIGHT};
	int initX = x, initY = y;
	
	do {
		bougerVersDirection(&x, &y, direction, taillePlateau);
		//printf("en train de sauter\n");
	} while(plateau[x][y] == VIDE);
	
	switch (plateau[x][y]) {
		case NOCLICK:
			plateau[x][y] = STRAIGHT;
			printf("straight\n");
			break;
		case ADJACENT:
			calculerAdjacent(x, y, plateau, direction, taillePlateau, initX, initY);
			printf("adjacent\n");
			break;
		case ATOM:
			plateau[initX][initY] = HIT;
			printf("atom\n");
			break;
				
		default:
			break;
		
	}
	
	
	
}




void bougerVersDirection(int* x, int* y, int direction, int taillePlateau){
		switch (direction) {
		//enum {0 HAUT,1 BAS,2 GAUCHE,3 DROITE};

			case 0:
				if (*y > 0) {
					*y = *y - 1;
				}
				break;
			case 1:
				if (*y < taillePlateau-1) {
					*y = *y + 1;
				}
				break;
			case 2:
				if (*x > 0) {
					*x = *x - 1;
				}
				break;
			case 3:
				if (*x < taillePlateau-1) {
					*x = *x + 1;
				}
				break;
	
			default:
				break;
		}
	
}

void calculerAdjacent(int x, int y, int** plateau, int direction, int taillePlateau, int initX, int initY) {
	
}



