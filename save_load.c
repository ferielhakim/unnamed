/**

*@file save_load.c
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
#include "save_load.h"


/**
* @brief To save game
* @param j player
* @param c camera axe
* @return Nothing
*/



void save(joueur j,int c)
{
FILE *fp=NULL;
fp=fopen("save.txt","w");
if(fp==NULL)
{
printf("erreur de sauvegarde");
}
else
{
fprintf(fp,"%d %d %d %d %d",j.pospersonnage.x,j.pospersonnage.y,j.vie,j.score,c);

}
fclose(fp);
}

/**
* @brief To load game
* @param j player
* @param c camera axe
* @return Nothing
*/

void load(joueur j,int c)
{
FILE *fp=NULL;
fp=fopen("save.txt","r");
if(fp==NULL)
{
printf("erreur de load");
}
else
{
fscanf(fp,"%hi %hi %d %d %d",&j.pospersonnage.x,&j.pospersonnage.y,&j.vie,&j.score,&c);
}
fclose(fp);
}



