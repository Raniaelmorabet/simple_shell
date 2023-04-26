#include "main.h"

/**
 * h_exit - exits the shell
 * @bin: name of program
 * @status: status to exit with
 * @line: line number
 * Return: -1 if status is not a number, 0 otherwise
 */
int h_exit(char *bin, char *status, int line)
{
	int status_int = 0, i;
	char *line_nbr = NULL;

	if (status == NULL)
		status_int = 0;
	else
	{
		for (i = 0; status[i]; i++)
		{
			if (status[i] < '0' || status[i] > '9')
			{
				status_int = -1;
				break;
			}
		}
		if (status_int != -1)
			status_int = _atoi(status);
	}

	if (status_int < 0)
	{

		line_nbr = _itoa(line, "0123456789");
		write(STDERR_FILENO, bin, _strlen(bin));
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, line_nbr, _strlen(line_nbr));
		write(STDERR_FILENO, ": exit: Illegal number: ", 24);
		write(STDERR_FILENO, status, _strlen(status));
		write(STDERR_FILENO, "\n", 1);
		if (status != NULL)
			free(status);
		free(line_nbr);
		return (-1);
	}

	if (status != NULL)
		free(status);
	exit(status_int);
}
