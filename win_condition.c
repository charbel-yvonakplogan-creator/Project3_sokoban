#include <stdlib.h>
#include <stdio.h>
#include "struct.h"

int win_condition(nod *list) {
    
    nod *box = list->next;
    nod *destination = list->next->next;

    if (box->x == destination->x && box->y == destination->y)
        return 1; // Pour indiquer que c'est win

    else
       return 0;

}