#include <stdio.h>
#include <string.h>
#include "dlist.h"
#include "list.h"
#include "debug.h"

#define DLIST 1
#define LIST 1

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

/*
 * test functions
 *
 */
void list_prt(struct list *list)
{
	struct list_elmt *elmt;

	elmt = list_head(list);
	printf("-------------------------------\n");
	LOGGER(MOD_LIST, INFO, "size : %d\n", list_size(list));
	while (elmt != NULL) {
		printf("\n");
		LOGGER(MOD_LIST, INFO, "data : %p\n", elmt->data);
		LOGGER(MOD_LIST, INFO, "data : %d\n", *(int *)elmt->data);
		LOGGER(MOD_LIST, INFO, "curr : %p\n", elmt);
		LOGGER(MOD_LIST, INFO, "next : %p\n", elmt->next);
		elmt = elmt->next;
	}
	printf("-------------------------------\n\n");

	return;
}

int list_match(const void *key1, const void *key2)
{
	int res = 0;

	res = memcmp((void *)key1, (void *)key2, sizeof(int));

	return res == 0 ? 1 : 0;
}

void list_test(void)
{
	struct list list;
	int array[10] = {1, 2, 3, 4, 5, 6};

	list_init(&list, NULL, list_match);
	list_prt(&list);

	list_insert(&list, &array[0]);
	list_insert(&list, &array[1]);
	list_insert(&list, &array[2]);
	list_prt(&list);

    list_destroy(&list);
	list_prt(&list);

	return;
}

int main(int argc, char *argv[])
{
    list_test();

    /*
    printf("\n");
    LOGGER(MOD_DEMO, INFO, "demo[0].str --> %s\n", demo[0].str);
    LOGGER(MOD_DEMO, INFO, "demo[0].a --> %d\n", demo[0].a);
    LOGGER(MOD_DEMO, INFO, "demo[0].un.str --> %s\n", demo[0].un.str);
    printf("\n");
    LOGGER(MOD_DEMO, INFO, "demo[1].str --> %s\n", demo[1].str);
    LOGGER(MOD_DEMO, INFO, "demo[1].a --> %d\n", demo[1].a);
    LOGGER(MOD_DEMO, INFO, "demo[1].un.c --> %c\n", demo[1].un.c);
    printf("\n");
    LOGGER(MOD_DEMO, INFO, "demo[2].str --> %s\n", demo[2].str);
    LOGGER(MOD_DEMO, INFO, "demo[2].a --> %d\n", demo[2].a);
    LOGGER(MOD_DEMO, INFO, "demo[2].un.a --> %d\n", demo[2].un.a);
    printf("\n");
    */

	return 0;
}
