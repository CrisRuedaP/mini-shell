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
int fill_args(char *path, char **args);	
int print_numbers(int n);
int _strlen(const char *s);
void print_not_found(char *cmd, int count);
size_t print_list(const list_t *h);
char *_getenv(const char *name);
int _printp(const char *buffer, unsigned int size);
int _printf(const char * const format, ...);
int _putchar(char c);
int exist(char *filename);
