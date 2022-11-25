#include <unistd.h>

/**
 * _write - writes character to stdout
 * @c: the character to print
 *
 * Return: 1 success
 */

int _write(char c)
{
	return (write(1, &c, 1));
}
