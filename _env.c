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
		printf("%s\n", env[i++]);

	return (EXIT_SUCCESS);
}
