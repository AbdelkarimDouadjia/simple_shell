#include "shell.h"

/**
 ** hsh - the general main looped shell function.
 ** @inf: return structure data information & thier argu.
 ** @av: from the general main() funct has verctor as an parametere .
 ** Return: 0 if correct ,otherwise is 1 when error.
 **/
int hsh(info_s *inf, char **av)
{
ssize_t r = 0;
int builtin_ret = 0;

while (r != -1 && builtin_ret != -2)
{
	del_inf(inf);
	if (activitated(inf))
		_puutss("$ ");
	_charpiit(BUF_FLUSH);
	r = gis_inptu(inf);
	if (r != -1)
	{
		settin_inf(inf, av);
		builtin_ret = builtinco_fins(inf);
		if (builtin_ret == -1)
			fin_dcomnd(inf);
	}
	else if (activitated(inf))
		_puuchir('\n');
	fee_inff(inf, 0);

}
wriitc_eaphistory(inf);
fee_inff(inf, 1);
if (!activitated(inf) && inf->status)
	exit(inf->status);

if (builtin_ret == -2)
{
	if (inf->err_num == -1)
		exit(inf->status);
	exit(inf->err_num);
}
return (builtin_ret);
}

/**
** builtinco_fins - Serach for command that has a builtin.
**
** @inf: the parameter & return info struct
** Return: if (2) the signal has function exit,
**	else if (1) we get builtin incorect,
**	else if (0) we execut correctly,
**	else if (-1) we dont find any builtin funct.
*/
int builtinco_fins(info_s *inf)
{
int d, buuilt_i__r = -1;

bilttin_tal bultntl[] = {
	{"exit", exi_mi},
	{"env", _mievnv},
	{"help", _mihelyp},
	{"history", _mihist},
	{"setenv", _misetrevv},
	{"unsetenv", _miunssotenvv},
	{"cd", _micded},
	{"alias", _mihelpalias},
	{NULL, NULL}
};
for (d = 0; bultntl[d].type; d++)

	if (_strcmp(inf->argv[0], bultntl[d].type) == 0)
{
		inf->line_count++;
		buuilt_i__r = bultntl[d].func(inf);
	break;
	}

return (buuilt_i__r);
}

/**
 ** fin_dcomnd - Search a link path for commandes .
 ** @inf: it return a structure data of information & argum.
 ** Return: nothing
 **/
void fin_dcomnd(info_s *inf)
{
	char *path = NULL;
	int id, w;

inf->path = inf->argv[0];
if (inf->linecount_flag == 1)
{
	inf->line_count++;
	inf->linecount_flag = 0;
}
for (id = 0, w = 0; inf->arg[id]; id++)
	if (!del_is(inf->arg[id], " \t\n"))
		w++;
if (!w)
	return;

path = fedn_puht(inf, _getevv(inf, "PATH="), inf->argv[0]);
if (path)
{
	inf->path = path;
	for_ocmand(inf);
}
	else
	{
if ((activitated(inf) || _getevv(inf, "PATH=") || inf->argv[0][0] == '/')
&& is_comoodd(inf, inf->argv[0]))
			for_ocmand(inf);
		else if (*(inf->arg) != '\n')
		{
			inf->status = 127;
			errorp_rint(inf, "not found\n");
		}
	}
}

/**
 * for_ocmand - forking a thread exec after command runs
 * @inf: return structure of informations & an argument
 * Return: nothing
 */
void for_ocmand(info_s *inf)
{
pid_t child_pid;

child_pid = fork();
if (child_pid == -1)
{

perror("Error:");
return;
}
if (child_pid == 0)
{
if (execve(inf->path, inf->argv, envr_git(inf)) == -1)
{
	fee_inff(inf, 1);
	if (errno == EACCES)
		exit(126);
	exit(1);
}

}
else
{
wait(&(inf->status));
if (WIFEXITED(inf->status))
{
	inf->status = WEXITSTATUS(inf->status);
	if (inf->status == 126)
		errorp_rint(inf, "Permission denied\n");
}
}
}

