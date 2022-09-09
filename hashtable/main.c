#include <stdio.h>
#include "hashtable.h"


int
main(void)
{
	Hash *hash = hashNew(32);
	hashSet(hash, "Salim", "feo");
	hashSet(hash, "Yuuka", "burro");

	printf("Salim %s\n", (char*) hashGet(hash, "Salim"));
	printf("Yuuka %s\n", (char*) hashGet(hash, "Yuuka"));

	hashFree(hash);
	return 0;
}
