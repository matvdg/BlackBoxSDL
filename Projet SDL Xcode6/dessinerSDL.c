#include "dessinerSDL.h"

void drawBoard(SDL_Surface *ecran, int taillePlateau, int** plateau) {
	
	SDL_Surface *noclick = NULL, *vide = NULL, *atom = NULL, *adjacent = NULL, *reflect = NULL, *zero = NULL, *un = NULL, *deux = NULL, *trois = NULL, *quatre = NULL, *cinq = NULL, *six = NULL, *sept = NULL, *huit = NULL, *neuf = NULL, *hit = NULL, *straight = NULL;
	noclick = SDL_LoadBMP("/img/0.bmp");
	vide = SDL_LoadBMP("/img/1.bmp");
	atom = SDL_LoadBMP("/img/2.bmp");
	adjacent = SDL_LoadBMP("/img/3.bmp");
	reflect = SDL_LoadBMP("/img/4.bmp");
	zero = SDL_LoadBMP("/img/5.0.bmp");
	un = SDL_LoadBMP("/img/5.1.bmp");
	deux = SDL_LoadBMP("/img/5.2.bmp");
	trois = SDL_LoadBMP("/img/5.3.bmp");
	quatre = SDL_LoadBMP("/img/5.4.bmp");
	cinq = SDL_LoadBMP("/img/5.5.bmp");
	six = SDL_LoadBMP("/img/5.6.bmp");
	sept = SDL_LoadBMP("/img/5.7.bmp");
	huit = SDL_LoadBMP("/img/5.8.bmp");
	neuf = SDL_LoadBMP("/img/5.9.bmp");
	hit = SDL_LoadBMP("/img/6.bmp");
	straight = SDL_LoadBMP("/img/7.bmp");
	
	SDL_Rect positionJeu;
	positionJeu.x = 0;
	positionJeu.y = 0;
	
	int x = 0;
	int y = 0;
	
	//we fill the screen with blank
	SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
	
	for(x = 0; x < taillePlateau; x++)
	{
		for(y = 0; y < taillePlateau; y++)
		{
			if(!((x == 0 && y == 0) || (x == taillePlateau-1 && y == 0) || (x == 0 && y == taillePlateau-1) || (x == taillePlateau-1 && y == taillePlateau-1)))
				// Si l'on n'est pas dans l'un des coins
			{
				positionJeu.x = x * TAILLE_CASE; // On avance de 50 pixels en x et en y
				positionJeu.y = y * TAILLE_CASE;
				switch(plateau[x][y])
				{
					case NOCLICK:
						SDL_BlitSurface(noclick, NULL, ecran, &positionJeu);
						break;
					case VIDE:
						SDL_BlitSurface(vide, NULL, ecran, &positionJeu);
						break;
					case ATOM:
						//SDL_BlitSurface(vide, NULL, ecran, &positionJeu);
						SDL_BlitSurface(atom, NULL, ecran, &positionJeu);
						break;
					case ADJACENT:
						//SDL_BlitSurface(vide, NULL, ecran, &positionJeu);
						SDL_BlitSurface(adjacent, NULL, ecran, &positionJeu);
						break;
					case REFLECT:
						SDL_BlitSurface(reflect, NULL, ecran, &positionJeu);
						break;
					case UN:
						SDL_BlitSurface(un, NULL, ecran, &positionJeu);
						break;
					case DEUX:
						SDL_BlitSurface(deux, NULL, ecran, &positionJeu);
						break;
					case TROIS:
						SDL_BlitSurface(trois, NULL, ecran, &positionJeu);
						break;
					case QUATRE:
						SDL_BlitSurface(quatre, NULL, ecran, &positionJeu);
						break;
					case CINQ:
						SDL_BlitSurface(cinq, NULL, ecran, &positionJeu);
						break;
					case SIX:
						SDL_BlitSurface(six, NULL, ecran, &positionJeu);
						break;
					case SEPT:
						SDL_BlitSurface(sept, NULL, ecran, &positionJeu);
						break;
					case HUIT:
						SDL_BlitSurface(huit, NULL, ecran, &positionJeu);
						break;
					case NEUF:
						SDL_BlitSurface(neuf, NULL, ecran, &positionJeu);
						break;
					case HIT:
						SDL_BlitSurface(hit, NULL, ecran, &positionJeu);
						break;
					case STRAIGHT:
						SDL_BlitSurface(straight, NULL, ecran, &positionJeu);
						break;
						
				}
			}
		}
	}
	SDL_Flip(ecran);
}
