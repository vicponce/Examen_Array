#include <stdio.h>
#include <stdlib.h>

struct ArrayList{
	int reservedSize;
	int  Size;
	void **elementos;

	void (*add_element)();
	void (*remove_element)();
	void (*set)();
	struct ArrayList* (*get)();
	void (*push)();
	struct ArrayList* (*pop)();
	int (*indexOf)();
	int (*size)();
	int (*contains)();
	int (*containsAll)();
	int (*isEmpty)();
	struct ArrayList* (*clone)();
	struct ArrayList* (*subList)();
	void (*clear)();	
} ;
