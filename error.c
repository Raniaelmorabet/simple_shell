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


/**
 * cmd_error - prints an error message for a command
 * @bin: name of program
 * @cmd: command
 * @msg: error message
 * @line: line number
 */
void cmd_error(char *bin, char *cmd, char *msg, int line)
{
	char *line_str = NULL;

	line_str = _itoa(line, "0123456789");
	write(STDERR_FILENO, bin, _strlen(bin));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, line_str, _strlen(line_str));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, _strlen(cmd));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, msg, _strlen(msg));
	write(STDERR_FILENO, "\n", 1);
	free(line_str);
}
