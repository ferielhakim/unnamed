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
 int enigme1;
 int enigme2;
 int enigme3;
 int vie=1;//c'est pour un test 

}pers;
//--------------------------------------------
typedef struct back
{
 SDL_Surface* back1;
 SDL_Surface* back2;
 SDL_Surface* back3;
 SDL_Surface* con;
 SDL_Surface* lost;

 SDL_Rect backpos1;
 SDL_Rect backpos2;
 SDL_Rect backpos3;
 SDL_Rect conpos;
 SDL_Rect lostpos;
}back;



#ifndef TACHE1_H
#define TACHE1_H


void initback( back* back);
void affichage( back back,SDL_Surface* fenetre,per personnage);
#endif
