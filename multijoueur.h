#ifndef MULTIJOUEUR_H_
#define MULTIJOUEUR_H_

#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_ttf.h>
#include<SDL/SDL_mixer.h>

typedef struct 
{
    SDL_Surface *Mini_Back;
    SDL_Rect Mini_BackPosition;
    SDL_Surface *mere;
    SDL_Surface *fils;
    SDL_Rect merePosition;
    SDL_Rect filsPosition;
}Mini_map;


typedef struct 
{
    TTF_Font *fontTest;
    SDL_Surface *texte2 ;
    SDL_Rect position2;
    char distance[1000] ;
}score;


SDL_Rect MAJMinimap( SDL_Rect PersoPosition , int redimensionnement);
Mini_map afficherMini_map (Mini_map m, SDL_Surface * fenetre ,SDL_Rect filsGPosisition, SDL_Rect mereGPosition);
void Liberer (Mini_map m);
void initminimap(Mini_map*m);

void initialiser();
SDL_Surface *gestiondistance();
void AffichageScore(score s,SDL_Surface *fenetre,int compteur);
score initScore();
void FreeScore(score s);

int affichertemps(int temps);

SDL_Color GetPixel (SDL_Surface* pSurface,int x,int y);
int collision_back (/*SDL_Surface pers,*/SDL_Rect position, SDL_Surface* background);


#endif
