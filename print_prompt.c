#include <unistd.h>
#include <stdio.h>
#include "header.h"
int _printp(const char *buffer, unsigned int size)
{
	int wrote;

	wrote = write(STDOUT_FILENO, buffer, size);

	if (wrote == -1)
		return (-1);
	return (0);
}
