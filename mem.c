#include "Alxhell.h"
/**
 * free_mem - free the memory from buffer and array of arguments
 * @n: number of arguments
 *
 * Return: void;
 */
void free_mem(const unsigned int n, ...)
{
	va_list arglist;
	unsigned int i;
	char *arg;

	va_start(arglist, n);
	for (i = 0; i < n; i++)
	{
		arg = va_arg(arglist, char *);
		free(arg);
	}
}

/**
 * free_array - free the memory of pointer array
 * @arr: pointer array
 * Return: void
 */
void free_array(char **arr)
{
	free(arr);
}


