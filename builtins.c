#include "shell.h"

/**
 * new_exit - function to exit the shell where it is currently running
 * @args: pointer to array of arguments
 *
 * Return: 3 if error or exit status
 */
int new_exit(char **args)
{
	int status = 0, i;

	if (args[1] == NULL)
	{
		free(args[0]);
		free(args);
		exit(status);
	}

	for (i = 0; args[1][i] != '\0'; i++)
	{
		if (args[1][i] < 48 || args[1][i] > 57)
			return (3);
	}
	status = _atoi(args[1]);

	free(args[0]);
	free(args);
	exit(status);
}

/**
 * _printenv - print the environment
 * @args: pointer to pointer to arguments
 *
 * Return: 0 success
 */
int _printenv(char **args)
{
	int i;
	(void) args;

	for (i = 0; environ[i] != '\0'; i++)
	{
		_puts(environ[i]);
		_puts("\n");
	}
	return (0);
}
