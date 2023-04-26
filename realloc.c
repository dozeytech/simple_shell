#include "shell.h"

/**
 * _memset - fills memory with a constant byte
 * @s: pointer to the memory area
 * @b: byte to fill *s with
 * @n: amount of bytes to be filled
 * Return: (s) a pointer to the memory area s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int j;

	for (j = 0; j < n; j++)
		s[j] = b;
	return (s);
}

/**
 * ffree - frees a string
 * @pp: string of strings
 */
void ffree(char **pp)
{
	char **r = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(r);
}

/**
 * _realloc - reallocates a block memory
 * @ptr: pointer to previous allocated block
 * @old_size: byte size of previous block
 * @new_size: byte size of new block
 * Return: pointer to the old block name
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *pntr;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	pntr = malloc(new_size);
	if (!pntr)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		pntr[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (pntr);
}
