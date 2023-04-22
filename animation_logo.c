#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_ttf.h>
#include<SDL/SDL_mixer.h>
#include"animation_logo.h"
void init_animation_logo(logo *l)
{

l->tab_logo[0]=IMG_Load("animationlogo/logo1.png");
l->tab_logo[1]=IMG_Load("animationlogo/logo2.png");
l->tab_logo[2]=IMG_Load("animationlogo/logo3.png");
l->tab_logo[3]=IMG_Load("animationlogo/logo4.png");
l->tab_logo[4]=IMG_Load("animationlogo/logo5.png");
l->tab_logo[5]=IMG_Load("animationlogo/logo6.png");
l->tab_logo[6]=IMG_Load("animationlogo/logo7.png");
l->tab_logo[7]=IMG_Load("animationlogo/logo8.png");
l->tab_logo[8]=IMG_Load("animationlogo/logo9.png");
l->pos_logo.x=0;
l->pos_logo.y=0;
l->compteur=0;
l->quitter=0;
}
int animation_logo(logo *l,SDL_Surface *fenetre)
{
while (l->quitter!=3)
{l->compteur++;
if(l->compteur>=90)
{
l->compteur=0;
l->quitter++;
}
/*
if(l->quitter==10)
{l->quitter=1;}
*/

                SDL_BlitSurface(l->tab_logo[l->compteur/10],NULL,fenetre,&l->pos_logo);
SDL_Flip (fenetre);
}
return l->quitter;
}

