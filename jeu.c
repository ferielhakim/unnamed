#include<stdio.h>
#include<stdlib.h>
#include"SDL/SDL.h"
#include"SDL/SDL_image.h"
#include"SDL/SDL_ttf.h"
#include"SDL/SDL_mixer.h"
#include"collision.h"
#include"jeu.h"
#include"tache1.h"
#include"player.h"
#include"obstacle.h"



void jeu()
{


int continuer=1;
int timemort=5;
//initiation
SDL_Init(SDL_INIT_VIDEO);
if (SDL_Init(SDL_INIT_VIDEO))
fprintf(stderr,"Error SDL : %s\n",SDL_GetError());


//creation fenetre
SDL_Surface *fenetre=NULL;
fenetre=SDL_SetVideoMode(807,720,32,SDL_HWSURFACE);

SDL_FillRect(fenetre,NULL,SDL_MapRGB(fenetre->format,0,0,0));
SDL_Flip(fenetre);

Background map ;
SDL_Rect camera_pos;
initback(& map,&camera_pos) ;
SDL_BlitSurface(map.back,NULL,fenetre,&map.backpos);





//initialisation obstacle et affichage
obstacle ob;
obstacle ob1;
obstacle ob2;



initialiser_obstacle(&ob);
initialiser_obstacle1(&ob1);
initialiser_obstacle2(&ob2);

afficher_obstacle(ob,SDL_Surface* map,SDL_Surface *ecran)
player p;
 initializePlayer(&p)


SDL_BlitSurface(map.image,NULL,fenetre,&map.sprite);
//boucle du jeu

while(continuer)
{
SDL_Event event;
SDL_WaitEvent(&event);

if(event.type==SDL_QUIT)
{
continuer=0;
break;
}





else if(event.type==SDL_KEYDOWN){
  if(event.key.keysym.sym==SDLK_RIGHT){
if((p.Sprite.x>=400)&&(camera_pos.x<473))
{

camera_pos.x+=50;
ob.obstacle_pos.x-=10;
ob1.obstacle_pos.x-=10;
ob2.obstacle_pos.x-=10;

}
else
{

             p.Sprite.x+=50;

}


 if ( p.scrn.x ==202)
            p.scrn.x =303;
          else
            p.scrn.x=202;


if(collision(map,p.sprite,ob.obstacle_pos.x,0)==1)||(collision(map,p.sprite,ob.obstacle_pos.x,0)==1))||(collision(map,p.sprite,ob.obstacle_pos.x,0)==1))
{

timerMort--;;
p.Sprite.x-=150;


}

if(timerMort==0)
{
continuer=0;
}




}

  else if(event.key.keysym.sym==SDLK_LEFT){
if(camera_pos.x>0)
{

camera_pos.x-=50;
ob.obstacle_pos.x+=10;
ob1.obstacle_pos.x+=10;
ob2.obstacle_pos.x+=10;
}

else
{
          p.Sprite.x -=50;
}



if (p.scrn.x==0)
            p.scrn.x=95.72;
          else
            p.scrn.x =0;


if((collision(p.Sprite,ob.obstacle_pos)==1)||(collision(p.Sprite,ob1.obstacle_pos)==1)||(collision(p.Sprite,ob2.obstacle_pos)==1))
{

timerMort--;
p.Sprite.x+=150;

}

if(timerMort==0)
{
continuer=0;
}



}
 if ( p.Sprite.x < 0 ) {
      p.Sprite.x = 0;
    }
    else if ( p.Sprite.x > 807-95.72) {
     p.Sprite.x =  807-95.72;
    }



}

else if(event.key.keysym.sym==SDLK_UP)
{


p.Sprite.y-=30;






}
else if(event.key.keysym.sym==SDLK_DOWN)
{


p.Sprite.y+=30;






}










afficher(fenetre,p);
blitBackground(map,fenetre,camera_pos);
afficher_obstacle(fenetre,ob);
afficher_obstacle(fenetre,ob1);
afficher_obstacle(fenetre,ob2);


}




SDL_FreeSurface(fenetre);
freeBackground(&map);

liberer_player(&p) ; 
SDL_Quit();


}

