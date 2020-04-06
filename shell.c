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
char *argv[] = {"/bin/ls","/usr/", NULL};
pid_t child_pid = 0;
int status;
ssize_t bytes_read;
size_t nbytes;
char *str;
struct stat st;

printf("#cisfun$ ");
nbytes = 0;
str = NULL;
bytes_read = getline(&str, &nbytes, stdin);
argv[0] = strtok(str, "\n");
argv[1] = NULL;
str = argv[0];
stat(str, &st);
child_pid = fork();

 while (bytes_read != -1)
   {
     if (child_pid == -1)
       {
	 printf("Failed");
       } 
     else if (child_pid == 0)
       {
	 execve(argv[0], argv, envp);
       }
     else { /*child_pid != 0*/
       wait(&status);
     }
   }
 return (0);
}
