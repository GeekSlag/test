#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

/* Complexity: O(1) */
void list_init(struct list *list, void (*destroy)(void *data), int (*match)(const void *key1, const void *key2))
{
	list->size = 0;
    list->destroy = destroy;
	list->match = match;
	list->head = NULL;
	list->tail = NULL;

	return;
}

/* Complexity: O(n) */
void list_destroy(struct list *list)
{
    list_remove(list, NULL);
	memset(list, 0, sizeof(struct list));
    
	return;
}

/* Complexity: O(1) */
int list_insert(struct list *list, const void *data)
{
	struct list_elmt *new_element;

    new_element = list_search(list, data);
    if (new_element) {
        new_element->data = (void *)data;
        return 0;
    }

    if ((new_element = (struct list_elmt *)malloc(sizeof(struct list_elmt))) == NULL)
        return -1;

    new_element->data = (void *)data;
	if (list_size(list) == 0)
		list->tail = new_element;

	new_element->next = list->head;
	list->head = new_element;
	list->size++;

	return 0;
}

/* Complexity: O(n) */
int list_remove(struct list *list, const void *data)
{
	struct list_elmt *old_element;
	struct list_elmt *prev_element;

	if (list_size(list) == 0)
		return -1;

	prev_element = list->head;
	old_element = list->head;
	while (old_element != NULL) {
		if (!data)
			list->head = old_element->next;
		else {
			if (!list->match(data, old_element->data)) {
				prev_element = old_element;
				old_element = old_element->next;
				continue;
			}

            prev_element->next = old_element->next;
		}

		if (list_size(list) == 1)
			list->tail = NULL;

		if (old_element == list->head)
			list->head = old_element->next;

        if (list->destroy)
            list->destroy(old_element->data);
		free(old_element);
		old_element = old_element->next;
		list->size--;
	}

	return 0;
}

/* Complexity: O(n) */
void *list_search(struct list *list, const void *key)
{
	struct list_elmt *element;

	element = list->head;
	while (element != NULL) {
		if (list->match && list->match(key, element->data))
			return element->data;

		element = element->next;
	}

	return NULL;
}
