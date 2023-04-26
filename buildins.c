#include "main.h"

/**
 * is_buildin - checks if a command is a buildin
 * @cmd: command to check
 * Return: 1 if buildin, 0 otherwise
 */
int is_buildin(char *cmd)
{
	int i;
	char *buildins[] = {"exit", "env", NULL};

	for (i = 0; buildins[i]; i++)
	{
		if (_strcmp(cmd, buildins[i]) == 0)
			return (1);
	}
	return (0);
}

/**
 * execute_buildin - executes a buildin
 * @line: line read
 * @tokens: tokens to execute
 * @env: environment variables
 * @bin: name of program
 * @line_nbr: line number
 * Return: None
 */
void execute_buildin(char *line, char **tokens, char **env,
					 char *bin, int line_nbr)
{
	char *status = NULL;

	if (_strcmp(tokens[0], "exit") == 0)
	{
		status = _strdup(tokens[1]);
		if (h_exit(bin, status, line_nbr) != 0)
		{
			free_resources(&line, &tokens);
			return;
		}
	}
	else if (_strcmp(tokens[0], "env") == 0)
		h_env(env);
	free_resources(&line, &tokens);
}
