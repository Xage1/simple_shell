#include "Alxhell.h"

/**
 * check_pwd - check if the path contains current directory
 *
 * @pwd: address of the pointer pwd
 * @path: address of the pointer path
 *
 * Return: path updated
 */
char *check_pwd(char **pwd, char **path)
{
char *str;

if (*(*(path)) == ':')
{

str = malloc(sizeof(char) * (_strlen(*pwd) + _strlen(*path) + 1));
if (str == NULL)
{
free_mem(2, *pwd, *path);
return (NULL);
}
_strcpy(str, *pwd), _strcat(str, *path);
}

else if (_strstr(*path, "::") != NULL)
{
str = update_path(*path, *pwd);
if (str == NULL)
{
free_mem(2, *pwd, *path);
return (NULL);
}
}
else
{
str = malloc(sizeof(char) * (strlen(*path)) + 1);
if (str == NULL)
{
free_mem(2, *pwd, *path);
return (NULL);
}
_strcpy(str, *path);
}
return (str);
}
