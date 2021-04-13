#include "shell.h"
#include <stdlib.h>
#include <string.h>

/**
 * split_line - tokenizes a line with a delimiter
 * @line: line to tokenize
 * @delim: delimiter to tokenize along
 *
 * Return: pointer to an array of pointers to the tokens
 */
char **split_line(char *line, char *delim)
{
	char **tokens;
	int i = 0, n_tokens = 10;

	if (line == NULL)
		return (NULL);
	tokens = malloc(sizeof(char *) * n_tokens);
	if (tokens == NULL)
	{
		perror("Fatal Error");
		return (NULL);
	}
	while ((tokens[i] = _strtok(line, delim)) != NULL)
	{
		i++;
		if (i == n_tokens)
		{
			tokens = re_alloc(tokens, &n_tokens);
			if (tokens == NULL)
			{
				perror("Fatal Error");
				return (NULL);
			}
		}
		line = NULL;
	}
	return (tokens);
}
