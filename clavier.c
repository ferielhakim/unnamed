#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h> /* Inclusion du header de SDL_image (adapter le dossier au besoin) */
#include "clavier.h"
void boucle(SDL_Event event,SDL_Rect* positionperso)
{
                switch(event.key.keysym.sym)
                {
                    case SDLK_RIGHT: // Fl�che droite
                        positionperso->x++;
                        break;
                    case SDLK_LEFT: // Fl�che gauche
                        positionperso->x--;
                        break;
                }


}
