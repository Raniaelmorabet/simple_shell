#include "main.h"
#include "env.h"

int _env(cmd_t *cmd, env_t *env)
{
	if (cmd->args[1] != NULL)
	{
		error("env: ", cmd->args[1], 1);
		error(": No such file or directory\n", "", 1);
		return (1);
	}

	env_print(env);
	return (0);
}

int _setenv(cmd_t *cmd, env_t *env)
{
	char *name = NULL, *value = NULL;

	if (cmd->args[1] == NULL)
		return (1);

	char **env_var = strtow(cmd->args[1], '=');
	name = _strdup(env_var[0]);
	value = _strdup(env_var[1]);

	if (name == NULL || value == NULL)
	{
		// todo: free name or value
		return (1);
	}

	return(env_append(env, name, value));
}

int _unsetenv(cmd_t *cmd, env_t *env)
{
	if (cmd->args[1] == NULL)
		return (1);

	return (env_unset(env, cmd->args[1]));
}