#include "include/setup.h"
#include "include/menu.h"

int main() {
        SkipList skip_list = createSkipList();
        menu(&skip_list);

        freeSkipList(&skip_list);
        return 0;
}
