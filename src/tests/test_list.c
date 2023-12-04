#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../../includes/list.h"
#include "../../includes/tests/test_list.h"
// Test functions
static void test_createList() {
    t_d_list list = createEmptyList(5);
    printf("List created with %d levels\n", list.nbLevels);
}

static void test_insertCellAtHead() {
    t_d_list list = createEmptyList(5);
    insertCellAtHead(&list, 10, 0);
    insertCellAtHead(&list, 20, 1);
    insertCellAtHead(&list, 30, 2);
    displayListAligned(list);
}

static void test_insertCellAtTail() {
    t_d_list list = createEmptyList(5);
    insertCellAtTail(&list, 10, 0);
    insertCellAtTail(&list, 20, 1);
    insertCellAtTail(&list, 30, 2);
    displayListAligned(list);
}

static void test_insertCellAtIndex() {
    t_d_list list = createEmptyList(5);
    insertCellAtIndex(&list, 10, 0, 0);
    insertCellAtIndex(&list, 20, 1, 1);
    insertCellAtIndex(&list, 30, 2, 2);
    displayListAligned(list);
}

static void test_displayListLevel() {
    t_d_list list = createEmptyList(5);
    insertCellAtHead(&list, 10, 0);
    insertCellAtHead(&list, 20, 1);
    insertCellAtHead(&list, 30, 2);
    displayListLevel(list, 0);
    displayListLevel(list, 1);
    displayListLevel(list, 2);
}

static void test_displayList() {
    t_d_list list = createEmptyList(5);
    insertCellAtHead(&list, 10, 0);
    insertCellAtHead(&list, 20, 1);
    insertCellAtHead(&list, 30, 2);
    displayListAligned(list);
}

static void test_displayListAligned() {
    t_d_list list = createEmptyList(5);
    insertCellAtHead(&list, 10, 0);
    insertCellAtHead(&list, 20, 1);
    insertCellAtHead(&list, 30, 2);
    displayListAligned(list);
}

static void test_insertCellInAscendedOrder() {
    t_d_list list = createEmptyList(5);
    insertCellInAscendedOrder(&list, 10, 0);
    insertCellInAscendedOrder(&list, 20, 1);
    insertCellInAscendedOrder(&list, 30, 2);
    displayListAligned(list);
}

static void test_insertCellInDescendedOrder() {
    t_d_list list = createEmptyList(5);
    insertCellInDescendedOrder(&list, 10, 0);
    insertCellInDescendedOrder(&list, 20, 1);
    insertCellInDescendedOrder(&list, 30, 2);
    displayListAligned(list);
}

static void test_createRandomAscendedList() {
    srand(time(NULL));
    t_d_list list = createRandomAscendedList(10, 5, 20);
    displayListAligned(list);
}

static void test_sortList() {
    t_d_list list = createEmptyList(5);
    insertCellAtHead(&list, 10, 0);
    insertCellAtHead(&list, 20, 1);
    insertCellAtHead(&list, 30, 2);
    sortList(&list, 1); // Sort in ascending order
    displayListAligned(list);
}


void testLists() {
    printf("Testing list creation\n");
    test_createList();
    printf("\n\n");

    printf("Testing inserting cell at head\n");
    test_insertCellAtHead();
    printf("\n\n");

    printf("Testing inserting cell at tail\n");
    test_insertCellAtTail();
    printf("\n\n");

    printf("Testing inserting cell at index\n");
    test_insertCellAtIndex();
    printf("\n\n");

    printf("Testing displaying list level\n");
    test_displayListLevel();
    printf("\n\n");

    printf("Testing displaying list\n");
    test_displayList();
    printf("\n\n");

    printf("Testing displaying list aligned\n");
    test_displayListAligned();
    printf("\n\n");

    printf("Testing inserting cell in ascended order\n");
    test_insertCellInAscendedOrder();
    printf("\n\n");

    printf("Testing inserting cell in descended order\n");
    test_insertCellInDescendedOrder();
    printf("\n\n");

    printf("Testing creating random ascended list\n");
    test_createRandomAscendedList();
    printf("\n\n");

    printf("Testing sorting list\n");
    test_sortList();
    printf("\n\n");

}