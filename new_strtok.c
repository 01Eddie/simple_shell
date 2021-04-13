#include "shell.h"
#define DICT_LEN 256

/**
 * strloc - locates a char ins string
 * @str: string
 * @ch: character to be located
 *
 * Return: pointer to the first ocurrence
 */
char *strloc(char *str, char ch)
{
	while (*str != 0)
	{
		if (*str == ch)
			return (str);
		str++;
	}
	if (*str == ch)
		return (str);
	return (0);
}

/**
 * prefix_len - calculate the lenght of word before a delimit
 * @str: string
 * @delim: delim string
 *
 * Return: length of the string before a delimit
 */
int prefix_len(char *str, char *delim)
{
	int i, len = 0;

	while (str[len] != 0)
	{
		int flag = 0;

		for (i = 0; delim[i] != 0; i++)
		{
			if (str[len] == delim[i])
			{
				flag = 1;
				break;
			}
		}
		if (flag == 0)
			len++;
		else
			break;
	}
	return (len);
}

/**
 * *_strtok- function that extract tokens from strings
 * @str: string to be tokenized
 * @delim: delimeters character
 *
 * Return: pointer to each token or 0
 */
char *_strtok(char *str, char *delim)
{
	static char *tmp;
	int ch;

	if (!str)
		str = tmp;
	ch = *str++;
	while (strloc(delim, ch))
	{
		if (ch == 0)
			return (0);
		ch = *str++;
	}
	--str;
	tmp = str + prefix_len(str, delim);
	if (*tmp != 0)
	{
		*tmp = 0;
		tmp++;
	}
	return (str);
}
