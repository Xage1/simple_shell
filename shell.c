#include "Alxhell.h"



/**
 * shell_main - shell program
 * @argv: name of executable
 * @count: counter
 * Return: 0
 */
int shell_main(char **argv, int count)
{
int exit_status = 0;
char *buff = NULL, **av = NULL;
ssize_t retour;

if (prompt(&buff) == -1)
{
free_mem(1, buff);
return (1);
}

av = fill_argum(buff, " \t"), count++;
if (av[0] == NULL)
{
free_mem(1, buff), free_array(av);
return (0);
}

if (strcmp(av[0], "alias") == 0)
{
handle_alias_command(av);
free_mem(1, buff), free_array(av);
return (0);
}

if (strcmp(av[0], "exit") == 0)
{
if (av[1] != NULL)
{
exit_status = atoi(av[1]);
}
free_mem(1, buff);
free_array(av);
exit(exit_status);
}

if (strcmp(av[0], "clear") == 0)
{
clear_screen();
free_mem(1, buff), free_array(av);
return (0);
}

if (strcmp(av[0], "setenv") == 0)
{
setenv_command(av);
free_mem(1, buff), free_array(av);
return (0);
}

if (strcmp(av[0], "unsetenv") == 0)
{
unsetenv_command(av);
free_mem(1, buff), free_array(av);
return (0);
}

if (av[0][0] != '/' && av[0][0] != '.')
{
retour = check_built_ins(av, buff, count);
if (retour == 0 || retour == 2)
{
free_mem(1, buff), free_array(av), retour == 0 ? (retour = 0) : (retour = 1);
return (retour);
}
if (!(find_in_path(av)))
{
print_err(argv, count, av), free_mem(1, buff), free_array(av);
return (2);
}
else
{
process(argv, av, buff, count), free_mem(2, *av, buff), free_array(av);
return (0);
}
}
if (process(argv, av, buff, count) != 0)
{
free_mem(1, buff), free_array(av);
return (2);
}
free_mem(1, buff), free_array(av);
return (0);
}
