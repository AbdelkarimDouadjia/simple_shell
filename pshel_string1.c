#include "shell.h"

/**
 ** _stcocp - string has been copied.
 ** @dest: the location of dest
 ** @src: it is a source.
 ** Return: pointer to the dest variable.
 **/
char *_stcocp(char *dest, char *src)
{
	int d = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[d])
	{
		dest[d] = src[d];
		d++;
	}
	dest[d] = 0;
	return (dest);
}

/**
 * _strtprp - the entry string will be duplicated.
 * @str: it is a variable to stored the duplicated string
 * Return: the str var will be pointered
 */
char *_strtprp(const char *str)
{
		int length = 0;

char *ret;
	if (str == NULL)
		return (NULL);
		while (*str++)
		length++;
			ret = malloc(sizeof(char) * (length + 1));
if (!ret)
	return (NULL);

for (length++; length--;)
	ret[length] = *--str;
return (ret);
}
/**
 ** _puutss - givees us the string has on the input field.
 ** @str: print the entry string
 ** Return: void
 **/
void _puutss(char *str)
{
	int d = 0;
if (!str)
	return;
	while (str[d] != '\0')
	{
		_puuchir(str[d]);
		d++;
	}
}

/**
 ** _puuchir - give the char c to stdout funct and print it
 ** @c: it will print the given char
 ** Return: if(1) => correct.
 **		if (-1) it will return an error.
 **/
int _puuchir(char c)
{
static int d;
			static char buf[WRITE_BUF_SIZE];
if (c == BUF_FLUSH || d >= WRITE_BUF_SIZE)
		{
	write(1, buf, d);
		d = 0;
	}
if (c != BUF_FLUSH)
	buf[d++] = c;
return (1);
}
