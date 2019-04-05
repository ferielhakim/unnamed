#include<stdio.h>
#include<stdlib.h>
#include"SDL/SDL.h"
#include"SDL/SDL_image.h"
#include"SDL/SDL_ttf.h"
#include"SDL/SDL_mixer.h"
 

void pause()
{
    int continuer = 1;
    SDL_Event event;
 
    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
          case SDL_KEYDOWN:
            switch(event.key.keysym.sym)
                {
                  case SDLK_ESCAPE: continuer=0;
                        break;
                }
             break;
        }
    }
}

void jeu();
//fonction du menu
int main()
{

Mix_Music *music;
int continuer=1;
SDL_Event event ;
SDL_Rect positionClic;

putenv("SDL_VIDEO_CENTERED=1");//on centre la fenetre 

//initiation de la video
SDL_Init(SDL_INIT_VIDEO);
if (SDL_Init(SDL_INIT_VIDEO))
fprintf(stderr,"Error SDL : %s\n",SDL_GetError());

//SDL_WM_SetIcon(IMG_Load("icone.jpg"),NULL);//on cree un icone pour le jeux 

//mise en place de la bare caption :nommer la fenetre du jeux 
SDL_WM_SetCaption("THE LOST TREASURE",NULL);

//creation fenetre
SDL_Surface *fenetre=NULL;
fenetre=SDL_SetVideoMode(800,600,32,SDL_HWSURFACE);

SDL_FillRect(fenetre,NULL,SDL_MapRGB(fenetre->format,255,255,255));//pour remplir l'ecran
SDL_Flip(fenetre);


//creation background
SDL_Surface* background[8];
SDL_Surface* backgroundjeux;
background[0]=IMG_Load("menujeu.png");



SDL_Rect backgroundpos;
backgroundpos.x=0;
backgroundpos.y=0;
SDL_BlitSurface(background[0],NULL,fenetre,&backgroundpos);
SDL_Flip(fenetre);



background[1]=IMG_Load("menu play.png");
background[2]=IMG_Load("menu settings.png");
background[3]=IMG_Load("menu quit.png");
background[4]=IMG_Load("set.png");
background[5]=IMG_Load("set.png");
background[6]=IMG_Load("set.png");
background[7]=IMG_Load("set.png");
background[8]=IMG_Load("set.png");

//initialiser le son
if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS, 1024) == -1) //Initialisation de l'API Mixer
   {
      printf("%s", Mix_GetError());
   }
Mix_Music *musique; //Création du pointeur de type Mix_Music

musique = Mix_LoadMUS("ww");
Mix_PlayMusic(musique,-1);//pour répeter infiniment

int x;
while (continuer)
{
  SDL_PollEvent(&event);
  switch (event.type)
        {
        case SDL_QUIT:
               continuer=0;
               break;
        case SDL_KEYDOWN:
               switch(event.key.keysym.sym)
                     {
                     case SDLK_ESCAPE:
                          exit(0);
                          break;
                  //...            
                     }
	case SDL_MOUSEMOTION: 
                 if ( event.motion.x>82 && event.motion.x<247 && event.motion.y>205 && event.motion.y<291 )
        		{
			SDL_BlitSurface(background[1],NULL,fenetre,&backgroundpos);
			SDL_Flip(fenetre);
			}
		else if ( event.motion.x>62 && event.motion.x<252.007 && event.motion.y>319 && event.motion.y<391 )
			{
			x=2 ; 
			SDL_BlitSurface(background[2],NULL,fenetre,&backgroundpos);
			SDL_Flip(fenetre);
			}
		else if ( event.motion.x>55 && event.motion.x<254 && event.motion.y>429 && event.motion.y<505  )
			{
			SDL_BlitSurface(background[3],NULL,fenetre,&backgroundpos);
			SDL_Flip(fenetre);
			}

	break;
        case SDL_MOUSEBUTTONUP :
              	if ( event.button.button==SDL_BUTTON_LEFT)
             	       {
              	       positionClic.x=event.button.x;
               	       positionClic.y=event.button.y;
		       music = Mix_LoadMUS("SA FAIS CLIC CLIC.mp3"); //Chargement de la musique
		       //repetition de la musique
		       Mix_PlayMusic(music, 1);
              		if ( event.button.x>82 && event.button.x<247 && event.button.y>205 && event.button.y<291 )//boutton play
                   	    {
			    SDL_FreeSurface(background[1]);
                     	    SDL_BlitSurface(backgroundjeux,NULL,fenetre,&backgroundpos);
                     	    SDL_Flip(fenetre);
                     	     jeu();
                      	    }
                	else if( event.button.x>62 &&  event.button.x<252.007 && event.button.y>319 && event.button.y<391 )//setting
               	      	    {
                            SDL_BlitSurface(background[4],NULL,fenetre,&backgroundpos);
                            SDL_Flip(fenetre);
			    switch (event.type)
                    		 {
                      	 	 case SDL_MOUSEMOTION:
                         	   	{
                           		if(event.motion.x>70 && event.motion.x<220 && event.motion.y>290 && event.motion.y<340)
                              			{
                                		SDL_BlitSurface(background[5],NULL,fenetre,&backgroundpos);
                                                SDL_Flip(fenetre);
                              			}
                            		else if(event.motion.x>102 && event.motion.y<184 && event.motion.y>408 && event.motion.y<472)
                              			{
                                		SDL_BlitSurface(background[6],NULL,fenetre,&backgroundpos);
                                                SDL_Flip(fenetre);
                              			}
					else if(event.motion.x>102 && event.motion.y<184 && event.motion.y>408 && event.motion.y<472)
                              			{
                                		SDL_BlitSurface(background[7],NULL,fenetre,&backgroundpos);
                                                SDL_Flip(fenetre);
                              			}
					else if(event.motion.x>102 && event.motion.y<184 && event.motion.y>408 && event.motion.y<472)
                              			{
                                		SDL_BlitSurface(background[8],NULL,fenetre,&backgroundpos);
                                                SDL_Flip(fenetre);
                              			}
                         		 }
                          	break;
                    	 }
                        pause();
                  
  }
                        else if( event.button.x>55 && event.button.x<254 && event.button.y>429 && event.button.y<505 )//quitter
                	 {
Mix_Music *music;
int continuer=1;
SDL_Event event ;
SDL_Rect positionClic;

putenv("SDL_VIDEO_CENTERED=1");//on centre la fenetre 

//initiation de la video
SDL_Init(SDL_INIT_VIDEO);
if (SDL_Init(SDL_INIT_VIDEO))
fprintf(stderr,"Error SDL : %s\n",SDL_GetError());

SDL_WM_SetIcon(IMG_Load("icone.jpg"),NULL);//on cree un icone pour le jeux 

//mise en place de la bare caption :nommer la fenetre du jeux 
SDL_WM_SetCaption("THE LOST TREASURE",NULL);

//creation fenetre
SDL_Surface *fenetre=NULL;
fenetre=SDL_SetVideoMode(800,600,32,SDL_HWSURFACE);

SDL_FillRect(fenetre,NULL,SDL_MapRGB(fenetre->format,255,255,255));//pour remplir l'ecran
SDL_Flip(fenetre);


//creation background
SDL_Surface* background[9];
SDL_Surface* backgroundjeux;
background[0]=IMG_Load("menu.png");



SDL_Rect backgroundpos;
backgroundpos.x=0;
backgroundpos.y=0;
SDL_BlitSurface(background[0],NULL,fenetre,&backgroundpos);
SDL_Flip(fenetre);



background[1]=IMG_Load("menu play.png");
background[2]=IMG_Load("menu settings.png");
background[3]=IMG_Load("menu quit.png");
background[4]=IMG_Load("set.png");
background[5]=IMG_Load("set.png");
background[6]=IMG_Load("set.png");
background[7]=IMG_Load("set.png");
background[8]=IMG_Load("set.png");

//initialiser le son
if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS, 1024) == -1) //Initialisation de l'API Mixer
   {
      printf("%s", Mix_GetError());
   }

int x;
while (continuer)
{
  SDL_PollEvent(&event);
  switch (event.type)
        {
        case SDL_QUIT:
               continuer=0;
               break;
        case SDL_KEYDOWN:
               switch(event.key.keysym.sym)
                     {
                     case SDLK_ESCAPE:
                          exit(0);
                          break;
                  //...            
                     }
	case SDL_MOUSEMOTION: 
                 if ( event.motion.x>82 && event.motion.x<247 && event.motion.y>205 && event.motion.y<291 )
        		{
			SDL_BlitSurface(background[1],NULL,fenetre,&backgroundpos);
			SDL_Flip(fenetre);
			}
		else if ( event.motion.x>62 && event.motion.x<252.007 && event.motion.y>319 && event.motion.y<391 )
			{
			x=2 ; 
			SDL_BlitSurface(background[2],NULL,fenetre,&backgroundpos);
			SDL_Flip(fenetre);
			}
		else if ( event.motion.x>55 && event.motion.x<254 && event.motion.y>429 && event.motion.y<505  )
			{
			SDL_BlitSurface(background[3],NULL,fenetre,&backgroundpos);
			SDL_Flip(fenetre);
			}

	break;
        case SDL_MOUSEBUTTONUP :
              	if ( event.button.button==SDL_BUTTON_LEFT)
             	       {
              	       positionClic.x=event.button.x;
               	       positionClic.y=event.button.y;
		       music = Mix_LoadMUS("SA FAIS CLIC CLIC.mp3"); //Chargement de la musique
		       //repetition de la musique
		       Mix_PlayMusic(music, 1);
              		if ( event.button.x>82 && event.button.x<247 && event.button.y>205 && event.button.y<291 )//boutton play
                   	    {
			    SDL_FreeSurface(background[1]);
                     	    SDL_BlitSurface(backgroundjeux,NULL,fenetre,&backgroundpos);
                     	    SDL_Flip(fenetre);
                     	    //jouer(ecran);
                      	    }
                	else if( event.button.x>62 &&  event.button.x<252.007 && event.button.y>319 && event.button.y<391 )//setting
               	      	    {
                            SDL_BlitSurface(background[4],NULL,fenetre,&backgroundpos);
                            SDL_Flip(fenetre);
			    switch (event.type)
                    		 {
                      	 	 case SDL_MOUSEMOTION:
                         	   	{
                           		if(event.motion.x>70 && event.motion.x<220 && event.motion.y>290 && event.motion.y<340)
                              			{
                                		SDL_BlitSurface(background[5],NULL,fenetre,&backgroundpos);
                                                SDL_Flip(fenetre);
                              			}
                            		else if(event.motion.x>102 && event.motion.y<184 && event.motion.y>408 && event.motion.y<472)
                              			{
                                		SDL_BlitSurface(background[6],NULL,fenetre,&backgroundpos);
                                                SDL_Flip(fenetre);
                              			}
					else if(event.motion.x>102 && event.motion.y<184 && event.motion.y>408 && event.motion.y<472)
                              			{
                                		SDL_BlitSurface(background[7],NULL,fenetre,&backgroundpos);
                                                SDL_Flip(fenetre);
                              			}
					else if(event.motion.x>102 && event.motion.y<184 && event.motion.y>408 && event.motion.y<472)
                              			{
                                		SDL_BlitSurface(background[8],NULL,fenetre,&backgroundpos);
                                                SDL_Flip(fenetre);
                              			}
                         		 }
                          	break;
                    	 }
                        pause();
                  
  }
                        else if( event.button.x>55 && event.button.x<254 && event.button.y>429 && event.button.y<505 )//quitter
                	 {exit(0);}
                
           	    	}
	break;
	}
SDL_FillRect(fenetre,NULL,SDL_MapRGB(fenetre->format,0,0,0));//pour remplir l'ecran
SDL_BlitSurface(background[0],NULL,fenetre,&backgroundpos);
SDL_Flip(fenetre);//mettre le menu a jour avant de fermer la boucle 
}
SDL_FreeSurface(background[9]);
SDL_FreeSurface(fenetre);
TTF_Quit();

Mix_FreeMusic(musique);
Mix_CloseAudio();
SDL_Quit();
}}
                
           	    	}
	break;
	}
SDL_FillRect(fenetre,NULL,SDL_MapRGB(fenetre->format,0,0,0));//pour remplir l'ecran
SDL_BlitSurface(background[0],NULL,fenetre,&backgroundpos);
SDL_Flip(fenetre);//mettre le menu a jour avant de fermer la boucle 
}




Mix_FreeMusic(musique);
Mix_CloseAudio();

}


return 0;

}
//******************************************************************

