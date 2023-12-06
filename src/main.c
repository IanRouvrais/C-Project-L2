#include <stdio.h>
#include<stdlib.h>
#include <time.h>

#include "include/cell.h"

int main() {
    srand(time(NULL));
    t_d_cell *cell = createCell(0, 5);
    display_cell(cell);
    freeCell(cell);
}





