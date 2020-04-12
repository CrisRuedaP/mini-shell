#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include "header.h"
#include <limits.h>
extern char **environ;

int main(void)
{
	ssize_t bytes_read = 0; /** Bytes leídos de un getline*/
	size_t nbytes = 0; /**Tamaño del buffer*/
	char *path = NULL; /**El path ingresado por el usuario*/
	char *args[20]; /**String de argumentos que ingresa el usr*/
	int count = 0;
	pid_t child_pid = 0;/**Child process id*/
	int status = 0;/**indica el status del child process*/
	int file = 0;/**Valor de retorno de exist, 0 si existe, != 0 si no existe*/
	_printp("#Cisfun$ ", 9);/**prompt mini-shell*/
	bytes_read = getline(&path, &nbytes, stdin); /**Almacena el input en "stdin" en un buffer "path" de "nbytes", retorna el # de bytes leídos, o -1 (Ctrl+D))*/
	while (bytes_read != -1)
	{
		
		if (*path == '\n')
			free(path);
		else if (*path != '\n')
		{
			fill_args(path, args);
		
			file = exist(args[0]);/**Exist evalua que el path ingresado exista*/

			if (file == 0) /**Encontró el archivo*/
			{
				child_pid = fork();/**Crea un proceso hijo*/
				if (child_pid == -1)/**Falló al crear*/
					_printp("failed\n", 7);
				else if (child_pid == 0)/**Es el hijo...*/
				{
					/**exe = */ execve(args[0], args, environ);/**Ejecuta el comando que se ingresó*/
					/**if (exe == -1)
					{
						perror("execve");
						exit();
					}*/
					exit(0);/**Terminar el child process con exito*/
				}
				else /**Es el padre*/
					wait(&status);/**Detiene la ejecución del padre hasta que el child termine*/
			}
			else if (file != 0)/**No encontró el archivo*/
			{
				print_not_found(path, count);
				/**printf("not found");*/

			}
			free(*args);
		}
		path = NULL; /**Reinicializa el puntero, para que getline tenga el puntero libre en cada llamado */
		count++;
		_printp("#Cisfun$ ", 9);/**prompt mini-shell*/
		bytes_read = getline(&path, &nbytes, stdin);
	}
	_putchar('\n');
	free(path); /**Libera el ultimo getline para el EOF*/
	return (0);
}
