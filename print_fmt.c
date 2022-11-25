#include "main.h"
#include <stdlib.h>

/**
 * _print_format - prints format
 * @format: format to prints
 * @args: list of variadic arguments
 *
 * Return: length of format
 */

int _print_format(const char *format, va_list args)
{
	int c = 0;
	int i = 0;

	while (format && format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
				return (-1);

			i++;

			while (format[i] == ' ')
				i++;

			if (format[i] == '%')
				c += _write(format[i]);

			if (_validate_char(format[i]) == 0)
			{
				c = _print_invaliid_spec(format[i - 1], format[i], c);
			}

			else
			{
				c += _print_spec(format[i], args);
			}
		}

		else
		{
			c += _write(format[i]);
		}

		i++;
	}

	return (c);
}

/**
 * _print_spec - prints a valid specifier
 * @format: spec to print
 * @args: list of variadic args
 *
 * Return: length of the spec
 */

int _print_spec(char format, va_list args)
{
	int c = 0;
	int len = 0;

	spc_dt _types[] = {
		{"c", _print_a_char},
		{"s", _print_a_string},
		{"d", _print_an_integer},
		{"i", _print_an_integer},
		{"b", _print_int_binary},
		{NULL, NULL}
	};

	while (_types[c].specifier)
	{
		if (*_types[c].specifier == format)
			len = _types[c].f(args);
		c++;
	}

	return (len);
}

/**
 * _print_invalid_spec - prints invalid specifier
 * @prev_format: previous specifier of original specifier
 * @format: spec to prints
 * @count: current count before invalid spec print
 *
 * Return: current count after invalid spec print
 */

int _print_invalid_spec(char prev_format, char format, int count)
{
	count += _write('%');

	if (prev_format == ' ')
	{
		count += _write(' ');
		count += _write(format);
	}

	else
	{
		count += _write(format);
	}

	return (count);
}

/**
 * _validate_char - type validator
 * @_type: char to compare
 *
 * Return: 1 if char = to type
 */

int _validate_char(char _type)
{
	char _types[] = {'c', 's', 'd', 'i', 'b', '%'};
	int c = 0;

	while (_types[c])
	{
		if (_types[c] == _type)
			return (1);

		c++;
	}
	return (0);
}


