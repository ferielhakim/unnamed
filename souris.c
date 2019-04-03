#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h> /* Inclusion du header de SDL_image (adapter le dossier au besoin) */
#include "souris.h"
void mouse(SDL_Event event,SDL_Rect* positionperso)
{
                positionperso->x = event.motion.x;
}

