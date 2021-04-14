#include "shell.h"

/**
 * print_error - print the error
 * @count_err: error count
 * @args: pointer to the array of arguments
 *
 * Return: void
 */
void print_error(int count_err, char **args)
{
	_puts(program_invocation_name);
	_puts(": ");
	printint(count_err);
	_puts(": ");
	_puts(args[0]);
	_puts(": ");
}

/**
 * format_error - manage the rror and print a format error
 * @status: exit status
 * @count_err: error count
 * @args: pointer to the array of arguments
 */
void format_error(int *status, int count_err, char **args)
{
	switch (*status)
	{
	case 127:
		print_error(count_err, args);
		_puts("not found");
		_puts("\n");
		break;
	case 3:
		print_error(count_err, args);
		_puts("Illegal number");
		if (args[1])
		{
			_puts(": ");
			_puts(args[1]);
			_puts("\n");
		}
		break;
	default:
		break;
	}
}
