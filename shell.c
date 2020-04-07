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
int main(void)
{
	ssize_t bytes_read;
	size_t nbytes;
	char *path;
	/**int file;*/
	char *args[20];
	char *parameter;
	pid_t child_pid = 0;
	int status;
	char *envp[] =
	{
		"HOME=/",
		"PATH=/bin:/usr/bin",
		"TZ=UTC0",
		"USER=beelzebub",
		"LOGNAME=tarzan",
        0
	};
	
	/**char * const *argv; */

	printf("#CisFun$");
	nbytes = 0;
	bytes_read = getline(&path, &nbytes, stdin);
	path = strtok(path, "\r\n\t ");
	parameter = strtok(NULL, "\r\n\t ");
	/**file = exist(str);*/
	
	args[0] = path;
	args[1] = parameter;
	args[2] = NULL;

	while (bytes_read != -1)
	{
		if (1) /**Encontró el archivo*/
		{
			child_pid = fork();
			if (child_pid == -1)
				printf("failed");
			else if (child_pid == 0)
				execve(args[0], args, envp);
			else
				wait(&status);
		}
		else
		{
			printf("Command not found433\n");
		}
		printf("#CisFun$");
		/**for () */
		bytes_read = getline(&path, &nbytes, stdin);
		path = strtok(path, "\n");
	}
	return (0);
}


/**
child_pid
child_pid = fork();
 while (bytes_read != -1)
   {
     if (child_pid == -1)
       {
        printf("Failed");
       } 
     else if (child_pid == 0)
       {
        execve(argv[0], argv, NULL);
       }
     else { *child_pid != 0*
       wait(&status);
     }
   }
 return (0);
}
*/
