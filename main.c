#include "shell.h"

/**
 * main - main function of project shell
 *
 * Return: 0 success
 */
int main(void)
{
	int status = 0, count_err = 0;
	char *line = NULL, **args = NULL;

	builtins_t builtin[] = {
		{"exit", new_exit},
		{"env", _printenv},
		{"cd", _cd},
		{NULL, NULL}
	};

	if (isatty(STDIN_FILENO) != 1)
		no_inter(builtin);

	signal(SIGINT, ctrlC);

	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2);

		count_err++;

		line = read_line();
		args = split_line(line, " \t\r\n\a");
		status = pr_exec(args, builtin);

		format_error(&status, count_err, args);

		free(args);
		free(line);
	}
	return (status);
}
