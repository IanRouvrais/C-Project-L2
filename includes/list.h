#ifndef LIST_H
#define LIST_H

#include "cell.h"

typedef struct s_list {
    t_d_cell **heads;  // Tableau de pointeurs vers les têtes des niveaux
    int nbLevels;
} t_d_list;

t_d_list createEmptyList(int maxLevels);
int insertCellAtHead(t_d_list *list, int value, int levels);
int insertCellAtTail(t_d_list *list, int value, int levels);
int insertCellAtIndex(t_d_list *list, int value, int levels, int index);
int deleteList(t_d_list *list);
int displayList(t_d_list list);
int displayListAligned(t_d_list list);
int displayListLevel(t_d_list list, int level);
int insertCellInAscendedOrder(t_d_list*, int, int);
int insertCellInDescendedOrder(t_d_list*, int, int);
t_d_list createRandomAscendedList(int nbCells, int maxLevel, int maxValue);
t_d_list createRandomDescendedList(int, int, int);
t_d_list createRandomList(int, int);
t_d_list createCompleteAscendedList(int levels);
t_d_list createCompleteDescendedList(int levels);
int sortList(t_d_list*, int);

#endif
