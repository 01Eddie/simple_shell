#include "shell.h"
/**
 * ctrlC - function of detected ctrl + c or ANSI C signal handling
 * @sig_num: Integer
 * Return: void
 */
 
void ctrlC(int sig_num)
{
	signal(sig_num, SIG_IGN);
	fflush(stdout);
}
