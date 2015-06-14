#include "choix.h"

void choixJeu(SDL_Surface *ecran, int partie)
{

    SDL_Surface *choix = NULL, *boutonChoix = NULL;
    SDL_Rect positionChoix;
    positionChoix.x = 0;
    positionChoix.y = 0;

    SDL_Event event;

    choix = SDL_LoadBMP("/img/ChoixFont.bmp");
    boutonChoix = SDL_LoadBMP("/img/choix.bmp");

    int continuer = 1, choixPlateau = -1, choixAtomes = -1;

    switch(partie)
    {
    case 1:
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
                    if((event.button.x >= 168 && event.button.x <= 259) && (event.button.y >= 337 && event.button.y <= 369))
                    {
                        choixPlateau = 10;
                    }
                    else if((event.button.x >= 355 && event.button.x <= 487) && (event.button.y >= 340 && event.button.y <= 378))
                    {
                        choixPlateau = 12;
                    }
                    else if((event.button.x >= 546 && event.button.x <= 677) && (event.button.y >= 336 && event.button.y <= 368))
                    {
                        choixPlateau = 14;
                    }
                    else if((event.button.x >= 211 && event.button.x <= 232) && (event.button.y >= 502 && event.button.y <= 526))
                    {
                        choixAtomes = 3;
                    }
                    else if((event.button.x >= 390 && event.button.x <= 415) && (event.button.y >= 502 && event.button.y <= 526))
                    {
                        choixAtomes = 4;

                    }
                    else if((event.button.x >= 578 && event.button.x <= 599) && (event.button.y >= 502 && event.button.y <= 526))
                    {
                        choixAtomes = 5;
                    }
                    else if((event.button.x >= 259 && event.button.x <= 549) && (event.button.y >= 558 && event.button.y <= 578) && choixPlateau != -1 && choixAtomes != -1)
                    {
                        initPlateau(choixPlateau, choixAtomes);
                        ecran = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
                    }
                }
                break;
            }
            SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
            SDL_BlitSurface(choix, NULL, ecran, &positionChoix);
            switch(choixPlateau)
            {
            case 10 :
                positionChoix.x = 142;
                positionChoix.y = 351;
                SDL_BlitSurface(boutonChoix, NULL, ecran, &positionChoix);
                break;
            case 12 :
                positionChoix.x = 329;
                positionChoix.y = 351;
                SDL_BlitSurface(boutonChoix, NULL, ecran, &positionChoix);
                break;
            case 14 :
                positionChoix.x = 520;
                positionChoix.y = 351;
                SDL_BlitSurface(boutonChoix, NULL, ecran, &positionChoix);
                break;
            }
            switch(choixAtomes)
            {
            case 3 :
                positionChoix.x = 185;
                positionChoix.y = 510;
                SDL_BlitSurface(boutonChoix, NULL, ecran, &positionChoix);
                break;
            case 4 :
                positionChoix.x = 364;
                positionChoix.y = 510;
                SDL_BlitSurface(boutonChoix, NULL, ecran, &positionChoix);
                break;
            case 5 :
                positionChoix.x = 552;
                positionChoix.y = 510;
                SDL_BlitSurface(boutonChoix, NULL, ecran, &positionChoix);
                break;
            }
            positionChoix.x = 0;
            positionChoix.y = 0;
            SDL_Flip(ecran);
        }
    }
    SDL_FreeSurface(choix);
    SDL_FreeSurface(boutonChoix);
}
