#include "shell.h"

/**
 * inpu_buff -  chainds commandes with buff.
 * @inf: struct argumnt
 * @buf: buisness of address
 * @len: location on the memory of length var
 * Return: bit code to read
 */
ssize_t inpu_buff(info_s *inf, char **buf, size_t *len)
{
	ssize_t r = 0;
	size_t len_p = 0;

	if (!*len)
	{
		free(*buf);
		*buf = NULL;
		signal(SIGINT, sigintHandler);
#if USE_GETLINE
		r = getline(buf, &len_p, stdin);
#else
		r = _geline(info, buf, &len_p);
#endif
		if (r > 0)
		{
			if ((*buf)[r - 1] == '\n')
			{
				(*buf)[r - 1] = '\0';
				r--;
			}
			inf->linecount_flag = 1;
			comments_replace(*buf);
			buil_ddhs_ls(inf, *buf, inf->histcount++);
			{
				*len = r;
				inf->cmd_buf = buf;
			}
		}
	}
	return (r);
}

/**
 * gts_inpu - delete new line from the line
 * @inf: argument struct
 * Return: bit code to read
 */
ssize_t gts_inpu(info_s *inf)
{
	static char *buf;
	static size_t v, w, len;
	ssize_t r = 0;
	char **buf_p = &(inf->arg), *p;
	_puuchir(BUF_FLUSH);
	r = inpu_buff(inf, &buf, &len);
	if (r == -1) 
		return (-1);
	if (len)
	{
		w = v;
		p = buf + v;

		chic_char(inf, buf, &w, v, len);
		while (w < len)
		{
			if (is_chair(inf, buf, &w))
				break;
			w++;
		}

		v = w + 1; 
		if (v >= len)
		{
			v = len = 0;
			inf->cmd_buf_type = CMD_NORM;
		}

		*buf_p = p;
		return (_stlesn(p));
	}

	*buf_p = buf;
	return (r);
}
/*
** buff_reead - reeads an article for buffer
** @inf: var struct
** @buf: bufers
** @h: siz
** Return: r
*/
ssize_t buff_reead(info_s *inf, char *buf, size_t *h)
{
	ssize_t r = 0;

	if (*h)
		return (0);
	r = read(inf->readfd, buf, READ_BUF_SIZE);
	if (r >= 0)
		*h = r;
	return (r);
}

/**
 ** _geline -obtain the following line of input from STDIN
 ** @inf: struct argu
 ** @ptr: address of the buffers pointered, else (reallocated / NULL).
 ** @length: if not NULL the size of preallocated ptr will buffer.
 ** Return: S.
 **/
int _geline(info_s *inf, char **ptr, size_t *length)
{
	static char buf[READ_BUF_SIZE];
	static size_t h, len;
	size_t k;
	ssize_t r = 0, s = 0;
	char *p = NULL, *new_p = NULL, *c;

	p = *ptr;
	if (p && length)
		s = *length;
	if (h == len)
		h = len = 0;

	r = buff_reead(inf, buf, &len);
	if (r == -1 || (r == 0 && len == 0))
		return (-1);

	c = _tischr(buf + h, '\n');
	k = c ? 1 + (unsigned int)(c - buf) : len;
	new_p = _reellocc(p, s, s ? s + k : k + 1);
	if (!new_p)
		return (p ? free(p), -1 : -1);
	if (s)
		_copncastr(new_p, buf + h, k - h);
	else
		_srtingcp(new_p, buf + h, k - h + 1);

	s += k - h;
	h = k;
	p = new_p;

	if (length)
		*length = s;
	*ptr = p;
	return (s);
}

/**
 ** sign_Hand - ctrl + C stopped
 ** @sig_num: an num like signal
 ** Return: nothing.
 **/
void sign_Hand(__attribute__((unused))int sig_num)
{
	_puutss("\n");
	_puutss("$ ");
	_puuchir(BUF_FLUSH);
}

