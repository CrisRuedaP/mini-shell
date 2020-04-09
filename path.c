#include "header.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char * path = NULL, *directory = NULL;
	const char *delim = ":";
	path = _getenv("PATH");
	int i = 0;

	directory = strtok(path, delim);

	while (directory)
	{
		printf("%s\n", directory);
		directory = strtok(NULL, delim);
	}
	return (0);
}
