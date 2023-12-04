#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../../includes/search.h"
#include "../../includes/list.h"
#include <string.h>

t_d_cell* searchLevel0Ascendant(t_d_list list, int value)
{
    if (list.heads == NULL) return NULL;

    t_d_cell *current = list.heads[0];
    while (current != NULL && current->value < value)
        current = current->next[0];

    if (current != NULL && current->value == value)
        return current;

    return NULL;
}

t_d_cell *searchAscendant(t_d_list list, int value)
{
    if (list.heads == NULL) return NULL;

    int currentLevel = list.nbLevels; 
    t_d_cell *current;
    do {
        currentLevel--;
        current = list.heads[currentLevel];
    } while (current == NULL && currentLevel >=0);
        if (current == NULL) return NULL;
    
    do
    {
        if (current->value == value)
            return current;

        if (currentLevel > 0 && current->value > value)
            current = list.heads[--currentLevel];
        else
            current = current->next[0];

    } while (current != NULL);

    return NULL;
}

t_d_cell *searchDescendant(t_d_list list, int value)
{
    if (list.heads == NULL) return NULL;

    int currentLevel = list.nbLevels; 
    t_d_cell *current;
    do {
        currentLevel--;
        current = list.heads[currentLevel];
    } while (current == NULL && currentLevel >=0);
        if (current == NULL) return NULL;
    
    do
    {
        if (current->value == value)
            return current;

        if (currentLevel > 0 && current->value < value)
            current = list.heads[--currentLevel];
        else
            current = current->next[0];

    } while (current != NULL);

    return NULL;
}
