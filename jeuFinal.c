#include "jeuFinal.h"
#include"menu.h"
#include"new.h"



int main(int argc,char *argv[]){
int a;

switch (menu())
{
case 1:
    a=jeu();
    enigmeFinal();
break;
}
return 0;
}


