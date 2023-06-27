#include "main.h"
#include <string.h>
#include <stdarg.h>
#include <stdio.h>
/**
 * _printf - prints a formatted string
 * @format: string that prints char *
 * @...: unknown parameters
 * Return: number of characters that are printed
 */
int _printf(const char *format, ...)
{
	va_list args;

	va_start(args, format);

	int char_count = 0;

	while (*format != '\0'){
		if (*format == '%'){
			format = format + 1;
			switch (*format)
			{
				case 'c':{
						int ch = va_arg(args, int);
						putchar(ch);
						char_count = char_count + 1;
						break;
					}
				case 's':{
						char *str = va_arg(args, char*);
						fputs(str, stdout);
						char_count = char_count + strlen(str);
						break;
					}
				case '%':{
						putchar('%');
						char_count = char_count + 1;
						break;
					}
				default:{
						putchar('%');
						putchar(*format);
						char_count = char_count + 2;
						break;
					}
			}
		}
		else{
			putchar(*format);
			char_count = char_count + 1;
		}
		format++;
	}
	va_end(args);
	return (char_count);
}
