#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h> /* Inclusion du header de SDL_image (adapter le dossier au besoin) */
#include "personnages_init.h"
void init_pers(SDL_Surface** img,SDL_Surface* ecran,char place[20],SDL_Rect pos)
{
    (*img) = IMG_Load(place);
    SDL_BlitSurface((*img), NULL, ecran, &pos);

}
