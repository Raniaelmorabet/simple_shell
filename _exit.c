#include "main.h"

void h_exit(int status)
{
	// TODO: free all resources
	write(STDOUT_FILENO, "exit\n", 5);
	exit(status);
}
