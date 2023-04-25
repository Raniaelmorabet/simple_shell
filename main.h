#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

typedef struct s_cmd_elem
{
	char *path;
	char **args;

	struct s_cmd_elem *next;
	struct s_cmd_elem *prev;
} cmd_elem_t;

typedef struct s_cmd
{
	cmd_elem_t *head;
	cmd_elem_t *tail;
	int	size;
} cmd_t;

typedef struct s_env_elem
{
	char *name;
	char *value;

	struct s_env *next;
	struct s_env *prev;
} env_elem_t;

typedef struct s_env
{
	env_elem_t *head;
	env_elem_t *tail;
	int	size;
} env_t;


typedef struct builtin
{
	char *name;
	int (*func)(char **, int);
} builtin_t;

int _env(char **env, int args);
void h_exit(int);
int _cd(char **env, int args);

size_t	_strlen(const char *s);

void *_realloc(void *ptr, size_t size);
char **strtow(char *str, char delim);

int error(char *msg, char *arg, int status);

#endif /* MAIN_H */
