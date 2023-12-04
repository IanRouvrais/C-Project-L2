#include <stdio.h>
#include <stdlib.h>
#include "../../includes/tests/test_search.h"
#include "../../includes/search.h"
#include "../../includes/list.h"

static void test_searchLevel0Ascendant() {
    t_d_list list = createEmptyList(5);
    insertCellAtHead(&list, 10, 0);
    insertCellAtHead(&list, 20, 1);
    insertCellAtHead(&list, 30, 2);
    t_d_cell* result = searchLevel0Ascendant(list, 20);
    if (result != NULL) {
        printf("Found value 20 at level 0\n");
    } else {
        printf("Value 20 not found at level 0\n");
    }
}

static void test_searchLevel0Descendant() {
    t_d_list list = createEmptyList(5);
    insertCellAtHead(&list, 10, 0);
    insertCellAtHead(&list, 20, 1);
    insertCellAtHead(&list, 30, 2);
    t_d_cell* result = searchLevel0Descendant(list, 20);
    if (result != NULL) {
        printf("Found value 20 at level 0\n");
    } else {
        printf("Value 20 not found at level 0\n");
    }
}

static void test_searchAscendant() {
    t_d_list list = createEmptyList(5);
    insertCellAtHead(&list, 10, 0);
    insertCellAtHead(&list, 20, 1);
    insertCellAtHead(&list, 30, 2);
    t_d_cell* result = searchAscendant(list, 20);
    if (result != NULL) {
        printf("Found value 20 in the list\n");
    } else {
        printf("Value 20 not found in the list\n");
    }
}

static void test_searchDescendant() {
    t_d_list list = createEmptyList(5);
    insertCellAtHead(&list, 10, 0);
    insertCellAtHead(&list, 20, 1);
    insertCellAtHead(&list, 30, 2);
    t_d_cell* result = searchDescendant(list, 20);
    if (result != NULL) {
        printf("Found value 20 in the list\n");
    } else {
        printf("Value 20 not found in the list\n");
    }
}

void testSearch() {
    printf("Testing searchLevel0Ascendant\n");
    test_searchLevel0Ascendant();
    printf("\n\n");

    printf("Testing searchLevel0Descendant\n");
    test_searchLevel0Descendant();
    printf("\n\n");

    printf("Testing searchAscendant\n");
    test_searchAscendant();
    printf("\n\n");

    printf("Testing searchDescendant\n");
    test_searchDescendant();
    printf("\n\n");
}