#include "shell.h"

/**
 * fill_null - fill with null bytes a memory
 * @buff: pointer to the memory
 * @size: size of teh memory
 *
 * Return: pointer to the memory filled with null bytes
 */

char *fill_null(char *buff, int size)
{
	int i;

	if (!buff)
		return (NULL);

	for (i = 0; i < size; i++)
		buff[i] = '\0';

	return (buff);
}

/**
 * _realloc - reallocate memory whith 3 args
 * @old_buff: pointer to the old block of memory
 * @old_size: size of the old block of memory
 * @new_size: size the new block of memory should be
 *
 * Return: New pointer to new block of memory if new_size differs from old_size
 */

void *_realloc(void *old_buff, unsigned int old_size, unsigned int new_size)
{
	unsigned int i;
	char *new_buff, *ch_oldbuff;

	if (new_size == old_size)
		return (old_buff);

	if (!new_size && old_buff)
	{
		free(old_buff);
		return (NULL);
	}

	/* Set new char pointer to the same element as ptr */
	ch_oldbuff = (char *) old_buff;

	new_buff = malloc(new_size);
	if (!new_buff)
		return (NULL);

	if (!old_buff)
		return (new_buff);

	fill_null(new_buff, new_size);

	for (i = 0; (i < old_size) && (i < new_size); i++)
	{
		new_buff[i] = ch_oldbuff[i];
	}

	/* Type cast new pointer back to void */
	new_buff = (void *) new_buff;

	free(old_buff);
	return (new_buff);
}

/**
 * _getline - function that get lines
 * @line: NULL pointer which text will be located
 *
 * Return: number of characters read
 */
ssize_t _getline(char **line)
{
	char *buff;
	int oldsize, bufsize = 64, pos = 0, num = 0;
	ssize_t i = 0;

	*line = NULL;

	if (!line || !*line)
	{
		buff = malloc(sizeof(char) * bufsize);
		if (!buff)
			return (0);
		fill_null(buff, bufsize);
		*line = buff;
	}


	do {
		num = read(STDIN_FILENO, buff + pos, 64);
		if (num == -1 || !*buff)
			return (-1);
		pos += num;

		if (num >= 64)
		{
			oldsize = bufsize;
			bufsize += 64;
			buff = _realloc(buff, oldsize, bufsize);
			if (!buff)
				return (0);
			*line = buff;
		}
	} while (num >= 64);

	i = _strlen(buff);

	return (i);
}
