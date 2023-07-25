#include "Alxhell.h"

/**
 * find_alias - Finds an alias by its name.
 * @name: The name of the alias to find.
 * Return: Pointer to the alias if found, otherwise NULL.
 */

struct Alias *find_alias(const char *name)
{
int i;

for (i = 0; i < num_aliases; i++)
{
if (strcmp(aliases[i].name, name) == 0)
{
return (&aliases[i]);
}
}
return (NULL);
}

/**
 * add_alias - Adds or updates an alias.
 * @name: The name of the alias to add or update.
 * @value: The value to set for the alias.
 */

void add_alias(const char *name, const char *value)
{
if (num_aliases < MAX_ALIASES)
{
strcpy(aliases[num_aliases].name, name);
strcpy(aliases[num_aliases].value, value);
num_aliases++;
}
else
{
printf("Maximum number of aliases reached.\n");
}
}

/**
 * print_aliases - Prints all aliases or specific aliases.
 * @name: The name of the alias to print, or NULL to print all aliases.
 */

void print_aliases(const char *name)
{
int i;
if (name == NULL)
{
for (i = 0; i < num_aliases; i++)
{
printf("%s='%s'\n", aliases[i].name, aliases[i].value);
}

}
else
{
struct Alias *alias = find_alias(name);
if (alias != NULL)
{
printf("%s='%s'\n", alias->name, alias->value);
}
else
{
printf("\n");
}
}
}

/**
 * handle_alias_command - Handles the alias command.
 * @arguments: An array of command-line arguments for the alias command.
 */

void handle_alias_command(char *arguments[])
{

int i;
char *arg;
char *equal_sign;
char *name;
char *value;

if (arguments[1] == NULL)
{
print_aliases(NULL);
}
else
{
for (i = 1; arguments[i] != NULL; i++)
{
arg = arguments[i];
equal_sign = strchr(arg, '=');

if (equal_sign == NULL)
{

print_aliases(arg);
}
else
{
*equal_sign = '\0';
name = arg;
value = equal_sign + 1;
add_alias(name, value);
}
}
}
}
