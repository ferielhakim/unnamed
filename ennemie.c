#include "ennemie.h"

int ennemie( Sprite *sprite )
{

	SDL_Surface *image;
	image = SDL_LoadBMP(fichier); //charger le fichier d image
	sprite->image = loadBmp(image);
	
	SDL_SetColorKey( sprite->image, SDL_SRCCOLORKEY, SDL_MapRGB( sprite->image->format, 255, 255, 255) );

	sprite->anim = 0;
	sprite->anim_courante = 0;// pre anim
	sprite->total_anims = 4;
	

	// chaque animation dure 5 affichages
	sprite->temps_anim = 8;

	// Le temps qu'il reste à afficher l'animation courante
	sprite->temps_anim_courante = 0;

	// On definit ensuite les dimentions du ennemie.
	sprite->largeur = 32 ;
	sprite->hauteur = 32;

	sprite->source.x = sprite->anim_courante * sprite->largeur;
	sprite->source.y = sprite->orientation * sprite->hauteur;
	sprite->source.w = sprite->largeur;
	sprite->source.h = sprite->hauteur;

	sprite->dest.x = 0;
	sprite->dest.y = 0;
	sprite->dest.w = sprite->largeur;
	sprite->dest.h = sprite->hauteur ;

	// on definit enfin la vitesse et la direction du ennemie
	sprite->vitesse = 2;
	sprite->direction = AUCUNE_DIRECTION;

	return 1;
}


void deplacement_ennemie( Sprite *sprite, int direction )
{
	// On affecte la direction au sprite
	sprite->direction = direction;

	// on affecte l'animation correcpondant à la direction au sprite
	if (direction != AUCUNE_DIRECTION)
	{
		sprite->anim = 1;
		switch (direction)
		{
		

		case DIRECTION_DROITE:
			sprite->orientation= DROITE;
			break;

		

		case DIRECTION_GAUCHE:
			sprite->orientation = GAUCHE;
			break;

		default:
			;
		}
	}
	else
		// si le sprite est areté, on ne l'anime pas
		sprite->anim = 0;

	// on met la première animation
	sprite->anim_courante = 0;
	sprite->temps_anim_courante = 0;

	// on regle la source de l'image à copier
	sprite->source.y = sprite->orientation * sprite->hauteur;
	sprite->source.x = sprite->anim_courante * sprite->largeur;
}

void miseAJourSprite( Sprite *sprite )
{
	 if (sprite->direction & DIRECTION_DROITE)
	{
		// on va à droite et on fait attention a ne pas sortie de l'ecran
		sprite->dest.x += sprite->vitesse;
		if (sprite->dest.x + sprite->largeur > LARGEUR_ECRAN)
			sprite->dest.x = LARGEUR_ECRAN - sprite->largeur;
	}
	else  if (sprite->direction & DIRECTION_GAUCHE)
	{
		// on va à gauche et on fait attention a ne pas sortie de l'ecran
		sprite->dest.x -= sprite->vitesse;
		if (sprite->dest.x < 0)
			sprite->dest.x = 0;
	}
}

void afficherSprite( Sprite *sprite, SDL_Surface *destination )
{
	/* si le sprite est animé, on gere l'animation */
	if (sprite->anim)
	{
		// on decremente le temps restant à l'animation courante
		sprite->temps_anim_courante--;
		// et on regarde s'il est temps de changer d'animation
		if ( sprite->temps_anim_courante <= 0 )
		{
			// s'il faut changer, on passe à l'animation suivante
			
                       sprite->anim_courante++;
			// si on était à la dernière animation, on repasse à la première
			
                        if (sprite->anim_courante >= sprite->total_anims)
				sprite->anim_courante = 0;

			// on regle la source à copier
			
                        sprite->source.x = sprite->largeur * sprite->anim_courante;
			sprite->temps_anim_courante = sprite->temps_anim;
		}
	}

	// enfin, on dessine le sprite à l'ecran
	SDL_BlitSurface( sprite->image, &sprite->source, destination, &sprite->dest );
}
void freeSprite( Sprite *sprite )
{
	SDL_FreeSurface( sprite->image );
}
