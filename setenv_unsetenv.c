#include "Alxhell.h"

/**
 * setenv_command - Handle the "setenv" command
 * @args: Array of command arguments
 *
 * Usage: setenv VARIABLE VALUE
 * Initializes a new environment variable or modifies an existing one.
 */

void setenv_command(char *args[])
{
if (args[1] == NULL || args[2] == NULL)
{
fprintf(stderr, "setenv: Incorrect number of arguments\n");
}
else
{
if (setenv(args[1], args[2], 1) != 0)
{
fprintf(stderr, "setenv: Failed to set environment variable\n");
}
}
}

/**
 * unsetenv_command - Handle the "unsetenv" command
 * @args: Array of command arguments
 *
 * Usage: unsetenv VARIABLE
 * Removes an environment variable.
 */

void unsetenv_command(char *args[])
{
if (args[1] == NULL)
{
fprintf(stderr, "unsetenv: Missing variable name\n");
}
else
{
if (unsetenv(args[1]) != 0)
{
fprintf(stderr, "unsetenv: Failed to unset environment variable\n");
}
}
}
