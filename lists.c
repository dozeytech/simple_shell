#include "shell.h"

/**
 * add_node - adds a node to the start of the list
 * @head: address of pointer to head node
 * @str: str field of node
 * @num: node index used by history
 *
 * Return: size of list
 */
list_t *add_node(list_t **head, const char *str, int num)
{
	list_t *current_head;

	if (!head)
		return (NULL);
	current_head = malloc(sizeof(list_t));
	if (!current_head)
		return (NULL);
	_memset((void *)current_head, 0, sizeof(list_t));
	current_head->num = num;
	if (str)
	{
		current_head->str = _strdup(str);
		if (!current_head->str)
		{
			free(current_head);
			return (NULL);
		}
	}
	current_head->next = *head;
	*head = current_head;
	return (current_head);
}

/**
 * add_node_end - adds a node to the end of the list
 * @head: address of pointer
 * @str: str field of node
 * @num: node index used by history
 *
 * Return: size of list
 */
list_t *add_node_end(list_t **head, const char *str, int num)
{
	list_t *current_node, *node;

	if (!head)
		return (NULL);

	node = *head;
	current_node = malloc(sizeof(list_t));
	if (!current_node)
		return (NULL);
	_memset((void *)current_node, 0, sizeof(list_t));
	current_node->num = num;
	if (str)
	{
		current_node->str = _strdup(str);
		if (!current_node->str)
		{
			free(current_node);
			return (NULL);
		}
	}
	if (node)
	{
		while (node->next)
			node = node->next;
		node->next = current_node;
	}
	else
		*head = current_node;
	return (current_node);
}

/**
 * print_list_str - prints the str element of a list_t linked list
 * @h: pointer to the node
 * Return: size of list
 */
size_t print_list_str(const list_t *h)
{
	size_t k = 0;

	while (h)
	{
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		k++;
	}
	return (k);
}

/**
 * delete_node_at_index - deletes node at given index
 * @head: address of the pointer
 * @index: index of node
 * Return: 1 on success, 0 on failure
 */
int delete_node_at_index(list_t **head, unsigned int index)
{
	list_t *node, *prev_node;
	unsigned int j = 0;

	if (!head || !*head)
		return (0);

	if (!index)
	{
		node = *head;
		*head = (*head)->next;
		free(node->str);
		free(node);
		return (1);
	}
	node = *head;
	while (node)
	{
		if (j == index)
		{
			prev_node->next = node->next;
			free(node->str);
			free(node);
			return (1);
		}
		j++;
		prev_node = node;
		node = node->next;
	}
	return (0);
}

/**
 * free_list - frees all nodes
 * @head_ptr: address of pointer
 * Return: void
 */
void free_list(list_t **head_ptr)
{
	list_t *node, *next_node, *head;

	if (!head_ptr || !*head_ptr)
		return;
	head = *head_ptr;
	node = head;
	while (node)
	{
		next_node = node->next;
		free(node->str);
		free(node);
		node = next_node;
	}
	*head_ptr = NULL;
}
