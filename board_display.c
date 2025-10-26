#include <stdlib.h>
#include <stdio.h>
#include "struct.h"

void board_display(nod *list){
char tableau[10][10];
int i;
int j;
nod *first = list; // C'est le debut de la liste chainee

for (i = 0; i<10; i++) {
    for (j = 0; j<10; j++) {
       if (i == 0 || i == 10-1 || j == 0 || j == 10-1)   //Ici on vient delimiter la map avec des symboles '#' pour definir des limites; aussi on initialise le rest avec des espaces vides.
                tableau[i][j] = LIMITE;
            else
                tableau[i][j] = SPACE;
    }
}


while (first) {
    tableau [first->x][first->y]= first->type;  //Ici on place les maillons sur la map, avec first->x et first->y qui indiquent dynamiquement les coord des chars sur la map et on pointe vers le maillon suivant
    first= first->next;
}

printf("\n");

printf("----Bienvenue dans le jeu du sokoban----");    

printf("\n");

    for (i = 0; i < 10; i++){
        for (j = 0; j < 10; j++)
            printf("%c ", tableau[i][j]);
        printf("\n");
    }

}