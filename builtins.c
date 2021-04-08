#include "shell.h"

/**
 * new_exit.c - function to exit the shell where it is currently running
 * @args: pointer to array of arguments
 *
 * Return: 3 if error or exit status
 */
int new_exit(char **args)
{
	int status = 0;

	free(args[0]);
	free(args);
	exit(status);
}
