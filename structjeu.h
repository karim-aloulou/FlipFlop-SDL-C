#ifndef STRUCTJEU_H_INCLUDED
#define STRUCTJEU_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_ttf.h>
#include<SDL/SDL_mixer.h>
#include"perso.h"
#include<unistd.h>
#include"multijoueur.h"

typedef struct 
{
    SDL_Surface *mat[2][16];
    SDL_Rect pos;
int vitesse;
int acceleration;
int saut;
int compteur;

}personne;

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



typedef struct Background
{
   SDL_Rect* backgroundPosition;
   SDL_Surface *background ;

}Background;


#endif



