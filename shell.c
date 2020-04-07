#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/sysmacros.h>
#include <time.h>


int main(void)
{
char *args[20];
pid_t child_pid = 0;
int status;
ssize_t bytes_read;
size_t nbytes;
char *path;
char *parameter;

printf("#cisfun$ ");
nbytes = 0;
bytes_read = getline(&path, &nbytes, stdin);
path = strtok(path, "/r/n/t ");
parameter = strtok(NULL, "\r\n\t ");

args[0] = path;
args[1] = parameter;
args[2] = NULL;

 while (bytes_read != -1)
   {
     if (1)
       {
	 child_pid = fork();
	 if (child_pid == -1)
	   printf("Failed");
	 else if (child_pid == 0)
	   execve(args[0], args, NULL);
	 else 
	   wait(&status);
       } 
     else
       {
	 printf("Command not found\n");
       }
     printf("#cisfun$ ");
     bytes_read = getline(&path, &nbytes, stdin);
     path = strtok(path, "\n");
   }
 return (0);
}
