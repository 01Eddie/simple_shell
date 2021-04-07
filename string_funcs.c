#include "shell.h"
/**
 * _strcmp - function that compare two strings
 * @dest: character
 * @src: character
 * Return: 0 or *dest -*src
*/
int _strcmp(const char *dest, const char *src)
{
	while ((*dest != '\0' && *src != '\0') && *dest == *src)
	{
		dest++;
		src++;
	}

	return ((*dest == *src) ? (0) : (*dest - *src));
}

/**
 * _strdup - function that duplicate a string
 * @s: Character
 * Return: NULL or dest
 */

char *_strdup(char *s)
{
	/*Space for length plus null*/
	char *dest = malloc(_strlen(s) + 1);
	/*No memory*/
	if (s == NULL)
		return (NULL);
	/*No memory*/
	if (dest == NULL)
		return (NULL);
	/*copy of characters*/
	_strcpy(dest, s);
	/*return the news characters*/
	return (dest);
}

/**
 * _strlen - function that calculate the length of a string
 * @s: description of parameters
 * Return: length of s
*/
int _strlen(char *s)
{
	int count = 0;

	while (s[count] != '\0')
		count++;

	return (count);
}

/**
 * _strcpy - function that copy a string
 * @dest: character
 * @src: character
 * Return: dest + '\0'
 */
char *_strcpy(char *dest, char *src)
{
	int count = 0;

	while (src[count] != '\0')
	{
		dest[count] = src[count];
		count++;
	}
	dest[count] = '\0';

	return (dest);
}

/**
 * _strcat - function that concatenates two strings
 * @str1: first string
 * @str2: second string to be concatenated
 *
 * Return: pointer to the concatenated string
 */
char *_strcat(char *str1, char *str2)
{
	char *string;
	int len1 = _strlen(str1), len2 = _strlen(str2), i, j;

	string = malloc(sizeof(char) * (len1 + len2 + 1));
	if (string == NULL)
	{
		perror("Error: impossible to allocate memory");
		exit(98);
	}
	for (i = 0; str1[i] != '\0'; i++)
	{
		string[i] = str1[i];
	}
	for (j = 0; str2[j] != '\0'; j++)
	{
		string[i + j] = str2[j];
	}
	string[i + j] = '\0';
	return (string);
}
