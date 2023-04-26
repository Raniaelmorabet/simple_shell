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
			perror(bin);
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
		perror(bin);
	else
	{
		/* parent process */
		wait(&status);
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

	prompt = isatty(STDIN_FILENO) ? prompt : "";

	/* display prompt */
	write(STDOUT_FILENO, prompt, _strlen(prompt));

	/* read input using getline */
	read = getline(&line, &len, stdin);
	if (read == -1)
	{
		free(line);
		return (NULL);
	}

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
	int line_count = 0;

	while (1337)
	{
		/* read input */
		line = readline("$ ");
		line_count++;
		if (!line)
			break;
		if (line[0] == '\n')
		{
			free(line);
			line = NULL;
			continue;
		}
		/* parse input into tokens */
		tokens = strtow(line, ' ');
		if (!tokens)
		{
			free(line);
			line = NULL;
			continue;
		}
		if (_strcmp(tokens[0], "exit") == 0)
		{
			free_resources(&line, &tokens);
			exit(0);
		}
		else if (_strcmp(tokens[0], "env") == 0)
			h_env(env);
		else if (access(tokens[0], F_OK) != -1)
			execute(tokens, env, av[0]); /* if it is, execute it */
		else
			cmd_error(av[0], tokens[0], "not found", line_count);
		free_resources(&line, &tokens);
	}
	return (0);
}
