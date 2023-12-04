#ifndef SEARCH_H
#define SEARCH_H
#include "timer.h"
#include "list.h"

t_d_cell* searchLevel0Ascendant(t_d_list* list, int value);
t_d_cell* searchLevel0Descendant(t_d_list* list, int value);
t_d_cell* searchAscendant(t_d_list* list, int value);
t_d_cell* searchDescendant(t_d_list* list, int value);
#endif