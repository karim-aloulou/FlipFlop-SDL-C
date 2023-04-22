#ifndef ENTITE_SECONDAIRE_H_INCLUDED
#define ENTITE_SECONDAIRE_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_ttf.h>
#include<SDL/SDL_mixer.h>
//#include"perso.h"
/*typedef struct 
{
    SDL_Surface *mat[2][16];
    SDL_Rect pos;
    int i , j ;

}Perso;
*/

typedef struct 
{
    SDL_Surface *ennemi_annime[10][16];
    int num;
    SDL_Rect posEnnemi;
    SDL_Rect min , max ;
        int test_min_max;
}Ennemi;

/*void initPerso(Perso *p);
void afficherPerso(Perso p, SDL_Surface * screen);
void annimerPerso(Perso *p);*/



void initEnnemi(Ennemi *E);

void animerEnnemi (Ennemi *E);
void afficherEnnemi(Ennemi E, SDL_Surface *screen,int *a);

void deplacer (Ennemi *E,int rapidite);
int collisionBB(SDL_Rect pos1 , SDL_Rect pos2);
//int collisionBB(personne p , Ennemi E );
void deplacerIA(Ennemi *E , SDL_Rect posPerso);
void Liberer_Entite ( Ennemi *E );
void initEnnemi_partage_plan1(Ennemi *E);
void initEnnemi_partage_plan2(Ennemi *E);


/*void deplacer_perso_R (Perso *p);
void deplacer_perso_L (Perso *p);*/





#endif // NEW_H_INCLUDED
