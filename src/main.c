#include <stdio.h>
#include<stdlib.h>
#include <time.h>

#include "../includes/list.h"
#include "../includes/search.h"

#include "../includes/tests/test_list.h"
#include "../includes/tests/test_search.h"

/*
void testDisplaying() {
    t_d_list myList = createEmptyList(4);
    insertCellAtHead(&myList, 2,4);
    insertCellAtHead(&myList, 1, 0);
    insertCellAtHead(&myList, 2, 1);
    insertCellAtHead(&myList, 3, 2);
    insertCellAtHead(&myList, 4, 3);
    insertCellAtHead(&myList, 5, 4);
    displayListAligned(myList);
    printf("\n\n");
    t_d_list list = createEmptyList(5);
    
    insertCellAtTail(&list, 6, 5);
    insertCellAtIndex(&list, 2, 1, 0);
    displayList(list);
    displayListAligned(list);
    displayListLevel(list, 0);
    displayListLevel(list, 1);
    displayListLevel(list, 5);
    displayListLevel(list, -1);
    displayListLevel(list, 6);
    
    printf("\n\n");

    t_d_list orderedList1 = createEmptyList(5);
    int rValue, rLevel;
    for(int i=0; i<5;i++) {
        rValue = rand() % 20;
        rLevel = rand() % 5;
        printf("(%d | %d) — ", rValue, rLevel);
        insertCellInAscendedOrder(&orderedList1, rValue, rLevel);
    }
    printf("\n");
    displayListAligned(orderedList1);

    t_d_list orderedList2 = createEmptyList(5);
    for(int i=0; i<5;i++) {
        rValue = rand() % 20;
        rLevel = rand() % 5;
        printf("(%d | %d) — ", rValue, rLevel);
        insertCellInDescendedOrder(&orderedList2, rValue, rLevel);
    }
    printf("\n");
    displayListAligned(orderedList2);

    t_d_list randomList = createRandomAscendedList(5, 5, 20);
    displayListAligned(randomList);
    deleteList(&randomList);


}
*/
int main() {

    // testLists();
    // testSearch();
    t_d_list myList = createCompleteAscendedList(3);

    int value;

    displayListAligned(myList);

    t_d_cell *cell;
    printf("%d", 9);
    
    cell = searchAscendant(myList, 5);

    

}





