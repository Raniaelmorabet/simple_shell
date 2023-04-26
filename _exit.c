#include "main.h"

void h_exit(int status)
{
	write(STDOUT_FILENO, "exit\n", 5);
	exit(status);
}
