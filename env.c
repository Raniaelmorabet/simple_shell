#include "env.h"
#include "main.h"
#include <stdio.h>

int env_len(char **env)
{
	int len = 0;

	while (env[len])
		len++;

	return (len);
}

/**
 * env_init - initialize environment variables
 * @env: environment variables
 * Return: pointer to env_t
 */
env_t *env_init(char **env)
{
	env_elem_t *new = NULL;
	char **tmp = NULL;

	env_t *env_vars = malloc(sizeof(env_t) * env_len(env));
	if (!env_vars)
		return (NULL);

	env_vars->size = 0;

	for (int i = 0; env[i]; i++)
	{
//		env_append(env_vars, strtow(env[i], '=')[0],
//				   strtow(NULL, '=')[1]);
		new = malloc(sizeof(env_elem_t));
		if (!new)
			return (NULL);

		tmp = strtow(env[i], '='); // tmp[0] = name, tmp[1] = value

		new->name = _strdup(tmp[0]);
		new->value = _strdup(tmp[1]);
		new->next = NULL;
		new->prev = NULL;


		if (!env_vars->head)
		{
			env_vars->head = new;
			env_vars->tail = new;
		}
		else
		{
			new->prev = env_vars->tail;
			env_vars->tail->next = new;
			env_vars->tail = new;
		}
		env_vars->size++;

		// free tmp
		free(tmp[0]);
		free(tmp[1]);
		free(tmp);
	}
	return (env_vars);
}

/**
 * env_destroy - free environment variables
 * @env: environment variables
 */
void env_destroy(env_t *env)
{
	env_elem_t *tmp = NULL;

	while (env->head)
	{
		tmp = env->head;
		env->head = env->head->next;
		free(tmp->name);
		free(tmp->value);
		free(tmp);
	}
	free(env);
}

/**
 * env_print - print environment variables
 * @env: environment variables
 */
void env_print(env_t *env)
{
	env_elem_t *tmp = env->head;

	while (tmp)
	{
		printf("%s=%s\n", tmp->name, tmp->value);
		tmp = tmp->next;
	}
}

/**
 * env_get - get environment variable
 * @env: environment variables
 * @name: name of variable
 * Return: value of variable
 */
char *env_get(env_t *env, char *name)
{
	env_elem_t *tmp = env->head;

	while (tmp)
	{
		if (strcmp(tmp->name, name) == 0)
			return (tmp->value);
		tmp = tmp->next;
	}
	return (NULL);
}

/**
 * env_set - set environment variable
 * @env: environment variables
 * @name: name of variable
 * @value: value of variable
 * Return: 0 on success, -1 on failure
 */
int env_set(env_t *env, char *name, char *value)
{
	env_elem_t *tmp = env->head;

	while (tmp)
	{
		if (strcmp(tmp->name, name) == 0)
		{
			free(tmp->value);
			tmp->value = _strdup(value);
			return (0);
		}
		tmp = tmp->next;
	}
	return (-1);
}

/**
 * env_unset - unset environment variable
 * @env: environment variables
 * @name: name of variable
 * Return: 0 on success, -1 on failure
 */
int env_unset(env_t *env, char *name)
{
	env_elem_t *tmp = env->head;

	while (tmp)
	{
		if (strcmp(tmp->name, name) == 0)
		{
			if (tmp->prev)
				tmp->prev->next = tmp->next;
			else
				env->head = tmp->next;
			if (tmp->next)
				tmp->next->prev = tmp->prev;
			else
				env->tail = tmp->prev;
			free(tmp->name);
			free(tmp->value);
			free(tmp);
			env->size--;
			return (0);
		}
		tmp = tmp->next;
	}
	return (-1);
}

/**
 * env_append - append environment variable
 * @env: environment variables
 * @name: name of variable
 * @value: value of variable
 * Return: 0 on success, -1 on failure
 */
int env_append(env_t *env, char *name, char *value)
{
	env_elem_t *new = NULL;

	new = malloc(sizeof(env_elem_t));
	if (!new)
		return (-1);

	new->name = _strdup(name);
	new->value = _strdup(value);
	new->next = NULL;
	new->prev = NULL;

	if (!env->head)
	{
		env->head = new;
		env->tail = new;
	}
	else
	{
		new->prev = env->tail;
		env->tail->next = new;
		env->tail = new;
	}
	env->size++;
	return (0);
}
