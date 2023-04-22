prog: animation_logo.o background.o entite_secondaire.o  perso.o enigmes.o menu.o main.o IA.o enigmeSF.o integrationFinale.o multijoueur.o
	gcc animation_logo.o background.o entite_secondaire.o  perso.o  multijoueur.o integrationFinale.o IA.o menu.o enigmes.o enigmeSF.o main.o -o prog -lSDL -lSDL_ttf -lSDL_image -lSDL_mixer -g
main.o:main.c
	gcc -c main.c -g
enigmes.o:enigmes.c
	gcc -c enigmes.c -g
IA.o:IA.c
	gcc -c IA.c -g
enigmeSF.o:enigmeSF.c
	gcc -c enigmeSF.c -g
menu.o:menu.c
	gcc -c menu.c -g
integrationFinale.o:integrationFinale.c
	gcc -c integrationFinale.c
multijoueur.o:multijoueur.c
	gcc -c multijoueur.c -g
background.o:background.c
	gcc -c background.c -g
animation_logo.o:animation_logo.c
	gcc -c animation_logo.c -g



