#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#define BUFFER_SIZE 1024
int _putchar(char c);
void handleConversionSpecifier(char specifier, unsigned int value);
int _printf(const char *format, ...);
int handle_conversion(char specifier, va_list args);
int print_char(va_list args);
int print_string(va_list args);
int print_int(va_list args);
int print_int_recursive(int num);

#endif /* MAIN_H */

