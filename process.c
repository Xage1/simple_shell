#include "Alxhell.h"

/**
 * process - create a process with the command store in the buffer
 * @argv: name of the shell
 * @av: array of arguments
 * @buf: buffer
 * @count: counter
 * Return: void
 */

int process(char **argv, char **av, char *buf, int count)
{
int status;
pid_t id;

if (buf == NULL)
return (-1);

id = fork();
if (id == -1)
{
free_mem(1, buf);
return (1);
}

if (id != 0)
wait(&status);
else if ((execve(av[0], av, NULL)) == -1)
{
print_err(argv, count, av);
free_mem(1, buf);
free_array(av);
_exit(98);
}
return (status);
}
