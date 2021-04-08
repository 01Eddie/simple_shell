#include "shell.h"

/**
 * main - main function of project shell
 *
 * Return: 0 success
 */
int main(void)
{
	int status = 0;
	char *line = NULL, **args = NULL;

	builtins_t builtin[] = {
		{"exit", new_exit},
		{NULL, NULL}
	};

	signal(SIGINT, ctrlC);

	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2);

		line = read_line();
		args = split_line(line, " \t\r\n\a");
		status = pr_exec(args, builtin);

		free(args);
		free(line);
	}
	return (status);
}
