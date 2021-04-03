#include "shell.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * re_alloc - reallocate the memory space
 * @ptr: pointer to the array
 * @size: pointer to number of elements of the array
 *
 * Return: pointer to array reallocated
 */
char **re_alloc(char **ptr, int *size)
{
	char **new_ptr;
	int i = 0;

	new_ptr = malloc(sizeof(char *) * ((*size) + 10));
	if (new_ptr == NULL)
	{
		free(ptr);
		return (NULL);
	}
	for (i = 0; i < (*size); i++)
	{
		new_ptr[i] = ptr[i];
	}
	*size += 10;
	free(ptr);
	return (new_ptr);
}
