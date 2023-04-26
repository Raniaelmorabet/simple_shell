#include "main.h"

/**
 * h_env - prints the environment
 * @env: environment variables
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int h_env(char **env)
{
	int i = 0;

	while (env[i])
	{
		/* check if '=' is present */
		if (_strchr(env[i], '='))
		{
			/* print the env variable */
			write(STDOUT_FILENO, env[i], _strlen(env[i]));
			write(STDOUT_FILENO, "\n", 1);
		}
		i++;
	}

	return (EXIT_SUCCESS);
}
