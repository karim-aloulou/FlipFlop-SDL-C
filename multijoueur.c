#include"multijoueur.h"
#include<unistd.h>

//////////////////////////// MINI MAP////////////////////////////////////////////////////////////////////////

void initminimap(Mini_map*m)
{
  m->fils=IMG_Load("ka3bourafils.png");
  m->Mini_Back=IMG_Load("Mini_map.png");
  m->mere=IMG_Load("ka3bouramere.png");
}


Mini_map afficherMini_map (Mini_map m, SDL_Surface *fenetre ,SDL_Rect filsGPosition, SDL_Rect mereGPosition)
{
  m.Mini_BackPosition.x= fenetre->w - m.Mini_Back->w;
  m.Mini_BackPosition.y=0;
  m.filsPosition= MAJMinimap(filsGPosition,30);
  m.merePosition= MAJMinimap(mereGPosition,30);
  m.merePosition.x=m.merePosition.x+10;
  m.merePosition.y=m.merePosition.y+60;
m.filsPosition.x=m.filsPosition.x-40;
  m.filsPosition.y=m.filsPosition.y+48;
  
         SDL_BlitSurface(m.Mini_Back,NULL,fenetre,&m.Mini_BackPosition);
         SDL_BlitSurface(m.fils,NULL,fenetre,&m.filsPosition);
         SDL_BlitSurface(m.mere,NULL,fenetre,&m.merePosition);
  
  return m;
}


SDL_Rect MAJMinimap( SDL_Rect PersoPosition , int redimensionnement)
{
  SDL_Rect smallPosition;

  smallPosition.x= (((PersoPosition.x)*redimensionnement)/100)+645;
  smallPosition.y= (((PersoPosition.y)*redimensionnement)/100)-52;

  return smallPosition;
}


void Liberer (Mini_map m)
{
  SDL_FreeSurface(m.fils);
  SDL_FreeSurface(m.mere);
  SDL_FreeSurface(m.Mini_Back);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////// GESTION DISTANCE /////////////////////////////////////////////////////////////////////


score initScore()
{
  score s;
  s.texte2=NULL;
  s.fontTest=TTF_OpenFont("fontTest.ttf",35);
  s.position2.x=0;
  s.position2.y=0;
  s.distance[0]='\0';
  return s;
}

void  AffichageScore(score s,SDL_Surface *fenetre,int compteur)

{
    SDL_Color couleurNoire = {0, 0, 0};
 
    //printf("affichage score \n");
    sprintf(s.distance, "%d metres", compteur);
   s.texte2=TTF_RenderText_Blended(s.fontTest,s.distance,couleurNoire);
   // compteur++;    
    sprintf(s.distance, "%.0f metres", (float)compteur/45); 
    SDL_FreeSurface(s.texte2);
    s.texte2=TTF_RenderText_Blended(s.fontTest,s.distance,couleurNoire);     
    SDL_BlitSurface(s.texte2, NULL, fenetre, &(s.position2));
    //printf("affcihage score finish\n");
}

void FreeScore(score s)
{
TTF_CloseFont(s.fontTest);
SDL_FreeSurface(s.texte2);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////// Pixel Perfect Collision/////////////////////////////////////////////////////
SDL_Color GetPixel (SDL_Surface* pSurface,int x,int y)
{
  SDL_Color color;
  Uint32 col= 0;
  char* pPosition = (char*) pSurface->pixels;
  pPosition += (pSurface->pitch * y);
  pPosition += (pSurface->format->BytesPerPixel * x);
  memcpy (&col,pPosition,pSurface->format->BytesPerPixel);
  SDL_GetRGB (col,pSurface->format,&color.r,&color.g,&color.b);
 return (color);
}

int collision_back (SDL_Rect position, SDL_Surface* background)
{
  SDL_Rect point[8];
  SDL_Color couleur[8];

point[0].x=position.x+position.w;
point[0].y=position.y+position.h;

point[1].x=position.x+position.w;
point[1].y=position.y+(position.h*3/4);

point[2].x=position.x+position.w;
point[2].y=position.y+(position.h/2);

point[3].x=position.x+position.w;
point[3].y=position.y+position.h/4;

point[3].x=position.x+position.w;
point[3].y=position.y;


point[4].x=position.x+(position.w*3/4);
point[4].y=position.y+position.h;

point[5].x=position.x+position.w/2;
point[5].y=position.y+position.h;

point[6].x=position.x+position.w/4;
point[6].y=position.y+position.h;

point[7].x=position.x;
point[7].y=position.y+position.h;



couleur[0]=GetPixel (background, point[0].x, point[0].y);
couleur[1]=GetPixel (background, point[1].x, point[1].y);
couleur[2]=GetPixel (background, point[2].x, point[2].y);
couleur[3]=GetPixel (background, point[3].x, point[3].y);
couleur[4]=GetPixel (background, point[4].x, point[4].y);
couleur[5]=GetPixel (background, point[5].x, point[5].y);
couleur[6]=GetPixel (background, point[6].x, point[6].y);
couleur[7]=GetPixel (background, point[7].x, point[7].y);
//couleur[8]=GetPixel (background, point[8].x, point[8].y);

if (couleur[0].r==0 && couleur[0].g==0 && couleur[0].b==0 || couleur[1].r==0 && couleur[1].g==0 && couleur[1].b==0 ||couleur[2].r==0 && couleur[2].g==0 && couleur[2].b==0 || couleur[3].r==0 && couleur[3].g==0 && couleur[3].b==0 ||couleur[4].r==0 && couleur[4].g==0 && couleur[4].b==0 || couleur[5].r==0 && couleur[5].g==0 && couleur[5].b==0 ||couleur[6].r==0 && couleur[6].g==0 && couleur[6].b==0 || couleur[7].r==0 && couleur[7].g==0 && couleur[7].b==0 ||couleur[8].r==0 )//&& couleur[8].g==0 && couleur[8].b==0 )
return 1;
else return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////


int affichertemps(int temps)
{
float duree=0;
Uint32 debut=0,fin=0;
int h;
debut= SDL_GetTicks ();

//ICI IL Y A L ENIGME
SDL_Delay(10);//on suppose que le jeu d'enigme a dure 10sec > 9 sec celle permise
fin = SDL_GetTicks ();

duree = (fin - debut);
if (duree>temps)
{ printf("perdant");return 0;}
return 1; 
// En effet si la fontion va retourner 0 il va perdre sinon il va continuer
}





