#include<string.h>
#include<stdio.h>
#include"SDL/SDL.h"
#include<SDL/SDL_image.h>
#include"inter.h"
#define LARGEUR_SPRITE 32    
#define HAUTEUR_SPRITE 32
void init_inter( inter* i)
{
	i->rectangle = NULL;
	i->radar=IMG_Load("pos.png");
    	i->rectangle = SDL_CreateRGBSurface(SDL_HWSURFACE, 350, 300, 32, 0, 255, 255, 0);
    
    	i->posradar.x=800;
    	i->posradar.y=580;
    	i->posradar.h=5;
    	i->posradar.w=5;


    	i->position.x = 800; 
    	i->position.y = 520;

}
void affichage_inter( inter i,SDL_Surface* screen)
{
SDL_Event event;
int continuer=1;

while(continuer)
{
int x=100;
SDL_Delay(x);
	if (i.posradar.x<220||i.posradar.y<720)
 	{
	SDL_PollEvent(&event);
	switch(event.type)
	{
    		case SDL_QUIT:
        	continuer = 0;
        	break;
    		case SDL_KEYDOWN:
        		switch(event.key.keysym.sym)
        		{
            		case SDLK_UP:    
                		i.posradar.y=i.posradar.y-1;
                		x = 50;
                		break; 
            		case SDLK_DOWN:
                
                		i.posradar.y=i.posradar.y+1;
                 		x = 50;
                		break;
            		case SDLK_RIGHT:
                		x = 50;
                 		i.posradar.x=i.posradar.x+1;             
                	break;
            		case SDLK_LEFT:
                		i.posradar.x=i.posradar.x-1;
                		x = 50;
                    
                       
                		break;

        		break;
			}
	}


  
    SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format,0,0,60));
    SDL_FillRect(i.rectangle, NULL, SDL_MapRGB(screen->format, 255, 255, 255)); 
    SDL_BlitSurface(i.rectangle, NULL, screen, &i.position); 
    SDL_BlitSurface(i.radar,NULL,screen,&i.posradar);
    SDL_Flip(screen); 
    }

   else
{
   i.posradar.x=0;
   i.posradar.y=580;
}
   }
}
void liberation_inter(inter* i,SDL_Surface* screen )
{
	  SDL_FreeSurface(i->radar);
  	  SDL_FreeSurface(screen);
  	  SDL_FreeSurface(i->rectangle); 
}
int main(int argc, char *argv[])
{
    inter i;
    SDL_Surface *screen = NULL;
    init_inter(&i);
     
    SDL_Init(SDL_INIT_VIDEO);
    screen = SDL_SetVideoMode(1280, 720, 32, SDL_HWSURFACE);
    
affichage_inter(i,screen);
liberation_inter(&i,screen);


    

    return EXIT_SUCCESS;
}




