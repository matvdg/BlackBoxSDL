#include "jeuSDL.h"

void jouerUnJoueur(int **plateau, int taillePlateau, int nbrAtomes)
{
	SDL_Surface *ecran = NULL;
	SDL_Event event;
	
	SDL_Init(SDL_INIT_VIDEO);
	SDL_WM_SetCaption("Black Box Game", NULL);
	ecran = SDL_SetVideoMode(TAILLE_CASE * taillePlateau, TAILLE_CASE * (taillePlateau+1), 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
	SDL_Surface *win = SDL_LoadBMP("/img/win.bmp"), *lost = SDL_LoadBMP("/img/gameover.bmp");
	SDL_Rect positionJeu;
	positionJeu.x = ecran->w/2 - win->w/2;
	positionJeu.y = ecran->h/2 - win->h/2;
	int continuer = 1;
	int status = ENCOURS;
	int score = 100;
	//printf("atomes %d",nbrAtomes);
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
		drawBoard(ecran, taillePlateau, plateau, nombreAtomeRestantATrouver, score);
		int etat = verifierFin(&score, status,taillePlateau, &nombreAtomeRestantATrouver);
		if (etat == PERDU) {
			// afficher ecran perte
			SDL_BlitSurface(lost, NULL, ecran, &positionJeu);
			SDL_Flip(ecran);
			SDL_Delay(2000);
			continuer = 0;
		} else if (etat == GAGNE) {
			SDL_BlitSurface(win,NULL,ecran,&positionJeu);
			SDL_Flip(ecran);
			SDL_Delay(2000);
			// afficher ecran winner
			continuer = 0;
		}
		status = ENCOURS;
		
	}
}

int verifierFin(int* score, int status, int taillePlateau, int* nombreAtomeRestantATrouver) {
	switch (status) {
		case PERDU:
			printf("Perdu!\n");
			return PERDU;
			break;
		case SCORE:
			*score = *score - (100/(taillePlateau*2));
			printf("Vous perdez du score! %d%%\n",*score);
			if (*score <= 0) {
				printf("Perdu!");
				return PERDU;
			} else {
				return ENCOURS;
			}
			break;
		case TROUVE:
			
			*nombreAtomeRestantATrouver = *nombreAtomeRestantATrouver -1 ;
			printf("Bravo, un atome a été trouvé! %d restant\n",*nombreAtomeRestantATrouver);
			if (*nombreAtomeRestantATrouver == 0) {
				printf("Vous avez gagné !\n");
				return GAGNE;
			}
			return ENCOURS;
			break;
		default:
			return ENCOURS;
			break;
	}
}
