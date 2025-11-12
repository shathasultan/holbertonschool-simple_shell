#include "shell.h"

/**
 * builtin_setenv - Initialize or modify an environment variable
 * @args: Arguments (args[1] = variable, args[2] = value)
 * Return: 0 on success, 1 on failure
 */
int builtin_setenv(char **args)
{
    if (!args[1] || !args[2])
    {
        fprintf(stderr, "Usage: setenv VARIABLE VALUE\n");
        return (1);
    }

    if (setenv(args[1], args[2], 1) != 0)
    {
        perror("setenv");
        return (1);
    }

    return (0);
}
