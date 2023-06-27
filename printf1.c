/**
 * _printf - prints a string in a formatted format
 * @format: string to print (char *)
 * @...: unknown parameters
 * Return: number of characters to be printed
 */
#include <stdarg.h>
#include "main.h"
#include "unistd.h"
int _printf(const char *format, ...)
{
	int i = 0;
	int count = 0;
	int value = 0;

	while (format[i])
	{
		value = write(1, &format[i], 1);
		count = count + value;
		i++;
	}

	return (count);
}
