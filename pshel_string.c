#include "shell.h"

/**
 * _stlesn - gives us the size of the entry string.
 * @s: verifie whose length has string
 * Return: number of the size of the entry string.
 */
int _stlesn(char *s)
{

int d = 0;
if (!s)
	return (0);


while (*s++)
	d++;
return (d);
}

/**
 ** _stcmmp - comparing the two entry strings on the parameters.
 ** @s1: a 1 strang
 ** @s2: a 2 strang
 **
 ** Return: (0) is they equal s1 === s2, else nergative if (s1 < s2),
 ** otherwise we get positive on (s1 > s2).
 **/
int _stcmmp(char *s1, char *s2)
{
while (*s1 && *s2)
{
	if (*s1 != *s2)
		return (*s1 - *s2);
	s1++;
	s2++;
}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * strest_wit - verifie to needle the begin stackhay.
 * @haystack: we need to find the string
 * @needle: we need to search the substring in the begin
 * Return: next charactere address on the memory has haystack or NULL
*/
char *strest_wit(const char *haystack, const char *needle)
{

	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _stceat - the two strings must be joinds in one string.
 * @dest: bufes has a destination
 * @src: location of buffes
 * Return: location buffes has been pointered
 */
char *_stceat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}

