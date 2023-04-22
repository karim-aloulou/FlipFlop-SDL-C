
#include "enigmeFinal.h"

int enigmeFinal(){

SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO |SDL_DOUBLEBUF);
TTF_Init();


///////////////////COMPTEUR///////////
TTF_Font *fontTest;
fontTest=TTF_OpenFont("arial.ttf",35);//police w taille
SDL_Color fontColor={0,0,0};//couleur du texteTTF_Font *fontTest;
SDL_Color colorCoor={0,0,0};
SDL_Surface *coordinates;
char coorText[20];
//sprintf(coorText,"%d,%d");
coordinates=TTF_RenderText_Blended(fontTest,"0,0",colorCoor);
SDL_Rect coordinatesPostion;
coordinatesPostion.x=0;
coordinatesPostion.y=0;
///////////////////

//*****fenetre********
SDL_Surface *fenetre=NULL;
fenetre=SDL_SetVideoMode(900,600,32,SDL_HWSURFACE);


///////////ENIGME INIT YASMINE////////////
SDL_Surface *win=NULL;
SDL_Surface *loss=NULL;
win=IMG_Load("vrai.png");
loss=IMG_Load("faux.png");
int reponse=-1;
enigmeSF esf;
esf=generer();/*generer aleatoirement une enigmeSF
enigmeSF contient {une question , 3 reponses , le nombre de solution correcte}
et l'enregistrer dans e.*/

//////////////////////////////////////////


/////////////ENIGME EMNA INITT/////////////
char* filename = "new.txt";
enigme e;
int a,r=0,w;
e=Init_Enigme();
e=Generate_Enigme();
//////////////////////////////////////////

///////////////ENIGME IA2 KARIM////////////
int j=0 ;
allumettes A;
SDL_Surface *backgroundK;
backgroundK=IMG_Load("backgrounds/backgroundK.jpg");
SDL_Rect backgroundKPosition;
backgroundKPosition.x=0;
backgroundKPosition.y=0;
//********init allumette
initialisation_Allumettes(&A);
SDL_Surface *perdu;
perdu=IMG_Load("background/oops2.png");
SDL_Rect perduPosition;
perduPosition.x=0;
perduPosition.y=0;


////////////////////////////////////////////


//******event******
SDL_Event event;

//*******initialisation background
SDL_Surface *background;
background=IMG_Load("backgrounds/background.png");
SDL_Rect backgroundPosition;
backgroundPosition.x=0;
backgroundPosition.y=0;
//********init bouton1
SDL_Surface *bouton1;
bouton1=IMG_Load("bouton.gif");
SDL_Rect bouton1Position;
bouton1Position.x=fenetre->w/2-bouton1->w/2;
bouton1Position.y=fenetre->h/4-bouton1->h/2+10;
//********init bouton2
SDL_Surface *bouton2;
bouton2=IMG_Load("bouton.gif");
SDL_Rect bouton2Position;
bouton2Position.x=fenetre->w/2-bouton2->w/2;
bouton2Position.y=fenetre->h/2-bouton2->h/2+10;

//********init bouton3
SDL_Surface *bouton3;
bouton3=IMG_Load("bouton.gif");
SDL_Rect bouton3Position;
bouton3Position.x=fenetre->w/2-bouton3->w/2;
bouton3Position.y=fenetre->h*3/4-bouton3->h/2+10;





int x=0,y=0;
int continuer =1;
while(continuer)
{SDL_PollEvent(&event);
SDL_GetMouseState(&x,&y);
   if (event.type==SDL_QUIT)
        {break;}
    if(event.type==SDL_KEYDOWN)
    {
        if(event.key.keysym.sym==SDLK_ESCAPE)
        {continuer=0;}
    }
////////////////////////////////////EMNAAAAAAAAAAAA////////////////////////////////////////////////////////////////////////////////
if((event.motion.x>360)&&(event.motion.x<535)&&(event.motion.y>125)&&(event.motion.y<200)&&(event.button.button==SDL_BUTTON_LEFT))
{
while (w==0)
{
affichage_Enigme(e,fenetre);
SDL_WaitEvent(&event);

  switch( event.key.keysym.sym )
  {
   case  SDLK_a:
    w=1;     
    
    break;
   case  SDLK_b:
     w=2;
     
    break;
   case  SDLK_c:
    w=3;
    
    break;
    
  }//switch2*/
if(w==1)
 {r=Resolution(e,w);
afficher_resultat (fenetre,e,w);
printf("reso=%d\n",r);
return r;}
if(w==2)
{r=Resolution(e,w);
afficher_resultat (fenetre,e,w);
printf("reso=%d\n",r);
return r;}
if(w==3)
{r=Resolution(e,w);
afficher_resultat (fenetre,e,w);
printf("reso=%d\n",r);
return r;}
  }
SDL_Flip(fenetre);

w=0;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
if((event.motion.x>360)&&(event.motion.x<535)&&(event.motion.y>280)&&(event.motion.y<340)&&(event.button.button==SDL_BUTTON_LEFT))

{while (A.nombre_Allumettes>0)
  {SDL_BlitSurface(backgroundK,NULL,fenetre,&backgroundKPosition);
   SDL_WaitEvent(&event);
    if(event.type==SDL_KEYDOWN)
    {
        if(event.key.keysym.sym==SDLK_ESCAPE)
        {break;}
        if (A.nombre_Allumettes >= 1 )
        {
            
            A.nombre_Allumettes -= My_play(A.nombre_Allumettes);
            printf("\nnombre allumettes  = %d \n#############################" , A.nombre_Allumettes);
		if(A.nombre_Allumettes == 0)
                return 1;
            A.nombre_Allumettes -= IA_play(A.nombre_Allumettes);
            printf("\nnombre allumettes IA  = %d \n#############################" , A.nombre_Allumettes);
            SDL_Delay(500);
            if(A.nombre_Allumettes == 0)
            return 0;
        }
    }
affichage (A,fenetre);
SDL_Flip(fenetre);
}
}

else if((event.motion.x>360)&&(event.motion.x<535)&&(event.motion.y>430)&&(event.motion.y<495)&&(event.button.button==SDL_BUTTON_LEFT))

{

while (reponse!=1)
  {

 afficherenigmeSF(&esf,fenetre);
    SDL_Flip(fenetre);
    while(SDL_PollEvent(&event))
{

switch(event.type)
{
case SDL_QUIT:
continuer=0;
break;
        case SDL_KEYDOWN:
        /*
        repondre avec le clavier
        a : reponse 1
        z : reponse 2
        e : reponse 3
        */
switch (event.key.keysym.sym)
{

case SDLK_a :
if (esf.solution==1)
                {
                     reponse=1;
                    printf("vrai");
                    ////////////////
                }
                else {
                    reponse=0;
                    printf("faux");
                }
               
      break;
            case SDLK_z :
                if (esf.solution==2)
                {
                    printf("vrai");
                    reponse=1;
                }
                else {
                    printf("faux");
                    reponse=0;
                }
            break;
            case SDLK_e:
                if (esf.solution==3)
                {
                    printf("vrai");
                    reponse=1;
                }
                else {
                   reponse=0;
                    printf("faux");
                }
            break;
            }
        break;
        case SDL_MOUSEBUTTONDOWN://repondre avec le souris
            if (event.motion.x >= 30 && event.motion.x <= 303 && event.motion.y >= 300 && event.motion.y <= 438)//cad:si on clique sur boutton1
            {
                if (esf.solution==1)
                {
                    printf("vrai");
                    reponse=1;
                }
                else {
                    printf("faux");
                    reponse=0;
                }
            }
            if (event.motion.x >= 420 && event.motion.x <= 693 && event.motion.y >= 300 && event.motion.y <= 438)//clique sur boutton2
            {
                if (esf.solution==2)
                {
                    printf("vrai");
                    reponse=1;
                }
                else {
                    printf("faux");
                    reponse=0;
                }
            }
            if (event.motion.x >= 720 && event.motion.x <= 993 && event.motion.y >= 300 && event.motion.y <= 438)//clique sur boutton3
            {
                if (esf.solution==3)
                {
                    printf("vrai");
                    reponse=1;
                }
                else {
                    printf("faux");
                    reponse=0;
                }
            }
            break;
        }
    }


if (reponse!=-1)
{
if (reponse==1)
{
 
    SDL_BlitSurface(win, NULL, fenetre, NULL); 
    SDL_Flip(fenetre);
SDL_Delay(500);
return 1;
break;


    
}
else  
{ 
    SDL_BlitSurface(loss, NULL, fenetre, NULL); 
    SDL_Flip(fenetre);
SDL_Delay(500);
return 0;
   break;
}

  }

}//fin if yasmine

}
SDL_BlitSurface(background,NULL,fenetre,&backgroundPosition);
SDL_BlitSurface(bouton1,NULL,fenetre,&bouton1Position);
SDL_BlitSurface(bouton2,NULL,fenetre,&bouton2Position);
SDL_BlitSurface(bouton3,NULL,fenetre,&bouton3Position);
SDL_BlitSurface(coordinates,NULL,fenetre,&coordinatesPostion);
if(event.type==SDL_MOUSEMOTION)
{
sprintf(coorText,"%d,%d",event.motion.x,event.motion.y);
coordinates=TTF_RenderText_Blended(fontTest,coorText,colorCoor);
}



 SDL_Flip(fenetre);

}
SDL_FreeSurface(win);
SDL_FreeSurface(loss);
SDL_FreeSurface(fenetre);
SDL_FreeSurface(background);
SDL_FreeSurface(bouton1);
SDL_FreeSurface(bouton2);
SDL_FreeSurface(bouton3);
SDL_FreeSurface(backgroundK);
TTF_Quit();
return 0 ;}
