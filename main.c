#include <stdlib.h>
#include <stdio.h>
#include "struct.h"



int main() {
    system("clear");
    nod *list = start_nod();
    if(!list) {
        fprintf(stderr, "Erreur");
        return 1; 
    }

    char tableau [10][10];


// On forme les maillons avec les coord de base qu'on veut pour notre user, notre box et notre destination
nod *user = create_list(4, 5, USER);
nod *box = create_list(3, 4, BOX);
nod *destination = create_list(7, 8, DESTINATION);




// On les relie entre eux sans oublier de renvoyer le dernier vers NULL
user->next = box;
box->next = destination;
destination->next = NULL;  // On lie le user, a la chaine de la box, la chaine de la box a la destination et on ferme la liste chainee

list = user;

char check;
int win = 0;
while (!win) {
    system("clear");
    board_display(list);
    printf("Choisissez un mouvement : haut(z) bas(s) gauche(q) droite(d) arreter(a) : ");
    scanf("%c", &check);
    
    if (check == 'a') {
        printf("On sort du jeu \n");
        return 0;
    }
    
    win = moves(list, check);
    win = win_condition(list);
}

board_display(list);
if (win)
    printf("C'est gagne ! \n");
else
    printf("C'est perdu ! \n");

// On free la memoire

nod *tmp;
while(tmp != NULL){
    nod *list = tmp;
    tmp = tmp->next;
    free(tmp);
}



return 0;






}
























