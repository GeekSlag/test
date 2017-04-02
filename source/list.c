#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

/* Complexity: O(1) */
void list_init(list_t *list, int elmt_size, int (*match)(const void *key1, const void *key2))
{
	list->size = 0;
	list->elmt_size = elmt_size;
	list->match = match;
	list->head = NULL;
	list->tail = NULL;

	return;
}

/* Complexity: O(n) */
void list_destroy(list_t *list)
{
	while (list_size(list) > 0)
		list_remove(list, NULL);

	memset(list, 0, sizeof(list_t));
	return;
}

/* Complexity: O(1) */
int list_insert(list_t *list, const void *key, const void *data)
{
	list_elmt_t *new_element;

	if (key == NULL) {
		if ((new_element = (list_elmt_t *)malloc(sizeof(list_elmt_t))) == NULL)
			return -1;

		if ((new_element->data = (void *)malloc(list->elmt_size)) == NULL)
			return -1;
	}

	memcpy(new_element->data, data, list->elmt_size);
	if (list_size(list) == 0)
		list->tail = new_element;

	new_element->next = list->head;
	list->head = new_element;
	list->size++;

	return 0;
}

/* Complexity: O(n) */
int list_remove(list_t *list, const void *key)
{
	list_elmt_t *old_element;
	list_elmt_t *prev_element;

	if (list_size(list) == 0)
		return -1;

	old_element = list->head;
	while (old_element != NULL) {
		if (key == NULL)
			list->head = old_element->next;
		else 
		{
			if (list->match(key, old_element->data) == 0) {
				prev_element = old_element;
				old_element = old_element->next;
				continue;
			}
		}

		if (list_size(list) == 1)
			list->tail = NULL;

		if (prev_element != NULL)
			prev_element->next = old_element->next;

		if (old_element == list->head)
			list->head = old_element->next;

		free(old_element->data);
		free(old_element);
		memset(old_element, 0, sizeof(list_elmt_t));
		old_element = old_element->next;
		list->size--;
	}

	return 0;
}

/* Complexity: O(n) */
int list_search(list_t *list, const void *key, void *data)
{
	list_elmt_t *element;

	element = list->head;
	while (element != NULL) {
		if (list->match != NULL && list->match(key, element->data) == 1) {
			memcpy(data, element->data, list->elmt_size);
			return 0;
		}

		element = element->next;
	}

	return -1;
}

/*
 * test functions
 *
 */
void list_prt(list_t *list)
{
	list_elmt_t *elmt;

	elmt = list_head(list);
	printf("-------------------------------\n");
	printf("|LIST| size : %d\n", list_size(list));
	while (elmt != NULL) {
		printf("\n");
		printf("|LIST| data : %p\n", elmt->data);
		printf("|LIST| curr : %p\n", elmt);
		printf("|LIST| next : %p\n", elmt->next);
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
	list_t list;
	int array[10] = {1, 2, 3, 4, 5, 6};
	int key = 3;

	list_init(&list, sizeof(int), list_match);
	list_prt(&list);

	list_insert(&list, NULL, &array[0]);
	list_insert(&list, NULL, &array[1]);
	list_insert(&list, NULL, &array[2]);
	list_prt(&list);

	list_remove(&list, &key);
	list_prt(&list);

	return;
}

