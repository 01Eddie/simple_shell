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
		status = 2;
		fflush(stdout);
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

/**
 * _cd - function that changes the current directory
 * @args: argument cd
 *
 * Return: 1 on success
 **/
int _cd(char **args)
{
	char buff[1024], *cwd, *new_wd, *comp = "-", *old_pwd;
	int chint = 0;
	char *env;

	cwd = getcwd(buff, sizeof(buff));
	if (args[1] == NULL)
	{
		setenv("OLDPWD", getcwd(buff, sizeof(buff)), 1);
		env = _getenv("HOME");
		chdir(env);
		return (0);
	}
	if (_strcmp(args[1], comp) == 0)
	{
		old_pwd = _getenv("OLDPWD");
		setenv("OLDPWD", getcwd(buff, sizeof(buff)), 1);
		chdir(old_pwd);
		return (0);
	}

	if (cwd == NULL)
	{
		free(args);
		perror("Error: ");
		return (1);
	}

	chint = chdir(args[1]);

	if (chint == -1)
	{
		free(args);
		perror("Error: ");
		return (1);
	}
	setenv("OLDPWD", _getenv("PWD"), 1);
	new_wd = getcwd(buff, sizeof(buff));
	setenv("PWD", new_wd, 1);
	return (0);
}
