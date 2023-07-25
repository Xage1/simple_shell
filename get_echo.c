#include "Alxhell.h"

/**
 * _echo - function echo
 *
 * @av: list of arguments
 *
 * Return: 0
 */

int _echo(char **av)
{
int i = 1;
char *var_value;

if (av[1] == NULL)
{
_printf("\n");
return (0);
}

while (av[i])
{
if (av[i][0] == '$')
{

char *var_name = av[i] + 1;
var_value = getenv(var_name);

if (var_value)
_printf("%s", var_value);
}
else
{
_printf("%s", av[i]);
}

if (av[i + 1] != NULL)
_printf(" ");
else
_printf("\n");

i++;
}

return (0);
}
