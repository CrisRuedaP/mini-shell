#include "header.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char * path = NULL, *directory = NULL; /**path--> aloja el PATH, directory--> aloja los directorios (token by token)*/
	const char *delim = ":"; /**Delimitador para partir tokens*/
	path = _getenv("PATH"); /**trae en contenido de la variable "PATH"*/

	list_t *head; /**Lista de strings con los directorios*/

	directory = strtok(path, delim); /**parte el path en directorios usando delim*/
	while (directory) /**Mientras que hayan directorios (tokens)*/
	{
		add_node_end(&head, directory); /**Añade el siguiente directorio al final de la lista*/
		directory = strtok(NULL, delim); /**Salta al siguiente directorio (token)*/
	}
	print_list(head); /**Imprime la lista para comprobar*/
	return (0);
}
