#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>




int main ()
{
	SDL_Surface *screen=NULL;
	SDL_Surface *background;
	SDL_Rect positionecran;
	SDL_Rect positionbackground;
	SDL_Event e;
	int continuer=1;

	SDL_Init(SDL_INIT_EVERYTHING);
	
	background=IMG_Load("map final 1.jpg");


	SDL_Rect camera ;
	camera.x=0;
	camera.y=0;
	camera.w=8000 ;
	camera.h=420;
         screen = SDL_SetVideoMode(800,600, 32, SDL_HWSURFACE);
   
	while(continuer)
	{		SDL_BlitSurface(background,&camera,screen,NULL);
		SDL_Flip(screen);
		SDL_Delay(100);
		while(SDL_PollEvent(&e));
    switch(e.type)
    {
    	case SDL_KEYDOWN:
    	{
  	switch(e.key.keysym.sym)
		    	 {
                   case SDLK_LEFT:
                   camera.x-=100;
                   break;
                   case SDLK_RIGHT:
                   camera.x+=100;
                   break;
		    	 }
	
	}
	if(camera.x>=720)
		camera.x=720;
	if(camera.x<=0)
		camera.x=0;
	}	    	 
 	}

	SDL_Quit();
return 0;
}
