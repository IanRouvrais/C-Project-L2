#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../../includes/search.h"
#include "../../includes/list.h"
#include <string.h>

t_d_cell *searchLevel0Ascendant(t_d_list list, int value)
{
    if (list.heads == NULL) return NULL;

    t_d_cell* current = (t_d_cell*)calloc(1, 9);
    current = list.heads[0];
    if (current==NULL) return NULL;

    do
    {
        if (current->value == value)
            return current;

        if (current->value > value)
            break;
        else
            current = current->next[0];

    } while (current != NULL);

    return NULL;
}

t_d_cell *searchLevel0Descendant(t_d_list list, int value)
{
    if (list.heads == NULL) return NULL;

    t_d_cell* current = (t_d_cell*)calloc(1, 8);
    current = list.heads[0];

    do
    {
        if (current->value == value)
            return current;

        if (current->value < value)
            break;
        else
            current = current->next[0];

    } while (current != NULL);

    return NULL;
}

t_d_cell *searchAscendant (t_d_list list, int value)
{
    if (list.heads == NULL) return NULL;

    int currentLevel = list.nbLevels-1; 
    t_d_cell* current = (t_d_cell*)calloc(1, 9);
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
    t_d_cell* current = (t_d_cell*)malloc(  9);
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
