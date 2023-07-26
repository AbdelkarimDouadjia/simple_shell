#include "shell.h"

/**
 * is_comoodd - try to test the file to check if he execute commandes or not .
 * @inf: a structure inf.
 * @path: link to the directory file
 * Return: 1 on correct, else 0 .
 */
int is_comoodd(info_s *inf, char *path)
{
	struct stat st;

	(void)inf;
	if (!path || stat(path, &st))
	return (0);

	if (st.st_mode & S_IFREG)
	{
	return (1);
	}
	return (0);
}

/**
 * chaa_rdupp -  char with duplicate every one 0
 * @pathstr: a PATH is the strings .
 * @start: index in the beginning
 * @stop: index has halting.
 * Return: pointing to new bufe.
 */
char *chaa_rdupp(char *pathstr, int start, int stop)
{
static char buf[1024];
int d = 0, w = 0;

for (w = 0, d = start; d < stop; d++)
if (pathstr[d] != ':')
	buf[w++] = pathstr[d];
buf[w] = 0;
return (buf);
}

/**
 ** fedn_puht - a path of string identifier the com.
 ** @inf: structure of data info.
 ** @pathstr: a PATH is an string of characteres.
 ** @cmd: a commande to serach for it
 ** Return: a path of commande , else give us a NULL.
 **/
char *fedn_puht(info_s *inf, char *pathstr, char *cmd)
{
int d = 0, curr_pos = 0;
char *path;

if (!pathstr)
	return (NULL);
if ((_stlesn(cmd) > 2) && strest_wit(cmd, "./"))
{
	if (is_comoodd(inf, cmd))
		return (cmd);
}
while (1)
{
	if (!pathstr[d] || pathstr[d] == ':')
	{
		path = chaa_rdupp(pathstr, curr_pos, d);
		if (!*path)
			_stceat(path, cmd);
		else
		{
			_stceat(path, "/");
			_stceat(path, cmd);
		}
		if (is_comoodd(inf, path))
			return (path);
		if (!pathstr[d])
			break;
		curr_pos = d;
	}
	d++;
}
return (NULL);
}

