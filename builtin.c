#include "shell.h"

/**
 * _myexit - exits
 * @info: function containing parameters
 * Return: exits with a given exit status
 * (0) if info.argv[0] != "exit"
 */
int _myexit(info_t *info)
{
	int exit;

	if (info->argv[1])
	{
		exit = _erratoi(info->argv[1]);
		if (exit == -1)
		{
			info->status = 2;
			print_error(info, "Illegal number: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->err_num = _erratoi(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}

/**
 * _mycd - changes the current dir
 * @info: Function containing parameters
 * Return: Success 0
 */
int _mycd(info_t *info)
{
	char *s, *d, buffer[1024];
	int ret;

	s = getcwd(buffer, 1024);
	if (!s)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		d = _getenv(info, "HOME=");
		if (!d)
			ret = /* TODO: what should this be? */
				chdir((d = _getenv(info, "PWD=")) ? d : "/");
		else
			ret = chdir(d);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!_getenv(info, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
		ret = /* TODO: what should this be? */
			chdir((d = _getenv(info, "OLDPWD=")) ? d : "/");
	}
	else
		ret = chdir(info->argv[1]);
	if (ret == -1)
	{
		print_error(info, "can't cd to ");
		_eputs(info->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * _myhelp - changes the current directory
 * @info: Function containing parameters
 * Return: Always 0
 */
int _myhelp(info_t *info)
{
	char **arg_array;

	arg_array = info->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*arg_array); /* temp att_unused workaround */
	return (0);
}

