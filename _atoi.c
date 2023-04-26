#include "shell.h"

/**
 * interactive - returns true if shell is interactive mode
 * @info: struct address
 * Return: 1 if interactive mode, else 0
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - determine if character is a delimeter
 * @c: char to cheack
 * @delim: delimeter string
 * Return: 1 if true, if false 0
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 * _isalpha - check for alphabets
 * @c: character to input
 * Return: 1 if c is an alphabet, else 0
 */
int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - convert string to int
 * @s: string to be converted
 * Return: 0 if no numbers in string
 */
int _atoi(char *s)
{
	int p, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (p = 0; s[p] != '\0' && flag != 2; p++)
	{
		if (s[p] == '-')
			sign *= -1;

		if (s[p] >= '0' && s[p] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[p] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}

