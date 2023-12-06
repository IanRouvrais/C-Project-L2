#ifndef CELL_H
#define CELL_H

#define SIZE_OF_CELL 8 // 8 bytes (2 * sizeof(int))
#define SIZE_OF_PTR sizeof(void *)

typedef struct s_cell 
{
    int value, level;
    struct s_cell **next;  // Tableau de pointeurs vers les niveaux suivants
} t_d_cell;

t_d_cell *createCell(int value, int levels);
void freeCell(t_d_cell *cell);
void display_cell(t_d_cell *cell);


#endif
