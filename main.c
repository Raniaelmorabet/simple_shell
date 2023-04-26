#include "main.h"

/**
 * execute - executes a command
 * @tokens: tokens to execute
 * @env: environment variables
 * @bin: name of program
 * Return: None
 */
void execute(char **tokens, char **env, char *bin)
{
	pid_t pid;
	int status;

	/* fork a child process */
	pid = fork();
	if (pid == 0)
	{
		/* child process */
		if (execve(tokens[0], tokens, env) == -1)
			perror(bin); /* todo: change this to av[0] */
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		/* error forking */
		perror(bin);
	}
	else
	{
		/* parent process */
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
}

/**
 * readline - reads a line from stdin
 * @prompt: prompt to display
 * Return: line read
 */
char *readline(char *prompt)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	/* display prompt */
	write(STDOUT_FILENO, prompt, _strlen(prompt));

	/* read input using getline */
	read = getline(&line, &len, stdin);
	if (read == -1)
		return (NULL);

	/* check if input is empty */
	if (line[0] == '\n')
		return (line);

	/* remove new line from input */
	line[_strlen(line) - 1] = '\0';

	return (line);
}

/**
 * main - entry point
 * @av: number of arguments
 * @ac: arguments
 * @env: environment variables
 *
 * Return: 0 on success
 */
int main(__attribute__((unused))int ac, char **av, char **env)
{
	char **tokens = NULL;
	char *line = NULL;
	int i;

	while (1337)
	{
		/* read input */
		line = readline("$ ");
		if (!line)
			break;
		if (line[0] == '\n')
			continue;

		/* parse input into tokens */
		tokens = strtow(line, ' ');
		if (!tokens)
			continue;

		/* if not, check if it's a path to an executable */
		if (access(tokens[0], F_OK) != -1)
			execute(tokens, env, av[0]); /* if it is, execute it */
		else
		{
			/* if not, print error */
			error(av[0], ": ", 127);
			error(tokens[0], ": command not found\n", 127);
		}

		/* free all resources */
		for (i = 0; tokens[i]; i++)
			free(tokens[i]);
		free(tokens);
	}

	write(STDOUT_FILENO, "exit\n", 5); /* ctrl + d was pressed */
	free(line); /* free resources */
	return (0);
}
