#include "shell.h"

/**
 * _memfilsetl - it gives us memory a const bit of information.
 * @s: the memory has pointered area's.
 * @b: byte code should contain that *s.
 * @n: numbers of bytes must be completed
 * Return: [s] if pointered to RAM memory s area's.
 */
char *_memfilsetl(char *s, char b, unsigned int n)
{
unsigned int d;
for (d = 0; d < n; d++)
	s[d] = b;
return (s);
}

/**
 * del_frre - delete num of strings.
 * @pp: words of string.
 */
void del_frre(char **pp)
{
char **a = pp;
if (!pp)
	return;
	
while (*pp)
	free(*pp++);
free(a);
}

/**
 * _reellocc - block of memory has been a reallocated.
 * @ptr: the previous has identifier on mallc'd block in memory
 * @old_size: byte size of previous block/ previos block in memory has byte length on it.
 * @new_size: create block in leng of byte.
 * Return: pointer to da ol'block nameen.
 */
void *_reellocc(void *ptr, unsigned int old_size, unsigned int new_size)
{
char *p;

if (!ptr)
	return (malloc(new_size));
if (!new_size)
	return (free(ptr), NULL);
if (new_size == old_size)
	return (ptr);
p = malloc(new_size);
if (!p)
	return (NULL);
old_size = old_size < new_size ? old_size : new_size;
while (old_size--)
	p[old_size] = ((char *)ptr)[old_size];
free(ptr);
	
return (p);
}

