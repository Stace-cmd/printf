/**
 * handleConversionSpecifier - determines which specifier is passed
 * @specifier: conversion specifier
 * @value: value to be formatted
 */
#include <stdio.h>
#include "main.h"

void handleConversionSpecifier(char specifier, unsigned int value)
{
	switch (specifier)
	{
		case 'u':
			printf("%u", value);
			break;
		case 'o':
			printf("%o", value);
			break;
		case 'x':
			printf("%x", value);
			break;
		case 'X':
			printf("%X", value);
			break;
		default:
			printf("Invalid conversion specifier");
			break;
	}
}
