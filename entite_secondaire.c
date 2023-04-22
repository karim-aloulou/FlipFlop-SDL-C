#include "entite_secondaire.h"

void initEnnemi(Ennemi *E)
{
     
     int i ; 
	    
	    // j'ai initialisé le premier obstable avec plusieurs images pour l'annimer
	    // ces images sont des images de notre personnage // c'est just pour le test MME 
	    
	    for ( i=0 ; i < 15 ; i++ )
	    	{
	    		E->ennemi_annime[0][i]=IMG_Load("images/baton2.png");
	    	}

	     for ( i=0 ; i < 15 ; i++ )
	    	{
	    		E->ennemi_annime[1][i]=IMG_Load("images/ceinture.png");
	    	}
	 for ( i=0 ; i < 15 ; i++ )
	    	{
	    		E->ennemi_annime[2][i]=IMG_Load("images/chleka.png");
	    	}
	    	
	    	// dans ce cas l'entitée n'est pas animée donc je vais just charger une seule image 
	    
	    E->num = 0 ;
	    E->posEnnemi.x = 1000;
	    E->posEnnemi.y = 350;   
    		E->min.x = 0; 
    		E->max.x = 2500;
		E->max.y = E->min.y = 200;

             E->test_min_max = 0 ;
}




void afficherEnnemi(Ennemi E, SDL_Surface *screen,int* a)
{

if(E.posEnnemi.x==1200)
	(*a)++;
if ((*a)==3)
(*a)=0;
	SDL_BlitSurface(E.ennemi_annime[*a][1],NULL,screen,&E.posEnnemi);		

	

}

void animerEnnemi (Ennemi *E)
{
		if(E->num<16) 
		{	
		E->num++;
		}else
		E->num=0;
	
}



void deplacer (Ennemi *E,int rapidite)
{
 	if(E->posEnnemi.x == E->max.x ) 
	
        E->test_min_max = 0 ;
    
	else if (E->posEnnemi.x == E->min.x )
	   // E->test_min_max = 1 ;
    E->posEnnemi.x=E->max.x;
    
    if (E->test_min_max == 0)
    {
        E->posEnnemi.x-=rapidite;
    }
   /* else
    E->posEnnemi.x++;
    */


        
}


int collisionBB(SDL_Rect pos1 , SDL_Rect pos2 )
{
   
     if (pos1.x < pos2.x + pos2.w &&  pos1.x + pos1.w > pos2.x && pos1.y < pos2.y + pos2.h && pos1.h + pos1.y > pos2.y)
 {
    return 1 ;  
}
    
    else 
  return 0;
}

void Liberer_Entite ( Ennemi *E )
{
int i ,j ;
for(i=0 ; i<3 ; i++ )
 {
for(j=0 ; j < 15 ; j++ )
SDL_FreeSurface(E->ennemi_annime[i][j]);
 }
}





void deplacerIA(Ennemi *E , SDL_Rect posPerso)
{
    if ( ( E->posEnnemi.x - posPerso.x) > 100 &&  ( E->posEnnemi.x - posPerso.x) < 200  )
        { 
            E->test_min_max = 0;
        	E->min.x = 100 ; 
    		E->max.x = 900;
        }
        else if ( (posPerso.x - E->posEnnemi.x ) > 200 )  
            { 
            E->test_min_max = 1;
        	E->min.x = 100 ; 
    		E->max.x = 900;
            }
            else 
            {
                E->min.x = 500 ; 
    		    E->max.x = 900;
            }
}


///////////////////FAROUK

void initEnnemi_partage_plan1(Ennemi *E)
{
     
      
     int i ; 
	    
	    // j'ai initialisé le premier obstable avec plusieurs images pour l'annimer
	    // ces images sont des images de notre personnage // c'est just pour le test MME 
	    
	    for ( i=0 ; i < 15 ; i++ )
	    	{
	    		E->ennemi_annime[0][i]=IMG_Load("images/baton2.png");
	    	}

	     for ( i=0 ; i < 15 ; i++ )
	    	{
	    		E->ennemi_annime[1][i]=IMG_Load("images/ceinture.png");
	    	}
	 for ( i=0 ; i < 15 ; i++ )
	    	{
	    		E->ennemi_annime[2][i]=IMG_Load("images/chleka.png");
	    	}
	    	
	    	// dans ce cas l'entitée n'est pas animée donc je vais just charger une seule image 
	    
	    E->num = 0 ;
	    
	    E->posEnnemi.x = 900;
	    E->posEnnemi.y = 200;   
    		E->min.x = 0; 
    		E->max.x = 1500;
			E->max.y = E->min.y = 220;

             E->test_min_max = 0 ;
}

void initEnnemi_partage_plan2(Ennemi *E)
{
     
      
     int i ; 
	    
	    // j'ai initialisé le premier obstable avec plusieurs images pour l'annimer
	    // ces images sont des images de notre personnage // c'est just pour le test MME 
	    
	    for ( i=0 ; i < 15 ; i++ )
	    	{
	    		E->ennemi_annime[0][i]=IMG_Load("images/baton2.png");
	    	}

	     for ( i=0 ; i < 15 ; i++ )
	    	{
	    		E->ennemi_annime[1][i]=IMG_Load("images/ceinture.png");
	    	}
	 for ( i=0 ; i < 15 ; i++ )
	    	{
	    		E->ennemi_annime[2][i]=IMG_Load("images/chleka.png");
	    	}
	    	
	    	// dans ce cas l'entitée n'est pas animée donc je vais just charger une seule image 
	    
	    E->num = 0 ;
	    
	    E->posEnnemi.x = 900;
	    E->posEnnemi.y = 500;   
    		E->min.x = 0; 
    		E->max.x = 1500;
			E->max.y = E->min.y = 520;

             E->test_min_max = 0 ;
}

/////////////////////////



