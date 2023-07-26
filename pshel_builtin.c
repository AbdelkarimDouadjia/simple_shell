#include "shell.h"

/**
 ** exi_mi - the shell exist
 ** @inf: struct contain petential argu and use the const func prototype
 ** Return: exits with the exit
 ** if 0 is the info.argv[0]!= "exit"
 **/
int exi_mi(info_s *inf)
{
	int exiverifie;

	if (inf->argv[1])
	{
		exiverifie = str_oint(inf->argv[1]);
		if (exiverifie == -1)
		{
			inf->status = 2;
			errorp_rint(inf, "Illegal number: ");
			_eputts(inf->argv[1]);
			_charpiit('\n');
			return (1);
		}
		inf->err_num = str_oint(inf->argv[1]);
		return (-2);
	}
	inf->err_num = -1;
	return (-2);
}

/**
 * _micded - change the current directory of process
 * @inf: struct containe potential arguments
 * Return: 0 always
 */
int _micded(info_s *inf)
{
	char *z, *dr, bufers[1024];
	int chdir_ret;

	z = getcwd(bufers, 1024);
	if (!z)
		_puutss("TODO: >>getcwd failure emsg here<<\n");
	if (!inf->argv[1])
	{
		dr = _getevv(inf, "HOME=");
		if (!dr)
			chdir_ret = chdir((dr = _getevv(inf, "PWD=")) ? dr : "/");
		else
			chdir_ret = chdir(dr);
	}
	else if (_stcmmp(inf->argv[1], "-") == 0)
	{
		if (!_getevv(inf, "OLDPWD="))
		{
			_puutss(z);
			_puuchir('\n');
			return (1);
		}
		_puutss(_getevv(inf, "OLDPWD=")), _puuchir('\n');
		chdir_ret = /* TODO: what should this be? */
			chdir((dir = _getevv(inf, "OLDPWD=")) ? dr : "/");
	}
	else
		chdir_ret = chdir(inf->argv[1]);
	if (chdir_ret == -1)
	{
		errorp_rint(inf, "can't cd to ");
		_eputts(inf->argv[1]), _charpiit('\n');
	}
	else
	{
		_sinitenva(inf, "OLDPWD", _getevv(inf, "PWD="));
		_sinitenva(inf, "PWD", getcwd(bufers, 1024));
	}
	return (0);
}

/**
 ** _mihelyp - change current directory of process
 ** @inf: struct containe potential argument
 **Return: 0 always
 **/
int _mihelyp(info_s *inf)
{
	char **arg_array;

	arg_array = inf->argv;
	_puutss("help call works. Function not yet implemented \n");
	if (0)
		_puutss(*arg_array);
	return (0);
}
