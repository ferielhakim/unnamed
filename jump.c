#include"jump.h"
void initperso( perso* p)
{
	 p->image[0][0]= IMG_Load("persoright.png");
         p->image[0][1]= IMG_Load("persoright2.png");
         
         p->image[1][0]= IMG_Load("persoleft.png");
         p->image[1][1]= IMG_Load("persoleft1.png");
        
         p->pospersonnage.x=0;
         p->pospersonnage.y=300;
         
         p->img_int=p->image[0][0] ;

	 p->vie[0]=IMG_Load("vie0.png") ; 
	 p->vie[1]=IMG_Load("vie1.png") ; 
	 p->vie[2]=IMG_Load("vie2.png") ; 
	 p->vie[3]=IMG_Load("GameOver.png") ; 
	 p->img=p->vie[0] ;
	 p->s = STAT_SOL;
    	 p->vx = p->vy = 0.0f;
}

void afficher_pers(SDL_Surface* fenetre,perso p) 
{
	SDL_BlitSurface(p.img_int,NULL,fenetre,&p.pospersonnage);
}



void Saute(perso* p,float impulsion)
{
    p->vy = -impulsion;
    p->s = STAT_AIR;
}

void ControleSol(perso* p)
{
    if (p->pospersonnage.y>250.0f)
    {
        p->pospersonnage.y = 250.0f;
        if (p->vy>0)
            p->vy = 0.0f;
        p->s = STAT_SOL;
    }
}

void Gravite(perso* p,float factgravite,float factsautmaintenu,Uint8* keys)
{
    if (p->s == STAT_AIR && keys[SDLK_SPACE])
        factgravite/=factsautmaintenu;
    p->vy += factgravite;
}

void Evolue(perso* p,Uint8* keys)
{
    float lateralspeed = 0.5f;
    float airlateralspeedfacteur = 0.5f;
    float maxhspeed = 3.0f;
    float adherance = 1.5f;
    float impulsion = 6.0f;
    float factgravite = 0.5f;
    float factsautmaintenu = 3.0f;
// controle lateral
    if (p->s == STAT_AIR) // (*2)
        lateralspeed*= airlateralspeedfacteur;
    if (keys[SDLK_LEFT]) // (*1)
        p->vx-=lateralspeed;
    if (keys[SDLK_RIGHT])
        p->vx+=lateralspeed;
    if (p->s == STAT_SOL && !keys[SDLK_LEFT] && !keys[SDLK_RIGHT]) // (*3)
        p->vx/=adherance;
// limite vitesse
    if (p->vx>maxhspeed) // (*4)
        p->vx = maxhspeed;
    if (p->vx<-maxhspeed)
        p->vx = -maxhspeed;
// saut
    if (keys[SDLK_SPACE] && p->s == STAT_SOL)
        Saute(p,impulsion);
    Gravite(p,factgravite,factsautmaintenu,keys);
    ControleSol(p);
// application du vecteur à la position.
    p->pospersonnage.x +=p->vx;
    p->pospersonnage.y +=p->vy;
}

int main(int argc,char** argv)
{
    SDL_Surface* screen;
    int numkeys;
    Uint8 * keys;
    perso p;
    Uint32 timer,elapsed;
    SDL_Init(SDL_INIT_VIDEO);
    screen=SDL_SetVideoMode(400,320,32,SDL_SWSURFACE|SDL_DOUBLEBUF);
    initperso(&p);
    //InitSprite(&S);
    do 
    {
        timer = SDL_GetTicks();
        SDL_FillRect(screen,NULL,0);
        SDL_PumpEvents();
        keys = SDL_GetKeyState(&numkeys);
        Evolue(&p,keys);
	afficher_pers(screen,p) ;
        //Render(&p,screen);
        SDL_Flip(screen);
        elapsed = SDL_GetTicks() - timer;
        if (elapsed<20)
            SDL_Delay(20-elapsed);
    } while (!keys[SDLK_ESCAPE]);
    SDL_Quit();
    return 0;
}

