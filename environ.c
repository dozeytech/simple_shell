#include "shell.h"

/**
 * _myenv - print the environment
 * @info: function containing parameters.
 * Return: Always 0
 */
int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * _getenv - gets the value of the environment.
 * @info: function containing parameters.
 * @name: environment's name
 * Return: value of environment
 */
char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *pntr;

	while (node)
	{
		pntr = starts_with(node->str, name);
		if (pntr && *pntr)
			return (pntr);
		node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenv - compute a new environment variable,
 * @info: function containing parameters.
 *  Return: Always 0
 */
int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of parameters\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv - Delete an environment variable
 * @info: Function containing parameters.
 * Return: Always 0
 */
int _myunsetenv(info_t *info)
{
	int j;

	if (info->argc == 1)
	{
		_eputs("Too few parameters.\n");
		return (1);
	}
	for (j = 1; j <= info->argc; j++)
		_unsetenv(info, info->argv[j]);

	return (0);
}

/**
 * populate_env_list - populates environmet linked list
 * @info: function containing parameters
 * Return: Always 0
 */
int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t j;

	for (j = 0; environ[j]; j++)
		add_node_end(&node, environ[j], 0);
	info->env = node;
	return (0);
}

