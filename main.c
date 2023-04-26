#include "main.h"

int main (int av, char **ac, char **env)
{
	char **tokens = NULL;
	char *line = NULL;
	size_t len = 0, read;

	while (1337)
	{
		/* display prompt */
		write(STDOUT_FILENO, "$ ", 2);

		/* read input using getline */
		read = getline(&line, &len, stdin);
		if (read == -1)
			break;

		/* check if input is empty */
		if (line[0] == '\n')
			continue;

		/* remove new line from input */
		line[_strlen(line) - 1] = '\0';

		/* parse input into tokens */
		tokens = strtow(line, ' ');
		if (!tokens)
			continue;

		/* check if first token is a built-in */

		/* if not, check if it's a path to an executable */
		if (access(tokens[0], F_OK) != -1)
		{
			/* if it is, execute it */
			int pid = fork();
			if (pid == 0)
				execve(tokens[0], tokens, env);
			else
				wait(NULL);

		}
		else
		{
			/* if not, print error */
			error("hsh: ", tokens[0], 127);
			error(": command not found\n", "", 127);
		}

		/* free all resources */
		for (int i = 0; tokens[i]; i++)
			free(tokens[i]);
		free(tokens);

	}

	/* ctrl + d was pressed */
	write(STDOUT_FILENO, "exit\n", 5);

	/* free resources */
	free(line);

	return (0);
}
