#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf - produces output according to a format.
 * @format: string to be printed according to its format
 *
 * Return: the number of characters printed
 * (excluding the null byte used to end output to strings)
 */
int _printf(const char *format, ...)
{
	int i, count;
	va_list args;

	va_start(args, format);
	count = 0;
	for (i = 0; format[i]; i++)
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
			case 'c':
				count += write_char(va_arg(args, int));
				break;
			case 's':
				count += write_str(va_arg(args, char *));
				break;
			case '%':
				count += write_char('%');
				break;
			default:
				count += write_char('%');
				count += write_char(format[i]);
				break;
			}
		}
		else
		{
			count += write_char(format[i]);
		}
	}

	va_end(args);
	return (count);
}
