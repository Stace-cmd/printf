/**
 * _printf - prints formatted string
 * @format: format string
 * @...: unknown parameters
 * Return: number of characters printed
 */
#include "main.h"
#include "print_helpers.h"
#include <unistd.h>
#include <stdarg>

int _printf(const char *format, ...)
{
	int ccount = 0;
	va_list args;

	va_start(args, format);
	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			count++;
		}
		else
		{
			format++;
			if (*format == '\0')
			{
				write(1, format, 1);
				count++;
			}
		}
		else if  (*format == 'c')
		{
			count += print_char(args);
		}
		else if (*format == 's')
		{
			count += print_string(args);
		}
		format++;
	}
	va_end(args);
	return (count);
}
