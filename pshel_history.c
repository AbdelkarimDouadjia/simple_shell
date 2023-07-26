#include "shell.h"

/**
 ** git_histoir_fi - obtains the histrique files
 ** @inf: struct argum.
 ** Return:  historique of the file in the allocated string .
 **/

char *git_histoir_fi(info_s *inf)
{
	char *buf, *dir;

	dir = _getevv(inf, "HOME=");
	if (!dir)
		return (NULL);
	buf = malloc(sizeof(char) * (_stlesn(dir) + _stlesn(HIST_FILE) + 2));
	if (!buf)
		return (NULL);
	buf[0] = 0;
	_stcocp(buf, dir);
	_stceat(buf, "/");
	_stceat(buf, HIST_FILE);
	return (buf);
}

/**
 * wriitc_eaphistory - appends or changes a file to exist one.
 * @inf: structure argument
 * Return: 1 correct ;-1 otherwise
 */
int wriitc_eaphistory(info_s *inf)
{
	ssize_t fd;
	char *filename = git_histoir_fi(inf);
	list_s *node = NULL;

	if (!filename)
		return (-1);

	fd = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(filename);
	if (fd == -1)
		return (-1);
	for (node = inf->history; node; node = node->next)
	{
		_pufstd(node->str, fd);
		_pufiudf('\n', fd);
	}
	_pufiudf(BUF_FLUSH, fd);
	close(fd);
	return (1);
}

/**
 * reed_hihist - reades historique from the files.
 * @inf: structure Argu
 * Return: correct if histcount,else  0.
 */
int reed_hihist(info_s *inf)
{
	int h, last = 0, linecount = 0;
	ssize_t fd, rdlen, fsize = 0;
	struct stat st;
	char *buf = NULL, *filename = git_histoir_fi(inf);

	if (!filename)
		return (0);

	fd = open(filename, O_RDONLY);
	free(filename);
	if (fd == -1)
		return (0);
	if (!fstat(fd, &st))
		fsize = st.st_size;
	if (fsize < 2)
		return (0);
	buf = malloc(sizeof(char) * (fsize + 1));
	if (!buf)
		return (0);
	rdlen = read(fd, buf, fsize);
	buf[fsize] = 0;
	if (rdlen <= 0)
		return (free(buf), 0);
	close(fd);
	for (h = 0; h < fsize; h++)
		if (buf[h] == '\n')
		{
			buf[h] = 0;
			buil_ddhs_ls(inf, buf + last, linecount++);
			last = h + 1;
		}
	if (last != h)
		buil_ddhs_ls(inf, buf + last, linecount++);
	free(buf);
	inf->histcount = linecount;
	while (inf->histcount-- >= HIST_MAX)
		rmove_node_at_index(&(inf->history), 0);
	remun_hest(inf);
	return (inf->histcount);
}

/**
 * buil_ddhs_ls - create an entry at histoire (linked-list).
 * @inf: Struct containe potential of argums .
 * @buf: bufers
 * @linecount: linecount of the histoire or histcount var.
 * Return:  opposite of 1.
 */
int buil_ddhs_ls(info_s *inf, char *buf, int linecount)
{
	list_s *nod = NULL;

	if (inf->history)
		nod = inf->history;
	nodd_add_end(&nod, buf, linecount);

	if (!inf->history)
		inf->history = nod;
	return (0);
}

/**
 * remun_hest - the revisions, is histoire of (linked-list) on renumber.
 * @inf: an struct containe potential argums.
 * Return: updated of histcount var.
*/
int remun_hest(info_s *inf)
{
	list_s *nod = inf->history;
	int i = 0;

	while (nod)
	{
		nod->num = i++;
		nod = nod->next;
	}
	return (inf->histcount = i);
}

