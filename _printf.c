#include "main.h"
#include <unistd.h>

/**
 * _printf - Prints output according to a format.
 * @format: The format string.
 *
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;
    char *ptr = (char *)format;

    va_start(args, format);

    while (*ptr)
    {
        if (*ptr == '%')
        {
            ptr++;
            if (*ptr == '\0')
                break;
            if (*ptr == '%')
            {
                count += write(1, "%", 1);
                ptr++;
            }
            else if (*ptr == 'c')
            {
                /* Handle character */
                int c = va_arg(args, int);
                count += write(1, &c, 1);
                ptr++;
            }
            else if (*ptr == 's')
            {
                /* Handle string */
                char *s = va_arg(args, char *);
                while (*s)
                {
                    count += write(1, s, 1);
                    s++;
                }
                ptr++;
            }
        }
        else
        {
            count += write(1, ptr, 1);
            ptr++;
        }
    }

    va_end(args);

    return count;
}

