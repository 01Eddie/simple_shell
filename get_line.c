#include <stdint.h>
#include "shell.h"

/**
 * _getline - function that get lines
 * @line: double Character
 * @len: size_t
 * @fp: FILE
 * Return: -1 or _strlen(*line)
 */
ssize_t _getline(char **line, size_t *len, FILE *fp)
{
	char chunk[128];

	if (line == NULL || len == NULL || fp == NULL)
	{
		perror("Error: Bad arguments or Pointers files bad. \n");
		return (-1);
	}

	if (*line == NULL)
	{
		*len = sizeof(chunk);
		*line = malloc(*len);
		if (line == NULL)
		{
			perror("Fatal error.");
			free(line);
			return (-1);
		}
	}
	(*line)[0] = '\0';

	while (fgets(chunk, sizeof(chunk), fp) != NULL)
	{
		*len = _strlen(*line);
		if (*len < sizeof(chunk))
		{
			*len = sizeof(chunk) + 1;
			*line = malloc(*len);
			if (line == NULL)
			{
				perror("Fatal error.");
				free(line);
				return (-1);
			}
		}
		_strcat2(*line, chunk);
		if ((*line)[_strlen(*line) - 1] == '\n')
			return (_strlen(*line));
	}
	return (-1);
}
