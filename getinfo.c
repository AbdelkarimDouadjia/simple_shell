#include "shell.h"

/**
 * del_inf - initial the info_s struct
 * @inf: adresses in the  struct .
 */
void del_inf(info_s *inf)
{
	inf->arg = NULL;
	inf->argv = NULL;
	inf->path = NULL;
	inf->argc = 0;
}

/**
 * settin_inf - initial by establishe the info_s struct
 * @inf: the adresses structure.
 * @av: parameter of vector
 */
void settin_inf(info_s *inf, char **av)
{
	int d = 0;

	inf->fname = av[0];
	if (inf->arg)
	{
		inf->argv = stoiww(inf->arg, " \t");
		if (!inf->argv)
		{
			inf->argv = malloc(sizeof(char *) * 2);
			if (inf->argv)
			{
				inf->argv[0] = _strtprp(inf->arg);
				inf->argv[1] = NULL;
			}
		}
		for (d = 0; inf->argv && inf->argv[d]; d++)
			;
		inf->argc = d;

		chang_alia(inf);
		change_ver(inf);
	}
}

/**
 * fee_inff - delete the struct of  info_s fieldes.
 * @inf: the adresses structure.
 * @all: Correct if deleting all the fieldes.
 */
void fee_inff(info_s *inf, int all)
{
	del_frre(inf->argv);
	inf->argv = NULL;
	inf->path = NULL;
	if (all)
	{
		if (!inf->cmd_buf)
			free(inf->arg);
		if (inf->env)
			frfee_lis(&(inf->env));
		if (inf->history)
			frfee_lis(&(inf->history));
		if (inf->alias)
			frfee_lis(&(inf->alias));
		del_frre(inf->environ);
			inf->environ = NULL;
		bf_fer((void **)inf->cmd_buf);
			if (inf->readfd > 2)
				close(inf->readfd);
		_puuchir(BUF_FLUSH);
	}
}

