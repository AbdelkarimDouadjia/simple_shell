#include "shell.h"

/**
 ** _mienvv - prints the environment
 ** @inf: Struct containe potential argu.
 ** Return: 0
 **/
int _mienvv(info_s *inf)
{
	prin_li_stt(inf->env);
	return (0);
}

/**
 ** _getevv - give a value of an envi var
 ** @inf: Struct containe potential arguments
 ** @nam: env var nam
 ** Return: value
 **/
char *_getevv(info_s *inf, const char *nam)
{
	list_s *nod = inf->env;
	char *p;

	while (nod)
	{
		p = strest_wit(nod->str, nam);
		if (p && *p)
			return (p);
		nod = nod->next;
	}
	return (NULL);
}

/**
 ** _misetrevv -initialized a new env var
 **		or change an existing env var
 ** @inf: Struct containepotential argu,Use to maintain
 **        const funct prototype.
 **  Return: 0
 **/
int _misetrevv(info_s *inf)
{
	if (inf->argc != 3)
	{
		_epputss("Incorrect number of arguements\n");
		return (1);
	}
	if (_sinitenva(inf, inf->argv[1], inf->argv[2]))//
		return (0);
	return (1);
}

/**
 ** _miunssotenvv - Delete the env var
 ** @inf: Struct containe potential argum. Use to maintain
 **        const funct prototype.
 ** Return: 0
 **/
int _miunssotenvv(info_s *inf)
{
	int z;

	if (inf->argc == 1)
	{
		_epputss("Too few arguements.\n");
		return (1);
	}
	for (z = 1; z <= inf->argc; z++)
		_rmounsetenvv(inf, inf->argv[z]);

	return (0);
}

/**
 * evv_populate_lis - populates env files en linked list
 * @inf: Argument with possible arguments.
 *  	used to retain the prototype of  const funct
 * Return: 0
 */
int evv_populate_lis(info_s *inf)
{
	list_s *nod = NULL;
	size_t v;

	for (v = 0; environ[v]; v++)
		nodd_add_end(&nod, environ[v], 0);
	inf->env = nod;
	return (0);
}
