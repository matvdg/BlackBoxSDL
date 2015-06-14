#include "jeuSDL.h"

void jouerUnJoueur(int **plateau, int taillePlateau, int nbrAtomes)
{
	SDL_Surface *ecran = NULL;
	SDL_Event event;
	
	SDL_Init(SDL_INIT_VIDEO);
	SDL_WM_SetCaption("Black Box Game", NULL);
	ecran = SDL_SetVideoMode(50 * taillePlateau, 50 * taillePlateau, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
	
	int continuer = 1;
	int status = ENCOURS;
	int score = 100;
	int nombreAtomeRestantATrouver = nbrAtomes;
	
	while (continuer)
	{
		SDL_WaitEvent(&event);
		switch(event.type)
		{
			case SDL_QUIT:
				continuer = 0;
				break;
			case SDL_KEYDOWN:
				if(event.key.keysym.sym == SDLK_ESCAPE)  // Veut arrêter le jeu
				{
					continuer = 0;
				}
				break;
			case SDL_MOUSEBUTTONDOWN:
				if(event.button.button == SDL_BUTTON_LEFT)
				{
					status = ENCOURS;
					gestionClic(event.button.x / TAILLE_CASE, event.button.y / TAILLE_CASE, plateau, taillePlateau, &status);
				}
				break;
			default:
				status = ENCOURS;
				break;
				
		}
		drawBoard(ecran, taillePlateau, plateau);
		int etat = verifierFin(&score, status,taillePlateau, &nombreAtomeRestantATrouver);
		if (etat == PERDU) {
			// afficher ecran perte
			continuer = 0;
		} else if (etat == GAGNE) {
			// afficher ecran winner
			continuer = 0;
		}
		status = ENCOURS;
		
	}
}

int verifierFin(int* score, int status, int taillePlateau, int* nombreAtomeRestantATrouver) {
	switch (status) {
		case PERDU:
			printf("Perdu!");
			return PERDU;
			break;
		case SCORE:
			*score = *score - (100/(taillePlateau*2));
			printf("Vous perdez du score! %d %",*score);
			if (*score <= 0) {
				printf("Perdu!");
				return PERDU;
			} else {
				return ENCOURS;
			}
			break;
		case TROUVE:
			printf("Bravo, un atome a été trouvé!");
			*nombreAtomeRestantATrouver = *nombreAtomeRestantATrouver -1;
			if (*nombreAtomeRestantATrouver == 0) {
				printf("Vous avez gagné !");
				return GAGNE;
			}
			return ENCOURS;
			break;
		default:
			return ENCOURS;
			break;
	}
}
