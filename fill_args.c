#include "header.h"

int fill_args(char *path, char **args)
{
	int i = 0;
	char *parameter, *tmp = path;

	path = strtok(path, "\n\t\r "); /**Almacena el primer token en path (Ruta al exe)*/
	args[i] = path; /**Almacena path en args*/
	while (tmp != NULL) /**Mientras que hayan tokens*/
	{
		++i;
		parameter = strtok(NULL, "\n\t\r "); /**Almacena el n argumento en parameter*/
		tmp = parameter;
		args[i] = parameter; /**almacena parameter i en args[i]*/
	}
	args[i] = NULL; /**Marca el fin array*/
	return (i); /**Retorna el length de args[]*/
}	
