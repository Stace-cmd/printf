/**
 * print_char - function that prints a character
 * @args: va_list argument containing the character to be printed
 * Return: number of characters printed
 */
#include <unistd.h>
#include "main.h"
int print_char(va_list args)
{
	char ch = va_arg(args, int);

	write(1, &ch, 1);
	return (1);
}
/**
 * print_string - function that returns a string
 * @args: va_list argument containing the string to be printed
 * Return: number of characters printed
 */
int print_string(va_list args)
{
	char *str = va_arg(args, char *);
	int count = 0;

	while (str[count])
		count++;
	write(1, str, count);
	return (count);
}
