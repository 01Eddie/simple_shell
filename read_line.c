#include "shell.h"

/**
 * read_line - read the input from stdin
 *
 * Return: pointer to line read
 */
char *read_line(void)
{
	char *line = NULL;

	if (_getline(&line) == EOF)
	{
		write(STDOUT_FILENO, "\n", 1);
		free(line);
		exit(127);
	}
	return (line);
}
