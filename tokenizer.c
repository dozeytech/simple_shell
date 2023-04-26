#include "shell.h"

/**
 * **strtow - splits a string into words.
 * @str: the input string
 * @d: delimiter string
 * Return: a pointer to an array of strings, or NULL on failure
 */

char **strtow(char *str, char *d)
{
	int j, k, m, a, number_of_words = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (j = 0; str[j] != '\0'; j++)
		if (!is_delim(str[j], d) && (is_delim(str[j + 1], d) || !str[j + 1]))
			number_of_words++;

	if (number_of_words == 0)
		return (NULL);
	s = malloc((1 + number_of_words) * sizeof(char *));
	if (!s)
		return (NULL);
	for (j = 0, k = 0; k < number_of_words; k++)
	{
		while (is_delim(str[j], d))
			j++;
		m = 0;
		while (!is_delim(str[j + m], d) && str[j + m])
			m++;
		s[k] = malloc((m + 1) * sizeof(char));
		if (!s[k])
		{
			for (m = 0; m < k; m++)
				free(s[m]);
			free(s);
			return (NULL);
		}
		for (a = 0; a < m; a++)
			s[k][a] = str[j++];
		s[k][a] = 0;
	}
	s[k] = NULL;
	return (s);
}

/**
 * **strtow2 - splits string into words
 * @str: input string
 * @d: delimiter
 * Return: a pointer to an array of strings, or NULL on failure
 */
char **strtow2(char *str, char d)
{
	int j, k, m, a, number_of_words = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (j = 0; str[j] != '\0'; j++)
		if ((str[j] != d && str[j + 1] == d) ||
				    (str[j] != d && !str[j + 1]) || str[j + 1] == d)
			number_of_words++;
	if (number_of_words == 0)
		return (NULL);
	s = malloc((1 + number_of_words) * sizeof(char *));
	if (!s)
		return (NULL);
	for (j = 0, k = 0; k < number_of_words; k++)
	{
		while (str[j] == d && str[j] != d)
			j++;
		m = 0;
		while (str[j + m] != d && str[j + m] && str[j + m] != d)
			m++;
		s[k] = malloc((m + 1) * sizeof(char));
		if (!s[k])
		{
			for (m = 0; m < k; m++)
				free(s[m]);
			free(s);
			return (NULL);
		}
		for (a = 0; a < m; a++)
			s[k][a] = str[j++];
		s[k][a] = 0;
	}
	s[k] = NULL;
	return (s);
}
