#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * _printf - printf function
 * @format: string with format specifier
 * Return: number of char printed
 */

int _printf(const char *format, ...)
{
	va_list args;
	int length = 0;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	length = _print_format(format, args);
	va_end(args);
	return (length);
}
