#ifndef BACKGROUND_H_INCLUDED
#define BACKGROUND_H_INCLUDED
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
typedef struct Background
{
   SDL_Rect* backgroundPosition1;
   SDL_Rect* backgroundPosition2;
   SDL_Surface* background ;

}Background;

void initBackground(Background* backgroundScrolling,char* nom,int x);
void scrolling (Background* backgroundScrolling,int rapidite);
void afficherBackground (Background* backgroundScrolling,  SDL_Surface * screen);
//PARTAGE ECRAN :
void init_Partage_ecran(Background* backgroundScrolling);
void scrolling_partage (Background* backgroundScrolling);
void afficherBackground_partage (Background* backgroundScrolling , SDL_Surface *screen );

#endif
