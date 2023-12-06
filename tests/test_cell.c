#include "include/test_cell.h"
#include "include/cell.h"

static void test_createCell() {
    int randValue = rand() % 100;
    int randLevel = rand() % 10;
    t_d_cell *cell = createCell(randValue, randLevel);
    assert(cell != NULL);
    assert(cell->value == randValue);
    assert(cell->level == randLevel);
    assert(cell->next != NULL);
    for (int i = 0; i <= cell->level; ++i) {
        assert(cell->next[i] == NULL);
    }
    freeCell(cell);
}

static void test_freeCell() {
    int randValue = rand() % 100;
    int randLevel = rand() % 10;
    t_d_cell *cell = createCell(randValue, randLevel);
    freeCell(cell);
    assert(cell->next == NULL);
    assert(cell == NULL);
}

static void test_displayCell() {
    int randValue = rand() % 100;
    int randLevel = rand() % 10;
    t_d_cell *cell = createCell(randValue, randLevel);
    displayCell(cell);
    freeCell(cell);
}

void test_cell() {
    printf("Testing cell...\n");
    test_createCell();
    test_freeCell();
    test_displayCell();
    printf("All tests passed!\n");
}
