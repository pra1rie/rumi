#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#include <stdlib.h>

typedef struct array_list {
	size_t size;
	size_t alloc_size;
	size_t item_size;
	size_t inc_size;
	void **buffer;
} ArrayList;

static void listResize(ArrayList *list);
ArrayList *listNew(size_t item_size, size_t alloc_size);
void listFree(ArrayList *list);
void *listPop(ArrayList *list, size_t index);
void *listPopBack(ArrayList *list);
void listAdd(ArrayList *list, size_t index, void *item);
void listAddBack(ArrayList *list, void *item);
void *listGet(ArrayList *list, size_t index);
void listSet(ArrayList *list, size_t index, void *item);

#endif /* ARRAY_LIST_H */
