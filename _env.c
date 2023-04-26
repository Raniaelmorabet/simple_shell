#include "main.h"

int _env(char **env, int args)
{
	int i = 0;

	if (args > 1)
	{
		printf("env: too many arguments\n");
		return (EXIT_FAILURE);
	}

	while (env[i])
	{
		/* check if '=' is present */
		if (strchr(env[i], '='))
		{
			/* print the env variable */
			write(STDOUT_FILENO, env[i], _strlen(env[i]));
			write(STDOUT_FILENO, "\n", 1);
		}
	}

	return (EXIT_SUCCESS);
}
