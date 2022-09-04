#include <stdio.h>
#include "array_list.h"


int
main(void)
{
	ArrayList *list = listNew(sizeof(int), 10);
	listAddBack(list, (void*)34);
	listAddBack(list, (void*)35);

	printf("%d\n", ((int)listPopBack(list)) + ((int)listPopBack(list)));

	listFree(list);
	return 0;
}
