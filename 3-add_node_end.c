#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 *add_node_end - Adds node to the begining of a list
 *@str: String
 *@head: double pointer
 *Return: Pointer to node
 *
 */
list_t *add_node_end(list_t **head, const char *str)
{
	unsigned int len = 0;
	list_t *node;
	list_t *tmp;

	if (str == NULL)
		return (NULL);
	while (str[len] != '\0')
	{
		len++;
	}
	node = malloc(sizeof(list_t));
	if (node == NULL)
		return (NULL);
	if (*head == NULL)
	{
		node->str = strdup(str);
		node->len = len;
		node->next = NULL;
		*head = node;
		return (node);
	}
	node->str = strdup(str);
	node->len = len;
	tmp = *head;

	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}

	tmp->next = node;
	node->next = NULL;
	return (node);
}
