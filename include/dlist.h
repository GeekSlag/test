#ifndef DLIST_H
#define DLIST_H

/* Define a structure for doubly-linked list elements. */
struct dlist_elmt {
	void *data;
	struct dlist_elmt *prev;
	struct dlist_elmt *next;
};

/* Define a structure for doubly-linked list. */
struct dlist {
	int size;
	int elmt_size;
	int (*match)(const void *data1, const void *data2);
	struct dlist_elmt *head;
	struct dlist_elmt *tail;
};

/* Public Interface */
void dlist_init(struct dlist *dlist, int elmt_size, int (*match)(const void *data1, const void *data2));
void dlist_destroy(struct dlist *dlist);
int dlist_insert(struct dlist *dlist, const void *data);
int dlist_remove(struct dlist *dlist, const void *data);
struct dlist_elmt *dlist_search(struct dlist *dlist, const void *data);

#endif
