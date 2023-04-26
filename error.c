#include "main.h"

/**
 * error - prints an error message
 * @msg: error message
 * @arg: argument to print
 * @status: status to return
 *
 * Return: status
 */
int error(char *msg, char *arg, int status)
{
	write(STDERR_FILENO, msg, _strlen(msg));
	write(STDERR_FILENO, arg, _strlen(arg));
	return (status);
}
