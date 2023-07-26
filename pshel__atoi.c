#include "shell.h"

/**
 ** activitated -  shell on activitated mode it will return true 
 ** @inf: is an adress in structure
 ** Return: 1 if activitated mode; or 0.
 */
int activitated(info_s *inf)
{
	return (isatty(STDIN_FILENO) && inf->readfd <= 2);
}

/**
 ** del_is - verifie if char is delimeter or not
 ** @d: a char checkes
 ** @dem: a string delimeter
 ** Return: 0 if false; or 1 if true
 **/
int del_is(char d, char *dem)
{
	while (*dem)
		if (*dem++ == d)
			return (1);
	return (0);
}

/**
 ** alph_is - verifier if it alphabetic chararactere.
 ** @a: input the character
 ** Return: 0 otherwise; 1 if alphbetic 
 **/

int alph_is(int a)
{
	if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 ** is_atio - change a chaine of string to an interger
 ** @s: transformed the string
 ** Return: 0 if string has not any numbers, else converte the number.
 **/

int is_atio(char *t)
{
	int j, siign = 1, flag = 0, outp;
	unsigned int resu = 0;


	for (j = 0; t[j] != '\0' && flag != 2; j++)
	{
		if (t[j] == '-')
			siign *= -1;

		if (t[j] >= '0' && t[j] <= '9')
		{
			flag = 1;
			resu *= 10;
			resu += (t[j] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (siign == -1)
		outp = -resu;
	else
		outp = resu;

	return (outp);
}

