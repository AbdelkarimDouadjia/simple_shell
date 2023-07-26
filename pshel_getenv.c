#include "shell.h"

/**
 ** envr_git - returns a mount of letters on array cpy of our environ
 ** @inf: Structure containe potential argum.
 ** Return: 0
 **/
char **envr_git(info_s *inf)
{
	if (!inf->environ || inf->env_changed)
	{
		inf->environ = liss_to_str(inf->env);
		inf->env_changed = 0;
	}

	return (inf->environ);
}

/**
 * _rmounsetenvv - Delete an var envr
 * @inf: Structure containe potential argum.
 *  Return: 1 when remove, 0 else
 * @var: property String var env.
 */
int _rmounsetenvv(info_s *inf, char *var)
{
	list_s *nod = inf->env;
	size_t d = 0;
	char *p;

	if (!nod || !var)
		return (0);

	while (nod)
	{
		p = strest_wit(nod->str, var);
		if (p && *p == '=')
		{
			inf->env_changed = rmove_node_at_index(&(inf->env), d);
			d = 0;
			nod = inf->env;
			continue;
		}
		nod = nod->next;
		d++;
	}
	return (inf->env_changed);
}

/**
 * _sinitenva - Initial a new environment var,
 *             or change an exist 1.
 * @inf: Struct containe potential argum.
 * @var: an string of env variable property
 * @value: an string of env variable values.
 *  Return: 0.
 */
int _sinitenva(info_s *inf, char *var, char *value)
{
	char *buf = NULL;
	list_s *nod;
	char *p;

	if (!var || !value)
		return (0);

	buf = malloc(_stlesn(var) + _stlesn(value) + 2);
	if (!buf)
		return (1);
	_stcocp(buf, var);
	_stceat(buf, "=");
	_stceat(buf, value);
	nod = inf->env;
	while (nod)
	{
		p = strest_wit(nod->str, var);
		if (p && *p == '=')
		{
			free(nod->str);
			nod->str = buf;
			inf->env_changed = 1;
			return (0);
		}
		nod = nod->next;
	}
	nodd_add_end(&(inf->env), buf, 0);
	free(buf);
	inf->env_changed = 1;
	return (0);
}


