#include <stdarg.h>
#include <unistd.h>
#include "main.h"
/**
 * _printf - Prints a formatted string to the standard output.
 * @format: The format string.
 *
 * Return: The number of characters printed
 * (excluding the null byte used to end
 * output to strings), or -1 if an error occurred.
 */
int _printf(const char *format, ...)
{
	va_list args;
	int len;

	len = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			switch (*(++format))
			{
			case 'c':
				len += _putchar(va_arg(args, int));
				break;

			case 's':
				len += _puts(va_arg(args, char *));
				break;

			case '%':
				len += _putchar('%');
				break;

			case 'd':
			case 'i':
				len += _printd(va_arg(args, int));
				break;

			default:
				len += _putchar('%');
				len += _putchar(*format);
				break;
			}
		}
		else
			len += _putchar(*format);
		++format;
	}
	va_end(args);
	return (len);
}
