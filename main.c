#include "main.h"
#include "env.h"

/**
 * main - entry point
 * @ac: argument count
 * @av: argument vector
 * @env: environment variables
 * Return: SUCCESS
 */
int main (int ac, char **av, char **env)
{

	env_t *env_vars = env_init(env);
	env_print(env_vars);
	exit(0);

	char **tokens = NULL;
	char *line = NULL;
	size_t len = 0, read;
	char **PATHS = NULL;

	// search for PATH in env
	for (int i = 0; env[i]; i++)
	{
		if (strncmp(env[i], "PATH=", 5) == 0)
		{
			// parse PATH into tokens
			PATHS = strtow(env[i] + 5, ':');
			break;
		}
	}

	while (1337)
	{
		// display prompt
		write(STDOUT_FILENO, "$ ", 2);

		// read input using getline
		read = getline(&line, &len, stdin);
		if (read == -1)
			break;

		// check if input is empty
		if (line[0] == '\n')
			continue;

		// remove new line from input
		line[_strlen(line) - 1] = '\0';

		// parse input into tokens
		tokens = strtow(line, ' ');
		if (!tokens)
			continue;

		// check if first token is a built-in
		if (strcmp(tokens[0], "exit") == 0)
			h_exit(0);

		// if not, check if it's a path to an executable
		int is_cmd = 0;
		char cmd[1024];

		for (int i = 0; PATHS[i]; i++)
		{
			strcpy(cmd, PATHS[i]);
			strcat(cmd, "/");
			strcat(cmd, tokens[0]);
			if (access(cmd, F_OK) != -1)
			{
				is_cmd = 1;
				break;
			}
			memset(cmd, 0, 1024);
		}

//		if (access(tokens[0], F_OK) != -1)
		if (is_cmd)
		{
			// if it is, execute it
			int pid = fork();
			if (pid == 0)
				execve(cmd, tokens, env);
			else
				wait(NULL);

		} else
		{
			// if not, print error
			error("hsh: ", tokens[0], 127);
			error(": command not found\n", "", 127);
		}

		// free all resources
		for (int i = 0; tokens[i]; i++)
			free(tokens[i]);
		free(tokens);

	}

	// ctrl + d was pressed
	write(STDOUT_FILENO, "exit\n", 5);

	// free resources
	free(line);

	return (0);
}
