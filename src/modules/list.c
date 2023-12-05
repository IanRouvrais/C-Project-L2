#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "../../includes/list.h"
#include <string.h>

typedef char* string;

t_d_list createEmptyList(int maxLevels)
{
    t_d_list list;
    list.nbLevels = maxLevels;
    if (maxLevels < 1) maxLevels = 1;


    list.heads = (t_d_cell **)calloc(maxLevels+1, 8);


    for ( int i = 0; i < maxLevels; i++)
        list.heads[i] = NULL;

    return list;
}

int insertCellAtHead(t_d_list *list, int value, int levels) {
    if (list == NULL) {
        fprintf(stderr, "Error: Can't add to an empty list");
        return 1;
    }
    if (levels < 0) levels = 0;
    if (levels >= list->nbLevels) levels = list->nbLevels - 1;

    t_d_cell *newCell = createCell(value, levels);
    for ( int i = 0; i <= levels; ++i) {
        newCell->next[i] = list->heads[i];
        list->heads[i] = newCell;
    }
    return 0;
}

int displayListLevel(t_d_list list, int level)
{
    if (level < 0) level = 0;
    if (level >= list.nbLevels) level = list.nbLevels - 1;

    t_d_cell *current = list.heads[level];

    printf("[list head_%d @-]--> ", level);
    if (current == NULL)
    {
        printf("\033[1;34mNUL\033[1;0mL\n");
        return 0;
    }
    while (current != NULL)
    {
        printf(" [%d|@-]--> ", current->value);
        current = current->next[level];
    }
    printf("\033[1;34mNULL\033[1;0m\n");
    return 0;
}

int displayList(t_d_list list)
{
    for ( int i = 0; i < list.nbLevels; i++)
    {
        displayListLevel(list, i);
    }
    return 0;
}

int displayListAligned(t_d_list list)
{
    int diff;
    if(list.heads[0] == NULL) {
        for ( int i = 0; i < list.nbLevels; i++)
        {
            printf("[list head_%d @-]--> \033[1;34mNULL\033[1;0m\n", i);
        }
        return 0;
    }
   
    t_d_cell **current = list.heads;
    char outputs[list.nbLevels][20000];

    while (current[0]!=NULL) {
        for ( int i=0; i<list.nbLevels; i++) {
            sprintf(outputs[i], "[list head_%d @-]--", i);
        }

        while(current[0]!=NULL) {
            sprintf(outputs[0], "%s> [%d|@-]--", outputs[0], current[0]->value);

            for ( int i=1; i<list.nbLevels; i++) {
                
                if(current[i]==current[0]) {
                    sprintf(outputs[i], "%s> [%d|@-]--", outputs[i], current[i]->value);
                    current[i] = current[i]->next[i];
                }
                else {
                    diff = strlen(outputs[0]) - strlen(outputs[i]);
                    for(int j = 0; j < diff; j++) {
                        strcat(outputs[i], "-");
                        
                    }
                }
            }
            current[0] = current[0]->next[0];
        }
    }

    for( int i = 0; i < list.nbLevels; i++) {
        strcat(outputs[i], "> \033[1;34mNULL\033[1;0m\n");
    }

    for( int i = 0; i < list.nbLevels; i++) {
        printf("%s", outputs[i]);
    }

    return 0;
}

int insertCellInAscendedOrder(t_d_list *list, int value, int levels) {
    if (list == NULL) {
        fprintf(stderr, "Error: Can't add to an empty list");
        return 1;
    }
    if (levels < 0) levels = 0;
    if (levels >= list->nbLevels) levels = list->nbLevels - 1;

    t_d_cell *newCell = createCell(value, levels);

    t_d_cell *current = list->heads[0];
    t_d_cell *prev = NULL;

    if (current == NULL || current->value >= value) {
        for ( int i = levels; i >= 0; i--) {
            newCell->next[i] = list->heads[i];
            list->heads[i] = newCell;
        }
        return 0;
    }

    for ( int i = levels; i >= 0; i--) {
        current = list->heads[i];
        prev = NULL;

        while (current != NULL && current->value < value) {
            prev = current;
            current = current->next[i];
        }

        if (prev == NULL) {
            newCell->next[i] = list->heads[i];
            list->heads[i] = newCell;
        } else {
            newCell->next[i] = prev->next[i];
            prev->next[i] = newCell;
        }
    }

    return 0;
}

int insertCellInDescendedOrder(t_d_list *list, int value, int levels) {
    if (list == NULL) {
        fprintf(stderr, "Error: Can't add to an empty list");
        return 1;
    }
    if (levels < 0) levels = 0;
    if (levels >= list->nbLevels) levels = list->nbLevels - 1;

    t_d_cell *newCell = createCell(value, levels);

    t_d_cell *current = list->heads[0];
    t_d_cell *prev = NULL;

    if (current == NULL || current->value <= value) {
        for ( int i = levels; i >= 0; i--) {
            newCell->next[i] = list->heads[i];
            list->heads[i] = newCell;
        }
        return 0;
    }

    for ( int i = levels; i >= 0; i--) {
        current = list->heads[i];
        prev = NULL;

        while (current != NULL && current->value > value) {
            prev = current;
            current = current->next[i];
        }

        if (prev == NULL) {
            newCell->next[i] = list->heads[i];
            list->heads[i] = newCell;
        } else {
            newCell->next[i] = prev->next[i];
            prev->next[i] = newCell;
        }
    }

    return 0;
}

t_d_list createCompleteAscendedList(int nbLevels) {
    t_d_list list = createEmptyList(nbLevels);
    int nbCells = (int)pow(2, nbLevels) - 1;
    int cellLevel;
    for( int i = nbCells; i>=0; i--) {
        cellLevel = 0;
        for( int j = 1; j<nbLevels; j++) {
            if(i % (int)pow(2, j) == 0) {
                cellLevel++;
            }
        }
        insertCellAtHead(&list, i, cellLevel);
    }
    return list;
}

int deleteList(t_d_list *list) {
    if (list == NULL) {
        fprintf(stderr, "Error: Can't delete an empty list");
        return 1;
    }

    t_d_cell *current = list->heads[0];
    t_d_cell *next;

    while (current != NULL) {
        next = current->next[0];
        freeCell(current);
        current = next;
    }

    free(list->heads);
    return 0;
}