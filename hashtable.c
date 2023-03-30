#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hashtable.h"

size_t
hashSimpleHash(Hash *hash, char *key)
{
	size_t val = 0;
	size_t len = strlen(key);
	for (size_t i = 0; i < len; ++i) {
		val += key[i] * len;
	}
	return val % hash->size;
}

HashBranch*
hashBranch(char *key, void *value)
{
	HashBranch *b = malloc(sizeof(HashBranch));
	b->key = key;
	b->value = value;
	b->next = NULL;
	return b;
}

Hash*
hashNew(size_t size)
{
	Hash *hash = malloc(sizeof(Hash));
	hash->list = calloc(sizeof(HashBranch), size);
	hash->size = size;
	hash->hash = &hashSimpleHash;

	for (size_t i = 0; i < size; ++i) {
		hash->list[i] = (HashBranch) {
				.key = "",
				.value = NULL,
				.next = NULL,
		};
	}

	return hash;
}

void
hashFree(Hash *hash)
{
	// this supposedly frees all branches
	for (size_t i = 0; i < hash->size; ++i) {
		HashBranch *next, *current;
		next = hash->list[i].next;

		while (next != NULL) {
			current = next;
			next = next->next;
			free(current);
		}
	}

	free(hash->list);
	free(hash);
}

void*
hashGet(Hash *hash, char *key)
{
	size_t pos = hash->hash(hash, key);

	if (strcmp(key, hash->list[pos].key) == 0)
		return hash->list[pos].value;

	HashBranch *next = &hash->list[pos];
	while (next != NULL) {
		if (strcmp(key, next->key) == 0)
			return next->value;
		next = next->next;
	}

	return NULL;
}

void
hashSet(Hash *hash, char *key, void *value)
{
	size_t pos = hash->hash(hash, key);

	if (strlen(hash->list[pos].key) == 0) {
		hash->list[pos] = (HashBranch) {
			.key = key,
			.value = value,
			.next = NULL,
		};
		return;
	}

	if (strcmp(key, hash->list[pos].key) == 0) {
		hash->list[pos].value = value;
		return;
	}

	HashBranch *next = &hash->list[pos];
	while (next->next != NULL) {
		if (strcmp(key, next->key) == 0) {
			next->value = value;
			return;
		}
		next = next->next;
	}

	next->next = hashBranch(key, value);
}
