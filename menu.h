#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_ttf.h>
#include<SDL/SDL_mixer.h>
typedef struct
{
  SDL_Surface *background;
  SDL_Surface *solo;
  SDL_Surface *duo;
  SDL_Surface *quit;
  SDL_Surface *boutton_active;
  SDL_Surface *quit_active;
  SDL_Surface *text1;
  SDL_Surface *text2;
  SDL_Rect backgroundpos;
  SDL_Rect solopos;
  SDL_Rect duopos;
  SDL_Rect quitpos;
  SDL_Rect solopos_active;
  SDL_Rect duopos_active;
  SDL_Rect quitpos_active;
  SDL_Rect text1pos;
  SDL_Rect text2pos;
}menu_jouer;
void init_menu_multiplayer (menu_jouer *j);
void affichage_menu_multiplayer ( menu_jouer j , SDL_Surface *screen ,int x  ) ;
int update_menu_multiplayer (SDL_Event event , int jeu);
int menu(int *jeu);
#endif
