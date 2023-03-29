#include "main.h"

/**
 * _puts - Writes a string of characters to the standard output.
 * @str: The string to write.
 *
 * Return: On success, the number of characters
 * written. On error, -1 is returned
 * and errno is set appropriately.
 */
int _puts(char *str)
{
	int len = 0;

	while (*str)
	{
		len += _putchar(*str++);
	}

	return (len);
}
