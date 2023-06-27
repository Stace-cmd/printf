/**
 * handleConversionSpecifier - determines the specifier 
 * @specifier: the specifier
 * @value: value to be formatted
 */
#include "main.h"
void handleConversionSpecifier(char specifier, unsigned int value)
{
	char buffer[BUFFER_SIZE];
	int length = 0;

	switch (specifier)
	{
		case 'u':
			length = snprintf(buffer, BUFFER_SIZE, "%u", value);
			break;
		case 'o':
			length = snprintf(buffer, BUFFER_SIZE, "%o", value);
			break;
		case 'x':
			length = snprintf(buffer, BUFFER_SIZE, "%x", value);
			break;
		case 'X':
			length = snprintf(buffer, BUFFER_SIZE, "%X", value);
			break;
		default:
			snprintf(buffer, BUFFER_SIZE, "Invalid conversion specifier");
			length = strlen(buffer);
			break;
	}
}
