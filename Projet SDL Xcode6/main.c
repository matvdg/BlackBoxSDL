/* Simple program:  Create a blank window, wait for keypress, quit.
 
 Please see the SDL documentation for details on using the SDL API:
 /Developer/Documentation/SDL/docs.html
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <SDL/SDL.h>
#include <stdlib.h>
#include <stdio.h>
#include "choix.h"

int main(int argc, char* argv[])
{
	
	SDL_Surface *ecran = NULL, *menu = NULL;
	SDL_Rect positionMenu;
	SDL_Event event;
	
	int continuer = 1;
	
	SDL_Init(SDL_INIT_VIDEO);
	SDL_WM_SetCaption("Black Box Game", NULL);
	ecran = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
	
	menu = SDL_LoadBMP("/img/MenuFont.bmp");
	positionMenu.x = 0;
	positionMenu.y = 0;
	
	while (continuer)
	{
		SDL_WaitEvent(&event);
		switch(event.type)
		{
			case SDL_QUIT:
				continuer = 0;
				break;
			case SDL_KEYDOWN:
				if(event.key.keysym.sym == SDLK_ESCAPE)
				{
					continuer = 0;
				}
				break;
			case SDL_MOUSEBUTTONDOWN:
				if(event.button.button == SDL_BUTTON_LEFT) // Si l'on clique avec la souris (gauche)
				{
					if((event.button.x >= 282 && event.button.x <= 510) && (event.button.y >= 236 && event.button.y <= 263))
					{
						//un joueur
						choixJeu(ecran, 1);
						ecran = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
					}
					else if((event.button.x >= 282 && event.button.x <= 660) && (event.button.y >= 340 && event.button.y <= 367))
					{
						//deux joueurs
					}
					else if((event.button.x >= 343 && event.button.x <= 486) && (event.button.y >= 491 && event.button.y <= 527))
					{
						//quitter le jeu
						continuer = 0;
					}
					break;
				}
				break;
		}
		// Actualisation de l'écran
		SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
		SDL_BlitSurface(menu, NULL, ecran, &positionMenu);
		SDL_Flip(ecran);
	}
	
	SDL_FreeSurface(menu);
	SDL_FreeSurface(ecran);
	SDL_Quit();
	
	return EXIT_SUCCESS;
	
}

