#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h> /* Inclusion du header de SDL_image (adapter le dossier au besoin) */
#include "clavier.h"
#include "souris.h"
#include "personnages_init.h"
int main(int argc, char *argv[])
{

    SDL_Surface *ecran = NULL, *perso = NULL, *bg= NULL,*freeman = NULL,*mc = NULL;
    SDL_Rect positionperso,positionbg,positionmc;
    positionbg.x=0;
    positionbg.y=0;
    SDL_Event event;
    //mc->h=200;
    //mc->w=200;
    positionmc.x = 200;
    positionmc.y = 150;

    SDL_Init(SDL_INIT_VIDEO|SDL_DOUBLEBUF|SDL_INIT_TIMER);

    ecran = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE);
    SDL_WM_SetCaption("Gestion des événements en SDL", NULL);

    //bg=IMG_Load("lac_en_montagne.bmp");
    //perso=IMG_Load("perso.bmp");
    init_pers(&bg,ecran,"lac_en_montagne.bmp",positionbg);
    init_pers(&perso,ecran,"perso.bmp",positionperso);
    init_pers(&mc,ecran,"mc.jpg",positionmc);

    /* On centre perso à l'écran */
    positionperso.x = 1;
    positionperso.y = ecran->h / 2 - perso->h / 2;



    int continuer = 1;
    SDL_EnableKeyRepeat(1, 1);
    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;
            case SDL_KEYDOWN:
               boucle(event,&positionperso);
                break;
            case SDL_MOUSEMOTION:
                {
                  /*if (positionperso.x < positionmc.x + mc->w && positionperso.x + perso->w > positionmc.x && positionperso.y < positionmc.y + mc->h && positionperso.y + perso->h > positionmc.y)
                    init_pers(&perso,ecran,"mc.jpg",positionperso);
                  else
                    {*/
                      mouse(event,&positionperso);
                   // }
                }
        }
        SDL_BlitSurface(bg, NULL, ecran, &positionbg);
        SDL_BlitSurface(perso, NULL, ecran, &positionperso);
        SDL_Flip(ecran);

    }





    SDL_FreeSurface(perso);
    SDL_FreeSurface(mc);
    SDL_FreeSurface(freeman);
    SDL_Quit();

    return EXIT_SUCCESS;
}

