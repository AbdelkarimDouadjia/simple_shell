#include "shell.h"

/**
 * str_oint - changes a string to an int
 * @s: string will be conveted
 * Return: if no number return 0 convert number else
 *       -1 on error
 */
int str_oint(char *s)
{
	int v = 0;
	unsigned long int resu = 0;

	if (*s == '+')
		s++; 
	for (v = 0;  s[v] != '\0'; v++)
	{
		if (s[v] >= '0' && s[v] <= '9')
		{
			resu *= 10;
			resu += (s[v] - '0');
			if (resu > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (resu);
}

/**
 ** errorp_rint -  print a message error
 ** @inf: the return is struct info & parameter
 ** @estrr: string containe specifie type error
 ** Return: if no num return 0, otherwise 
 ** -1 error
 **/
void errorp_rint(info_s *inf, char *estrr)
{
	_epputss(inf->fname);
	_epputss(": ");
	decc_print(inf->line_count, STDERR_FILENO);
	_epputss(": ");
	_epputss(inf->argv[0]);
	_epputss(": ");
	_epputss(estrr);
}

/**
 * decc_print - prints funct decimal integer num
 * @input: inpput
 * @fd: filedescriptore to print to
 *
 * Return: num of char will be printed
 */
int decc_print(int input, int fd)
{
	int (*__putchar)(char) = _puuchir;
	int h, count = 0;
	unsigned int _abs_, current;

	if (fd == STDERR_FILENO)
		_puuchir = _charpiit;
	if (input < 0)
	{
		_abs_ = -input;
		_puuchir('-');
		count++;
	}
	else
		_abs_ = input;
	current = _abs_;
	for (h = 1000000000; h > 1; h /= 10)
	{
		if (_abs_ / h)
		{
			_puuchir('0' + current / h);
			count++;
		}
		current %= h;
	}
	_puuchir('0' + current);
	count++;

	return (count);
}

/**
 * converr_nuum - change the funct and clone of itoa
 * @num: number
 * @base: basee
 * @flags: argum flag
 * Return: string of charactere
 */
char *converr_nuum(long int num, int base, int flags)
{
	static char *array; //
	static char bufers[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';

	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &bufers[49];
	*ptr = '\0';

	while (n != 0)
	{
		*--ptr = array[n % base];
		n /= base;
	}

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 ** comments_replace - replace funct for the first instance of '#' with '\0'
 ** @buf: modify the address of the string
 ** Return:  0;
 **/
void comments_replace(char *buf)
{
	int g;

	for (g = 0; buf[g] != '\0'; g++)
		if (buf[g] == '#' && (!g || buf[g - 1] == ' '))
		{
			buf[g] = '\0';
			break;
		}
}

