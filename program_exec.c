#include "shell.h"

/**
 * _free2 - frees args and path
 * @args: Buffer containing the tokens
 * @path: path to look for execution files
 *
 *Return: void
 */
void _free2(char **args, char **path)
{
	free(args[0]);
	free(args);
	free(path);
}

/**
 * check_existence - checkes whether a file exists
 * @path: pointer to the path to search in
 *
 * Return: 1 on success, -1 if failed
 */
int check_existence(char *path)
{
	int fd = access(path, F_OK | X_OK);

	if (fd == -1)
		return (-1);
	return (1);
}

/**
 * pr_launch - launch a program and wait until finalization
 * @args: pointer to an array of arguments
 *
 * Return: 1 to continue execution
 */

int pr_launch(char **args)
{
	int status, existence, c;
	int child_pid;
	char *env = 0, **path = 0, *path_command = 0, *command = 0;

	child_pid = fork();
	if (child_pid < 0)
		perror("Fatal Error");
	else if (child_pid == 0)
	{
		env = _getenv("PATH");

		path = split_line(env, ":");
		for (c = 0; path[c]; c++)
		{
			command = _strcat("/", args[0]);
			path_command = _strcat(path[c], command);
			existence = check_existence(path_command);
			if (existence != -1)
			{
				args[0] = path_command;
				break;
			}
			else
				free(path_command);
			free(command);
		}
		existence = check_existence(args[0]);
		if (existence == -1)
		{
			_free2(args, path);
			exit(2);
		}
		if (execve(args[0], args, environ) == -1)
			perror("Fatal Error");
		_free2(args, path);
		exit(2);
	}
	else
		wait(&status);
	return (WEXITSTATUS(status));
}

/**
 * pr_exec - execute the arguments
 * @args: pointer to the array of arguments
 * @builtin: struc of builtin funcs
 *
 * Return: 1 success
 */
int pr_exec(char **args, builtins_t *builtin)
{
	int i;

	if (args[0] == NULL)
		return (0);

	for (i = 0; i < 1; i++)
	{
		if (_strcmp(args[0], builtin[i].command) == 0)
			return (builtin[i].func(args));
	}
	return (pr_launch(args));
}
