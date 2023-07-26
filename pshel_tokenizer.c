#include "shell.h"

/**
 * **stoiww - divides the entry string into words and ignore the repeat mots
 * @strr: the entry string on the inout fields
 * @d: the entry string has delimeter.
 * Return: gives us NULL or pointered the entry string to an array.
 */

char **stoiww(char *strr, char *d)
{
	int h, w, k, m, numwords = 0;
	char **s;

if (strr == NULL || strr[0] == 0)
	return (NULL);
if (!d)
	d = " ";
for (h = 0; strr[h] != '\0'; h++)
	if (!del_is(strr[h], d) && (del_is(strr[h + 1], d) || !strr[h + 1]))
		numwords++;

if (numwords == 0)
	return (NULL);


s = malloc((1 + numwords) * sizeof(char *));

	if (!s)
		return (NULL);
	for (h = 0, w = 0; w < numwords; w++)
	{
		while (del_is(strr[h], d))
			h++;
		k = 0;
		while (!del_is(strr[h + k], d) && strr[h + k])
			k++;
			s[w] = malloc((k + 1) * sizeof(char));
			if (!s[w])
			{
				for (k = 0; k < w; k++)
					free(s[k]);
				free(s);
				return (NULL);
			}
			for (m = 0; m < k; m++)
				s[w][m] = strr[h++];
			s[w][m] = 0;
			}
	s[w] = NULL;
	return (s);
}

/**
 * **stoiww2 - separe the entry string into a small words.
 * @strr: store the entry string
 * @d: the entry string has been delimeter.
 * Return: gives us a NULL or s entry string in array pointered on memory
 */
char **stoiww2(char *strr, char d)
{

	int h, w, f, m, numwords = 0;

	char **s;
if (strr == NULL || strr[0] == 0)
	return (NULL);
for (h = 0; strr[h] != '\0'; h++)
		if ((strr[h] != d && strr[h + 1] == d) ||
				    (strr[h] != d && !strr[h + 1]) || strr[h + 1] == d)
			numwords++;
	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (h = 0, w = 0; w < numwords; w++)
	{
		while (strr[h] == d && strr[h] != d)
			h++;
		f = 0;
		while (strr[h + f] != d && strr[h + f] && strr[h + f] != d)
			f++;
		s[w] = malloc((f + 1) * sizeof(char));
		if (!s[w])
		{
			for (f = 0; f < w; f++)
				free(s[f]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < f; m++)
			s[w][m] = strr[h++];
		s[w][m] = 0;
	}
	s[w] = NULL;
	return (s);
}

