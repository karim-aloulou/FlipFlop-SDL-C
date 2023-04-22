#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <time.h>
#include "enigmes.h"
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h> 
#include <string.h>
enigme Init_Enigme()
{
enigme e;
    
  
    strcpy(e.Question1, "") ;
    strcpy(e.Answer1, "") ;
    strcpy(e.Answer2, "") ;
    strcpy(e.Answer3, "") ;
   
		
    e.Font = TTF_OpenFont("arial.ttf",30);
    e.InputUser = 0 ;
    e.solution = 0 ;
    e.Question1Pos.x = 50 ;
    e.Question1Pos.y = 50 ;
    e.Answer1Pos.x = 100;
    e.Answer1Pos.y = 200 ;
    e.Answer2Pos.x = 100 ;
    e.Answer2Pos.y = 250 ;
    e.Answer3Pos.x = 100 ;
    e.Answer3Pos.y = 300 ;
	  
return e ;
}



int nblignes(char * filename)
{ FILE *f;
enigme e;
char tmp[4];
int nb_lignes=0;
f=fopen(filename,"r");
if(f!=NULL)
{
   while(fscanf(f,"%s\n%s\n%s\n%s\n%d", e.Question1,e.Answer1,e.Answer2,e.Answer3,&e.solution)!=EOF)
{
        
         nb_lignes++; }
         
}
else
    printf("erreur !!");
fclose(f);
return (nb_lignes);

}


enigme Generate_Enigme()
{
enigme e;
    int  k=0,j=0;
    int z;
    k= nblignes("new.txt");
    //printf("\nnb_lignes = %d \n" , k ) ; 
    srand(time(NULL));
  int i = rand() % k + 1 ;

  FILE *f = fopen("new.txt", "r");
  
 
while( j!=i && fscanf(f,"%s\n%s\n%s\n%s\n%d", e.Question1,e.Answer1,e.Answer2,e.Answer3,&e.solution)!=EOF)
{ j++;}

	z=0;

  while(e.Question1[z] != '\0')
  {
  	if(e.Question1[z] == '/')
  		e.Question1[z] = ' ';
   z++;
   } 
z=0;

  while(e.Answer1[z] != '\0')
  {
  	if(e.Answer1[z] == '/')
  		e.Answer1[z] = ' ';
   z++;
   } 
  		
 z=0;

  while(e.Answer2[z] != '\0')
  {
  	if(e.Answer2[z] == '/')
  		e.Answer2[z] = ' ';
   z++;
   } 
  		
 z=0;

  while(e.Answer3[z] != '\0')
  {
  	if(e.Answer3[z] == '/')
  		e.Answer3[z] = ' ';
   z++;
   } 
    
    fclose(f);
    return e;
   
    }
    
    


int Resolution(enigme e,int x)
{
	int vrai=0;
	
	if (e.solution == x)	 
		{vrai=1;}

return vrai;
}

void afficher_resultat (SDL_Surface * ecran,enigme e,int x)
 {SDL_Surface *background; background=NULL;
  SDL_Rect pos;
 	if (x==e.solution)
 	{  
 		background=IMG_Load("vrai.png");
 		pos.x=0;pos.y=0;pos.w=ecran->w;pos.h=ecran->h;
 		SDL_BlitSurface(background, NULL, ecran, &pos) ;
        SDL_Flip(ecran);
	//SDL_Delay(500);
 	}
 	else
 	{
 		background=IMG_Load("faux.png");
 		SDL_BlitSurface(background, NULL, ecran, NULL) ;
      SDL_Flip(ecran);
	SDL_Delay(500);
 	}
 }
 
 


void affichage_Enigme(enigme e, SDL_Surface *ecran)
{


SDL_Surface *backgroundENIGMESF;
backgroundENIGMESF=IMG_Load("backgrounds/backgroundE.png");
SDL_Rect backgroundENIGMESFPosition;
backgroundENIGMESFPosition.x=0;
backgroundENIGMESFPosition.y=0;
        SDL_Color policeNoire = {0 ,0 ,0 };
	SDL_Color policeBlanche = {255 ,255 ,255 };
	SDL_Color policeRouge = {255 ,0 ,0 };
	SDL_Color policeRouge1 = {101 ,27 ,29 };

	e.Question= TTF_RenderText_Blended(e.Font,e.Question1,policeNoire);
	e.Reponse1= TTF_RenderText_Blended(e.Font,e.Answer1,policeRouge1);
	e.Reponse2= TTF_RenderText_Blended(e.Font,e.Answer2,policeRouge1);
	e.Reponse3= TTF_RenderText_Blended(e.Font,e.Answer3,policeRouge1);
	SDL_BlitSurface(backgroundENIGMESF,NULL,ecran,&backgroundENIGMESFPosition);
	SDL_BlitSurface(e.Question, NULL, ecran, &e.Question1Pos);
	SDL_BlitSurface(e.Reponse1, NULL, ecran, &e.Answer1Pos);
	SDL_BlitSurface(e.Reponse2, NULL, ecran, &e.Answer2Pos);
	SDL_BlitSurface(e.Reponse3, NULL, ecran, &e.Answer3Pos); 

        
        SDL_Flip(ecran);  

}







