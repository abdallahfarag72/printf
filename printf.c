#include <stdarg.h>
#include <stdlib.h>
#include "main.h"

/**
 * _printf - produces output according to a format.
 * @format: character string containing format specifiers
 * @...: additional arguments to replace format specifiers
 *
 * Return: number of characters printed
 * (excluding the null byte used to end output to strings)
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
				len += _puts(va_arg(args, char*));
				break;

			case '%':
				len += _putchar('%');
				break;

			default:
				len += _putchar('%');
				len += _putchar(*format);
				break;
			}
		}
		else
		{
			len += _putchar(*format);
		}
		++format;
	}
	va_end(args);
	return (len);
}
