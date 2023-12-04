#include <stdio.h>
#include<stdlib.h>
#include <time.h>
#include "../includes/list.h"
#include "../includes/test_list.h"
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

    t_d_list randomList = createRandomAscendedList(5, 5);
    displayListAligned(randomList);
    deleteList(&randomList);


}

int main() {
    srand(time(NULL));
    testLists();


}

/*
/usr/bin/ld: out/parts/main.c.o: in function `main':
main.c:(.text.startup+0xa): undefined reference to `createEmptyList'
/usr/bin/ld: main.c:(.text.startup+0x22): undefined reference to `insertCellAtHead'
/usr/bin/ld: main.c:(.text.startup+0x30): undefined reference to `displayList'
collect2: error: ld returned 1 exit status
*/

