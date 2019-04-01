#include"vie.h"

void initvie(vie* v)
{

v->position.x=0;
v->position.y=0;

v->val=0;

v->image[0]=IMG_Load("vie4.png");
v->image[1]=IMG_Load("vie3.png");
v->image[2]=IMG_Load("vie2.png");
v->image[3]=IMG_Load("vie1.png");
v->image[4]=IMG_Load("game over.jpeg");

}

void mise(vie* v,int chest)
{
if(chest && v->val <5) 
(v->val)++;
}
void displayvie(vie v, SDL_Surface* fenetre)
{
SDL_BlitSurface(v.image[v.val],NULL,fenetre,&v.position);
}
void liberation_vie(vie* v)
{
SDL_FreeSurface(v->image[0]);
SDL_FreeSurface(v->image[1]);
SDL_FreeSurface(v->image[2]);
SDL_FreeSurface(v->image[3]);
SDL_FreeSurface(v->image[4]);
}
/*int main()
{
vie v;
int chest=4;
putenv("SDL_VIDEO_CENTERED=1");//on centre la fenetre 

//initiation de la video
SDL_Init(SDL_INIT_VIDEO);
if (SDL_Init(SDL_INIT_VIDEO))
fprintf(stderr,"Error SDL : %s\n",SDL_GetError());

//creation fenetre
SDL_Surface *fenetre=NULL;
fenetre=SDL_SetVideoMode(704,704,32,SDL_HWSURFACE);

SDL_FillRect(fenetre,NULL,SDL_MapRGB(fenetre->format,255,255,255));//pour remplir l'ecran
SDL_Flip(fenetre);

initvie(&v);
mise(&v,chest);
displayvie(v,fenetre);
liberation_vie(&v);
SDL_Delay(30000);
SDL_Quit();
}*/
