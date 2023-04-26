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
 * @tokens: tokens to execute
 * @env: environment variables
 * @bin: name of program
 * @line_nbr: line number
 * Return: None
 */
void execute_buildin(char **tokens, char **env, char *bin, int line_nbr)
{
	(void)bin;
	(void)line_nbr;

	if (_strcmp(tokens[0], "exit") == 0)
		exit(0);
	else if (_strcmp(tokens[0], "env") == 0)
		h_env(env);
}
