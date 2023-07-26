#include "Alxhell.h"

#define MAX_COMMAND_LENGTH 1024

/**
 * handle_variable_replacement - Function to handle variable replacement
 * @command: The input command string
 * @status: The exit status of the last command
 * @pid: The process ID of the current shell
 *
 * Return: The command string after variable replacement
 */

char *handle_variable_replacement(char *command, int status, int pid)
{
char *result = malloc(MAX_COMMAND_LENGTH);
char *p = command;
char *r = result;

while (*p != '\0')
{
if (*p == '$')
{
p++;
if (*p == '$')
{
r += sprintf(r, "%d", pid);
}

else if (*p == '?')
{
r += sprintf(r, "%d", status);
}

else
{
*r++ = '$';
*r++ = *p;
}
}
else
{
*r++ = *p;
}
p++;
}
*r = '\0';

return (result);
}
