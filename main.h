#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * struct s_cmd_elem - linked list element for commands
 * @path: path to command
 * @args: arguments to command
 * @next: pointer to next element
 * @prev: pointer to previous element
 */
typedef struct s_cmd_elem
{
	char *path;
	char **args;

	struct s_cmd_elem *next;
	struct s_cmd_elem *prev;
} cmd_elem_t;

/**
 * struct s_cmd - linked list for commands
 * @head: pointer to head of list
 * @tail: pointer to tail of list
 * @size: number of elements in list
 */
typedef struct s_cmd
{
	cmd_elem_t *head;
	cmd_elem_t *tail;
	int	size;
} cmd_t;

/**
 * struct s_env_elem - linked list element for environment variables
 * @name: name of environment variable
 * @value: value of environment variable
 * @next: pointer to next element
 * @prev: pointer to previous element
 */
typedef struct s_env_elem
{
	char *name;
	char *value;

	struct s_env *next;
	struct s_env *prev;
} env_elem_t;

/**
 * struct s_env - linked list for environment variables
 * @head: pointer to head of list
 * @tail: pointer to tail of list
 * @size: number of elements in list
 */
typedef struct s_env
{
	env_elem_t *head;
	env_elem_t *tail;
	int	size;
} env_t;

/**
 * struct builtin - builtin command
 * @name: name of builtin
 * @func: function to execute builtin
 */
typedef struct builtin
{
	char *name;
	int (*func)(char **, int);
} builtin_t;

int _env(char **env, int args);
void h_exit(int);
int _setenv(char **env, int args);
int _unsetenv(char **env, int args);
/*int _cd(char **env, int args);*/

void *_realloc(void *ptr, size_t size);
char **_strtok(char *str, char *delim);
char **strtow(char *str, char delim);
int _strlen(char *s);
char *_strdup(char *str);

int error(char *msg, char *arg, int status);

#endif /* MAIN_H */
