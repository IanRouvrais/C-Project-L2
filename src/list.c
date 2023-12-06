#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "include/list.h"

t_d_list* createEmptyList(int maxLevel) {
    t_d_list* list = calloc(1, SIZE_OF_LIST);
    if (list == NULL) return NULL; // gestion de l'échec de l'allocation

    *list = (t_d_list){ maxLevel, (t_d_cell **)calloc(maxLevel + 1, SIZE_OF_PTR) };
    if (list->head == NULL) {
        free(list); return NULL; // gestion de l'échec de l'allocation
    }

    // inits all pointers to NULL
    memset(list->head, 0, (maxLevel + 1) * SIZE_OF_PTR);
    return list;
}

void freeList(t_d_list* list) {
    if (list != NULL) {
        t_d_cell* cell = list->head[0];
        while (cell != NULL) {
            t_d_cell* next = cell->next[0];
            freeCell(cell);
            cell = next;
        }
        free(list->head);
        list->head = NULL;  // Mettre à jour les pointeurs à NULL après la libération
        free(list);
    }
}
