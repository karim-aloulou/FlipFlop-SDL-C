#ifndef IA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include <math.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <time.h>

typedef struct 
{
int etat[11];//brulée ou pas
SDL_Surface *images[2][11];
SDL_Rect position[11];
int nombre_Allumettes;
}allumettes;


void initialisation_Allumettes  (allumettes *A);
void affichage(allumettes A,SDL_Surface *fenetre );
//void genererEnigme(allumettes*A, SDL_Surface *fenetre );
//int IA(int nombre_Allumettes);

int My_play (int nombre_Allumettes);
int IA_play (int nombre_Allumettes);
#endif
