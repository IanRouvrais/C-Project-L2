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

    list.heads = (t_d_cell **)malloc(maxLevels * sizeof(t_d_cell *));

    for (register int i = 0; i < maxLevels; i++)
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
    for (register int i = 0; i <= levels; ++i) {
        newCell->next[i] = list->heads[i];
        list->heads[i] = newCell;
    }
    return 0;
}


int insertCellAtTail(t_d_list *list, int value, int levels)
{
    if (list == NULL)
    {
        fprintf(stderr, "Error: Can't add to an empty list");
        return 1;
    }
    if (levels < 0) levels = 0;
    if (levels >= list->nbLevels) levels = list->nbLevels-1;

    t_d_cell *newCell = createCell(value, levels);

    t_d_cell *current = list->heads[0];

    if (current == NULL)
    {
        for (register int i = 0; i < levels; i++)
        {
            newCell->next[i] = list->heads[i];
            list->heads[i] = newCell;
        }
        return 0;
    }

    while (current->next[0] != NULL)
    {
        current = current->next[0];
    }

    for (register int i = 0; i <= levels; i++)
    {
        newCell->next[i] = current->next[i];
        current->next[i] = newCell;
    }
    return 0;
}


int insertCellAtIndex(t_d_list *list, int value, int levels, int index)
{
    if (list == NULL)
    {
        fprintf(stderr, "Error: Can't add to an empty list");
        return 1;
    }
    if (levels < 0) levels = 0;
    if (levels >= list->nbLevels) levels = list->nbLevels - 1;

    if (index < 0) index = 0;
    if (index > list->nbLevels) index = list->nbLevels;

    t_d_cell *newCell = createCell(value, levels);

    if (index == 0)
    {
        for (register int i = 0; i <= levels; ++i)
        {
            newCell->next[i] = list->heads[i];
            list->heads[i] = newCell;
        }
    }
    else
    {
        t_d_cell *current = list->heads[0];
        int count = 0;

        while (current != NULL && count < index - 1)
        {
            current = current->next[0];
            count++;
        }

        if (current == NULL)
        {
            fprintf(stderr, "Error: Index out of range");
            return 1;
        }

        for (register int i = 0; i <= levels; ++i)
        {
            newCell->next[i] = current->next[i];
            current->next[i] = newCell;
        }
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
    for (register int i = 0; i < list.nbLevels; i++)
    {
        displayListLevel(list, i);
    }
    return 0;
}

int displayListAligned(t_d_list list)
{
    int diff;
    if(list.heads[0] == NULL) {
        for (register int i = 0; i < list.nbLevels; i++)
        {
            printf("[list head_%d @-]--> \033[1;34mNULL\033[1;0m\n", i);
        }
        return 0;
    }
   
    t_d_cell **current = list.heads;
    char outputs[list.nbLevels][20000];

    while (current[0]!=NULL) {
        for (register int i=0; i<list.nbLevels; i++) {
            sprintf(outputs[i], "[list head_%d @-]--", i);
        }

        while(current[0]!=NULL) {
            sprintf(outputs[0], "%s> [%d|@-]--", outputs[0], current[0]->value);

            for (register int i=1; i<list.nbLevels; i++) {
                
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

    for(register int i = 0; i < list.nbLevels; i++) {
        strcat(outputs[i], "> \033[1;34mNULL\033[1;0m\n");
    }

    for(register int i = 0; i < list.nbLevels; i++) {
        printf("%s", outputs[i]);
    }

    return 0;
}

int insertCellatIndex(t_d_list *list, int value, int levels, int index)
{
    if (list == NULL)
    {
        fprintf(stderr, "Error: Can't add to an empty list");
        return 1;
    }
    if (levels < 0) levels = 0;
    if (levels >= list->nbLevels) levels = list->nbLevels - 1;

    t_d_cell *newCell = createCell(value, levels);

    t_d_cell *current = list->heads[0];

    if (current == NULL)
    {
        for (register int i = 0; i < levels; i++)
        {
            newCell->next[i] = list->heads[i];
            list->heads[i] = newCell;
        }
        return 0;
    }

    while (current->next[0] != NULL)
    {
        current = current->next[0];
    }

    for (register int i = 0; i < levels; i++)
    {
        newCell->next[i] = current->next[i];
        current->next[i] = newCell;
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

    if (current == NULL || current->value > value) {
        for (register int i = levels; i >= 0; i--) {
            newCell->next[i] = list->heads[i];
            list->heads[i] = newCell;
        }
        return 0;
    }

    while (current != NULL && current->value <= value) {
        prev = current;
        current = current->next[0];
    }

    for (register int i = levels; i >= 0; i--) {
        newCell->next[i] = prev->next[i];
        prev->next[i] = newCell;
    }

    return 0;
}

t_d_list createRandomAscendedList(int nbCells, int maxLevels) {
    t_d_list list = createEmptyList(maxLevels);
    int rValue, rLevel;
    for(register int i=0; i<nbCells;i++) {
        rValue = rand() % 20;
        rLevel = rand() % maxLevels;
        printf("Inserting cell with value %d at level %d\n", rValue, rLevel);
        insertCellInAscendedOrder(&list, rValue, rLevel);
    }
    return list;
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

    if (current == NULL || current->value < value) {
        for (register int i = levels; i >= 0; i--) {
            newCell->next[i] = list->heads[i];
            list->heads[i] = newCell;
        }
        return 0;
    }

    while (current != NULL && current->value >= value) {
        prev = current;
        current = current->next[0];
    }

    for (register int i = levels; i >= 0; i--) {
        newCell->next[i] = prev->next[i];
        prev->next[i] = newCell;
    }

    return 0;
}

static int compareAsc(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

static int compareDesc(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

int sortList(t_d_list *list, int order) {
    if (list == NULL) {
        fprintf(stderr, "Error: Can't sort an empty list");
        return 1;
    }

    int nbCells = 0;
    t_d_cell *current = list->heads[0];
    while (current != NULL) {
        nbCells++;
        current = current->next[0];
    }

    int values[nbCells];
    current = list->heads[0];
    for (register int i = 0; i < nbCells; i++) {
        values[i] = current->value;
        current = current->next[0];
    }

    if (order == 1) {
        qsort(values, nbCells, sizeof(int), compareAsc);
    } else {
        qsort(values, nbCells, sizeof(int), compareDesc);
    }

    current = list->heads[0];
    for (register int i = 0; i < nbCells; i++) {
        current->value = values[i];
        current = current->next[0];
    }

    return 0;
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