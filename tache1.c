 #include"tache1.h"

//pour passer d'un backgroud(de niveau) à un autre il faut qu'un des personnage(deux personnages) resoud l'enigme


void initback( back* back)
{
//creation background
back->back=IMG_Load("map final 1.jpg");

back->backpos.x=0;
back->backpos.y=0;

}


void affichage( back back,SDL_Surface* fenetre,pers personnage)
{
personnage.vie=1;
if(personnage.vie>0)
  SDL_BlitSurface((back.back),NULL,fenetre,&(back.backpos));
SDL_Flip(fenetre);

}
void liberation_back(back* back)
{
SDL_FreeSurface(back->back);
}

void scroller_background(back back,int d/*,ennemie *e,ennemie *e1*/)
{
  if(d==0)
  {
    if(back.camera.x<8000-250 )
    {
	back.camera.x+=10;
	/*e->position.x-=10;
	e1->position.x-=10;*/
    }
  }
  else if(d==1)
  {
	if(back.camera.x>0)
        {
		back.camera.x-=10;
   	        /*e->position.x+=10;
    		e1->position.x+=10;*/
    	}
  }
}


int main ()
{
back back;
back.back=IMG_Load("map final 1.jpg");
SDL_Surface *fenetre=NULL;
pers personnage;

//initiation de la video
SDL_Init(SDL_INIT_VIDEO);
if (SDL_Init(SDL_INIT_VIDEO))
fprintf(stderr,"Error SDL : %s\n",SDL_GetError());

putenv("SDL_VIDEO_CENTERED=1");//on centre la fenetre 

//creation fenetre
fenetre=SDL_SetVideoMode(704,430,32,SDL_HWSURFACE);
SDL_Flip(fenetre);

SDL_FillRect(fenetre,NULL,SDL_MapRGB(fenetre->format,0,0,0));//pour remplir l'ecran
//initialsation du personnage et son evennement 
SDL_Surface *perso;
SDL_Rect pospersonnage;
SDL_Event event;

int done=1,continuer=1;
perso=IMG_Load("pers.png");

pospersonnage.x=50;
pospersonnage.y=250;

initback(&back);
affichage(back,fenetre,personnage);
liberation_back(&back);
SDL_Delay(1000);
int d=1;
/*scroller_background(back,d);*/

while(continuer)
{
SDL_PollEvent(&event);
switch(event.type)
{
    case SDL_QUIT:
        continuer = 0;
        break;
    case SDL_KEYDOWN:
        switch(event.key.keysym.sym)
        {   case SDLK_ESCAPE:
             continuer=0;
             break;
            case SDLK_UP:
                pospersonnage.y--;
                break;
            case SDLK_DOWN:
                pospersonnage.y++;
                break;
            case SDLK_RIGHT:
                pospersonnage.x++;
                break;
            case SDLK_LEFT:
                pospersonnage.x--;
                break;
        }
        break;
}
if ((pospersonnage.x>0)||(pospersonnage.y>0)) { d=1; } else { d=0;}
/*SDL_FillRect(fenetre, NULL, SDL_MapRGB(fenetre->format, 0, 0, 0));
affichage(back,fenetre,personnage);*/
SDL_BlitSurface(perso,NULL,fenetre,&pospersonnage);
scroller_background(back,d);
SDL_Flip(fenetre);
}
while(done)
{
SDL_PollEvent(&event);
switch(event.type)
{
case SDL_QUIT:
done=0;
break;
case SDL_KEYDOWN:
if(event.key.keysym.sym==SDLK_ESCAPE)
done=0;
break;
}
}


}

