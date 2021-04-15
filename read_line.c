#include "shell.h"

/**
 * read_line - read the input from stdin
 *
 * Return: pointer to line read
 */
char *read_line(void)
{
	char *line = NULL;
	size_t bufsize = 0;

	if (getline(&line, &bufsize, stdin) == EOF)
	{
		write(STDOUT_FILENO, "\n", 1);
		free(line);
		exit(127);
	}
	line[_strlen(line) - 1] = '\0';
	return (line);
}
