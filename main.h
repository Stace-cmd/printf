#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int _putchar(char c);
int _printf(const char *format, ...);
int handle_conversion(char specifier, va_list args);
int print_char(va_list args);
int print_string(va_list args);
int print_int(va_list args);
int print_int_recursive(int num);

#endif /* MAIN_H */

