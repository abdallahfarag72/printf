#include <stdio.h>
#include <unistd.h>
#include "main.h"

/**
 * write_str - writes a string to standard output.
 * @str: string to be printed
 *
 * Return: length
 */
int write_str(char *str)
{
	int i, length, fd;

	length = 0;
	for (i = 0; str[i]; i++)
	{
		length++;
	}
	fd = fileno(stdin);
	write(fd, str, length);
	return (length);
}
