#include "main.h"
/**
 * _printd - Writes a signed integer to the standard output.
 * @n: The integer to write.
 *
 * Return: On success, the number of characters
 * written. On error, -1 is returned
 * and errno is set appropriately.
 */
int _printd(int n)
{
	int len, digit;

	len = 0;
	if (n < 0)
	{
		len += _putchar('-');
		n = -n;
	}

	if (n / 10)
	{
		len += _printd(n / 10);
	}

	digit = n % 10;
	len += _putchar(digit + '0');

	return (len);
}
