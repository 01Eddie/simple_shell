#include "shell.h"
#include <unistd.h>


/**
 * ctrlC - function of detected ctrl + c or ANSI C signal handling
 * @sig_num: Integer
 *
 * Return: void
 */
void ctrlC(int sig_num)
{
	_putchar('\n');
	write(STDOUT_FILENO, "$ ", 2);
	fflush(stdout);
}
