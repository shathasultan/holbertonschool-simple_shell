#include "shell.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * builtin_setenv - Builtin version of setenv
 * @args: command arguments
 * Return: 0 on success, 1 on failure
 */
int builtin_setenv(char **args)
{
	if (!args[1] || !args[2])
	{
		fprintf(stderr, "setenv: Usage: setenv VARIABLE VALUE\n");
		return (1);
	}

	if (setenv(args[1], args[2], 1) != 0)
	{
		perror("setenv");
		return (1);
	}

	return (0);
}

/**
 * builtin_unsetenv - Builtin version of unsetenv
 * @args: command arguments
 * Return: 0 on success, 1 on failure
 */
int builtin_unsetenv(char **args)
{
	if (!args[1])
	{
		fprintf(stderr, "unsetenv: Usage: unsetenv VARIABLE\n");
		return (1);
	}

	if (unsetenv(args[1]) != 0)
	{
		perror("unsetenv");
		return (1);
	}

	return (0);
}

/**
 * _setenv - Create or modify an environment variable
 * @name: variable name
 * @value: variable value
 * @overwrite: if 1, overwrite existing variable
 * Return: 0 on success, -1 on failure
 */
int _setenv(const char *name, const char *value, int overwrite)
{
	if (!name || !value)
		return (-1);
	if (strchr(name, '=') != NULL)
		return (-1);

	if (getenv(name) && !overwrite)
		return (0);

	if (setenv(name, value, overwrite) != 0)
		return (-1);

	return (0);
}

/**
 * _unsetenv - Remove an environment variable
 * @name: variable name
 * Return: 0 on success, -1 on failure
 */
int _unsetenv(const char *name)
{
	if (!name)
		return (-1);

	if (unsetenv(name) != 0)
		return (-1);

	return (0);
}
