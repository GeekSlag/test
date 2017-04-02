#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dlist.h"

/* Complexity: O(1) */
void dlist_init(struct dlist *dlist, int elmt_size, int (*match)(const void *data1, const void *data2))
{
	dlist->size = 0;
	dlist->elmt_size = elmt_size;
	dlist->match = match;
	dlist->head = NULL;
	dlist->tail = NULL;

	return;
}

/* Complexity: O(n) */
struct dlist_elmt *dlist_search(struct dlist *dlist, const void *data)
{
	struct dlist_elmt *element;

	element = dlist->head;
	while (element != NULL) {
		if (dlist->match && dlist->match(data, element->data))
			return element;

		element = element->next;
	}

	return NULL;
}

/* Complexity: O(1) */
int dlist_insert(struct dlist *dlist, const void *data)
{
	struct dlist_elmt *new_element;
	struct dlist_elmt *old_element;

    old_element = dlist_search(dlist, data);
    if (old_element) {
        memcpy(old_element->data, data, dlist->elmt_size);
        return 0;
    }

    new_element = (struct dlist_elmt *)malloc(sizeof(struct dlist_elmt));
    if (!new_element)
        return -1;

    new_element->data = malloc(dlist->elmt_size);
    if (!new_element->data)
        return -1;

    if (dlist->head == NULL) {
        dlist->head = new_element;
        dlist->tail = new_element;
        new_element->prev = NULL;
        new_element->next = NULL;
    }
    else
    {
        new_element->prev = dlist->tail;
        new_element->next = NULL;
        dlist->tail->next = new_element;
        dlist->tail = new_element;
    }

	memcpy(new_element->data, data, dlist->elmt_size);
	dlist->size++;

	return 0;
}

/* Complexity: O(n) */
void dlist_destroy(struct dlist *dlist)
{
    struct dlist_elmt *tmp;

	while (dlist->head) {
        free(dlist->head->data);
        tmp = dlist->head->next;
        free(dlist->head);
        dlist->head = tmp;
    }

	memset(dlist, 0, sizeof(struct dlist));

	return;
}

/* Complexity: O(n) */
int dlist_remove(struct dlist *dlist, const void *data)
{
	struct dlist_elmt *old_element;

	old_element = dlist_search(dlist, data);
    if (!old_element)
        return -1;

    if (old_element == dlist->head && old_element == dlist->tail) {
        dlist->head = NULL;
        dlist->tail = NULL;
    } 
    else if (old_element == dlist->head) {
        dlist->head = old_element->next;
        old_element->next->prev = NULL;
    }
    else if (old_element == dlist->tail) {
        dlist->tail = old_element->prev;
        old_element->prev->next = NULL;
    } 
    else {
        old_element->prev->next = old_element->next;
        old_element->next->prev = old_element->prev;
    }

    free(old_element->data);
    free(old_element);
    dlist->size--;

	return 0;
}
