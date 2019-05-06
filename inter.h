#include<stdio.h>
#include<stdlib.h>

#include"SDL/SDL.h"
#include"SDL/SDL_image.h"

typedef struct inter
{
 SDL_Surface* radar;
 SDL_Rect posradar;
 SDL_Surface* rectangle;
 SDL_Rect position;
}inter;

void init_inter( inter* i);
void affichage_inter( inter i,SDL_Surface* screen);
void liberation_inter(inter* i,SDL_Surface* screen );


