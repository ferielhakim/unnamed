#include<stdio.h>
#include<stdlib.h>

#include"SDL/SDL.h"
#include"SDL/SDL_image.h"
#include"SDL/SDL_ttf.h"
#include"SDL/SDL_mixer.h"
 


#ifndef DEF_CONSTANTES
#define DEF_CONSTANTES//evité les inculsions infinies

#define LARGEUR_FENETRE 800
#define HAUTEUR_FENETRE 600//800 pixel sur 600 pixel 

//jeu
//void jeux(SDL_Surface* ecran);
void menu();
void pause();
int main();
#endif
