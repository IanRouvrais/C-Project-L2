#ifndef CELL_H
#define CELL_H

typedef struct s_cell 
{
    int value;
    int levels;
    struct s_cell **next;  // Tableau de pointeurs vers les niveaux suivants
} t_d_cell;

t_d_cell *createCell(int value, int levels);
void freeCell(t_d_cell *cell);

#endif
