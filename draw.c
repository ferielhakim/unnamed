
#include "draw.h"


void drawImage(SDL_Surface *image, int x, int y)
{
	SDL_Rect dest;

	/* Règle le rectangle à blitter selon la taille de l'image source */
	dest.x = x;
	dest.y = y;
	dest.w = image->w;
	dest.h = image->h;

	/* Blitte l'image entière sur l'écran aux coordonnées x et y */
	SDL_BlitSurface(image, NULL, jeu.screen, &dest);
}


void drawTile(SDL_Surface *image, int destx, int desty, int srcx, int srcy)
{
    /* Rectangle de destination à blitter */
	SDL_Rect dest;

	dest.x = destx;
	dest.y = desty;
	dest.w = TILE_SIZE;
	dest.h = TILE_SIZE;

	/* Rectangle source à blitter */
	SDL_Rect src;

	src.x = srcx;
	src.y = srcy;
	src.w = TILE_SIZE;
	src.h = TILE_SIZE;

	/* Blitte la tile choisie sur l'écran aux coordonnées x et y */
	SDL_BlitSurface(image, &src, jeu.screen, &dest);
}


void draw(void)
{

    int i;

    /* Affiche le fond (background) aux coordonnées (0,0) */
    drawImage(map.background, 0, 0);

    /* Affiche la map de tiles */
    drawMap();