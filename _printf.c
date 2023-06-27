#include "main.h"
#include <stdarg.h>

int _printf(const char *format, ...)
{
    va_list args;
    int len = 0;
    char *str;

    va_start(args, format);
    while (*format)
    {
        if (*format == '%')
        {
            format++;
            switch (*format)
            {
                case 'c':
                    _print_char(va_arg(args, int));
                    len++;
                    break;
                case 's':
                    str = va_arg(args, char *);
                    len += _print_str(str);
                    break;
                case '%':
                    _putchar('%');
                    len++;
                    break;
            }
        }
        else
        {
            _putchar(*format);
            len++;
        }
        format++;
    }
    va_end(args);
    return (len);
}

int _print_char(char c)
{
    return (write(1, &c, 1));
}

int _print_str(char *str)
{
    int len = 0;
    while (*str)
    {
        _putchar(*str);
        len++;
        str++;
    }
    return (len);
}

int _putchar(char c)
{
    return (write(1, &c, 1));
}

