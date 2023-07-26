#include "shell.h"

/**
 **_srtingcp - duplicate a string
 *@dest: copied a string
 *@src: original string.
 *@n: duplicated many char.
 *Return: string has been joined.
 */
char *_srtingcp(char *dest, char *src, int n)
{
	char *s = dest;
	int v = 0;
	while (src[v] != '\0' && v < n - 1)
	{
		dest[v] = src[v];
		v++;
	}
	if(v < n)
	{
		int j = v;
		while (j < n)
		{
			dest[j] = '\0';
			j++;
		}
	}
	
	return (s);
}

/**
 **_copncastr - join two strings
 *@dest: string has open.
 *@src: backup group.
 *@n: backup group.
 *Return: string that has been joined.
*/
char *_copncastr(char *dest, char *src, int n)
{
	char *s = dest;
	int v = 0;
	int j = 0;
	
	while (dest[v] != '\0')
	{
		v++;
	}
	
	while (src[j] != '\0' && j < n)
	{
		dest[v + j] = src[j];
		j++;
	}
	
	if (j < n)
	{
		dest[v + j] = '\0';
	}
	
	return (s);
}

/**
*_tischr - seek the char within the string.
*@s: to prased the string.
*@c: person to watch out for.
*Return: (s) a reference to location the memory.
**/
char *_tischr(char *s, char c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return (s);
		s++;
	}
	
	return (NULL);
}
