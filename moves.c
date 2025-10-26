#include <stdlib.h>
#include <stdio.h>
#include "struct.h"

//Source et aide : https://www.youtube.com/watch?v=vnynz0djT3I&t=208s

int moves(nod *list, char touches) {

    nod *user = list;
    nod *box =  list->next;

    int mx = 0;  // Creation de variables initialise a 0 pour stocker les coordonnees des deplacements (m pour moves)
    int my = 0;

    if (touches == 'z') mx = -1;      // Ici les nouvelles variables, en fonction de la touche appuyee, sont initialises a 1 ou -1(axe des abscisses et des ordonnees)
    else if (touches == 's') mx = 1;
    else if (touches == 'q') my = -1;
    else if (touches == 'd') my = 1;
    
    else return 0;


    int new_pos_x = user->x + mx;  // Ici, on ajoute aux positions determines suite aux touches, la nouvelle position que le user 'X' va reach
    int new_pos_y = user->y + my;

    if (new_pos_x == 0 || new_pos_x == 10-1 || new_pos_y == 0 || new_pos_y == 10-1) return (0);  // Pour check si on touche les limites de la map ou pas

    if (new_pos_x == box->x && new_pos_y == box->y) {  // Si les coord de deplacements concordent avec celles de la box, on update les coord potentielles et celles de la boite 
        int box_x = box->x + mx;
        int box_y = box->y + my;

        if (box_x == 0 || box_x == 10-1 || box_y == 0 || box_y == 10-1) return (0); // Retourner une erreur si la boite aussi touche les bords de la map

        box->x = box_x; // Une fois les conditions testes, on update les coord de la boite dans les maillons pour les deplacer
        box->y = box_y;

    }

    user->x = new_pos_x; // Meme procede, on update les nouvelles positions du user au niveau des maillons, pour pouvoir le deplacer
    user->y = new_pos_y; 

    return win_condition(list); //Une fois la destination atteinte, on renvoie a l'usersi il a gagné ou non via la fonction de win condition
}