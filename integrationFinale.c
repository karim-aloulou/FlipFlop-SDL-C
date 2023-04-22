#include"perso.h"
#include"multijoueur.h"
#include"entite_secondaire.h"
#include "menu.h"
#include "jeuFinal.h"
#include "background.h"
#include "animation_logo.h"





int main()
{
    TTF_Init();
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO |SDL_DOUBLEBUF|SDL_FULLSCREEN);
    SDL_WM_SetCaption("Flip Flop",NULL);
    //init score 
    score s;
    int compteur = 0;
    s=initScore();



/////////////menu_multiplayer/////////////////

 Background BackgroundData_partage;
SDL_Rect partageRect1;
    SDL_Rect partageRect2;
    BackgroundData_partage.backgroundPosition1 = &partageRect1;
    BackgroundData_partage.backgroundPosition2 = &partageRect2;
init_Partage_ecran(&BackgroundData_partage);
     personne P_partage_plan1;
    personne P2_partage_plan1;
    personne P_partage_plan2;
    personne P2_partage_plan2;
menu_jouer menu_multiplayer ;
  init_menu_multiplayer(&menu_multiplayer);
Ennemi E_partage_plan1;
    Ennemi E_partage_plan2;
 initperso_partage_plan1(&P_partage_plan1);
    initperso_partage_plan2(&P_partage_plan2);
 initperso2_partage_plan1(&P2_partage_plan1);
    initperso2_partage_plan2(&P2_partage_plan2);
 
initEnnemi_partage_plan1(&E_partage_plan1);
    initEnnemi_partage_plan2(&E_partage_plan2);
 init_partage(&P_partage_plan1);
    init_partage(&P_partage_plan2);
    init2_partage(&P2_partage_plan1);
    init2_partage(&P2_partage_plan2);
 int continuerb=1;
   int continue1=1;
   int jeu=0;
int menui = 0 ;
int collision_fils_plan1  , collision_mere_plan2;  
collision_fils_plan1 = collision_mere_plan2 = 0 ;
//////////////////////////////////

/////animation logo////
logo l;
init_animation_logo(&l);

///////////////////////

    //////////////init miniMap////////////////////////
    Mini_map m;
    Background BackgroundData;
    Background BackgroundData2;
    SDL_Rect scrollingRect;
    SDL_Rect scrollingRect1;
    BackgroundData.backgroundPosition1 = &scrollingRect;
    BackgroundData2.backgroundPosition1 = &scrollingRect1;
    initBackground(&BackgroundData,"background1.jpg",0);
    initBackground(&BackgroundData2,"Mini_map.png",650);
    int j=0 ;
    personne P;
    personne P2;
  

    //E.vitesse=1;
    P.acceleration=0;
    SDL_Rect pos;
    int test;
    //////////////init Ennemi////////////////////////
    Ennemi E;
    //*****fenetre********
    SDL_Surface *fenetre=NULL;
    fenetre=SDL_SetVideoMode(900,600,32,SDL_HWSURFACE);
    //******event******
    SDL_Event event;
    initperso(&P);
    initperso2(&P2);
    initEnnemi(&E);

    initminimap(&m);
    //*******initialisation animation_normal_fils 
    init(&P);
    init2(&P2);

/////////////////VIE/////////////////////
SDL_Surface *vie_complete;
vie_complete=IMG_Load("images/vie_complete.png");
SDL_Rect vie_completePosition;
vie_completePosition.x=20;
vie_completePosition.y=40;



SDL_Surface *mi_vie;
mi_vie=IMG_Load("images/vie_moyenne.png");
SDL_Rect mi_viePosition;
mi_viePosition.x=20;
mi_viePosition.y=40;



SDL_Surface *vie_vide;
vie_vide=IMG_Load("images/vie_vide.png");
SDL_Rect vie_videPosition;
vie_videPosition.x=20;
vie_videPosition.y=40;

//////////////////////////////////////////
SDL_Surface *game_over;
game_over=IMG_Load("backgrounds/game_over.png");
SDL_Rect game_overPosition;
game_overPosition.x=0;
game_overPosition.y=0;


    Uint32 tp=0,dt=1;
   int continuer=1;
int rapidite=2;
int a=0;
int gameOver=0;

    //SDL_EnableKeyRepeat (SDL_DEFAULT_REPEAT_DELAY,SDL_DEFAULT_REPEAT_INTERVAL);
int collision=0,collision1=0;


int test_logo=0;
 
while(continue1)
{

if (test_logo==0)
{
l.quitter=animation_logo(&l,fenetre);
}
test_logo=1;
menui = menu(&jeu) ; 
continuerb = 1 ;

switch (menui)
{ 

case 0 :
	jeu = 0;
	break; 

case 1:
while (continuerb)

{
		SDL_WaitEvent(&event);
		
		switch (update_menu_multiplayer(event , jeu))
		{
			case 0 :
			affichage_menu_multiplayer ( menu_multiplayer , fenetre , 0 ) ;
			break;
			case 1 :
			affichage_menu_multiplayer ( menu_multiplayer , fenetre , 1 ) ;
			break;
			case 2 :
			affichage_menu_multiplayer ( menu_multiplayer , fenetre , 2) ;
			break;
			case 3 : 

    while(continuer)
    {

        test=0;
	afficherBackground(&BackgroundData, fenetre);
	//afficherBackground(&BackgroundData2, fenetre);

        scrolling (&BackgroundData,rapidite);
	//scrolling (&BackgroundData2,rapidite,0);

        afficherperso(&P,fenetre);
        afficherperso(&P2,fenetre);
        afficherEnnemi(E,fenetre,&a);


        tp=SDL_GetTicks();
        SDL_PollEvent(&event);


        if(event.key.keysym.sym==SDLK_ESCAPE){break;}

        test=controlerpersonnage(event,&P);
        if(test==1)//deplacer fils
         {
        deplacerperso(&P,dt);
         }
        if(test==2)//deplacer mere
         {
        deplacerperso(&P2,dt);
         }
        if(test==3)//acceleration fils
         {
         P.acceleration=0.5;
         acceleration(&P,dt);
	 }
	 if(test==4)//acceleration mere
	 {
	 P.acceleration=-0.5;
	 acceleration(&P,dt);
	 }
	 if(test==5)//saut mere et fils
	 {
	saut(&P);
	 }
	if (test==6)
	{
	slide(&P);
	}
		
	collision= collisionBB(P.pos ,E.posEnnemi);
        collision1= collisionBB(P2.pos ,E.posEnnemi);
		
	if (collision==1)
	 { 
   	if (P.vie==1) {continuer=0;break;}//////AU LIEU DE BREAK BLIT PERDU
	 {if (enigmeFinal() ==1)
		  {P.vie--;
               E.posEnnemi.x= P.pos.x-P.pos.w;
		   }
                   else{continuer =0;}
        	   }
		
         }


/*if(compteur==100*45)
initBackground(&BackgroundData,"back.png",0);///////////////////////////////////////
*/
if (collision1==1)
{
saut (&P2);
}

if(E.posEnnemi.x<0)
 initEnnemi(&E);

if (compteur>100*45&& compteur<200*45)
rapidite=3;
if(compteur>300*45)
rapidite=4;




	animerperso(&P);
	animerperso(&P2);
	//animerEnnemi(&E);
	  ///////////////Partie gestion//////////////////////
	compteur++;    
	deplacer(&E,rapidite);
	//deplacerIA(&E , P.pos);

	AffichageScore( s,fenetre,compteur);
	m = afficherMini_map(m,fenetre,P.pos,P2.pos);


if (P.vie==2)
SDL_BlitSurface(vie_complete,NULL,fenetre,&vie_completePosition);
if (P.vie==1)
SDL_BlitSurface(mi_vie,NULL,fenetre,&mi_viePosition);

/*if (gameOver==1)
{SDL_BlitSurface(game_over,NULL,fenetre,&game_overPosition);SDL_Delay(500);}
*/
	SDL_Flip(fenetre);
	dt=SDL_GetTicks()-tp;

    }menui=3;continuerb=0;
 break;



case 4 : 
				while(continuer)
			    {
			    	test=0;
			    	afficherBackground_partage(&BackgroundData_partage , fenetre);
			    	scrolling_partage (&BackgroundData_partage);
			    	afficherperso_partage_plan1(&P_partage_plan1,fenetre);
				afficherperso_partage_plan1(&P2_partage_plan1,fenetre);
				afficherperso_partage_plan2(&P_partage_plan2,fenetre);
				afficherperso_partage_plan2(&P2_partage_plan2,fenetre);
				afficherEnnemi(E_partage_plan1,fenetre,&a);
				afficherEnnemi(E_partage_plan2,fenetre,&a);
				
				tp=SDL_GetTicks();
				SDL_PollEvent(&event);
				
				if(event.key.keysym.sym==SDLK_ESCAPE){break;}

				test=controlerpersonnage(event,&P_partage_plan1);
				test=controlerpersonnage(event,&P_partage_plan2);
				
				if(test==1)//deplacer fils
				 {
				deplacerperso(&P_partage_plan1,dt);
				deplacerperso(&P_partage_plan2,dt);
				 }
				if(test==2)//deplacer mere
				 {
				deplacerperso(&P2_partage_plan1,dt);
				deplacerperso(&P2_partage_plan2,dt);
				 }
				if(test==3)//acceleration fils
				 {
				 P_partage_plan1.acceleration=0.5;
				 P_partage_plan2.acceleration=0.5;
				 acceleration(&P_partage_plan1,dt);
				 acceleration(&P_partage_plan2,dt);
				 }
				 if(test==4)//acceleration mere
				 {
				 P_partage_plan1.acceleration=-0.5;
				 P_partage_plan2.acceleration=0.5;
				 acceleration(&P_partage_plan1,dt);
				 acceleration(&P_partage_plan2,dt);
				 }
				 if(test==5)//saut mere et fils
				 {
				saut(&P_partage_plan1);
				saut(&P_partage_plan2);
				//saut(&P2);
				}
				
				collision_fils_plan1 = collisionBB(P_partage_plan1.pos ,E_partage_plan1.posEnnemi);
				collision_mere_plan2 = collisionBB(P2_partage_plan2.pos ,E_partage_plan2.posEnnemi);

					
				/*if (collision==1)
				 { printf("nombre de vie= %d \n",P.vie);
			   	if (P.vie==1) {continuer=0;break;}//////AU LIEU DE BREAK BLIT PERDU
				 {if (enigmeFinal() ==1)
					  {P.vie--;
				       E.posEnnemi.x= P.pos.x-P.pos.w;
					   }
					   else continuer =0;
					   }
					 printf("vie= %d \n",P.vie);  
				 }*/
				
			if (compteur>100*45&& compteur<200*45)
			rapidite=3;
			if(compteur>300*45)
			rapidite=4;
			
			/*if (collision_mere_plan2==1)
			{
			saut (&P2_partage_plan1);
			saut (&P2_partage_plan2);
			}*/



				animerperso_partage(&P_partage_plan1);
				animerperso_partage(&P_partage_plan2);
				animerperso_partage(&P2_partage_plan1);
				animerperso_partage(&P2_partage_plan2);
				compteur++; 
				
				deplacer(&E_partage_plan1,rapidite);
				deplacer(&E_partage_plan2,rapidite);
				AffichageScore( s,fenetre,compteur);
				//m = afficherMini_map(m,fenetre,P.pos,P2.pos);
				SDL_Flip(fenetre);
				dt=SDL_GetTicks()-tp;

			    }
			break;
			
			case 5 : 
			affichage_menu_multiplayer ( menu_multiplayer , fenetre , 3) ;
			break;
			case 6 : 
			jeu = 0;
			//printf("\njeu = %d " ,jeu );
			menui = 0 ;
			continuerb = 0 ;
			
			break;
		}
		if(event.key.keysym.sym==SDLK_ESCAPE){continuerb = 0;}
		//affichage_menu_multiplayer ( menu_multiplayer , fenetre ) ;
		



		SDL_Flip(fenetre);
	}
	break;
	case 3 : 
	continue1 = 0 ;
	break ;
	}
	
	if(event.key.keysym.sym==SDLK_ESCAPE){continue1 = 0;}
		//affichage_menu_multiplayer ( menu_multiplayer , fenetre ) ;
		SDL_Flip(fenetre);



}
    
SDL_FreeSurface(fenetre);
SDL_FreeSurface(BackgroundData.background);
SDL_FreeSurface(BackgroundData2.background);
SDL_FreeSurface(vie_complete);
SDL_FreeSurface(mi_vie);
SDL_FreeSurface(vie_vide);
FreeScore(s);
Liberer (m);
Liberer_Entite(&E);
Liberer_perso(&P);
SDL_FreeSurface(game_over);
    return 0;
}


/*AGRANDIR FENETRE?  .. SON BREF.. SON CONTINU..FREESURFACE..OBSTACLES.. BACKGROUNDS .. mini map*/
