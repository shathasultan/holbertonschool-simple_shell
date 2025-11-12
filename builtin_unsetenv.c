#include "shell.h"

/**
 * builtin_unsetenv - Remove an environment variable
 * @args: Arguments (args[1] = variable)
 * Return: 0 on success, 1 on failure
 */
int builtin_unsetenv(char **args)
{
    if (!args[1])
    {
        fprintf(stderr, "Usage: unsetenv VARIABLE\n");
        return (1);
    }

    if (unsetenv(args[1]) != 0)
    {
        perror("unsetenv");
        return (1);
    }

    return (0);
}
