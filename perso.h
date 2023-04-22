/** 
* @file perso.h 
* @brief .h du prog. 
* @author ahmed
* @version 0.1 
* @date avr 22, 2021 
* 
* programme du personnage * 
*/
#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_ttf.h>
#include<SDL/SDL_mixer.h>
#include<unistd.h>


#ifndef PERSO_H_
#define PERSO_H_
typedef struct 
{
    SDL_Surface *mat[3][16];
    SDL_Rect pos;
int vitesse;
int acceleration;
int saut;
int compteur;
int vie;
}personne;

void initperso(personne *E);
void initperso2(personne *E);
void animerperso(personne *E);
void init(personne *E);
void init2(personne *E);
void saut(personne *E);
void afficherperso(personne *E,SDL_Surface *fenetre);
void deplacerperso(personne *p,Uint32 dt);
void acceleration(personne *p, Uint32 dt);
int controlerpersonnage(SDL_Event event,personne *E);
void Liberer_perso ( personne *P );
void slide(personne *E);
void animerperso_partage(personne *E);


void initperso_partage_plan1(personne *E);
void initperso_partage_plan2(personne *E);
void initperso2_partage_plan1(personne *E);
void initperso2_partage_plan2(personne *E);
void init_partage(personne *E);
void init2_partage(personne *E);
void afficherperso_partage_plan1(personne *E,SDL_Surface *fenetre);
void afficherperso_partage_plan2(personne *E,SDL_Surface *fenetre);


#endif
