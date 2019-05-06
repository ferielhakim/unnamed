#ifndef SAVE_LOAD_DEFINED
#define SAVE_LOAD_H_INCLUDED
/**

*@file save_load.h
* @brief save and load
* @author Invicta
* @version 0.1
* @date Apr 29, 2019
*/

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
/**
@struct joueur
* @brief struct for player
*/
typedef struct joueur joueur;
struct joueur
{
SDL_Surface *personnage; /*!< Surface*/
SDL_Rect pospersonnage ; /*!< Rectangle*/
int vie ;           /*!< Life*/
int score ; /*!< Score*/
SDL_Rect  spriteSrc;   /*!< Rectangle*/
};




 
void save(joueur j,int c);
void load(joueur j,int c);

#endif
