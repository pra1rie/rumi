#include <stdio.h>
#include "hashtable/hashtable.h"
#include "arraylist/arraylist.h"

int
main(void)
{
	Hash *hash = hashNew(32);
	ArrayList *list = listNew(sizeof(int), 10);

	hashSet(hash, "Salim", "burro");
	hashSet(hash, "Yuuka", "feo");

	listAddBack(list, (void*)34);
	listAddBack(list, (void*)35);

	printf("Salim %s\n", (char*) hashGet(hash, "Salim"));
	printf("Yuuka %s\n", (char*) hashGet(hash, "Yuuka"));

	printf("%d\n", ((int)listPopBack(list)) + ((int)listPopBack(list)));

	hashFree(hash);
	listFree(list);

	return 0;
}
