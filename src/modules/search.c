#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../../includes/search.h"
#include "../../includes/list.h"
#include <string.h>

t_d_cell* searchLevel0Ascendant(t_d_list* list, int value) {
    t_d_cell* current = list->heads[0];
    
    while(current != NULL || current->value <= value) {
        if(current->value == value) {
            return current;
        }
        current = current->next[0];
    }
    return current;
}

t_d_cell* searchLevel0Descendant(t_d_list* list, int value) {
    t_d_cell* current = list->heads[0];
    
    while(current != NULL || current->value >= value) {
        if(current->value == value) {
            return current;
        }
        current = current->next[0];
    }
    return current;
}

t_d_cell* searchAscendant(t_d_list* list, int value) {
    t_d_cell* current = list->heads[list->nbLevels-1];
    int level = list->nbLevels-1;
    
    while(level >= 0) {
        while(current->next[level] != NULL && current->next[level]->value <= value) {
            current = current->next[level];
        }
        if(current->value == value) {
            return current;
        }
        level--;
    }
    return NULL;
}

t_d_cell* searchDescendant(t_d_list* list, int value) {
    t_d_cell* current = list->heads[list->nbLevels-1];
    int level = list->nbLevels-1;
    
    while(level >= 0) {
        while(current->next[level] != NULL && current->next[level]->value >= value) {
            current = current->next[level];
        }
        if(current->value == value) {
            return current;
        }
        level--;
    }
    return NULL;
}