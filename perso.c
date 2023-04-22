/** 
* @file perso.c 
* @brief les fonctions du personnage. 
* @author ahmed 
* @version 0.1 
* @date Apr 22, 2012 
* 
*  * 
*/

#include"perso.h"


void initperso(personne *E)
{
    
    E->pos.x = 400;
    E->pos.y = 300;
E->vitesse=1;
E->compteur=0;
E->saut=0;
E->vie=2;

}
void initperso2(personne *E)

{
E->pos.x = 50;
    E->pos.y = 220;
E->vitesse=1;
E->compteur=0;
E->saut=0;
}

void slide(personne *E)
{
E->saut=2;
E->compteur=0;
}

void animerperso(personne *E)
{

E->compteur++;
//printf("%d\n",E->saut);
if(E->compteur>=160&&E->saut==1){E->saut=0;}
if(E->compteur>=160&&E->saut==2){E->saut=0;}
if(E->compteur>=160){E->compteur=0;}



//printf("%d\n",somme);

}
void init(personne *E)
{
    int i;
    SDL_Rect position;
  
    //E->pos= intialiser_position();

    // *************************************animation normal (run)

    E->mat[0][0]=IMG_Load("filsPics/1.png");
    E->mat[0][1]=IMG_Load("filsPics/2.png");
    E->mat[0][2]=IMG_Load("filsPics/3.png");
    E->mat[0][3]=IMG_Load("filsPics/4.png");
    E->mat[0][4]=IMG_Load("filsPics/5.png");
    E->mat[0][5]=IMG_Load("filsPics/6.png");
    E->mat[0][6]=IMG_Load("filsPics/7.png");
    E->mat[0][7]=IMG_Load("filsPics/8.png");
    E->mat[0][8]=IMG_Load("filsPics/9.png");
    E->mat[0][9]=IMG_Load("filsPics/10.png");
    E->mat[0][10]=IMG_Load("filsPics/11.png");
    E->mat[0][11]=IMG_Load("filsPics/12.png");
    E->mat[0][12]=IMG_Load("filsPics/13.png");
    E->mat[0][13]=IMG_Load("filsPics/14.png");
    E->mat[0][14]=IMG_Load("filsPics/15.png");
    E->mat[0][15]=IMG_Load("filsPics/16.png");

    
    
    // *************************************animation sauter (jump)
    
    E->mat[1][0]=IMG_Load("filsPics/2j.png");
    E->mat[1][1]=IMG_Load("filsPics/2j.png");
    E->mat[1][2]=IMG_Load("filsPics/3.png");
    E->mat[1][3]=IMG_Load("filsPics/4.png");
    E->mat[1][4]=IMG_Load("filsPics/5j.png");
    E->mat[1][5]=IMG_Load("filsPics/6j.png");
    E->mat[1][6]=IMG_Load("filsPics/7j.png");
    E->mat[1][7]=IMG_Load("filsPics/8j.png");
    E->mat[1][8]=IMG_Load("filsPics/9j.png");
    E->mat[1][9]=IMG_Load("filsPics/10j.png");
    E->mat[1][10]=IMG_Load("filsPics/11j.png");
    E->mat[1][11]=IMG_Load("filsPics/12j.png");
    E->mat[1][12]=IMG_Load("filsPics/13j.png");
    E->mat[1][13]=IMG_Load("filsPics/13j.png");
    E->mat[1][14]=IMG_Load("filsPics/13j.png");
    E->mat[1][15]=IMG_Load("filsPics/13j.png");

    E->mat[2][0]=IMG_Load("slide/1s.png");
    E->mat[2][1]=IMG_Load("slide/2s.png");
    E->mat[2][2]=IMG_Load("slide/3s.png");
    E->mat[2][3]=IMG_Load("slide/4s.png");
    E->mat[2][4]=IMG_Load("slide/7s.png");
    E->mat[2][5]=IMG_Load("slide/7s.png");
    E->mat[2][6]=IMG_Load("slide/7s.png");
    E->mat[2][7]=IMG_Load("slide/7s.png");
    E->mat[2][8]=IMG_Load("slide/7s.png");
    E->mat[2][9]=IMG_Load("slide/7s.png");
    E->mat[2][10]=IMG_Load("slide/7s.png");
    E->mat[2][11]=IMG_Load("slide/8s.png");
    E->mat[2][12]=IMG_Load("slide/9s.png");
    E->mat[2][13]=IMG_Load("slide/10s.png");
    E->mat[2][14]=IMG_Load("slide/11s.png");
    E->mat[2][15]=IMG_Load("slide/12s.png");

    



}


void init2(personne *E)
{

// *************************************animation normal (run)

    E->mat[0][0]=IMG_Load("merePics/mere1.png");
    E->mat[0][1]=IMG_Load("merePics/mere2.png");
    E->mat[0][2]=IMG_Load("merePics/mere3.png");
    E->mat[0][3]=IMG_Load("merePics/mere4.png");
    E->mat[0][4]=IMG_Load("merePics/mere5.png");
    E->mat[0][5]=IMG_Load("merePics/mere6.png");
    E->mat[0][6]=IMG_Load("merePics/mere7.png");
    E->mat[0][7]=IMG_Load("merePics/mere8.png");
    E->mat[0][8]=IMG_Load("merePics/mere9.png");
    E->mat[0][9]=IMG_Load("merePics/mere10.png");
    E->mat[0][10]=IMG_Load("merePics/mere11.png");
    E->mat[0][11]=IMG_Load("merePics/mere12.png");
    E->mat[0][12]=IMG_Load("merePics/mere13.png");
    E->mat[0][13]=IMG_Load("merePics/mere14.png");
    E->mat[0][14]=IMG_Load("merePics/mere15.png");
    E->mat[0][15]=IMG_Load("merePics/mere16.png");

    
    
    // *************************************animation sauter (jump)
    
    E->mat[1][0]=IMG_Load("merePics/merej2.png");
    E->mat[1][1]=IMG_Load("merePics/merej2.png");
    E->mat[1][2]=IMG_Load("merePics/merej3.png");
    E->mat[1][3]=IMG_Load("merePics/merej4.png");
    E->mat[1][4]=IMG_Load("merePics/merej5.png");
    E->mat[1][5]=IMG_Load("merePics/merej6.png");
    E->mat[1][6]=IMG_Load("merePics/merej7.png");
    E->mat[1][7]=IMG_Load("merePics/merej8.png");
    E->mat[1][8]=IMG_Load("merePics/merej9.png");
    E->mat[1][9]=IMG_Load("merePics/merej10.png");
    E->mat[1][10]=IMG_Load("merePics/merej11.png");
    E->mat[1][11]=IMG_Load("merePics/merej12.png");
    E->mat[1][12]=IMG_Load("merePics/merej13.png");
    E->mat[1][13]=IMG_Load("merePics/merej13.png");
    E->mat[1][14]=IMG_Load("merePics/merej13.png");
    E->mat[1][15]=IMG_Load("merePics/merej13.png");
    

}

void saut(personne *E)

{
E->saut=1;
E->compteur=0;

}
void afficherperso(personne *E,SDL_Surface *fenetre)
{
int i;
i=E->compteur/10;
if(E->saut==1)
{

if (E->compteur<=80)
{ E->pos.y=E->pos.y-10;}

if (E->compteur>80 && E->compteur<159)
{ E->pos.y=E->pos.y+3;}

if (i>16)
{E->pos.y=200;}



}
if(E->saut==2)
{
if(i==4){E->pos.y+=15;}
if(i==11){E->pos.y=300;}
}



                SDL_BlitSurface(E->mat[E->saut][E->compteur/10],NULL,fenetre,&E->pos);

 
}

void deplacerperso(personne *p,Uint32 dt)
{
//p->pos.x+=p->acceleration;
p->pos.x+=(p->vitesse)*dt;
}

void acceleration(personne *p, Uint32 dt)
{
p->vitesse+=p->acceleration*dt;
p->pos.x+=((0.5*p->acceleration)*dt*dt)+p->vitesse*dt;
}


void Liberer_perso ( personne *P )
{
int i ,j ;
for(i=0 ; i<2 ; i++ )
   {
for(j=0 ; j < 16 ; j++ )
SDL_FreeSurface(P->mat[i][j]);
   }
}




int controlerpersonnage(SDL_Event event,personne *E)
{
int test;
if(event.type==SDL_KEYDOWN)
    {
        

if(event.key.keysym.sym==SDLK_t)
{
test=1;
}
if(event.key.keysym.sym==SDLK_l)
{
test=2;
}
if(event.key.keysym.sym==SDLK_c)
{
test=3;
}
if(event.key.keysym.sym==SDLK_h)
{
test=4;
}


        if(event.key.keysym.sym==SDLK_SPACE&&E->saut!=1)
        {
            test=5;
        }
if(event.key.keysym.sym==SDLK_s&&E->saut!=2)
{
test=6;
}



    }
return test;
}











///////////////////FAROUKK//////////////////


void initperso_partage_plan1(personne *E)
{
    
    E->pos.x = 400;
    E->pos.y = 120;
E->vitesse=1;
E->compteur=0;
E->saut=0;
E->vie=2;

}
void initperso_partage_plan2(personne *E)
{
    
    E->pos.x = 400;
    E->pos.y = 430;
E->vitesse=1;
E->compteur=0;
E->saut=0;
E->vie=2;

}

void initperso2_partage_plan1(personne *E)

{
E->pos.x = 50;
    E->pos.y = 90;
E->vitesse=1;
E->compteur=0;
E->saut=0;
}
void initperso2_partage_plan2(personne *E)

{
E->pos.x = 50;
    E->pos.y = 390;
E->vitesse=1;
E->compteur=0;
E->saut=0;
}

void animerperso_partage(personne *E)
{

E->compteur++;
//printf("%d\n",E->saut);
if(E->compteur>=80&&E->saut==1){E->saut=0;}
if(E->compteur>=80){E->compteur=0;}


//printf("%d\n",somme);

}


void init_partage(personne *E)
{
    E->mat[0][0]=IMG_Load("fils_partage/1p.png");
    E->mat[0][1]=IMG_Load("fils_partage/2p.png");
    E->mat[0][2]=IMG_Load("fils_partage/3p.png");
    E->mat[0][3]=IMG_Load("fils_partage/4p.png");
    E->mat[0][4]=IMG_Load("fils_partage/5p.png");
    E->mat[0][5]=IMG_Load("fils_partage/6p.png");
    E->mat[0][6]=IMG_Load("fils_partage/7p.png");
    E->mat[0][7]=IMG_Load("fils_partage/8p.png");
    E->mat[0][8]=IMG_Load("fils_partage/9p.png");
    E->mat[0][9]=IMG_Load("fils_partage/10p.png");
    E->mat[0][10]=IMG_Load("fils_partage/11p.png");
    E->mat[0][11]=IMG_Load("fils_partage/12p.png");
    E->mat[0][12]=IMG_Load("fils_partage/13p.png");
    E->mat[0][13]=IMG_Load("fils_partage/14p.png");
    E->mat[0][14]=IMG_Load("fils_partage/15p.png");
    E->mat[0][15]=IMG_Load("fils_partage/16p.png");

    
    
    // *************************************animation sauter (jump)
    
    E->mat[1][0]=IMG_Load("fils_partage/2jp.png");
    E->mat[1][1]=IMG_Load("fils_partage/2jp.png");
    E->mat[1][2]=IMG_Load("fils_partage/3p.png");
    E->mat[1][3]=IMG_Load("fils_partage/4p.png");
    E->mat[1][4]=IMG_Load("fils_partage/5jp.png");
    E->mat[1][5]=IMG_Load("fils_partage/6jp.png");
    E->mat[1][6]=IMG_Load("fils_partage/7jp.png");
    E->mat[1][7]=IMG_Load("fils_partage/8jp.png");
    E->mat[1][8]=IMG_Load("fils_partage/9jp.png");
    E->mat[1][9]=IMG_Load("fils_partage/10jp.png");
    E->mat[1][10]=IMG_Load("fils_partage/11jp.png");
    E->mat[1][11]=IMG_Load("fils_partage/12jp.png");
    E->mat[1][12]=IMG_Load("fils_partage/13jp.png");
    E->mat[1][13]=IMG_Load("fils_partage/13jp.png");
    E->mat[1][14]=IMG_Load("fils_partage/13jp.png");
    E->mat[1][15]=IMG_Load("fils_partage/13jp.png");
}


void init2_partage(personne *E)
{

// *************************************animation normal (run)

    E->mat[0][0]=IMG_Load("merePicsP/mere1.png");
    E->mat[0][1]=IMG_Load("merePicsP/mere2.png");
    E->mat[0][2]=IMG_Load("merePicsP/mere3.png");
    E->mat[0][3]=IMG_Load("merePicsP/mere4.png");
    E->mat[0][4]=IMG_Load("merePicsP/mere5.png");
    E->mat[0][5]=IMG_Load("merePicsP/mere6.png");
    E->mat[0][6]=IMG_Load("merePicsP/mere7.png");
    E->mat[0][7]=IMG_Load("merePicsP/mere8.png");
    E->mat[0][8]=IMG_Load("merePicsP/mere9.png");
    E->mat[0][9]=IMG_Load("merePicsP/mere10.png");
    E->mat[0][10]=IMG_Load("merePicsP/mere11.png");
    E->mat[0][11]=IMG_Load("merePicsP/mere12.png");
    E->mat[0][12]=IMG_Load("merePicsP/mere13.png");
    E->mat[0][13]=IMG_Load("merePicsP/mere14.png");
    E->mat[0][14]=IMG_Load("merePicsP/mere15.png");
    E->mat[0][15]=IMG_Load("merePicsP/mere16.png");

    
    
    // *************************************animation sauter (jump)
    
    E->mat[1][0]=IMG_Load("merePicsP/merej2.png");
    E->mat[1][1]=IMG_Load("merePicsP/merej2.png");
    E->mat[1][2]=IMG_Load("merePicsP/merej3.png");
    E->mat[1][3]=IMG_Load("merePicsP/merej4.png");
    E->mat[1][4]=IMG_Load("merePicsP/merej5.png");
    E->mat[1][5]=IMG_Load("merePicsP/merej6.png");
    E->mat[1][6]=IMG_Load("merePicsP/merej7.png");
    E->mat[1][7]=IMG_Load("merePicsP/merej8.png");
    E->mat[1][8]=IMG_Load("merePicsP/merej9.png");
    E->mat[1][9]=IMG_Load("merePicsP/merej10.png");
    E->mat[1][10]=IMG_Load("merePicsP/merej11.png");
    E->mat[1][11]=IMG_Load("merePicsP/merej12.png");
    E->mat[1][12]=IMG_Load("merePicsP/merej13.png");
    E->mat[1][13]=IMG_Load("merePicsP/merej13.png");
    E->mat[1][14]=IMG_Load("merePicsP/merej13.png");
    E->mat[1][15]=IMG_Load("merePicsP/merej13.png");
}   

 
void afficherperso_partage_plan1(personne *E,SDL_Surface *fenetre)
{
int i;
i=E->compteur/5;
if(E->saut==1)
{
/*
if(E->pos.y>=200&&E->pos.y<=80)
{
E->pos.y=E->pos.y-10;
}
if(E->pos.y>80&&E->pos.y<=200)
{
E->pos.y=E->pos.y+10;
}
*/
/*printf("i=%d\n",i);
if(i>=0&&i<=7)
{
E->pos.y=E->pos.y-10;
}
if(i>7&&i<15)
{
E->pos.y=E->pos.y+6;

}
if(i==16){E->pos.y=200;}*/
if (E->compteur<=40)
{ E->pos.y-=3;}

if (E->compteur>40 && E->compteur<80)
{ E->pos.y+=3;}


if (i>=15)
{E->pos.y=120;}

}


                SDL_BlitSurface(E->mat[E->saut][i],NULL,fenetre,&E->pos);

   
  //E->saut=0;  
}

void afficherperso_partage_plan2(personne *E,SDL_Surface *fenetre)
{
int i;
i=E->compteur/5;
if(E->saut==1)
{
/*
if(E->pos.y>=200&&E->pos.y<=80)
{
E->pos.y=E->pos.y-10;
}
if(E->pos.y>80&&E->pos.y<=200)
{
E->pos.y=E->pos.y+10;
}
*/
/*printf("i=%d\n",i);
if(i>=0&&i<=7)
{
E->pos.y=E->pos.y-10;
}
if(i>7&&i<15)
{
E->pos.y=E->pos.y+6;

}
if(i==16){E->pos.y=200;}*/
if (E->compteur<=40)
{ E->pos.y-=3;}

if (E->compteur>40 && E->compteur<80)
{ E->pos.y+=3;}

if (i>=15)
{E->pos.y=420;}

}


                SDL_BlitSurface(E->mat[E->saut][i],NULL,fenetre,&E->pos);

   
  //E->saut=0;  
}



////////////////////////////////////////////








