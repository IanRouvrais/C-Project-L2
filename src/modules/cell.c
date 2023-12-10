#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "include/cell.h"

Cell *createCell(int cellValue, int cellLevel) {
    Cell *cell = (Cell *)calloc(1, SIZE_OF_CELL);
    if (cell == NULL) return NULL; // gestion de l'échec de l'allocation

    *cell = (Cell){cellValue, cellLevel, (Cell **)calloc(cellLevel + 1, SIZE_OF_PTR)};
    if (cell->next == NULL) {
        free(cell); return NULL; // gestion de l'échec de l'allocation
    }

    // inits all pointers to NULL
    memset(cell->next, 0, (cellLevel + 1) * SIZE_OF_PTR); 
    return cell;
}

inline void freeCell(Cell *cell) {
    if (cell != NULL) {
        free(cell->next);
        cell->next = NULL;  // Mettre à jour les pointeurs à NULL après la libération
        free(cell);
    }
}

void displayCell(Cell *cell) {
    printf("[CELL | %p]  Value: %d, Level: %d, Next: [", cell, cell->value, cell->level);
    for (int i = 0; i <= cell->level; ++i) {
        printf("%p%s", (void *)(cell->next[i]), (i < cell->level) ? ", " : "");
    }
    printf("]\n");
}
