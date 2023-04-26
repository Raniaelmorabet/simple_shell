#include "main.h"

/**
 * h_exit - exits the shell
 * @status: status to exit with
 */
void h_exit(int status)
{
	write(STDOUT_FILENO, "exit\n", 5);
	exit(status);
}
