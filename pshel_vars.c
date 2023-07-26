#include "shell.h"

/**
 * is_chair - check is the current car in buffes is delimeter char or not
 * @inf:  the structure argum.
 * @buf: a buffes charactere
 * @p: location adress on the memory of the current buffes
 * Return: 0 always, else 1 => delimeter chair
 */
int is_chair(info_s *inf, char *buf, size_t *p)
{
	size_t w = *p;

	if (buf[w] == '|' && buf[w + 1] == '|')
	{
		buf[w] = 0;
			w++;
		inf->cmd_buf_type = CMD_OR;
	}

	else if (buf[w] == '&' && buf[w + 1] == '&')
	{
		buf[w] = 0;

		w++;
		inf->cmd_buf_type = CMD_AND;
	}
	else if (buf[w] == ';')
	{
		buf[w] = 0;
		inf->cmd_buf_type = CMD_CHAIN;
	}


else
	return (0);
*p = w;
return (1);
}



/**
 ** chic_char - verifie wat must continue chain base on last state
 ** @inf:  the structure argum.
 ** @buf: a buffes charactere
 ** @p:  location adress on the memory of the current buffes
 ** @i: pos of beginnign in buffes
 **
 ** @len: buffes size
 ** Return: Nothing
 **/
void chic_char(info_s *inf, char *buf, size_t *p, size_t i, size_t len)
{
	size_t w = *p;

if (inf->cmd_buf_type == CMD_AND)
{
if (inf->status)
{
	buf[i] = 0;
	w = len;
}
	}
	if (inf->cmd_buf_type == CMD_OR)
	{
		if (!inf->status)
		{
			buf[i] = 0;
			w = len;
		}
	}

	*p = w;
}

/**
 * replace_alias - changes the alias's string entry tokenize .
 * @inf: the structure argum.
 * Return: (0) always , else 1 replace the entry string.
 */
int replace_alias(info_s *inf)
{
	int h;
	list_s *noe;
	char *p;

	for (h = 0; h < 10; h++)
	{
		noe = start_nodd_wi(inf->alias, inf->argv[0], '=');
		if (!noe)
			return (0);
		free(inf->argv[0]);
		p = _tischr(noe->str, '=');
		if (!p)
			return (0);
		p = _strtprp(p + 1);
		if (!p)
			return (0);
		inf->argv[0] = p;
	}
	return (1);
}

/**
 ** change_ver - changes a variables into string tokenize .
 ** @inf: a structure has argum.
 ** Return: always (0) , otherwise we get (1) after replaced .
 **/
int change_ver(info_s *inf)
{
	int h = 0;
	list_s *noe;

for (h = 0; inf->argv[h]; h++)
{
if (inf->argv[h][0] != '$' || !inf->argv[][1])
	continue;

if (!_stcmmp(inf->argv[h], "$?"))
{
	cahnge_strr(&(inf->argv[h]),
			_strtprp(converr_nuum(inf->status, 10, 0)));
	continue;
}
	if (!_stcmmp(inf->argv[h], "$$"))
	{
					cahnge_strr(&(inf->argv[h]),
							_strtprp(converr_nuum(getpid(), 10, 0)));
					continue;
				}
		noe = start_nodd_wi(inf->env, &inf->argv[h][1], '=');
if (noe)
{
	cahnge_strr(&(inf->argv[h]),
			_strtprp(_tischr(noe->str, '=') + 1));
	continue;
}
cahnge_strr(&inf->argv[h], _strtprp(""));

}
return (0);
}

/**
 * cahnge_strr - the entry string will be changes
 * @old: stored the first entry string in var.
 * @new: stored the second entry string in var.
 * Return: 0 always, otherwise if (1) the second
 *		string will be changed to first.
 */
int cahnge_strr(char **old, char *new)
{

free(*old);

		*old = new;


return (1);
}

