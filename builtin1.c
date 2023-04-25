#include "shell.h"

/**
 * _myhistory - displays the list history
 * @info: Structure containing arguments.
 *  Return: Success 0
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias - sets alias to the string
 * @info: struct parameter
 * @str: the string
 * Return: Always 0 on success, 1 on error
 */
int unset_alias(info_t *info, char *str)
{
	char *pntr, k;
	int ret;

	pntr = _strchr(str, '=');
	if (!pntr)
		return (1);
	k = *pntr;
	*pntr = 0;
	ret = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*pntr = k;
	return (ret);
}

/**
 * set_alias - sets alias to string
 * @info: struck parameter
 * @str: the string
 * Return: Always 0 on success, 1 on error
 */
int set_alias(info_t *info, char *str)
{
	char *pntr;

	pntr = _strchr(str, '=');
	if (!pntr)
		return (1);
	if (!*++pntr)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - prints alias string
 * @node: alias node
 * Return: Always 0 on success, 1 on error
 */
int print_alias(list_t *node)
{
	char *pntr = NULL, *j = NULL;

	if (node)
	{
		pntr = _strchr(node->str, '=');
		for (j = node->str; j <= pntr; j++)
		_putchar(*j);
		_putchar('\'');
		_puts(pntr + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - mimics the builtin
 * @info: Structure containing potential arguments.
 *  Return: Always 0
 */
int _myalias(info_t *info)
{
	int k = 0;
	char *pntr = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (k = 1; info->argv[k]; k++)
	{
		pntr = _strchr(info->argv[k], '=');
		if (pntr)
			set_alias(info, info->argv[k]);
		else
			print_alias(node_starts_with(info->alias, info->argv[k], '='));
	}

	return (0);
}

