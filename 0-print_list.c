#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <stddef.h>
/**
 *print_list - Print a linked list values
 *@h: Pointer to list_t struct
 *Return: Size_t
 *
 *
 */
size_t print_list(const list_t *h)
{
	const list_t *temporary = h;
	int i = 0;

	while (temporary !=  NULL)
	{
		if (temporary->str == NULL)
		{
			printf("[0] (nil)\n");
			temporary = temporary->next;
			i++;
		}
		else
		{
		printf("[%d] %s\n", temporary->len, temporary->str);
		temporary = temporary->next;
		i++;
		}
	}

	return (i);
}
