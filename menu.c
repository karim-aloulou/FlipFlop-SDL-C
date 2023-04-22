#include"menu.h"
////Functions PARTAGE ECRAN ://///////////////////////////////////////////////
void init_menu_multiplayer (menu_jouer *j)
{
	j->background = IMG_Load( "fondflou.gif");
	j->solo = j->duo = IMG_Load("bouton.gif");
	j->boutton_active  = IMG_Load("Btn 1 click.png");
	
	
	j->quit = IMG_Load("xx.png");
	j->quit_active=IMG_Load("quit.png");
	
	
	TTF_Font *fontTest;
	fontTest=TTF_OpenFont("game.ttf",35);//police w taille
	SDL_Color fontColor={0,0,0};
	j->text1 = TTF_RenderText_Blended(fontTest,"SOLO",fontColor);
	j->text2 = TTF_RenderText_Blended(fontTest,"1 VS 1",fontColor);
	
	j->backgroundpos.x = j->backgroundpos.y = 0 ; 
	j->solopos.x = 400;
	j->solopos.y = 200+80;
	j->text1pos.x = 460;
	j->text1pos.y = 210+80;
	j->duopos.x = 400;
	j->duopos.y = 400-30;
	j->text2pos.x = 460;
	j->text2pos.y = 410-30;
	
	j->solopos_active.x = 370;
	j->solopos_active.y = 170+80;
	j->duopos_active.x = 370;
	j->duopos_active.y = 370-30;
	
	j->quitpos.x = 420;
	j->quitpos.y =100 ; 
	j->quitpos_active.x = 576;
	j->quitpos_active.y = 148; 
	
	

}
void affichage_menu_multiplayer ( menu_jouer j , SDL_Surface *screen ,int x  ) 
{

	SDL_BlitSurface(j.background,NULL,screen,&j.backgroundpos);
	switch (x)
	{ 
	case 0 :
	
	SDL_BlitSurface(j.solo,NULL,screen,&j.solopos);
	SDL_BlitSurface(j.duo,NULL,screen,&j.duopos);
	SDL_BlitSurface(j.quit,NULL,screen,&j.quitpos);
	break;
	case 1 :
	SDL_BlitSurface(j.boutton_active,NULL,screen,&j.solopos_active);
	SDL_BlitSurface(j.duo,NULL,screen,&j.duopos);
	SDL_BlitSurface(j.quit,NULL,screen,&j.quitpos);
	break;
	case 2 :
	SDL_BlitSurface(j.solo,NULL,screen,&j.solopos);
	SDL_BlitSurface(j.boutton_active,NULL,screen,&j.duopos_active);
	SDL_BlitSurface(j.quit,NULL,screen,&j.quitpos);
	break;
	case 3 : 
	SDL_BlitSurface(j.solo,NULL,screen,&j.solopos);
	SDL_BlitSurface(j.duo,NULL,screen,&j.duopos);
	SDL_BlitSurface(j.quit_active,NULL,screen,&j.quitpos_active);
	break;
	}
	SDL_BlitSurface(j.text1,NULL,screen,&j.text1pos);
	SDL_BlitSurface(j.text2,NULL,screen,&j.text2pos);
	
	
	
}

int update_menu_multiplayer (SDL_Event event,int jeu)
{
	
if((event.motion.x>375)&&(event.motion.x<570)&&(event.motion.y>280)&&(event.motion.y<330)&&(event.button.button==SDL_BUTTON_LEFT)&&(jeu==1))
	return 3 ;
	
	else if ((event.motion.x>375)&&(event.motion.x<570)&&(event.motion.y>400)&&(event.motion.y<450)&&(event.button.button==SDL_BUTTON_LEFT)&&(jeu==1))
	return 4;
	else if ((event.motion.x>550)&&(event.motion.x<600)&&(event.motion.y>120)&&(event.motion.y<190)&&(event.button.button==SDL_BUTTON_LEFT)&&(jeu==1))
	return 6;
	else if ((event.motion.x>550)&&(event.motion.x<600)&&(event.motion.y>120)&&(event.motion.y<190)&&(jeu==1))
	return 5 ;
	else if((event.motion.x>375)&&(event.motion.x<570)&&(event.motion.y>200+80)&&(event.motion.y<250+80)&&(jeu==1))
	return 1 ;
	else if ((event.motion.x>375)&&(event.motion.x<570)&&(event.motion.y>400)&&(event.motion.y<450)&&(jeu==1))
	return 2 ;
	else 
	return 0 ;
}


int menu(int *jeu){
int a=0,b=0,c=0,d=0;

SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO |SDL_DOUBLEBUF|SDL_FULLSCREEN);
TTF_Init();

//******************************************************************POLICE***********************************
//cree une police
TTF_Font *fontTest;
fontTest=TTF_OpenFont("game.ttf",35);//police w taille
SDL_Color fontColor={0,0,0};//couleur du texteTTF_Font *fontTest;

SDL_Color colorCoor={0,0,0};
SDL_Surface *coordinates;
char coorText[20];
//sprintf(coorText,"%d,%d");
coordinates=TTF_RenderText_Blended(fontTest,"0,0",colorCoor);
SDL_Rect coordinatesPostion;
coordinatesPostion.x=0;
coordinatesPostion.y=0;



//******************************************************************MUSIC***********************************
//initialisation music
if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 2048 ) == -1);
  {
      printf("Erreur initialisation SDL_mixer :%s", Mix_GetError());
   }
Mix_Music *musique;
Mix_Chunk *soundEffect;
  soundEffect=Mix_LoadWAV("son_bref.wav");
musique=Mix_LoadMUS("soncontinue.mp3");
Mix_PlayMusic(musique,-1);





//**************************************************************************FENETRE************************
SDL_Surface *fenetre=NULL;//initialiser une surface fenetre

//****************************************************************************MENU**************************

//background menu 
SDL_Surface *personnage;

//initialisation boutons menu
SDL_Surface *bouton_jouer;
SDL_Surface *bouton_option;
SDL_Surface *bouton_quitter;
SDL_Surface *mere;
SDL_Surface *fils;
SDL_Surface *animation1=malloc(sizeof(animation1));
SDL_Surface *animation2=malloc(sizeof(animation2));





//Load boutons menu
personnage=IMG_Load("ahla7.gif");
bouton_jouer=IMG_Load("bouton.gif");
bouton_option=IMG_Load("bouton.gif");
bouton_quitter=IMG_Load("bouton.gif");
mere=IMG_Load("mom.png");
fils=IMG_Load("fils2.png");



//positions boutons menu    //on peut faire width et hight 
SDL_Rect personnagePosition;
personnagePosition.x=0;
personnagePosition.y=0;

SDL_Rect background_optionPosition;
background_optionPosition.x=0;
background_optionPosition.y=0;

SDL_Rect bouton_jouerPosition;
bouton_jouerPosition.x=400;
bouton_jouerPosition.y=200;

SDL_Rect bouton_optionPosition;
bouton_optionPosition.x=400;
bouton_optionPosition.y=300;

SDL_Rect bouton_quitterPosition;
bouton_quitterPosition.x=400;
bouton_quitterPosition.y=400;

SDL_Rect merePosition;
merePosition.x=585;
merePosition.y=138;

SDL_Rect filsPosition;
filsPosition.x=170;
filsPosition.y=200;

SDL_Rect animation1Position;
animation1Position.x=250;
animation1Position.y=380;

SDL_Rect animation2Position;
animation2Position.x=-10;
animation2Position.y=340;





//positions botons menu active 
SDL_Rect bouton_jouer_active_Position;
SDL_Rect bouton_option_active_Position;
SDL_Rect bouton_quitter_active_Position;

bouton_jouer_active_Position.x=372;
bouton_jouer_active_Position.y=172;

bouton_option_active_Position.x=372;
bouton_option_active_Position.y=272;

bouton_quitter_active_Position.x=372;
bouton_quitter_active_Position.y=372;



//texte menu
SDL_Surface *texte_quitter;
SDL_Surface *texte_option;
SDL_Surface *texte_jouer;
SDL_Surface *texte_menu;


//Render text menu
texte_quitter=TTF_RenderText_Blended(fontTest,"Quit",fontColor);
texte_option=TTF_RenderText_Blended(fontTest,"Settings",fontColor);
texte_jouer=TTF_RenderText_Blended(fontTest,"Play",fontColor);
texte_menu=TTF_RenderText_Blended(fontTest,"menu",fontColor);


//position texte menu
SDL_Rect texte_quitterPosition; 
texte_quitterPosition.x=460;
texte_quitterPosition.y=415;

SDL_Rect texte_optionPosition; 
texte_optionPosition.x=435;
texte_optionPosition.y=315;

SDL_Rect texte_jouerPosition;
texte_jouerPosition.x=460;
texte_jouerPosition.y=215;

SDL_Rect texte_menuPosition;
texte_menuPosition.x=440;
texte_menuPosition.y=70;




//*********************************************************************OPTION**********************************

//background option
SDL_Surface *background_option;

//intialisation botons option
SDL_Surface *bouton_plein_ecran;
SDL_Surface *bouton_ecran_reduit;
SDL_Surface *bouton_volume;
SDL_Surface *bouton_plus_moin;
//SDL_Surface *bouton_moin;
SDL_Surface *bouton_fermeture_option;
SDL_Surface *bouton_fermeture_option_active;



//Load bottons option
background_option=IMG_Load("fondflou.gif");
bouton_plein_ecran=IMG_Load("bouton.gif");
bouton_ecran_reduit=IMG_Load("bouton.gif");
bouton_volume=IMG_Load("100.gif");
bouton_fermeture_option=IMG_Load("xx.png");
bouton_fermeture_option_active=IMG_Load("quit.png");
bouton_plus_moin=IMG_Load("Group4.png");



//positions boutons option
SDL_Rect bouton_plein_ecranPosition;
bouton_plein_ecranPosition.x=400;
bouton_plein_ecranPosition.y=460;

SDL_Rect bouton_ecran_reduitPosition;
bouton_ecran_reduitPosition.x=400;
bouton_ecran_reduitPosition.y=385;

SDL_Rect bouton_ecran_reduit_activePosition;
bouton_ecran_reduit_activePosition.x=375;
bouton_ecran_reduit_activePosition.y=358;

SDL_Rect bouton_plein_ecran_activePosition;
bouton_plein_ecran_activePosition.x=368;
bouton_plein_ecran_activePosition.y=431;

SDL_Rect bouton_volumePosition;
bouton_volumePosition.x=250;
bouton_volumePosition.y=240;

SDL_Rect bouton_fermeture_optionPosition;
bouton_fermeture_optionPosition.x=420;
bouton_fermeture_optionPosition.y=100;

SDL_Rect bouton_fermeture_option_activePosition;
bouton_fermeture_option_activePosition.x=576;
bouton_fermeture_option_activePosition.y=148;

SDL_Rect bouton_plus_moinPosition;
bouton_plus_moinPosition.x=550;
bouton_plus_moinPosition.y=266;


//texte option
SDL_Surface *texte_plein_ecran;
SDL_Surface *texte_ecran_reduit;
SDL_Surface *texte_volume;
SDL_Surface *texte_screen;
SDL_Surface *texte_settings;


//Render texte option
texte_plein_ecran=TTF_RenderText_Blended(fontTest,"fullscreen",fontColor);
texte_ecran_reduit=TTF_RenderText_Blended(fontTest,"normal",fontColor);
texte_volume=TTF_RenderText_Blended(fontTest,"volume",fontColor);
texte_screen=TTF_RenderText_Blended(fontTest,"screen",fontColor);
texte_settings=TTF_RenderText_Blended(fontTest,"option",fontColor);




//positions texte option
SDL_Rect texte_plein_ecranPosition; 
texte_plein_ecranPosition.x=412;
texte_plein_ecranPosition.y=472;

SDL_Rect texte_ecran_reduitPosition;
texte_ecran_reduitPosition.x=440;
texte_ecran_reduitPosition.y=400;

SDL_Rect texte_volumePosition;
texte_volumePosition.x=420;
texte_volumePosition.y=230;

SDL_Rect texte_screenPosition;
texte_screenPosition.x=440;
texte_screenPosition.y=340;

SDL_Rect texte_settingsPosition;
texte_settingsPosition.x=430;
texte_settingsPosition.y=145;


//************************************************************************************************************

//botons active 
SDL_Surface *botton_active;
botton_active=IMG_Load("Btn 1 click.png");






int mouse_detect_botton=0;
int quit_option=0;
int menu=1;
int option=0;

int h;
int volume=1;


fenetre=SDL_SetVideoMode(900,600,32,SDL_HWSURFACE | SDL_DOUBLEBUF);//surface de type fenetre b taille eli theb aaleha


SDL_Event event;

while(1)
{


/*//Animation Background Menu 
animation1Position.x=animation1Position.x+2;
animation2Position.x=animation2Position.x+2;
//SDL_Delay(100);

if(animation2Position.x==850)
{
animation1Position.x=200;
animation2Position.x=0;
}
else if(animation1Position.x>50 && animation1Position.x<100 )
{
animation1=IMG_Load("animation/fils22.png");
animation2=IMG_Load("animation/mere22.png");
}
else if(animation1Position.x>100 && animation1Position.x<150 )
{
animation1=IMG_Load("animation/fils33.png");
animation2=IMG_Load("animation/mere33.png");
}
else if(animation1Position.x>150 && animation1Position.x<200 )
{
animation1=IMG_Load("animation/fils44.png");
animation2=IMG_Load("animation/mere44.png");
}
else if(animation1Position.x>200 && animation1Position.x<250 )
{
animation1=IMG_Load("animation/fils55.png");
animation2=IMG_Load("animation/mere55.png");
}
else if(animation1Position.x>250 && animation1Position.x<300 )
{
animation1=IMG_Load("animation/fils66.png");
animation2=IMG_Load("animation/mere66.png");
}
else if(animation1Position.x>300 && animation1Position.x<350 )
{
animation1=IMG_Load("animation/fils1.png");
animation2=IMG_Load("animation/mere77.png");
}
else if(animation1Position.x>350 && animation1Position.x<400 )
{
animation1=IMG_Load("animation/fils22.png");
animation2=IMG_Load("animation/mere88.png");
}
else if(animation1Position.x>400 && animation1Position.x<450 )
{
animation1=IMG_Load("animation/fils33.png");
animation2=IMG_Load("animation/mere99.png");
}
else if(animation1Position.x>450 && animation1Position.x<500 )
{
animation1=IMG_Load("animation/fils44.png");
animation2=IMG_Load("animation/mere10.png");
}
else if(animation1Position.x>500 && animation1Position.x<550 )
{
animation1=IMG_Load("animation/fils55.png");
animation2=IMG_Load("animation/mere11.png");
}
else if(animation1Position.x>550 && animation1Position.x<600 )
{
animation1=IMG_Load("animation/fils66.png");
animation2=IMG_Load("animation/mere22.png");
}
else if(animation1Position.x>600 && animation1Position.x<650 )
{
animation1=IMG_Load("animation/fils1.png");
}
else if(animation1Position.x>650 && animation1Position.x<700 )
{
animation1=IMG_Load("animation/fils22.png");
animation2=IMG_Load("animation/mere33.png");
}
else if(animation1Position.x>700 && animation1Position.x<750 )
{
animation1=IMG_Load("animation/fils33.png");
animation2=IMG_Load("animation/mere44.png");
}
else if(animation1Position.x>750 && animation1Position.x<800 )
{
animation1=IMG_Load("animation/fils44.png");
animation2=IMG_Load("animation/mere55.png");
}
else if(animation1Position.x>800 && animation1Position.x<850 )
{
animation1=IMG_Load("animation/fils55.png");
animation2=IMG_Load("animation/mere66.png");
}
else if(animation1Position.x>850)
{
animation1=IMG_Load("animation/fils66.png");
animation2=IMG_Load("animation/mere77.png");
}
*/

SDL_PollEvent(&event);


if((event.type==SDL_KEYDOWN)&&((option==1)||(menu==1)))//ay felsa tetnzel bech yodkhol lil if hedhi
{
if(event.key.keysym.sym==SDLK_d)
{
volume=volume+5;
SDL_Delay(250);
h=volume;
}

if(event.key.keysym.sym==SDLK_u){
volume=volume-5;
SDL_Delay(250);
h=volume;
if(volume==-4){volume=1;}
}


//*******************************************************REGLAGE VOLUME AHMED *****************

if(h==1)
{
if(Mix_PausedMusic() == 1)//Si la musique est en pause
                    {
                        Mix_ResumeMusic(); //Reprendre la musique
                    }
bouton_volume=IMG_Load("100.gif");
}
if(h==6)
{
if(Mix_PausedMusic() == 1)//Si la musique est en pause
                    {
                        Mix_ResumeMusic(); //Reprendre la musique
                    }
bouton_volume=IMG_Load("75.gif");
}
if(h==11)
{
if(Mix_PausedMusic() == 1)//Si la musique est en pause
                    {
                        Mix_ResumeMusic(); //Reprendre la musique
                    }
bouton_volume=IMG_Load("50.gif");
}
if(h==16)
{
if(Mix_PausedMusic() == 1)//Si la musique est en pause
                    {
                        Mix_ResumeMusic(); //Reprendre la musique
                    }
bouton_volume=IMG_Load("25.gif");
}
if(h==21)
{
Mix_PauseMusic();
bouton_volume=IMG_Load("0.gif");
}

Mix_VolumeMusic(MIX_MAX_VOLUME / volume);
}






if(event.type==SDL_QUIT) {return 3 ;}


else if(event.type==SDL_KEYDOWN)//ay felsa tetnzel bech yodkhol lil if hedhi
{

 if((event.key.keysym.sym==SDLK_DOWN)&&(option==0)&&(menu==1) && a==0 &&b==0 &&c==0 &&d==0)
{mouse_detect_botton=1;
d=0;
a=1;
SDL_Delay(150);
}
 else if((event.key.keysym.sym==SDLK_DOWN)&&(option==0)&&(menu==1) && a==1 && b==0 && c==0 && d==0)
{mouse_detect_botton=2;
a=0;
b=1;
SDL_Delay(150);
}
 else if((event.key.keysym.sym==SDLK_DOWN)&&(option==0)&&(menu==1) && b==1 && a==0 && c==0 &&d==0)
{mouse_detect_botton=3;
b=0;
c=1; 
SDL_Delay(150);
}

else if((event.key.keysym.sym==SDLK_DOWN)&&(option==0)&&(menu==1) && b==0 && a==0 && c==1 && d==0)
{mouse_detect_botton=1;
c=0;
SDL_Delay(150);
}

else if ((event.key.keysym.sym==SDLK_RETURN)&& mouse_detect_botton==2)
{menu=0;option=1;
mouse_detect_botton=0;}

else if ((event.key.keysym.sym==SDLK_RETURN)&& mouse_detect_botton==1)
{(*jeu)=1;
return 1;}
}


else if((event.type==SDL_MOUSEBUTTONDOWN)&&(menu==1)){
if((event.button.button==SDL_BUTTON_LEFT)&&(event.motion.x>375)&&(event.motion.x<570)&&(event.motion.y>300)&&(event.motion.y<350))
{
Mix_PlayChannel(-1,soundEffect,0);

option=1;
menu=0;
}

/*----*/else if((event.button.button==SDL_BUTTON_LEFT)&&(event.motion.x>400)&&(event.motion.x<570)&&(event.motion.y>200)&&(event.motion.y<262)&&(option==0)&& (*jeu)==0) 
{

//Mix_PlayChannel(-1,soundEffect,0);
(*jeu)=1;
menu=0;
return 1;
}


/*----*/


else if ((event.motion.x>375)&&(event.motion.x<570)&&(event.motion.y>200)&&(event.motion.y<250)&&(option==0))
Mix_PlayChannel(-1,soundEffect,0);
}
else if((menu==1)&&(event.type==SDL_MOUSEMOTION)){
int x;
int y;
SDL_GetMouseState(&x,&y); 
if((event.motion.x>375)&&(event.motion.x<570)&&(event.motion.y>200)&&(event.motion.y<250)&&(option==0)) 
{

//Mix_PlayChannel(-1,soundEffect,0);
mouse_detect_botton=1;
}

else if((event.motion.x>375)&&(event.motion.x<570)&&(event.motion.y>300)&&(event.motion.y<350)&&(option==0)) 
{

//Mix_PlayChannel(-1,soundEffect,0);
mouse_detect_botton=2;
}
else if((event.motion.x>375)&&(event.motion.x<570)&&(event.motion.y>400)&&(event.motion.y<450)&&(option==0)) 
{

//Mix_PlayChannel(-1,soundEffect,0);
mouse_detect_botton=3;
}






else
mouse_detect_botton=0;
}
else if ((option==1)&&(event.type==SDL_MOUSEMOTION))
{
int x;
int y;
SDL_GetMouseState(&x,&y);
if((event.motion.x>550)&&(event.motion.x<600)&&(event.motion.y>120)&&(event.motion.y<190))
quit_option=1;
else if ((event.motion.x>400)&&(event.motion.x<600)&&(event.motion.y>375)&&(event.motion.y<450)&&(option==1)) 
mouse_detect_botton=4;
else if((event.motion.x>400)&&(event.motion.x<550)&&(event.motion.y>460)&&(event.motion.y<520)&&(option==1))
mouse_detect_botton=5;
else
{quit_option=0;
mouse_detect_botton=0;
}
 }



else if ((option==1)&&(event.type==SDL_MOUSEBUTTONDOWN))
{
int x;
int y;
SDL_GetMouseState(&x,&y);
if((event.motion.x>550)&&(event.motion.x<600)&&(event.motion.y>120)&&(event.motion.y<190)&&(event.button.button==SDL_BUTTON_LEFT))
{menu=1;
option=0;
quit_option=0;
Mix_PlayChannel(-1,soundEffect,0);}
else if ((x>544)&&(x<580)&&(y>264)&&(y<315)&&(event.button.button==SDL_BUTTON_LEFT))
{
    volume=volume+5;
    h=volume;
    menu=0;

    //Mix_PlayChannel(-1,soundEffect,0);
}
else if ((x>590)&&(x<640)&&(y>264)&&(y<315)&&(event.button.button==SDL_BUTTON_LEFT))
{
    volume=volume-5;
    h=volume;
    menu=0;
    //Mix_PlayChannel(-1,soundEffect,0);
    if(volume==-4){volume=1;}
}
else
menu=0;
}
else if ((option==0)&&((*jeu)==0)&&(event.motion.x>375)&&(event.motion.x<570)&&(event.motion.y>400)&&(event.motion.y<450)&&(event.button.button==SDL_BUTTON_LEFT))
{return 3 ;}


if(event.type==SDL_MOUSEMOTION)
{
sprintf(coorText,"%d,%d",event.motion.x,event.motion.y);
coordinates=TTF_RenderText_Blended(fontTest,coorText,colorCoor);
}






if( ( option == 0 )&&( menu==1 )&&((*jeu)==0))
{
switch (mouse_detect_botton)
{
case 0 :
SDL_BlitSurface(personnage,NULL,fenetre,&personnagePosition);//bech nharkou taswira lil position jdida


SDL_BlitSurface(bouton_jouer,NULL,fenetre,&bouton_jouerPosition);
SDL_BlitSurface(bouton_option,NULL,fenetre,&bouton_optionPosition);
SDL_BlitSurface(bouton_quitter,NULL,fenetre,&bouton_quitterPosition);
SDL_BlitSurface(mere,NULL,fenetre,&merePosition);
SDL_BlitSurface(fils,NULL,fenetre,&filsPosition);
SDL_BlitSurface(animation1,NULL,fenetre,&animation1Position);
SDL_BlitSurface(animation2,NULL,fenetre,&animation2Position);
SDL_BlitSurface(texte_quitter,NULL,fenetre,&texte_quitterPosition);
SDL_BlitSurface(texte_option,NULL,fenetre,&texte_optionPosition);
SDL_BlitSurface(texte_jouer,NULL,fenetre,&texte_jouerPosition);
SDL_BlitSurface(coordinates,NULL,fenetre,&coordinatesPostion);
SDL_Flip(fenetre);
break;

case 1 :
SDL_BlitSurface(personnage,NULL,fenetre,&personnagePosition);
SDL_BlitSurface(botton_active,NULL,fenetre,&bouton_jouer_active_Position);
SDL_BlitSurface(bouton_option,NULL,fenetre,&bouton_optionPosition);
SDL_BlitSurface(bouton_quitter,NULL,fenetre,&bouton_quitterPosition);
SDL_BlitSurface(mere,NULL,fenetre,&merePosition);
SDL_BlitSurface(fils,NULL,fenetre,&filsPosition);
SDL_BlitSurface(animation1,NULL,fenetre,&animation1Position);
SDL_BlitSurface(animation2,NULL,fenetre,&animation2Position);
SDL_BlitSurface(texte_quitter,NULL,fenetre,&texte_quitterPosition);
SDL_BlitSurface(texte_option,NULL,fenetre,&texte_optionPosition);
SDL_BlitSurface(texte_jouer,NULL,fenetre,&texte_jouerPosition);
SDL_Flip(fenetre);
break;

case 2 :
SDL_BlitSurface(personnage,NULL,fenetre,&personnagePosition);
SDL_BlitSurface(bouton_jouer,NULL,fenetre,&bouton_jouerPosition);
SDL_BlitSurface(botton_active,NULL,fenetre,&bouton_option_active_Position);
SDL_BlitSurface(bouton_quitter,NULL,fenetre,&bouton_quitterPosition);
SDL_BlitSurface(mere,NULL,fenetre,&merePosition);
SDL_BlitSurface(fils,NULL,fenetre,&filsPosition);
SDL_BlitSurface(animation1,NULL,fenetre,&animation1Position);
SDL_BlitSurface(animation2,NULL,fenetre,&animation2Position);
SDL_BlitSurface(texte_quitter,NULL,fenetre,&texte_quitterPosition);
SDL_BlitSurface(texte_option,NULL,fenetre,&texte_optionPosition);
SDL_BlitSurface(texte_jouer,NULL,fenetre,&texte_jouerPosition);
SDL_Flip(fenetre);
break;

case 3 :
SDL_BlitSurface(personnage,NULL,fenetre,&personnagePosition);
SDL_BlitSurface(bouton_jouer,NULL,fenetre,&bouton_jouerPosition);
SDL_BlitSurface(bouton_option,NULL,fenetre,&bouton_optionPosition);
SDL_BlitSurface(botton_active,NULL,fenetre,&bouton_quitter_active_Position);
SDL_BlitSurface(mere,NULL,fenetre,&merePosition);
SDL_BlitSurface(fils,NULL,fenetre,&filsPosition);
SDL_BlitSurface(animation1,NULL,fenetre,&animation1Position);
SDL_BlitSurface(animation2,NULL,fenetre,&animation2Position);
SDL_BlitSurface(texte_quitter,NULL,fenetre,&texte_quitterPosition);
SDL_BlitSurface(texte_option,NULL,fenetre,&texte_optionPosition);
SDL_BlitSurface(texte_jouer,NULL,fenetre,&texte_jouerPosition);
SDL_Flip(fenetre);
break;
}
}

if((option==1)&&(menu==0)&&((*jeu)==0))
{


switch(mouse_detect_botton)
{
case 0 :
if(quit_option==0)
{
SDL_BlitSurface(background_option,NULL,fenetre,&personnagePosition);
SDL_BlitSurface(bouton_plein_ecran,NULL,fenetre,&bouton_plein_ecranPosition);
SDL_BlitSurface(bouton_ecran_reduit,NULL,fenetre,&bouton_ecran_reduitPosition);
SDL_BlitSurface(bouton_volume,NULL,fenetre,&bouton_volumePosition);
SDL_BlitSurface(bouton_plus_moin,NULL,fenetre,&bouton_plus_moinPosition);
SDL_BlitSurface(bouton_fermeture_option,NULL,fenetre,&bouton_fermeture_optionPosition);
//SDL_BlitSurface(bouton_fermeture_option_active,NULL,fenetre,&bouton_fermeture_option_activePosition);
SDL_BlitSurface(texte_ecran_reduit,NULL,fenetre,&texte_ecran_reduitPosition);
SDL_BlitSurface(texte_volume,NULL,fenetre,&texte_volumePosition);
SDL_BlitSurface(texte_screen,NULL,fenetre,&texte_screenPosition);
SDL_BlitSurface(texte_settings,NULL,fenetre,&texte_settingsPosition);
SDL_BlitSurface(texte_plein_ecran,NULL,fenetre,&texte_plein_ecranPosition);
SDL_BlitSurface(mere,NULL,fenetre,&merePosition);
SDL_BlitSurface(fils,NULL,fenetre,&filsPosition);
SDL_BlitSurface(coordinates,NULL,fenetre,&coordinatesPostion);
SDL_Flip(fenetre);
}
else if(quit_option==1)
{
SDL_BlitSurface(background_option,NULL,fenetre,&personnagePosition);
SDL_BlitSurface(bouton_plein_ecran,NULL,fenetre,&bouton_plein_ecranPosition);
SDL_BlitSurface(bouton_ecran_reduit,NULL,fenetre,&bouton_ecran_reduitPosition);
SDL_BlitSurface(bouton_volume,NULL,fenetre,&bouton_volumePosition);
SDL_BlitSurface(bouton_plus_moin,NULL,fenetre,&bouton_plus_moinPosition);
//SDL_BlitSurface(bouton_fermeture_option,NULL,fenetre,&bouton_fermeture_optionPosition);
SDL_BlitSurface(bouton_fermeture_option_active,NULL,fenetre,&bouton_fermeture_option_activePosition);
SDL_BlitSurface(texte_ecran_reduit,NULL,fenetre,&texte_ecran_reduitPosition);
SDL_BlitSurface(texte_volume,NULL,fenetre,&texte_volumePosition);
SDL_BlitSurface(texte_screen,NULL,fenetre,&texte_screenPosition);
SDL_BlitSurface(texte_settings,NULL,fenetre,&texte_settingsPosition);
SDL_BlitSurface(texte_plein_ecran,NULL,fenetre,&texte_plein_ecranPosition);
SDL_BlitSurface(mere,NULL,fenetre,&merePosition);
SDL_BlitSurface(fils,NULL,fenetre,&filsPosition);
SDL_BlitSurface(coordinates,NULL,fenetre,&coordinatesPostion);
SDL_Flip(fenetre);
}
break;
case 4 :
SDL_BlitSurface(background_option,NULL,fenetre,&personnagePosition);
SDL_BlitSurface(bouton_plein_ecran,NULL,fenetre,&bouton_plein_ecranPosition);
SDL_BlitSurface(botton_active,NULL,fenetre,&bouton_ecran_reduit_activePosition);
SDL_BlitSurface(bouton_volume,NULL,fenetre,&bouton_volumePosition);
SDL_BlitSurface(bouton_plus_moin,NULL,fenetre,&bouton_plus_moinPosition);
SDL_BlitSurface(bouton_fermeture_option,NULL,fenetre,&bouton_fermeture_optionPosition);
//SDL_BlitSurface(bouton_fermeture_option_active,NULL,fenetre,&bouton_fermeture_option_activePosition);
SDL_BlitSurface(texte_ecran_reduit,NULL,fenetre,&texte_ecran_reduitPosition);
SDL_BlitSurface(texte_volume,NULL,fenetre,&texte_volumePosition);
SDL_BlitSurface(texte_screen,NULL,fenetre,&texte_screenPosition);
SDL_BlitSurface(texte_settings,NULL,fenetre,&texte_settingsPosition);
SDL_BlitSurface(texte_plein_ecran,NULL,fenetre,&texte_plein_ecranPosition);
SDL_BlitSurface(mere,NULL,fenetre,&merePosition);
SDL_BlitSurface(fils,NULL,fenetre,&filsPosition);
SDL_BlitSurface(coordinates,NULL,fenetre,&coordinatesPostion);
SDL_Flip(fenetre);
break;
case 5 :
SDL_BlitSurface(background_option,NULL,fenetre,&personnagePosition);
SDL_BlitSurface(botton_active,NULL,fenetre,&bouton_plein_ecran_activePosition);
SDL_BlitSurface(bouton_ecran_reduit,NULL,fenetre,&bouton_ecran_reduitPosition);
SDL_BlitSurface(bouton_volume,NULL,fenetre,&bouton_volumePosition);
SDL_BlitSurface(bouton_plus_moin,NULL,fenetre,&bouton_plus_moinPosition);
SDL_BlitSurface(bouton_fermeture_option,NULL,fenetre,&bouton_fermeture_optionPosition);
//SDL_BlitSurface(bouton_fermeture_option_active,NULL,fenetre,&bouton_fermeture_option_activePosition);
SDL_BlitSurface(texte_ecran_reduit,NULL,fenetre,&texte_ecran_reduitPosition);
SDL_BlitSurface(texte_volume,NULL,fenetre,&texte_volumePosition);
SDL_BlitSurface(texte_screen,NULL,fenetre,&texte_screenPosition);
SDL_BlitSurface(texte_settings,NULL,fenetre,&texte_settingsPosition);
SDL_BlitSurface(texte_plein_ecran,NULL,fenetre,&texte_plein_ecranPosition);
SDL_BlitSurface(mere,NULL,fenetre,&merePosition);
SDL_BlitSurface(fils,NULL,fenetre,&filsPosition);
SDL_BlitSurface(coordinates,NULL,fenetre,&coordinatesPostion);
SDL_Flip(fenetre);
break;
}

}

SDL_Flip(fenetre);
}

SDL_FreeSurface(fenetre);
SDL_FreeSurface(personnage);
SDL_FreeSurface(bouton_jouer);
SDL_FreeSurface(bouton_option);
SDL_FreeSurface(bouton_quitter);
SDL_FreeSurface(mere);
SDL_FreeSurface(fils);
SDL_FreeSurface(animation1);
SDL_FreeSurface(animation2);
SDL_FreeSurface(texte_quitter);
Mix_FreeMusic(musique);
Mix_FreeChunk(soundEffect);
Mix_CloseAudio();
Mix_Quit();
TTF_Quit();
SDL_Quit();

return 0;
}



