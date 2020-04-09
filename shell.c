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
	/**int file;*/
	char *args[20]; /**string de argumentos que ingresa el usr*/
	int ac = 0;
	int i = 0;
	ciar *parameter;/**parametros del comando (opciones especiales)*/
	pid_t child_pid = 0;/**Child process id*/
	int status;/**indica el status del child process*/
	int file = 0;/**Valor de retorno de exist, 0 si existe, != 0 si no existe*/
	printf("#CisFun$ ");/**prompt mini-shell*/
	bytes_read = getline(&path, &nbytes, stdin); /**Almacena el input en "stdin" en un buffer "path" de "nbytes", retorna el # de bytes leídos, o -1 (Ctrl+D))*/
	while (bytes_read != -1)
	{
		path = strtok(path, "\r\n\t ");/**Parte el input en tokens con base en unos delimitadores("\r\n\t ") para evaluar uno por uno*/
		parameter = strtok(NULL, "\r\n\t "); /**salta al siguiente token (parametro)*/
		file = exist(path);/**Exist evalua que el path ingresado exista*/

		args[0] = path;
		args[1] = parameter;
		args[2] = NULL;	/**arreglo de argumentos a pasar a execve*/
		ac = 3;
		if (file == 0) /**Encontró el archivo*/
		{
				child_pid = fork();/**Crea un proceso hijo*/
				if (child_pid == -1)/**Falló al crear*/
					printf("failed");
				else if (child_pid == 0)/**Es el hijo...*/
				{
					/**exe = */ execve(args[0], args, environ);/**Ejecuta el comando que se ingresó*/
					/**if (exe == -1)
					{
						perror("execve");
						exit();
					}*/
					/**free(path);*/
					exit(0);/**Terminar el child process con exito*/
				}
				else /**Es el padre*/
					wait(&status);/**Detiene la ejecución del padre hasta que el child termine*/
		}
		else /**No encontró el archivo*/
		{
			printf("Command not found433\n");
		}
		while (i < ac)
		{
			free(args[i]);
			args[i] = NULL;
			i++;
		}
	printf("#Cisfun$ ");
	bytes_read = getline(&path, &nbytes, stdin);
	}
	return (0);
}
