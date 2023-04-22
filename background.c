#include "background.h"

void initBackground(Background* backgroundScrolling,char* nom,int x)
{
    backgroundScrolling->background = IMG_Load(nom);
    backgroundScrolling->backgroundPosition1->x = x;
    backgroundScrolling->backgroundPosition1->y = 0;
    backgroundScrolling->backgroundPosition1->h = 0;
    backgroundScrolling->backgroundPosition1->w = 0;
}
 
void scrolling (Background* backgroundScrolling,int rapidite)
{
 
    //speed of Scrolling background
    backgroundScrolling->backgroundPosition1->x -= rapidite;
    
    // //If the background has gone too far
    if( backgroundScrolling->backgroundPosition1->x <= -backgroundScrolling->background->w )
    {
        //Reset the offset
        backgroundScrolling->backgroundPosition1->x = 0;
   
    }
}

void afficherBackground (Background* backgroundScrolling, SDL_Surface * screen)
{
    SDL_Rect offset , offset1;
    offset.x = backgroundScrolling->backgroundPosition1->x;
    offset.y = backgroundScrolling->backgroundPosition1->y;
    SDL_BlitSurface(backgroundScrolling->background,NULL,screen,&offset);
    offset1.x = backgroundScrolling->backgroundPosition1->x + backgroundScrolling->background->w;
    offset1.y = backgroundScrolling->backgroundPosition1->y;
    SDL_BlitSurface(backgroundScrolling->background,NULL,screen,&offset1);
    
}

void init_Partage_ecran(Background* backgroundScrolling)
{
    //intialisation de la position 1
    backgroundScrolling->background = IMG_Load( "Partage.png");
    backgroundScrolling->backgroundPosition1->x = 0;
    backgroundScrolling->backgroundPosition1->y = 0;
    backgroundScrolling->backgroundPosition1->h = 600;
    backgroundScrolling->backgroundPosition1->w = 1200;
    //intialisation de la position 2
     backgroundScrolling->backgroundPosition2->x = 0;
    backgroundScrolling->backgroundPosition2->y = 0;
    backgroundScrolling->backgroundPosition2->h = 600;
    backgroundScrolling->backgroundPosition2->w = 1200;

}



void scrolling_partage (Background* backgroundScrolling)
 {
     //speed of Scrolling background
     backgroundScrolling->backgroundPosition1->x -= 3;
     backgroundScrolling->backgroundPosition2->x -= 3;

    
         // //If the background has gone too far
     if(( backgroundScrolling->backgroundPosition1->x <= -backgroundScrolling->background->w ) && 
        ( backgroundScrolling->backgroundPosition2->x <= -backgroundScrolling->background->w ))
     {
         //Reset the offset
        backgroundScrolling->backgroundPosition1->x = 0;
        backgroundScrolling->backgroundPosition2->x = 0;
   
    }
 }

void afficherBackground_partage (Background* backgroundScrolling , SDL_Surface *screen )
{
    SDL_Rect offset;
    SDL_Rect offset1;
    offset.x = backgroundScrolling->backgroundPosition1->x;
    offset.y = backgroundScrolling->backgroundPosition1->y;
    offset1.x = backgroundScrolling->backgroundPosition2->x;
    offset1.y = backgroundScrolling->background->h;
    SDL_BlitSurface(backgroundScrolling->background,NULL,screen,&offset);
    SDL_BlitSurface(backgroundScrolling->background,NULL,screen,&offset1);
    offset.x = backgroundScrolling->backgroundPosition1->x + backgroundScrolling->background->w;
    offset.y = backgroundScrolling->backgroundPosition1->y;
    offset1.x = backgroundScrolling->backgroundPosition2->x + backgroundScrolling->background->w;
    offset1.y = backgroundScrolling->background->h;
    SDL_BlitSurface(backgroundScrolling->background,NULL,screen,&offset);
    SDL_BlitSurface(backgroundScrolling->background,NULL,screen,&offset1);

}




