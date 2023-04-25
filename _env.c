#include "main.h"

int _env(char **env, int args)
{
	int i = 0;

	while (env[i])
	{
		// check if '=' is present
		if (strchr(env[i], '='))
		{
			// print the env variable
			write(STDOUT_FILENO, env[i], _strlen(env[i]));
			write(STDOUT_FILENO, "\n", 1);
		}
	}

	return (EXIT_SUCCESS);
}
