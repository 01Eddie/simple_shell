#include "shell.h"

/**
 * _puts - print in the standar output
 * @s: string to be printed
 *
 * Return: void
 */
void _puts(char *s)
{
	write(STDOUT_FILENO, s, _strlen(s));
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(const char c)
{
	return (write(1, &c, 1));
}

/**
 * printint - print an int number
 * @n: number to be printed
 *
 * Return: vod
 */
void printint(int n)
{
	unsigned int n1;

	if (n < 0)
	{
		_putchar('-');
		n1 = -n;
	}
	else
		n1 = n;

	if (n1 / 10)
		printint(n1 / 10);
	_putchar(n1 % 10 + '0');
}
