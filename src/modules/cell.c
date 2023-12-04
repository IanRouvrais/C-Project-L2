#include <stdlib.h>

#include "../../includes/cell.h"

t_d_cell *createCell(int value, int levels) {
    t_d_cell *cell = (t_d_cell *)calloc(1, 8);
    cell->value = value;
    cell->levels = levels;
    cell->next = (t_d_cell**)calloc(levels+1, 8);
    for (int i = 0; i < levels; ++i) {
        cell->next[i] = NULL;
    }
    return cell;
}

void freeCell(t_d_cell *cell) {
    free(cell->next);
    free(cell);
}
