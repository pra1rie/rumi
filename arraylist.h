#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#include <stdlib.h>

typedef struct array_list
{
	size_t size;
	size_t alloc_size;
	size_t item_size;
	size_t inc_size;
	void **buffer;
} List;

static void listResize(List *list);
List *listNew(size_t item_size, size_t alloc_size);
void listFree(List *list);
void *listPop(List *list, size_t index);
void *listPopBack(List *list);
void listAdd(List *list, size_t index, void *item);
void listAddBack(List *list, void *item);
void *listGet(List *list, size_t index);
void listSet(List *list, size_t index, void *item);

#endif /* ARRAY_LIST_H */
