#include "shell.h"

/**
 * no_inter - function execute shell in non-interactive way
 * @builtin: array of structures of built-ins
 *
 * Return: void
 */
void no_inter(builtins_t *builtin)
{
	int status = 0, count_err = 0;
	char *line = NULL, **args = NULL;

	while (_getline(&line) != EOF)
	{
		count_err++;
		args = split_line(line, " \t\r\n\a");
		status = pr_exec(args, builtin);

		format_error(&status, count_err, args);
		free(args);
	}
	free(line);
	exit(status);
}
