#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct list_s
{
	char *str;
	unsigned int len;
	struct list_s *next;
} list_t;

list_t *add_node_end(list_t **head, const char *str);
size_t print_list(const list_t *h);
char *_getenv(const char *name);
int exist(char *filename);
