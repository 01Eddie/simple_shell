#include "shell.h"

/**
 * *_memset- short description, single line
 * @s: character
 * @b: character
 * @n: unsigned integer
 * Return: void
*/
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int index;
	char *memory = s, value = b;

	for (index = 0; index < n; index++)
		memory[index] = value;

	return (memory);
}
