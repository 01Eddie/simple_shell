#include "shell.h"
#define DICT_LEN 256

/**
 * *create_delim_dict - function that create delimiter to tokenize again
 * @delim: pointer character
 * Return: d
*/
int *create_delim_dict(char *delim)
{
	int *d, i;

	d = (int *) malloc(sizeof(int) * DICT_LEN);
	_memset((void *)d, 0, sizeof(int) * DICT_LEN);

	for (i = 0; i < _strlen(delim); i++)
		d[delim[i]] = 1;

	return (d);
}

/**
 * *_strtok- function that extract tokens from strings
 * @str: character
 * @delim: character
 * Return: NULL or str
*/
char *_strtok(char *str, char *delim)
{
	static char *last, *to_free;
	int *deli_dict = create_delim_dict(delim);

	if (!deli_dict)
	{
		if (to_free)
			free(to_free);

		return (NULL);
	}

	if (str)
	{
		last = (char *)malloc(_strlen(str) + 1);
		if (!last)
		{
			free(deli_dict);
			return (NULL);
		}
		to_free = last;
		_strcpy(last, str);
	}

	while (deli_dict[*last] && *last != '\0')
		last++;

	str = last;
	if (*last == '\0')
	{
		free(deli_dict), free(to_free);
		deli_dict = NULL, to_free = NULL;
		return (NULL);
	}
	while (*last != '\0' && !deli_dict[*last])
		last++;

	*last = '\0', last++;

	free(deli_dict);
	return (str);
}
