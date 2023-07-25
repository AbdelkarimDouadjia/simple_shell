#include "shell.h"

/**
 ** _mihist - hows history list
 ** @inf: struct containe potential arguments
 **  Return: Always 0
 **/
int _mihist(inf_s *inf)
{
	priin_liss(inf->history);
	return (0);
}

/**
 * unseter_aliass - changes alias to string
 * @inf: structure parameter
 * @strr: string aliass
 *
 * Return: (0) if success, (1) otherways on error
 */
int unseter_aliass(info_t *inf, char *strr)
{
	char *p, c;
	int ret;

	p = _tischr(strr, '=');
	if (!p)
		return (1);
	c = *p;
	*p = 0;
	ret = rmove_node_at_index(&(inf->alias),
		gitt_index_index(inf->alias, start_nodd_wi(inf->alias, strr, -1)));
	*p = c;
	return (ret);
}

/**
 * alia_sett - changes alias to string
 * @inf: structure parameter
 * @strr: Alias the String
 * Return: (0) if on success , (1) otherways on error
 */
int alia_sett(info_s *inf, char *strr)
{
	char *p;

	p = _tischr(strr, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (unseter_aliass(inf, strr));

	unseter_aliass(inf, strr);
	return (nodd_add_end(&(inf->alias), strr, 0) == NULL);
}

/**
 ** strings_print_alias - alias string printed
 ** @nod: the node of the alias
 ** Return: (0) if success , else 1 an error 
 **/
int strings_print_alias(list_s *nod)
{
	char *p = NULL, *a = NULL;


	if (nod)
	{
		p = _tischr(nod->str, '=');
		while (a <= p)
		_puuchir(*a++);
		_puuchir('\'');
		_puutss(p + 1);
		_puutss("'\n");
		return (0);
	}
	return (1);
}


/**
 * _mihelpalias - use builtin alias (man ...)
 * @inf: Struct contain potential argu.
 *  Return: 0
 */
int _mihelpalias(info_s *inf)
{
	int v = 0;
	char *p = NULL;
	list_t *nod = NULL;

	if (inf->argc == 1)
	{
		nod = inf->alias;
		while (nod)
		{
			strings_print_alias(nod);
			nod = nod->next;
		}
		return (0);
	}
	for (v = 1; info->argv[v]; v++)
	{
		p = _tischr(inf->argv[v], '=');
		if (p)
			alia_sett(inf, inf->argv[v]);
		else
			strings_print_alias(start_nodd_wi(inf->alias, inf->argv[v], '='));
	}

	return (0);
}
