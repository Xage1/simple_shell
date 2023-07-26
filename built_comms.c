#include "Alxhell.h"

/**
 * check_built_ins - Check for built in commands
 * @av: Argument to check
 * @buff: buffer
 * @count: count
 * Return: 0 success, 1 not found
 */

int check_built_ins(char **av, char *buff, int count)
{
if (av && *av && buff)
{
if (strcmp("env", av[0]) == 0 && strlen(av[0]) == 3)
{
printenv();
return (0);
}

else if (strcmp("exit", av[0]) == 0 && strlen(av[0]) == 4)
return (2);
else if (strcmp("cd", av[0]) == 0 && strlen(av[0]) == 2)
{
change_direct(av, count);
return (0);
}

else if (strcmp("help", av[0]) == 0 && strlen(av[0]) == 4)
{
_help(av);
return (0);
}
else if (strcmp("echo", av[0]) == 0 && strlen(av[0]) == 4)
{
_echo(av);
return (0);
}
else if (strcmp("setenv", av[0]) == 0 && strlen(av[0]) == 6)
{
if (av[1] == NULL || av[2] == NULL)
{
fprintf(stderr, "Usage: setenv VARIABLE VALUE\n");
return (1);
}
if (setenv(av[1], av[2], 1) == -1)
{
perror("Error in setenv");
return (1);
}
return (0);
}
else if (strcmp("unsetenv", av[0]) == 0 && strlen(av[0]) == 8)
{
if (av[1] == NULL)
{
fprintf(stderr, "Usage: unsetenv VARIABLE\n");
return (1);
}
if (unsetenv(av[1]) == -1)
{
perror("Error in unsetenv");
return (1);
}
return (0);
}
}
return (1);
}

/**
 * printenv - Print the environnment
 *
 * Return: Void
 */

void printenv(void)
{
int i = 0;

while (environ[i])
{

_printf("%s\n", environ[i]);
i++;
}
}
