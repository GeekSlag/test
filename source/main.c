#include <stdio.h>
#include <string.h>
#include "dlist.h"
#include "debug.h"

#define DLIST 1

/*
 * test functions
 * 
 */
void dlist_prt(struct dlist *dlist)
{
    struct dlist_elmt *elmt;

    elmt = dlist->head;
    printf("-------------------------------\n");
    LOGGER(DLIST, INFO, "size : %d\n", dlist->size);
    while (elmt) {
        printf("\n");
        LOGGER(DLIST, INFO, "data : %p\n", elmt->data);
        LOGGER(DLIST, INFO, "curr : %p\n", elmt);
        LOGGER(DLIST, INFO, "prev : %p\n", elmt->prev);
        LOGGER(DLIST, INFO, "next : %p\n", elmt->next);
        elmt = elmt->next;
    }
    printf("-------------------------------\n\n");

    return;
}

int dlist_match(const void *data1, const void *data2)
{
    int res = 0;

    res = memcmp((void *)data1, (void *)data2, sizeof(int));

    return res == 0 ? 1 : 0;
}

void dlist_test(void)
{
    struct dlist dlist;
    int array[10] = {1, 2, 3, 4, 5, 6};

    dlist_init(&dlist, sizeof(int), dlist_match);
    dlist_prt(&dlist);

    dlist_insert(&dlist, &array[0]);
    dlist_insert(&dlist, &array[1]);
    dlist_insert(&dlist, &array[2]);
    dlist_prt(&dlist);

    dlist_destroy(&dlist);
    dlist_prt(&dlist);

    return;
}

int main(int argc, char *argv[])
{
    dlist_test();

	return 0;
}
