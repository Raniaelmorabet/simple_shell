#include "main.h"

int error(char *msg, char *arg, int status)
{
	write(STDERR_FILENO, msg, _strlen(msg));
	write(STDERR_FILENO, arg, _strlen(arg));
	return (status);
}
