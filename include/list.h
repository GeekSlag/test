#ifndef LIST_H
#define LIST_H

/* Define a structure for linked list elements. */
struct list_elmt {
	void *data;
	struct list_elmt *next;
};

/* Define a structure for linked list. */
struct list {
	int size;
	int (*match)(const void *key1, const void *key2);
    void (*destroy)(void *data);
	struct list_elmt *head;
	struct list_elmt *tail;
};

/* Public Interface */
void list_init(struct list *list, void (*destroy)(void *data), int (*match)(const void *key1, const void *key2));
void list_destroy(struct list *list);
int list_insert(struct list *list, const void *data);
int list_remove(struct list *list, const void *data);
void *list_search(struct list *list, const void *key);

#define list_size(list) ((list)->size)
#define list_head(list) ((list)->head)
#define list_tail(list) ((list)->tail)
#define list_is_head(list, element) ((element) == (list)->head ? 1 : 0)
#define list_is_tail(list, element) ((element->next) == NULL ? 1 : 0)
#define list_data(element) ((element)->data)
#define list_next(element) ((element)->next)

#endif
