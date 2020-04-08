#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

int exist(char *filename)
{
	int exist;
	struct stat buf;

	exist = (stat(filename, &buf));
	if (exist == 0)
	{
		return (0);
	}
	else
		return (-1);
}
