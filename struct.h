#ifndef _STRUCT_H
#define _STRUCT_H


typedef enum {
    USER = 'O',
    BOX = 'X',
    DESTINATION = '.',
    SPACE = ' ',
    LIMITE = '#'
} Typeobjet;

typedef struct s_soko nod;

struct s_soko {
    int x;
    int y;
    Typeobjet type;
    nod *next; //Pour indiquer le prochain maillon
};
   
nod *create_list(int x, int y, Typeobjet type);
nod *start_nod(void);

void board_display(nod *list);

int moves(nod *list, char touches);


int win_condition(nod *list);








#endif


