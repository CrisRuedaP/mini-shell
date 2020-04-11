#include "header.h"
#include <unistd.h>

void print_not_found(char *cmd, int count)
{
	char *name = "hsh";

  write(2, name, 3);
  write(2, ": ", 2);
  print_numbers(count);
  write(2, ": ", 2);
  write(2, cmd, _strlen(cmd));
  write(2, ": not found\n", 12);
}


