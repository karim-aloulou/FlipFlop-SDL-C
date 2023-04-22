#ifndef ENIGMES_H_INCLUDED
#define ENIGMES_H_INCLUDED
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h> 

typedef struct enigme
{
    char Question1[100], Answer1[100], Answer2[100] , Answer3[100], correct[100];
	SDL_Surface *Question,*Reponse1,*Reponse2,*Reponse3;
    SDL_Rect Question1Pos, Answer1Pos, Answer2Pos, Answer3Pos ;
    TTF_Font *Font;
	
    int InputUser, solution;
} enigme;

enigme Init_Enigme();
int nblignes(char filename[]);
enigme Generate_Enigme();

int Resolution(enigme e,int x);
void afficher_resultat (SDL_Surface * ecran,enigme e,int x);

void affichage_Enigme(enigme e , SDL_Surface *ecran);






#endif // ENIGMES_H_INCLUDED
