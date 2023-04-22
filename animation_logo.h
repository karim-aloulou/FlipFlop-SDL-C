#ifndef ANIMATION_LOGO_H_
#define ANIMATION_LOGO_H_

typedef struct 
{
SDL_Surface *tab_logo[10];
SDL_Rect pos_logo;
int compteur;
int quitter;

}logo;
void init_animation_logo(logo *l);
int animation_logo(logo *l,SDL_Surface *fenetre);


#endif
