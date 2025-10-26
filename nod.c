#include <stdlib.h>
#include <stdio.h>
#include "struct.h"

nod *create_list(int x, int y, Typeobjet type) // Creation du maillon qu'on reliera plus tard aux autres pour relier la box, le joueur et la destination

{
    nod *list = malloc(sizeof(*list));
    list->next = NULL;
    list->x = x;
    list->y = y;
    list->type = type;

    return list;

}


nod *start_nod() 
{
    nod *user = create_list(4, 5, USER);
    nod *box  = create_list(3, 4, BOX);
    nod *destination = create_list(7, 8, DESTINATION);


    user->next = box;           //Ici on relie les maillons du user, de la box et de la destination entre eux. C'est une liste chainee.
    box->next = destination;

    return user; 


}