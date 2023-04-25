#ifndef ENV_H
#define ENV_H

#include <stdio.h>
#include <stdlib.h>

typedef struct s_env_elem
{
	char *name;
	char *value;

	struct s_env_elem *next;
	struct s_env_elem *prev;
} env_elem_t;

typedef struct s_env
{
	env_elem_t *head;
	env_elem_t *tail;
	int	size;
} env_t;

env_t *env_init(char **env);
void env_destroy(env_t *env);
void env_print(env_t *env);
char *env_get(env_t *env, char *name);
int env_set(env_t *env, char *name, char *value);
int env_unset(env_t *env, char *name);
int env_append(env_t *env, char *name, char *value);

#endif /* ENV_H */
