#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "SDL/SDL.h"
#define DROITE	1
#define GAUCHE	3
#define AUCUNE_DIRECTION	0
#define DIRECTION_DROITE	2
#define DIRECTION_GAUCHE	8
#define LARGEUR_ECRAN 600
#define HAUTEUR_ECRAN 800

typedef struct
{
	SDL_Surface *image;
	SDL_Rect source;
	SDL_Rect dest;
	int largeur;
	int hauteur;
	int direction;
	int vitesse;
	int anim;
	int orientation;
	int anim_courante;
	int temps_anim;
	int temps_anim_courante;
	int total_anims;

}Sprite;

int ennemie( Sprite *sprite );
void deplacement_ennemie( Sprite *sprite, int direction );
void miseAJourSprite( Sprite *sprite );
void afficherSprite( Sprite *sprite, SDL_Surface *destination );
void freeSprite( Sprite *sprite );