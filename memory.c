#include "shell.h"

/**
 * bf_fer - delete the pointered adress and free the NULL adress on memory.
 * @ptr: delete the pointered adresses on the memory
 * Return: 1 only always on freed , 0 else.
 */
int bf_fer(void **ptr)
{
if (ptr && *ptr)
{
	free(*ptr);
	*ptr = NULL;
	return (1);
}
return (0);
}
