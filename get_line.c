#include "Alxhell.h"

#define BUF_SIZE 256

/**
 * _getLine - recodage getLine
 * @file: file
 *
 * Return: line read (should be freed by the caller)
 */

char *_getLine(const int file)
{
	static char readding[BUF_SIZE];
	static int index;
	int getting = 0;
	int count = 0;
	char *get = NULL;

	if (getting == 0 && index >= BUF_SIZE)
	{
		index = 0;
		getting = read(file, readding, BUF_SIZE);
		if (getting == -1)
			return (NULL);
		readding[getting] = '\0';
	}

	if (index < BUF_SIZE && readding[index] != '\0')
	{
		get = malloc(BUF_SIZE);
		if (get == NULL)
			return (NULL);
		while (readding[index] != '\n' && readding[index] != '\0')
			get[count++] = readding[index++];
		get[count] = '\0';
		if (readding[index] != '\0')
			index = index + 1;
	}
	return (get);
}
