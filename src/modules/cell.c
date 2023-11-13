#include <stdlib.h>

#include "../../includes/cell.h"

p_d_cell createCell(int value, int levels) {
    p_d_cell temp = (p_d_cell) malloc(sizeof(t_d_cell));
    temp->value = value;
    temp->levels = levels;
    for (int i = 0; i < levels; i++) {
        temp->next[i] = NULL;
    }
}
