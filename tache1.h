#include<stdio.h>
#include<stdlib.h>

#include"SDL/SDL.h"
#include"SDL/SDL_image.h"
#include"SDL/SDL_ttf.h"
//cette stuct m'aidera a l'affichage du backgroud
typedef struct pers//personnage + enigme
{
 int vie;//c'est pour un test 

}pers;
//--------------------------------------------
typedef struct back
{
 SDL_Surface* back;
 SDL_Rect backpos;
 SDL_Rect camera;
 SDL_Rect positionecran;
}back;



#ifndef TACHE1_H
#define TACHE1_H


void initback( back* back);
void affichage( back back,SDL_Surface* fenetre,pers personnage);
void liberation_back(back* back);
void initscroll( back* back);
void scroll(back* back, SDL_Surface* screen,char path[],int x);

#endif
