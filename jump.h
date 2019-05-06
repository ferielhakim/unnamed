#include<string.h>
#include<stdio.h>
#include"SDL/SDL.h"
#include<SDL/SDL_image.h>

#define STAT_SOL 0
#define STAT_AIR 1

typedef struct perso

{
SDL_Surface* image[2][2];
SDL_Surface* img_int;
SDL_Rect pospersonnage;
SDL_Surface *vie[4];
SDL_Surface *img;
float vx,vy;
int s;
}perso;


void initperso( perso* p);
void afficher_pers(SDL_Surface* fenetre,perso p) ;
void Saute(perso* p,float impulsion);
void ControleSol(perso* p);
void Gravite(perso* p,float factgravite,float factsautmaintenu,Uint8* keys);
void Evolue(perso* p,Uint8* keys);








