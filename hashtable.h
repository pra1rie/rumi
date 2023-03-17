#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <stdlib.h>

typedef struct hashtable_branch
{
	char *key;
	void *value;
	struct hashtable_branch *next;
} HashBranch;

typedef struct hashtable
{
	size_t size;
	HashBranch *list;
	size_t (*hash)(struct hashtable*, char*);
} Hash;

size_t hashSimpleHash(Hash *hash, char *key);

HashBranch *hashBranch(char *key, void *value);
Hash *hashNew(size_t size);
void hashFree(Hash *hash);
void *hashGet(Hash *hash, char *key);
void hashSet(Hash *hash, char *key, void *value);

#endif /* HASHTABLE_H */
