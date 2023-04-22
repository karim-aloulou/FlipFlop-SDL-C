#include "IA.h"

void initialisation_Allumettes (allumettes *A)
{
A->position[0].x=20;
A->position[0].y=340;
for (int j=0;j<11;j++)
	{
A->images[0][j]=IMG_Load("allumette.png");
A->images[1][j]=IMG_Load("allumetteBrulee.png");
A->position[j+1].x=A->position[j].x+90;
A->position[j+1].y=340;
A->etat[j]=1;

A->nombre_Allumettes = 10 ;
	}

}

void affichage(allumettes A, SDL_Surface *fenetre )
{
 // for (int i=0;i<2;i++)
  for (int j= A.nombre_Allumettes ;j < 10 ;j++)
  {
   SDL_BlitSurface(A.images[1][j],NULL,fenetre,&A.position[j]);
  }

  for ( int j = 0 ; j< A.nombre_Allumettes ; j++)
    SDL_BlitSurface(A.images[0][j],NULL,fenetre,&A.position[j]);
}

int IA_play (int nombre_Allumettes)
{
    srand(time(NULL));
    if (nombre_Allumettes == 0 )
        return 0;
        else if ((nombre_Allumettes - 1) % 4 == 0)
            return 1;
            else  if ((nombre_Allumettes - 2) % 4 == 0)
                return 2;
                else if ((nombre_Allumettes - 3) % 4 == 0)
                    return 3;
                    else 
                    return (1+rand()%3);
}




int My_play (int nombre_Allumettes)
{
    SDL_Event event;
    
    do 
    {
        SDL_PollEvent(&event);
    if ( event.key.keysym.sym == SDLK_a ) 
        return 1 ; 
        else if ( event.key.keysym.sym == SDLK_z && nombre_Allumettes > 2 ) 
            return 2 ; 
            else if ( event.key.keysym.sym == SDLK_e && nombre_Allumettes > 3 ) 
                return 3 ; 
    }while((event.key.keysym.sym != SDLK_a)&&(event.key.keysym.sym != SDLK_z||nombre_Allumettes < 2)&&(event.key.keysym.sym != SDLK_e||nombre_Allumettes < 3 ));
}


