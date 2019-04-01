#include<stdio.h>
#include<stdlib.h>

#include"SDL/SDL.h"
#include"SDL/SDL_image.h"
#include"SDL/SDL_ttf.h"
#include"SDL/SDL_mixer.h"
#include"SDL/SDL_getenv.h"

typedef struct vie
{
 SDL_Surface* image[5];
 int val;
 SDL_Rect position;
}vie;



#ifndef VIE_H
#define VIE_H


void initvie (vie *vie );
void mise(vie* v,int chest);
void displayvie(vie v, SDL_Surface* fenetre);
void liberation_vie(vie* v);

#endif // vie_H
