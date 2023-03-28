#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * write_char - writes a char to standard output.
 * @c: char to be printed
 *
 * Return: 1
 */
int write_char(char c)
{
	int fd;

	fd = fileno(stdin);
	write(fd, &c, sizeof(c));
	return (1);
}
