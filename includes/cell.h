#ifndef CELL_H
#define CELL_H

typedef struct s_d_cell
{
    int value;
    int levels;
    struct s_d_cell **next;
} t_d_cell, *p_d_cell;

p_d_cell createCell(int value, int levels);
void displaycell(t_d_cell cell);

#endif