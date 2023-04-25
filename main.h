#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

typedef struct s_info info_t;
typedef struct s_cmd cmd_t;
typedef struct s_cmd_elem cmd_elem_t;
typedef struct s_env env_t;
typedef struct s_env_elem env_elem_t;

typedef struct s_info
{
	cmd_t *cmd;
	env_t *env;
	int status;
} info_t;

typedef struct s_cmd
{
	char *path;
	char **args;

	struct s_cmd *next;
	struct s_cmd *prev;
} cmd_t;

typedef struct s_cmd_list
{
	cmd_elem_t *head;
	cmd_elem_t *tail;
	int	size;
} cmd_list_t;

typedef struct builtin
{
	char *name;
	int (*func)(char **, int);
} builtin_t;

int _env(cmd_t *cmd, env_t *env);
void h_exit(int);
int _setenv(cmd_t *cmd, env_t *env);
int _unsetenv(cmd_t *cmd, env_t *env);
int _cd(char **env, int args);

void *_realloc(void *ptr, size_t size);
char **_strtok(char *str, char *delim);
char **strtow(char *str, char delim);
int _strlen(char *s);
char *_strdup(char *str);

int error(char *msg, char *arg, int status);

#endif /* MAIN_H */
