#include "main.h"
#include <stddef.h>
/**
 * _printf - Print formatted output to stdout
 * @format: Format string containing directives
 *
 * Return: Number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
    va_list args;
    int length = 0;
    int i = 0;

    va_start(args, format);

    while (format && format[i])
    {
        if (format[i] == '%')
        {
            i++;
            if (format[i] == '\0')
                return (-1);
            length += handle_conversion(format[i], args);
        }
        else
        {
            _putchar(format[i]);
            length++;
        }
        i++;
    }

    va_end(args);
    return (length);
}

/**
 * handle_conversion - Handle the conversion specifier and call respective function
 * @specifier: Conversion specifier character
 * @args: va_list of arguments
 *
 * Return: Number of characters printed for the conversion specifier
 */
int handle_conversion(char specifier, va_list args)
{
    int count = 0;

    switch (specifier)
    {
        case 'c':
            count += print_char(args);
            break;
        case 's':
            count += print_string(args);
            break;
        case 'd':
        case 'i':
            count += print_int(args);
            break;
        default:
            _putchar('%');
            _putchar(specifier);
            count += 2;
            break;
    }

    return (count);
}

/**
 * print_char - Print a single character
 * @args: va_list of arguments
 *
 * Return: Always 1 (number of characters printed)
 */
int print_char(va_list args)
{
    char c = va_arg(args, int);

    _putchar(c);
    return (1);
}

/**
 * print_string - Print a string
 * @args: va_list of arguments
 *
 * Return: Number of characters printed
 */
int print_string(va_list args)
{
    char *str = va_arg(args, char *);
    int count = 0;

    if (str == NULL)
        str = "(null)";

    while (*str)
    {
        _putchar(*str);
        str++;
        count++;
    }

    return (count);
}

/**
 * print_int - Print an integer
 * @args: va_list of arguments
 *
 * Return: Number of characters printed
 */
int print_int(va_list args)
{
    int num = va_arg(args, int);
    int count = 0;

    if (num < 0)
    {
        _putchar('-');
        num = -num;
        count++;
    }

    if (num / 10)
        count += print_int_recursive(num / 10);

    _putchar('0' + (num % 10));
    count++;

    return (count);
}

/**
 * print_int_recursive - Recursive helper function to print an integer
 * @num: Integer to be printed
 *
 * Return: Number of digits in the integer
 */
int print_int_recursive(int num)
{
    int count = 0;

    if (num / 10)
        count += print_int_recursive(num / 10);

    _putchar('0' + (num % 10));
    count++;

    return (count);
}

