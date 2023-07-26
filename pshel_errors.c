#include "shell.h"

/**
 * _epputss - print a string on input field
 * @strr:  printed string
 *
 * Return: Void (Nothing)
 */
void _epputss(char *strr)
{
	int v = 0;

	if (!strr)
		return;
	while (strr[v] != '\0')
	{
		_charpiit(strr[v]);
		v++;
	}
}

/**
 * _charpiit - add the char C to Stderr
 * @h: The txt will be printed
 *
 * Return:  (1) if correct.
 **  Errno is will be a value of -1 is return.
 */
int _charpiit(char h)
{
	static int d;
	static char buf[WRITE_BUF_SIZE];

	if (h == BUF_FLUSH || d >= WRITE_BUF_SIZE)
	{
		write(2, buf, d);
		d = 0;
	}
	if (h != BUF_FLUSH)
		buf[d++] = h;
	return (1);
}

/**
 * _pufiudf - writes the Char c in the specfic fd.
 * @h: The txt will be printed.
 * @fd: adress to writed to it
 * Return:  1 if correct answser 1.
 * Otherways else an returned -1.
 */
int _pufiudf(char h, int fd)
{
	static int d;
	static char buf[WRITE_BUF_SIZE];

	if (h == BUF_FLUSH || d >= WRITE_BUF_SIZE)
	{
		write(fd, buf, d);
		d = 0;
	}
	if (h != BUF_FLUSH)
		buf[d++] = h;
	return (1);
}

/**
 * _pufstd - writes a string of input field
 * @strr: str that be printed.
 * @fd: his address to print.
 *
 * Return: number of char entered in input
 */
int _pufstd(char *strr, int fd)
{
	int f = 0;

	if (!strr)
		return (0);
	while (*strr)
	{
		f += _pufiudf(*strr++, fd);
	}
	return (f);
}
