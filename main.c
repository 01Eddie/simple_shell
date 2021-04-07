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

	signal(SIGINT, ctrlC);

	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2);

		line = read_line();
		args = split_line(line, " \t\r\n\a");
		status = pr_exec(args);

		free(args);
		free(line);
	}
	return (status);
}
