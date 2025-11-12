#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/* Structure for shell info */
typedef struct shell
{
	int last_status;
	char **env;
} t_shell;

/* Builtin functions */
int builtin_exit(char **args);
int builtin_cd(char **args);
int builtin_env(char **args);
int builtin_setenv(char **args);
int builtin_unsetenv(char **args);

/* Executor helpers */
int execute_builtin(char **args);
int exec_cmd(char **args, t_shell *info);

#endif /* SHELL_H */
