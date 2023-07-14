#include "Alxhell.h"

/**
 * print_err - prints an error message on stderr
 *
 * @argv: name of the executable
 * @count: counter of errors
 * @av: name of the command
 */

void print_err(char **argv, int count, char **av)
{
	write(2, *argv, strlen(*argv));
	write(2, ": ", 2);
	write_int_err(count);
	write(2, ": ", 2);
	write(2, *av, strlen(*av));
	write(2, ": ", 2);
	write(2, "not found\n", 10);
}

/**
 * write_int_err - print an integer with write's function on stderr
 * @number: integer
 * Return: number of characters printed
 */

int write_int_err(int number)
{
	int temp, characters_printed = 0;
	unsigned int c1;

	if (number < 0)
	{
		number = -number;
		write(2, "-", 1);
		characters_printed++;
	}
	c1 = number;
	if (c1 / 10)
	{
		characters_printed += write_int(c1 / 10);
	}
	temp = (c1 % 10) + '0';
	return (characters_printed += write(2, &temp, 1));
}


