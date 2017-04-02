#ifndef LIST_H
#define LIST_H

/* Define a structure for linked list elements. */
typedef struct list_elmt {
	void *data;
	struct list_elmt *next;
} list_elmt_t;

/* Define a structure for linked list. */
typedef struct {
	int size;
	int elmt_size;
	int (*match)(const void *key1, const void *key2);
	list_elmt_t *head;
	list_elmt_t *tail;
} list_t;

/* Public Interface */
void list_init(list_t *list, int elmt_size, int (*match)(const void *key1, const void *key2));
void list_destroy(list_t *list);
int list_insert(list_t *list, const void *key, const void *data);
int list_remove(list_t *list, const void *key);
int list_search(list_t *list, const void *key, void *data);

#define list_size(list) ((list)->size)
#define list_head(list) ((list)->head)
#define list_tail(list) ((list)->tail)
#define list_is_head(list, element) ((element) == (list)->head ? 1 : 0)
#define list_is_tail(list, element) ((element->next) == NULL ? 1 : 0)
#define list_data(element) ((element)->data)
#define list_next(element) ((element)->next)

#endif
