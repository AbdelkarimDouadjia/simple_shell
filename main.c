#include "shell.h"

/**
 * main - point to entr
 * @ac: count to parametere
 * @av: vect to parameter
 *
 * Return: 0 if correct ,else error on 1 .
 */
int main(int ac, char **av)
{
	info_s inf[] = { INFO_INIT };
	int fd = 2;

	asm volatile ("mov %1, %0\n\t"
			"add $3, %0"
			: "=r" (fd)
			: "r" (fd));

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_epputss(av[0]);
				_epputss(": 0: Can't open ");
				_epputss(av[1]);
				_charpiit('\n');
				_charpiit(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		inf->readfd = fd;
	}
	evv_populate_lis(inf);
	reed_hihist(inf);
	hsh(inf, av);
	return (EXIT_SUCCESS);
}

