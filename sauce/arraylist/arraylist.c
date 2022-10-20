#include <stdio.h>
#include <stdlib.h>

#include "arraylist.h"

#define ERROR_EXIT(...) { fprintf(stderr, __VA_ARGS__); exit(1); }

static void
listResize(ArrayList *list)
{
	if (list->size < list->alloc_size) return;

	list->alloc_size += list->item_size * list->inc_size;
	list->buffer = realloc(list->buffer, list->alloc_size);
}

ArrayList*
listNew(size_t item_size, size_t alloc_size)
{
	ArrayList *list = malloc(sizeof(ArrayList));
	list->item_size = item_size;
	list->alloc_size = alloc_size;
	list->size = 0;
	list->inc_size = 10;
	list->buffer = malloc(item_size * alloc_size);
	return list;
}

void
listFree(ArrayList *list)
{
	free(list->buffer);
	free(list);
}

void*
listPop(ArrayList *list, size_t index)
{
	if (index >= list->size)
		ERROR_EXIT("POP_ERROR: Index out of range: %ld\n", index);
	--list->size;

	void *item = list->buffer[index];

	for (size_t i = index; i < list->size; ++i) {
		list->buffer[i] = list->buffer[i+1];
	}

	return item;
}

void*
listPopBack(ArrayList *list)
{
	if (list->size == 0)
		ERROR_EXIT("POP_ERROR: Cannot pop from empty list\n");
	--list->size;
	return list->buffer[list->size];
}

void
listAdd(ArrayList *list, size_t index, void *item)
{
	if (index > list->size)
		ERROR_EXIT("ADD_ERROR: Index out of range: %ld\n", index);
	++list->size;

	listResize(list);

	for (size_t i = list->size-1; i > index; --i) {
		list->buffer[i] = list->buffer[i-1];
	}
	list->buffer[index] = item;
}

void
listAddBack(ArrayList *list, void *item)
{
	++list->size;
	listResize(list);
	list->buffer[list->size-1] = item;
}

void*
listGet(ArrayList *list, size_t index)
{
	if (index >= list->size)
		ERROR_EXIT("GET_ERROR: Index out of range: %ld\n", index);
	return (void*)list->buffer[index];
}

void
listSet(ArrayList *list, size_t index, void *item)
{
	if (index >= list->size)
		ERROR_EXIT("SET_ERROR: Index out of range: %ld\n", index);
	list->buffer[index] = item;
}
