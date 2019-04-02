#include"tache1.h"

//pour passer d'un backgroud(de niveau) à un autre il faut qu'un des personnage(deux personnages) resoud l'enigme


void initback( map* map)
{
//creation background
(map->back)=IMG_Load("map.jpg");
(map->backpos).x=0;
(map->backpos).y=0;

}

void afficher_Map(map map,SDL_Surface *ecran,pers*personnage,SDL_Rect camera,SDL_Rect destination)
{
personnage->vie=1;
if(personnage->vie>0)
  {
    SDL_BlitSurface(map.back, &camera, ecran, &destination);
  }
SDL_Flip(ecran);

}

int main
{
//initiation de la video
SDL_Init(SDL_INIT_VIDEO);
if (SDL_Init(SDL_INIT_VIDEO))
fprintf(stderr,"Error SDL : %s\n",SDL_GetError());

//creation fenetre
SDL_Surface *fenetre=NULL;
fenetre=SDL_SetVideoMode(400,563,32,SDL_HWSURFACE);

SDL_FillRect(fenetre,NULL,SDL_MapRGB(fenetre->format,0,0,0));//pour remplir l'ecran
SDL_Flip(fenetre);

initback(map);
afficher_Map(map,ecran,personnage, camera, destination);
return 0;
}
