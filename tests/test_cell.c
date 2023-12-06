#include "include/test.h"
#include "include/cell.h"

static void test_createCell() {
    t_d_cell *cell = createCell(0, 5);
    assert(cell != NULL);
    assert(cell->value == 0);
    assert(cell->level == 5);
    assert(cell->next != NULL);
    for (int i = 0; i <= cell->level; ++i) {
        assert(cell->next[i] == NULL);
    }
    freeCell(cell);
}

static void test_freeCell() {
    t_d_cell *cell = createCell(0, 5);
    freeCell(cell);
    assert(cell->next == NULL);
    assert(cell == NULL);
}

static void test_display_cell() {
    t_d_cell *cell = createCell(0, 5);
    display_cell(cell);
    freeCell(cell);
}

void test_cell() {
    test_createCell();
    test_freeCell();
    test_display_cell();
}
