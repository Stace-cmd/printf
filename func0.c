/**
 * _printf - function that prints the string in a formatted way
 * @format: identifier
 * @...: unknown parameters
 * Return: Number of characters in the string
 */
int _printf(const char * const format, ...)
{
	convert_match m[] = {
		{"%s", print_string}, {"%c", print_char},
		{"%%", print_37},
		{"%i", printf_int}, {"%d", print_dec}, {"%r", print_srev},
		{"%b", printf_bin}, {"%u", printf_unsigned},
		{"%o", printf_oct}, {"%x", printf_hex}, {"%X", printf_HEX},
		{"%S", printf_exclusive_string}, {"%p", printf_pointer}
	};
	va_list args;
	int val = 0;
	int elem_no;
	int char_count = 0;

	va_start(args, format);
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	while (format[val] != '\0')
	{
		elem_no = 13;
		while (elem_no >= 0)
		{
			if (m[elem_no].id[0] == format[val] && m[elem_no].id[1] == format[val + 1])
			{
				char_count += m[elem_no].f(args);
				val = val + 2;
				break;
			}
			elem_no--;
		}
		if (elem_no < 0)
		{
			_putchar(format[elem_no]);
			char_count++;
			val++;
		}
	}

	va_end(args);
	return (char_count);
}
