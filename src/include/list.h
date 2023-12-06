#ifndef LIST_H
#define LIST_H

#include "cell.h"
#define SIZE_OF_LIST sizeof(int)

typedef struct s_d_list {
    int size;
    t_d_cell **head;
} t_d_list;

t_d_list* createList(int maxLevel);
void freeList(t_d_list* list);
void displayList(t_d_list* list);

#endif
