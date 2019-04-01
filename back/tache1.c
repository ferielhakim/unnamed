#include"tache1.h"

//pour passer d'un backgroud(de niveau) à un autre il faut qu'un des personnage(deux personnages) resoud l'enigme


void initback( back* back)
{
//creation background
back1=IMG_Load("city.png");
back2=IMG_Load("forest.png");
back3=IMG_Load("beach.png");
con3=IMG_Load("con.png");
lost=IMG_Load("lost.png");

backpos1->x=0;
backpos1->y=0;

backpos2->x=0;
backpos2->y=0;

backpos3->x=0;
backpos3->y=0;

conpos->x=0;
conpos->y=0;

lostpos->x=0;
lostpos->y=0;

}

void affichage( back back,SDL_Surface* fenetre,pers personnage,eni enigme)
{
if(personnage->vie>0)
  {
  if(personnage->enigme1==0)//personnage.enigme==0 sig si pers n'a pas resolu l'enigme 
  {
  SDL_BlitSurface(back1,NULL,fenetre,&backpos1);
  }

  //de meme pour les autres

  else if (personnage->enigme1==1)//personnage.enigme==0 sig si pers a resolu l'enigme
  {
  SDL_BlitSurface(back2,NULL,fenetre,&backpos2);
  }
  else if (personnage->enigme2==0)
  {
  SDL_BlitSurface(back2,NULL,fenetre,&backpos3);
  }
  else if (personnage->enigme2==1)
  {
  SDL_BlitSurface(back3,NULL,fenetre,&backpos3);
  }
  else if (personnage->enigme3==0)
  {
  SDL_BlitSurface(back3,NULL,fenetre,&backpos3);
  }
  else if (personnage->enigme3==1)
  {
  SDL_BlitSurface(con,NULL,fenetre,&conpos);//il a gagné
  }
else 
{
SDL_BlitSurface(lost,NULL,fenetre,&lostpos);
}

}
SDL_Flip(fenetre);

}


