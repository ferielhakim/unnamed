#include<stdio.h>
#include<stdlib.h>

#include"SDL/SDL.h"
#include"SDL/SDL_image.h"
#include"SDL/SDL_ttf.h"
//cette stuct m'aidera a l'affichage du backgroud
typedef struct pers//personnage + enigme
{
 SDL_Surface* pers;
 SDL_Rect perspos;
 int vie;//c'est pour un test 

}pers;
//--------------------------------------------
typedef struct map
{
 SDL_Surface back;
 SDL_Rect backpos;
}map;



#ifndef TACHE1_H
#define TACHE1_H

void initialiser_Map(map* map);
void afficher_Map(map map,SDL_Surface *ecran,pers*personnage,SDL_Rect camera,SDL_Rect destination);

//void initback( back* back);
//void affichage( back back,SDL_Surface* fenetre,pers personnage);
#endif
//*******************************


