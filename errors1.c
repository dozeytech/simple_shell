#include "shell.h"

/**
 * _erratoi - converts string int
 * @s: string
 * Return: 0 if no number in string, converted number else
 *       -1 on error
 */
int _erratoi(char *s)
{
	int j = 0;
	unsigned long int result = 0;

	if (*s == '+')
		s++;
	for (j = 0;  s[j] != '\0'; j++)
	{
		if (s[j] >= '0' && s[j] <= '9')
		{
			result *= 10;
			result += (s[j] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
}

/**
 * print_error - prints error message
 * @info: parameter & return struck infor
 * @estr: string specified error type
 * Return: 0 if no numbers in string, converted number else
 *        -1 on error
 */
void print_error(info_t *info, char *estr)
{
	_eputs(info->fname);
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(estr);
}

/**
 * print_d - function that prints an int
 * @input: input
 * @fd: file descriptor
 * Return: number of char printed
 */
int print_d(int input, int fd)
{
	int (*__putchar)(char) = _putchar;
	int j, count = 0;
	unsigned int _abs_, new;

	if (fd == STDERR_FILENO)
		__putchar = _eputchar;
	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		count++;
	}
	else
		_abs_ = input;
	new = _abs_;
	for (j = 1000000000; j > 1; j /= 10)
	{
		if (_abs_ / j)
		{
			__putchar('0' + new / j);
			count++;
		}
		new %= j;
	}
	__putchar('0' + new);
	count++;

	return (count);
}

/**
 * convert_number - converter function.
 * @num: number to be converted
 * @base: base of the num
 * @flags: parameter flags
 * Return: string
 */
char *convert_number(long int num, int base, int flags)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *pntr;
	unsigned long n = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';

	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	pntr = &buffer[49];
	*pntr = '\0';

	do	{
		*--pntr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--pntr = sign;
	return (pntr);
}

/**
 * remove_comments - function replaces first instance
 * @buf: address of the string
 * Return: Always 0;
 */
void remove_comments(char *buf)
{
	int j;

	for (j = 0; buf[j] != '\0'; j++)
		if (buf[j] == '#' && (!j || buf[j - 1] == ' '))
		{
			buf[j] = '\0';
			break;
		}
}

